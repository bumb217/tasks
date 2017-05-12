#ifndef collegue_h
#define collegue_h

#include "mediator.h"
#include <string>
#include <vector>

class Colleague
{
protected:
    Mediator* system;
    
public:
    std::string name;
    int age;
    std::vector<std::string> messages;
    
    virtual void sendInfo(std::string m) = 0;
};

class Dog : public Colleague
{
public:
    Dog(std::string n, int years, Mediator* mediat) {
        name = n;
        age = years;
        system = mediat;
    }
    
    void sendInfo(std::string m) override {
        system->chat(this, m);
    }
    
};

#endif /* collegue_h */
