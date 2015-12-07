//
//  http_client.cpp
//  mono framework
//
//  Created by Kristoffer Andersen on 17/11/2015.
//  Copyright © 2015 Monolit ApS. All rights reserved.
//

#include "http_client.h"
#include "regex.h"

using namespace mono::network;

HttpClient::HttpClient() : INetworkRequest(), respData(this), getFrame(NULL) {}

HttpClient::HttpClient(String anUrl) : INetworkRequest(), respData(this), getFrame(NULL)
{
    mono::Regex reg("(http://)([^\\s/'\\\"<>\\?]+)(/?[^\\s'\\\"<>]*)");
    
    mono::Regex::Capture caps[3];
    bool success = reg.Match(anUrl, caps, 3);
    
    if (!success) {
        debug("url parse err");
        lastErrorCode = URL_PARSE_ERROR;
        triggerQueuedErrorHandler();
        return;
    }
    
    domain = reg.Value(caps[1]);
    path = reg.Value(caps[2]);
    
    debug("domain: %s, path: %s\n\r",domain(),path());
    
    dns = DnsResolver(domain);
    dns.setCompletionCallback<HttpClient>(this, &HttpClient::dnsComplete);
    dns.setErrorCallback<HttpClient>(this, &HttpClient::dnsResolutionError);
    
    setState(IN_PROGRESS_STATE);
    getFrame = NULL;
}


HttpClient::HttpClient(const HttpClient &other) :
    INetworkRequest(other),
    respData(other.respData),
    getFrame(other.getFrame)
{
    domain = other.domain;
    path = other.path;
    dns = other.dns;
    
    dns.setCompletionCallback<HttpClient>(this, &HttpClient::dnsComplete);
    dns.setErrorCallback<HttpClient>(this, &HttpClient::dnsResolutionError);
    
    if (getFrame != NULL)
    {
        getFrame->setDataReadyCallback<HttpClient>(this, &HttpClient::httpData);
    }
}

HttpClient &HttpClient::operator=(const mono::network::HttpClient &other)
{
    INetworkRequest::operator=(other);
    respData = other.respData;
    getFrame = other.getFrame;
    domain = other.domain;
    path = other.path;
    dns = other.dns;
    
    dns.setCompletionCallback<HttpClient>(this, &HttpClient::dnsComplete);
    dns.setErrorCallback<HttpClient>(this, &HttpClient::dnsResolutionError);
    
    if (getFrame != NULL)
    {
        getFrame->setDataReadyCallback<HttpClient>(this, &HttpClient::httpData);
    }
    
    return *this;
}


void HttpClient::dnsResolutionError(INetworkRequest::ErrorEvent *evnt)
{
    this->lastErrorCode = evnt->ErrorCode;
    triggerDirectErrorHandler(); // Error evnt is already queued
}

void HttpClient::dnsComplete(INetworkRequest::CompletionEvent *evnt)
{
    if (getFrame != NULL)
    {
        debug("getFrame != NULL, Invalid state! getFrame is: 0x%x\n\r",getFrame);
        lastErrorCode = INVALID_STATE_ERROR;
        triggerDirectErrorHandler(); // dns complete cb is already queued
        return;
    }
    
    debug("dns complete, call http get");
    getFrame = new redpine::HttpGetFrame(domain, dns.IpAddress(), path, NULL);
    getFrame->setDataReadyCallback<HttpClient>(this, &HttpClient::httpData);
    getFrame->commitAsync();
}

void HttpClient::httpData(redpine::HttpGetFrame::CallbackData *data)
{
    respData.bodyChunk = String((char*)(data->data), data->dataLength);
    respData.Finished = data->context->lastResponseParsed;
    
    debug("got data call data ready async\n\r");
    debug("-> %s\n\r",respData.bodyChunk());
    // call data ready async, to release mem. objs on stack
    Timer::callOnce<HttpClient>(0, this, &HttpClient::triggerDataReady);
}

void HttpClient::triggerDataReady()
{
    dataHandler.call(respData);
    
    if (respData.Finished)
    {
        debug("comp handlr\n\r");
        triggerCompletionHandler();
    }
}

HttpClient::~HttpClient()
{
    if (getFrame != NULL && getFrame->handlerContextObject == this)
    {
        delete getFrame;
    }
}


