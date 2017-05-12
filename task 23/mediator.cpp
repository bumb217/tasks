#include "mediator.h"
#include "collegue.h"

DogsChatSystem::DogsChatSystem(int n){
    number = n;
};

void DogsChatSystem::chat(Dog* coll, std::string message) {
    coll->messages.push_back(message);
}

