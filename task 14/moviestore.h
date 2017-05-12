#ifndef moviestore_h
#define moviestore_h

class MovieStore
{
public:
    Movie* order(std::string title, std::string lang)
    {
        Movie* ordered = new Movie(title);
        Language* l = new Language;
        AbstractFactory* f = l->getLangPack(lang);
        
        ordered->setAud(f->getAud());
        ordered->setSub(f->getSub());
        
        return ordered;
    }
};

#endif /* moviestore_h */
