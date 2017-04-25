//
//  main.cpp
//  libpuma
//
//  Created by Ibrahim Abdullah on 25/04/2017.
//  Copyright © 2017 Ibrahim Abdullah. All rights reserved.
//

#include <iostream>
#include "json.hpp"

#include "client.h"
#include "course.h"
#include "chapter.h"
#include "timer.h"

using json = nlohmann::json;

int main(int argc, const char * argv[]) {

    Timer timer;
    timer.add();
    timer.dump();
    
    Client client;
    Chapter chapter(&client);
    json data;
    
    timer.add();
    timer.dump();
    timer.add();
    
    data = chapter.get("586a003e890bf34a77bd6281");
    
    timer.add();
    timer.dump();
    
    std::cout << data["results"]["chapter"]["title"] << endl;
    
    timer.add();
    
    data = chapter.get("586a004c890bf34a77bd6282");
    
    timer.add();
    timer.dump();
    
    std::cout << data["results"]["chapter"]["title"] << endl;
    
    timer.add();
    timer.dump();
    
    return 0;
}
