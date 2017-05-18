#include "bacteria.h"

BacteriaPersonality::BacteriaPersonality(string name_, int age_,bool gender_)
{
    colony = "first";
    name = name_;
    age = age_;
    gender = gender_;
}

void BacteriaPersonality::show() const
{
    string gender_;
    if (gender == 0) gender_ = "Female";
            else gender_ = "Male";
    cout << name << " live " << age << " minutes, " << gender_ << ", family : " << colony << endl;
}

const Bacteria& BacteriaFactory::getBacteria(string name_, int age_, bool gender_)
{
    Bacterias::const_iterator iter = bactMass.find(name_);
    if (bactMass.end() == iter)
    {
        const Bacteria *bacteriaTemp = new BacteriaPersonality(name_, age_, gender_);
        bactMass[name_] = bacteriaTemp;
        return *bacteriaTemp;
    }
    else
    {
        return *iter->second;
    }
}

BacteriaFactory::~BacteriaFactory()
{
    for (Bacterias::const_iterator iter = bactMass.begin(); iter != bactMass.end(); ++iter)
    {
        delete iter->second;
    }
}
