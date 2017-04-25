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
    
    typedef unsigned long long timestamp;
    
    std::vector< timestamp > times;
    
    static timestamp getTimestamp();
    
    public:
        void add();
        void dump();
};

#endif /* timer_h */
