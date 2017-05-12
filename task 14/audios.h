#ifndef audios_h
#define audios_h


class Audio
{
public:
    std::string lang;
    Audio() {}
};

class EN_Aud : public Audio
{
public:
    EN_Aud() {
        lang = "English";
    }
};

class DE_Aud : public Audio
{
public:
    DE_Aud() {
        lang = "Deutsch";
    }
};

class UKR_Aud : public Audio
{
public:
    UKR_Aud() {
        lang = "Українська";
    }
};

#endif /* audios_h */
