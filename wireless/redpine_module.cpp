//
//  redpine_module.cpp
//  Mono::Redpine
//
//  Created by Kristoffer Andersen on 27/05/15.
//
//

#include "redpine_module.h"
#include <consoles.h>
#include <mbed.h>

using namespace mono::redpine;

/** Construct the module */
Module Module::moduleSingleton;

Module::Module()
{
    communicationInitialized = false;
    networkInitialized = false;
}

// STATIC PUBLIC METHODS

Module* Module::Instance()
{
    return &Module::moduleSingleton;
}

bool Module::initialize(ModuleCommunication *commInterface)
{
    
    if (commInterface == NULL)
    {
        mono::defaultSerial.printf("Cannot init Redpine Module without comm. interface!\n\r");
        return false;
    }
    
    // Assign interface to object
    Module* self = Module::Instance();
    self->comIntf = commInterface;
    
    self->comIntf->resetModule();
    
    mono::defaultSerial.printf("Initializing communication interface...\n\r");
    // initalize interface
    bool success = self->comIntf->initializeInterface();
    
    if (!success)
    {
        mono::defaultSerial.printf("Initialize failed to init communication interface\n\r");
        return false;
    }
    
    mono::defaultSerial.printf("Checking bootloader state...\n\r");
    uint16_t regval = self->comIntf->readMemory(HOST_INTF_REG_OUT);
    mono::defaultSerial.printf("HOST_INTF_REG_OUT: 0x%x\n\r", regval);
    
    if ((regval & HOST_INTERACT_REG_VALID) == 0xAB00)
    {
        mono::defaultSerial.printf("Module is in bootloader, load Image-I...\n\r");
        self->comIntf->InterfaceVersion = regval;
        self->comIntf->writeMemory(HOST_INTF_REG_IN, HOST_INTERACT_REG_VALID | RSI_LOAD_IMAGE_I_FW);
    }
    
    // we need to wait for board ready frame
    mono::defaultSerial.printf("Waiting for card ready to arrive on input...\n\r");
    int timeout = 0;
    while (!self->comIntf->pollInputQueue() && timeout++ < 50)
    {
        //wait a while
        mbed::wait_ms(2);
    }
    
    if (timeout >= 50)
    {
        mono::defaultSerial.printf("Timeout: Did not receive Card ready!\n\r");
        return false;
    }
    
    mono::defaultSerial.printf("Input pending, will read frame...\n\r");
    ManagementFrame frame;
    self->comIntf->readManagementFrame(frame);
    
    if (frame.commandId == ModuleFrame::CardReady)
    {
        mono::defaultSerial.printf("Card ready received\n\r");
        return true;
    }
    else
    {
        mono::defaultSerial.printf("Initialization failed on receiving card ready\n\r");
        mono::defaultSerial.printf("Initialization got 0x%x, not card ready\n\r",frame.commandId);
        return false;
    }
    
}

bool Module::setupWifiOnly(const char *ssid, const char *passphrase, WifiSecurityModes secMode)
{
    // send "set operating mode command"
    
    mono::defaultSerial.printf("Setting OperMode...\n\r");
    SetOperatingModeFrame opermode(SetOperatingModeFrame::WIFI_CLIENT_MODE);
    opermode.setDefaultConfiguration();
    opermode.commit();
    
    mono::defaultSerial.printf("Setting band...\n\r");
    BandFrame band;
    band.commit();
    
    mono::defaultSerial.printf("Initialize module RF and baseband...\n\r");
    InitFrame init;
    init.commit();
    
    mono::defaultSerial.printf("Scanning for networks...\n\r");
    ScanFrame scan;
    scan.commit();
    
    mono::defaultSerial.printf("Connecting to %s\n\r",ssid);
    JoinFrame join(ssid, passphrase, secMode);
    join.commit();
    
    mono::defaultSerial.printf("Getting IP address from DHCP...\n\r");
    SetIpParametersFrame ipparam;
    ipparam.commit();
    
    return true;
}











