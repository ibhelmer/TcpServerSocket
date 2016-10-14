// This software is part of OpenMono, see http://developer.openmono.com
// Released under the MIT license, see LICENSE.txt
#include "queue_interrupt.h"
#include "application_context_interface.h"
#include <us_ticker_api.h>

using namespace mono;

QueueInterrupt::QueueInterrupt(PinName pin, PinMode mode) : mbed::InterruptIn(pin)
{
    this->singleShot = false;
    this->mode(mode);
    this->addedToRunLoop = false;
    this->fallEvent = this->riseEvent = deactivateUntilHandler = false;
    this->isHandled = true;
    this->debounce = false;
    this->debounceTimeoutUs = 30000;
}

QueueInterrupt::~QueueInterrupt()
{
    deactivateQueueTaskHandler();
}

void QueueInterrupt::rise(void (*fptr)())
{
    activateQueueTaskHandler();
    _queue_rise.attach(fptr);
    _rise.attach<QueueInterrupt>(this, &QueueInterrupt::_irq_rise_handler);
    gpio_irq_set(&gpio_irq, IRQ_RISE, 1);
}

void QueueInterrupt::fall(void (*fptr)())
{
    activateQueueTaskHandler();
    _queue_fall.attach(fptr);
    _fall.attach<QueueInterrupt>(this, &QueueInterrupt::_irq_fall_handler);
    gpio_irq_set(&gpio_irq, IRQ_FALL, 1);
}

void QueueInterrupt::_irq_rise_handler()
{
    if (deactivateUntilHandler && !isHandled)
        return;

    this->snapShot = this->read();
    this->riseTimeStamp = us_ticker_read();

    if (debounce)
    {
        debounceRiseTimer.attach_us<QueueInterrupt>(this, &QueueInterrupt::debounceRiseHandler, debounceTimeoutUs);
    }
    else
    {
        this->riseEvent = true;
        this->isHandled = false;
    }
}

void QueueInterrupt::_irq_fall_handler()
{
    if (deactivateUntilHandler && !isHandled)
        return;

    this->snapShot = this->read();
    this->fallTimeStamp = us_ticker_read();

    if (debounce)
    {
        debounceFallTimer.attach_us<QueueInterrupt>(this, &QueueInterrupt::debounceFallHandler, debounceTimeoutUs);
    }
    else
    {
        this->fallEvent = true;
        this->isHandled = false;
    }
}

void QueueInterrupt::debounceRiseHandler()
{
    if (this->read())
    {
        this->riseEvent = true;
        this->isHandled = false;
    }
}

void QueueInterrupt::debounceFallHandler()
{
    if (!this->read())
    {
        this->fallEvent = true;
        this->isHandled = false;
    }
}

void QueueInterrupt::taskHandler()
{
    if (riseEvent) {
        riseEvent = false;
        _queue_rise.call();
        isHandled = true;
    }
    if (fallEvent)
    {
        fallEvent = false;
        _queue_fall.call();
        isHandled = true;
    }
}

void QueueInterrupt::DeactivateUntilHandled(bool deactive)
{
    deactivateUntilHandler = deactive;
    isHandled = true;
}

bool QueueInterrupt::IsInterruptsWhilePendingActive() const
{
    return this->deactivateUntilHandler;
}

void QueueInterrupt::setDebouncing(bool active)
{
    this->debounce = active;
}

void QueueInterrupt::setDebounceTimeout(int timeUs)
{
    this->debounceTimeoutUs = timeUs;
}

uint32_t QueueInterrupt::FallTimeStamp()
{
    return fallTimeStamp;
}

uint32_t QueueInterrupt::RiseTimeStamp()
{
    return riseTimeStamp;
}

bool QueueInterrupt::Snapshot()
{
    return snapShot;
}

void QueueInterrupt::activateQueueTaskHandler()
{
    if (!addedToRunLoop)
    {
        IApplicationContext::Instance->RunLoop->addDynamicTask(this);
        addedToRunLoop = true;
    }
}

void QueueInterrupt::deactivateQueueTaskHandler()
{
    if (addedToRunLoop)
    {
        IApplicationContext::Instance->RunLoop->removeDynamicTask(this);
        addedToRunLoop = false;
    }
}
