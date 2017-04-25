/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

#ifndef client_h
#define client_h

class Client {
    
    CURL *curl;
    const string url = "https://api.qcare-academy.nl";
    
    public:
        Client();
    
        json get(string path);
        static size_t response(void *contents, size_t size, size_t nmemb, void *userp);
    
        ~Client();
};

#endif /* client_h */
