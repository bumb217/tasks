#ifndef visitor_h
#define visitor_h

class GardenPlant;
class Garden;
class AppleTree;
class CherryTree;
class PearTree;
class LemonTree;

class GardenPlantVisitor
{
public:
    virtual string visit(Garden* garden) = 0;
    virtual string visit(CherryTree* cherry) = 0;
    virtual string visit(AppleTree* apple) = 0;
    virtual string visit(LemonTree* lemon) = 0;
    virtual string visit(PearTree* pear) = 0;
    
};

class Visitor : public GardenPlantVisitor
{
public:
    string visit(Garden* garden) {
        return "Checking garden.";
    };
    
    string visit(CherryTree* cherry) {
        return"Checking cherry tree.";
    };
    
    string visit(AppleTree* apple) {
        return"Checking apple tree.";
    };
    
    string visit(LemonTree* lemon) {
        return"Checking lemon tree.";
    };
    
    string visit(PearTree* pear) {
        return"Checking pear tree.";
    };
};


#endif /* visitor_h */
