#ifndef languages_h
#define languages_h

class Language
{
private:
    AbstractFactory* f;
public:
    Language() {};
    
    AbstractFactory* getLangPack(std::string lang)
    {
        if (lang == "EN")
        {
            f = new EN_Factory();
        }
        else if (lang == "DE")
        {
            f = new DE_Factory();
        }
        else if (lang == "UKR")
        {
            f = new UKR_Factory();
        }
        return f;
    };
};


#endif /* languages_h */
