#include "bacteria.h"
#include <ctime>

int main()
{
    BacteriaFactory bactFactory;
    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        string newName = "";
        for (int j = 0; j < 7;j++)
        {
            char temp = 'a'+ rand()%25;
            newName += temp;
        }
        const Bacteria& bacter = bactFactory.getBacteria(newName, rand()%10, rand()%2);
        bacter.show();
    }
    
    return 0;
}
