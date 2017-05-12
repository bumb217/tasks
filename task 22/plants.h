#ifndef plants_h
#define plants_h

#include "visitor.h"

class GardenPlant
{
public:
    virtual void accept(GardenPlantVisitor* plantVisitor) = 0;
    
    bool visited = false;
};



class AppleTree : public GardenPlant
{
public:
    void accept(GardenPlantVisitor* plantVisitor) {
        plantVisitor->visit(this);
        visited = true;
    }
};

class CherryTree : public GardenPlant
{
public:
    void accept(GardenPlantVisitor* plantVisitor) {
        plantVisitor->visit(this);
        visited = true;
    }
};
class LemonTree : public GardenPlant
{
public:
    void accept(GardenPlantVisitor* plantVisitor) {
        plantVisitor->visit(this);
        visited = true;
    }
};

class PearTree : public GardenPlant
{
public:
    void accept(GardenPlantVisitor* plantVisitor) {
        plantVisitor->visit(this);
        visited = true;
    }
};


#endif /* plants_h */
