/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "json.hpp"
#include "client.h"

#ifndef base_h
#define base_h

using json = nlohmann::json;

class Base {
    
    Client *client;
    
    public:
        Base(Client *client);
        json all();
        json get(string id);
    
    protected:
        virtual string path() = 0;
};

#endif /* base_h */
