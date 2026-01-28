#include<stdio.h>
#include "Module.h"
void module_trigger(int idx){
    switch(idx){
        case 0:
            Notification();
            break;
        case 1:
            Y();
            break;
        case 2:
            Z();
            break;
        case 3:
            P();
            break;
        case 4:
            Q();
            break;
        
    }
}
