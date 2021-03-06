
#include "scheduled_task.h"
#include "rtc_interface.h"

using namespace mono;

GenericQueue<ScheduledTask> ScheduledTask::queue;

ScheduledTask::ScheduledTask()
{
    runInSleep = true;
}

ScheduledTask::ScheduledTask(const DateTime &scheduledTime)
{
    runInSleep = true;
    time = scheduledTime;
}

ScheduledTask::ScheduledTask(const ScheduledTask &other)
{
    runInSleep = other.runInSleep;
    time = other.time;
    handler = other.handler;
    
    if (time.isValid() && time > DateTime::now() && handler)
        queue.Enqueue(this);
}

ScheduledTask::~ScheduledTask()
{
    queue.Remove(this);
}

ScheduledTask& ScheduledTask::operator=(const ScheduledTask &other)
{
    runInSleep = other.runInSleep;
    time = other.time;
    handler = other.handler;
    
    if (time.isValid() && time > DateTime::now() && handler)
        queue.Enqueue(this);
    
    return *this;
}

void ScheduledTask::reschedule(const mono::DateTime &newTime)
{
    queue.Remove(this);
    time = newTime;
    
    if (time.isValid() && time > DateTime::now())
        queue.Enqueue(this);
}

bool ScheduledTask::willRunInSleep() const
{
    return runInSleep;
}

void ScheduledTask::setRunInSleep(bool run)
{
    runInSleep = run;
}

void ScheduledTask::runTask(bool inSleep)
{
    queue.Remove(this);
    
    if ((inSleep && runInSleep) || !inSleep)
        handler.call();
}

bool ScheduledTask::isDue() const
{
    return time.isValid() && time <= DateTime::now();
}


void ScheduledTask::processScheduledTasks(bool inSleep)
{
    if (!IRTCSystem::__shouldProcessScheduledTasks)
        return;
    
    IRTCSystem::__shouldProcessScheduledTasks = false;
    ScheduledTask *task = ScheduledTask::queue.Peek();
    
    while (task != 0)
    {
        // get next before task might be dequeued and re-qeueued
        ScheduledTask *next = queue.Next(task);
        
        if (task->isDue())
        {
            task->runTask(inSleep);
        }
        
        task = next;
    }
}

