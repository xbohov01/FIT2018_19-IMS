//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Customer class file

#include "Customer.h"


void Customer::Behavior() {
    double time = Time;
    
    internalBehavior();

    Print("Customer time in system: %f\n", Time-time);
}


void Customer::internalBehavior() {
    Facility* f = facilityContainer->FindShortestQueueTicketMachine();

    Seize(*f);
    if (Random() < 0.9) {
        Wait(Uniform(30,60));   // Usual waiting time 
    } else {
        Wait(Uniform(MIN, 3*MIN));  // Extended waiting time
    }
    Release(*f);

    double r;
    r = Random();
    // Send or Receive list / Send or recive package / Other request 
    if (r < 0.3) {
        f = facilityContainer->QueueingSystem(1);
    } else if (r > 0.3 && r < 0.8) {
        f = facilityContainer->QueueingSystem(2);
    } else {
        f = facilityContainer->QueueingSystem(3);
    }

    Seize(*f);
    Wait(Uniform(3*MIN, 5*MIN));    // Customer time spent waiting for service 
    Release(*f);

    if ((r = Random()) < 0.2) {
        internalBehavior();
    }
}