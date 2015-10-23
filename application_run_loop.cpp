//
//  application_run_loop.cpp
//  displaySimTest
//
//  Created by Kristoffer Lyder Andersen on 12/07/15.
//
//

#include "application_run_loop.h"
#include "application_context_interface.h"
#include <mbed.h>
#include <consoles.h>

using namespace mono;

AppRunLoop::AppRunLoop()
{
    runLoopActive = true;
    lastDtrValue = true;
    resetOnDTR = true;
    resetOnUserButton = false;
    taskQueueHead = NULL;
}

void AppRunLoop::exec()
{
    debug("mono enter run loop!\n\r");
    
    lastDtrValue = mono::defaultSerial.DTR();
    
    while (runLoopActive) {
        
        if (mono::defaultSerial.IsReady())
        {
            bool dtr = mono::defaultSerial.DTR();
            if (resetOnDTR && (!dtr) && lastDtrValue)
            {
                debug("mono DTR reboot!\n\r");
                IApplicationContext::SoftwareReset();
            }
            lastDtrValue = dtr;
        }
        
        if (resetOnUserButton)
        {
            if (CyPins_ReadPin(SW_USER) == 0)
            {
                IApplicationContext::SoftwareReset();
            }
        }
        
        processDynamicTaskQueue();
        
        
        // what else todo
        wait_ms(10);
    }
    
    debug("run loop terminated!");
}


void AppRunLoop::processDynamicTaskQueue()
{
    if (taskQueueHead == NULL)
        return;
    
    IRunLoopTask *task = taskQueueHead;
    while (task != NULL) {
        
        task->taskHandler();
        
        if (task->singleShot)
            removeTaskInQueue(task);
        
        // we can still use the tasks next pointer,
        //  even if its not in the list anymore
        task = task->nextTask;
    }
}


bool AppRunLoop::addDynamicTask(mono::IRunLoopTask *task)
{
    if (taskQueueHead == NULL)
    {
        taskQueueHead = task;
        task->nextTask = NULL;
        task->previousTask = NULL;
    }
    else
    {
        IRunLoopTask *item = taskQueueHead;
        while (item->nextTask != NULL)
        {
            item = item->nextTask;
        }
        
        item->nextTask = task;
        task->previousTask = item;
        task->nextTask = NULL;
    }
    
    return true;
}

bool AppRunLoop::removeDynamicTask(mono::IRunLoopTask *task)
{
    if (taskQueueHead == NULL)
        return false;
    
    IRunLoopTask *item = taskQueueHead;
    
    while (item != NULL)
    {
        if (item == task)
        {
            removeTaskInQueue(item);
            return true;
        }
        
        item = item->nextTask;
    }
    
    return false;
}

void AppRunLoop::removeTaskInQueue(IRunLoopTask *item)
{
    if (item->previousTask != NULL)
        item->previousTask->nextTask = item->nextTask;
    
    if (item->nextTask != NULL)
        item->nextTask->previousTask = item->previousTask;
}

void AppRunLoop::setResetOnUserButton(bool roub)
{
    if (roub)
    {
        CyPins_SetPinDriveMode(SW_USER, CY_PINS_DM_RES_UP);
        wait_us(10); // wait for pull up resistor
        resetOnUserButton = true;
    }
    else
        resetOnUserButton = false;
}