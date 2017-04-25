/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "base.h"

#ifndef course_h
#define course_h

/**
 Course class definition extending base api class
 */
class Course : public Base {
    
    using Base::Base;
    
    protected:
        string path() override { return "/courses"; }
};

#endif /* course_h */
