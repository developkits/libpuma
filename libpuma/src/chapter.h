/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "base.h"

#ifndef chapter_h
#define chapter_h

/**
 Chapter class definition extending base api class
 */
class Chapter : public Base {
    
    using Base::Base;
    
    protected:
        string path() override { return "/chapters"; }
};

#endif /* chapter_h */
