#include <iostream>
#include <string>
#include <map>

using namespace std;

class Bacteria
{
public:
    virtual void show() const = 0;
    virtual ~Bacteria(){}

protected:
    string colony;
    int age;
    bool gender;
    string name;
};

class BacteriaPersonality :public Bacteria
{
public:
    BacteriaPersonality(string name_, int age_, bool gender_);
    virtual void show() const;
};

class BacteriaFactory
{
public:
    const Bacteria& getBacteria(string name_, int age_, bool gender_);
    virtual ~BacteriaFactory();

private:
    typedef map <string, const Bacteria*> Bacterias;
    Bacterias bactMass;
};
