#include "../include/dffos.h"
#include <stdio.h>



void invalid_unit(){
    #ifndef _rrasms_disable_warning_messages_
    perror("Invalid Unit!\n Please read libary README.");
    #endif
}


#if defined(__WIN64__) || defined(__WIN32__) //For win64 and win32 systems.
    #include <windows.h>



    /*Note: The error cannot occur on a 64-bit system, because an unsigned long and an unsigned long long can represent the same number of numbers on 64-bit systems (18,446,744,073,709,551,615), but the error can occur on a 32-bit system, because here the maximum number that can be represented by an unsigned long is 4,294,967,295, but the maximum number that can be represented by an unsigned long long remains the same, therefore the ram size 
    is shortened on 32-bit systems if it is too large and is therefore no longer as accurate.*/
    void ull_overflow_ul(){
        #ifndef _rrasms_disable_warning_messages_
        perror("Warning message unsigned long long overflows unsigned long! Data blocks could be lost.");
        #endif
    }
    
    
    size_tl get_total_ram(size_tl unit){
        MEMORYSTATUSEX statusex;
        statusex.dwLength = sizeof(statusex);
        GlobalMemoryStatusEx(&statusex);
        unsigned long long llresult;
        size_tl result;
        switch(unit){
            case 0: llresult = statusex.ullTotalPhys; break;
            case 1: llresult = statusex.ullTotalPhys / 1024; break;
            case 2: llresult = statusex.ullTotalPhys / (1024 * 1024); break;
            case 3: llresult = statusex.ullTotalPhys / (1024 * 1024 * 1024); break;
            default: invalid_unit(); break;
        }

        result = (size_tl) llresult;
        if(llresult > result){ull_overflow_ul();}
        return result;
    };


    size_tl get_free_ram(size_tl unit){
        MEMORYSTATUSEX statusex;
        statusex.dwLength = sizeof(statusex);
        GlobalMemoryStatusEx(&statusex);
        unsigned long long llresult;
        size_tl result;
        switch(unit){
            case 0: llresult = statusex.ullAvailPhys; break;
            case 1: llresult = statusex.ullAvailPhys / 1024; break;
            case 2: llresult = statusex.ullAvailPhys / (1024 * 1024); break;
            case 3: llresult = statusex.ullAvailPhys / (1024 * 1024 * 1024); break;
            default: invalid_unit(); break;
        }

        result = (size_tl) llresult;
        if(llresult > result){ull_overflow_ul();}
        return result;
    };







#elif defined(__unix__) //for linux/Unix-based systems.
    #include <sys/sysinfo.h>





    size_tl get_total_ram(size_tl unit){
        struct sysinfo info;

        #ifndef _rrasms_disable_warning_messages_
        if (sysinfo(&info) != 0) {
            
            perror("Failed to get system info");
            return 0;
        }
        #endif

        size_tl result;
        switch(unit){ /*
        converts the unit by either returning the bytes of the memory space or dividing 
        the number of bytes and multiplying 
        it several times by 1024 (because 1024 bytes is a kilobyte, 1024 kilobytes is a megabyte, etc.).
        */
            case 0: result = info.totalram * info.mem_unit; break;
            case 1: result = info.totalram * info.mem_unit / 1024; break;
            case 2: result = info.totalram * info.mem_unit / (1024 * 1024); break;
            case 3: result = info.totalram * info.mem_unit / (1024 * 1024 * 1024); break;
            default: invalid_unit(); break;
        }
        return result;
    }
    


    size_tl get_free_ram(size_t unit){
        static struct sysinfo info;

        #ifndef _rrasms_disable_warning_messages_
        if (sysinfo(&info) != 0) {
            perror("Failed to get system info");
            return 0;
        }
        #endif

        size_t result;
        switch(unit){
            case 0: result = info.freeram * info.mem_unit; break;
            case 1: result = info.freeram * info.mem_unit / 1024; break;
            case 2: result = info.freeram * info.mem_unit / (1024 * 1024); break;
            case 3: result = info.freeram * info.mem_unit / (1024 * 1024 * 1024); break;
            default: invalid_unit(); break;
        }
        return result;
            }
#else
    #error "Sorry, this library does not support this operating system!"
#endif
