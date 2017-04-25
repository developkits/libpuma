/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "client.h"

Client::Client() {
    this->curl = curl_easy_init();
};

json Client::get(string path) {

    string response;
    
    if (this->curl) {
        
        curl_easy_setopt(this->curl, CURLOPT_URL, (this->url + path).c_str());
        curl_easy_setopt(this->curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, this->response);
        curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &response);
        
        CURLcode res;
        
        res = curl_easy_perform(this->curl);
    }
    
    return json::parse(response);
};

size_t Client::response(void *contents, size_t size, size_t nmemb, void *userp) {
    
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
};


Client::~Client() {
    curl_easy_cleanup(this->curl);
};
