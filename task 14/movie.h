#ifndef movie_h
#define movie_h

class Movie
{
public:
    std::string title;
    Subtitle* sub;
    Audio* aud;
    
    Movie(std::string name)
    {
        title = name;
        sub = new Subtitle;
        aud = new Audio;
    }
    
    void setSub(Subtitle* newSub){
        sub = newSub;
    }
    
    void setAud(Audio* newAud){
        aud = newAud;
    }
    
};


#endif /* movie_h */
