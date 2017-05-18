//
//  main.cpp
//  task-2
//
//  Created by Андрей Пригода on 27.03.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#include "sequence.h"
#include <list>

class A {
public:
    A(int nval = 0):val(nval){};
    int val;
};

void test() {
    sequence<A> mySeq;
    
    for (int i = 0; i < 10; i++) {
        A *my = new A(i);
        
        try {
            mySeq.insert(my, 0);
        }
        catch(sequence<A>::outOfrangeException e) {
            e.printMessage();
        }
    }
    
    mySeq.pop(5);
    
    for (int i = 0; i < mySeq.size(); i++) {
        cout << mySeq.get(i)->val << " ";
    }
    cout << endl;
}


int main() {
    test();
    return 0;
}
