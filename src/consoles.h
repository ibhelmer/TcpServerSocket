// This software is part of OpenMono, see http://developer.openmono.com
// and is available under the MIT license, see LICENSE.txt

#ifndef __spiTest__consoles__
#define __spiTest__consoles__

#include <stdio.h>
#include <mn_serial.h>

namespace mono {
    
    static io::Serial defaultSerial;
    
    /**
     * Print a section of memory to the console as hex
     * 
     */
    void memdump(void *ptr, uint32_t length);
    
    /** Print an error on screen or console */
    //void error(const char *msg);
    
    /** Print a warning on screen or console */
    void warning(const char *msg);
    
    class Console
    {
    public:
        mbed::Serial *serial;
        
        Console(mbed::Serial *ser);
        
        Console& operator<<(const char *txt);
        Console& operator<<(int integer);
        Console& operator<<(char integer);
        Console& operator<<(float number);
        
    };
    
    static Console Error(&defaultSerial);
    static Console Warn(&defaultSerial);
    static Console Debug(&defaultSerial);
    
//    Console& operator<<(Console &console, const char *txt);
//    Console& operator<<(Console &console, int integer);
//    Console& operator<<(Console &console, char integer);
//    Console& operator<<(Console &console, float number);
    
}

#endif /* defined(__spiTest__consoles__) */
