//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//CustomerTimeout class file

#include "CustomerTimeout.h"

CustomerTimeout::CustomerTimeout(Customer *c, Facility *f) : customer(c), facility(f) {
    Activate(Time+Uniform(40*MIN, 90*MIN));
}

void CustomerTimeout::Behavior() {
    if (customer->isInQueue()) {
        customer->Out();    // Remove from current queue
        customer->Activate();   // Run again
    }
}