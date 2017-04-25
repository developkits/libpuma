/**
 * @author  Ibrahim Abdullah <ibrahim@ingeniousdev.nl>
 * @package libpuma
 * @created 25/04/2017
 */
#include "base.h"

Base::Base(Client *client) {
    this->client = client;
};

json Base::all() {
    return this->client->get(this->path());
};

json Base::get(string id) {
    return this->client->get(this->path() + "/" + id);
};
