#ifndef factories_h
#define factories_h

class AbstractFactory
{
public:
    virtual Subtitle* getSub() = 0;
    virtual Audio* getAud() = 0;
};

class EN_Factory : public AbstractFactory
{
public:
    Subtitle* getSub() {
        Subtitle* sub = new EN_Sub;
        return sub;
    }
    Audio* getAud() {
        Audio* aud = new EN_Aud;
        return aud;
    }
};

class DE_Factory : public AbstractFactory
{
public:
    Subtitle* getSub() {
        Subtitle* sub = new DE_Sub;
        return sub;
    };
    Audio* getAud() {
        Audio* aud = new DE_Aud;
        return aud;
    }

};

class UKR_Factory : public AbstractFactory
{
public:
    Subtitle* getSub() {
        Subtitle* sub = new UKR_Sub;
        return sub;
    };
    Audio* getAud() {
        Audio* aud = new UKR_Aud;
        return aud;
    }
    
};


#endif /* factories_h */
