//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Customer class file

#include "Customer.h"

Histogram Customer::H("Full time spent on post", 0, MIN, 60);

void Customer::Behavior() {
    double entered = Time;
    double r;
    int orders = 0;
    do {
        Facility* f = facilityContainer->FindShortestQueueTicketMachine();

        Seize(*f);

        if (Random() < 0.9) {
            Wait(Uniform(30,60));   // Usual waiting time 
        } else {
            Wait(Uniform(MIN, 3*MIN));  // Extended waiting time
        }
        Release(*f);

        // Send or Receive list / Send or recive package / Other request 
        if ((r = Random()) < 0.3) {
            f = facilityContainer->QueueingSystem(1);
        } else if (r >= 0.3 && r < 0.8) {
            f = facilityContainer->QueueingSystem(2);
        } else {
            f = facilityContainer->QueueingSystem(3);
        }

        Seize(*f);
        Wait(Uniform(3*MIN, 5*MIN));    // Customer time spent waiting for service 
        Release(*f);
    } while (++orders < 3  && (r = Random()) < 0.2);   // Other requests, but 3 at most

    H(Time-entered);    // Full time spent on post

}
