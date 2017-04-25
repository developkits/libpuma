/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "base.h"

/**
 Base Constructor
 
 @param client http client
 */
Base::Base(Client *client) {
    this->client = client;
};

/**
 Fetching the all endpoint
 
 @return json
 */
json Base::all() {
    return this->client->get(this->path());
};

/**
 Fetching endpoint record

 @param id MongoId of endpoint
 @return json
 */
json Base::get(string id) {
    return this->client->get(this->path() + "/" + id);
};
