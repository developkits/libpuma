/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "client.h"

/**
 HTTP get request
 Use only path of api; exclude url. That will be added automatically.

 @param path path of api endpoint
 @return json object of api
 */
json Client::get(string path) {

    // curl handler
    CURL *curl = curl_easy_init();
    
    // response of api
    string response;
    
    // curl response code
    CURLcode res;
    
    if (curl) {
        
        // setting up to be curled url
        curl_easy_setopt(curl, CURLOPT_URL, (this->url + path).c_str());
        
        // if redirected, follow
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        // catching response with #response function into local variable response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, this->response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
        // perform curl and cleanup
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    
    return json::parse(response);
};


/**
 Catching curl response into variable requires buffering data

 @param contents contents
 @param size size
 @param nmemb nmemb
 @param userp userp
 @return size * nmemb
 */
size_t Client::response(void *contents, size_t size, size_t nmemb, void *userp) {
    
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
};
