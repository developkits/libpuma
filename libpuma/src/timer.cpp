/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "timer.h"

void Timer::add() {
    times.push_back(get_timestamp());
};

void Timer::dump() {
    
    unsigned long total = times.size();
    timestamp_t t0;
    timestamp_t t1;
    double sec;
    
    try {
        
        t0  = times.at(total - 2);
        t1  = times.at(total - 1);
        sec = (t1 - t0) / 1000000.0L;
        
    } catch (std::out_of_range e) {
        
        t0  = 0;
        t1  = 0;
        sec = 0;
    }
    
    std::cout << "Executed: " + std::to_string(sec) << std::endl;
};
