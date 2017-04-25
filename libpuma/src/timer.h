/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include <sys/time.h>
#include <iostream>
#include <vector>

#ifndef timer_h
#define timer_h

class Timer {
    
    typedef unsigned long long timestamp_t;
    
    std::vector< timestamp_t > times;
    
    static timestamp_t get_timestamp() {
        
        struct timeval now;
        gettimeofday(&now, NULL);
        
        return now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
    };
    
    public:
        void add();
        void dump();
};

#endif /* timer_h */
