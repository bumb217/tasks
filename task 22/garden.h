#ifndef garden_h
#define garden_h

#include "plants.h"

class Garden : public GardenPlant
{
    vector<GardenPlant*> plants;
    
public:
    Garden() {
        plants = { new AppleTree(), new CherryTree(), new LemonTree(), new PearTree() };
    }
    
    vector<GardenPlant*> getPlants() {
        return plants;
    }
    
    void accept(GardenPlantVisitor* plantVisitor) {
        plantVisitor->visit(this);
        for (auto x : plants) {
            x->accept(plantVisitor);
        }
        visited = true;
    }
    
    ~Garden()
    {
        for (auto x : plants) {
            delete x;
        }
    }
};

#endif /* garden_h */
