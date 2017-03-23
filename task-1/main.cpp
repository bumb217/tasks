//
//  main.cpp
//  task-1
//
//  Created by Андрей Пригода on 23.03.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#include <iostream>

#include "sortpack.h"
#include <time.h>

int main() {
    
    srand(time(NULL));

    sortpack mySort;
    
    mySort.fill(10);
    mySort.printElements();
    
    mySort.select();
    mySort.printElements();
    
    return 0;
}
