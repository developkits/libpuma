/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "timer.h"

/**
 Adding timestamp to timer
 */
void Timer::add() {
    times.push_back(this->getTimestamp());
};


/**
 Dumping timer data from t<total - 2> and t<total - 1>
 */
void Timer::dump() {
    
    unsigned long total = times.size();
    Timer::timestamp t0;
    Timer::timestamp t1;
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

/**
 Getting current timestamp
 */
Timer::timestamp Timer::getTimestamp() {
    
    struct timeval now;
    gettimeofday(&now, NULL);
    
    return now.tv_usec + (Timer::timestamp)now.tv_sec * 1000000;
};
