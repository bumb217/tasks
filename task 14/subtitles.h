#ifndef subtitles_h
#define subtitles_h

class Subtitle
{
public:
    std::string lang;
    Subtitle() {}
};

class EN_Sub : public Subtitle
{
public:
    EN_Sub() {
        lang = "English";
    }
};

class DE_Sub : public Subtitle
{
public:
    DE_Sub() {
        lang = "Deutsch";
    }
};

class UKR_Sub : public Subtitle
{
public:
    UKR_Sub() {
        lang = "Українська";
    }
};


#endif /* subtitles_h */
