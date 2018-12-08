//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Customer class file

#include "Customer.h"
#include "ClerkRest.h"

Histogram Customer::FullTime("Full time spent on post", 0, 5*MIN, 20);
Histogram Customer::LineTime("Time spent in line to clerk", 0, 2*MIN, 50);
Histogram Customer::MachineTime("Time spent in line to machine", 0, 2*MIN, 50);
int Customer::customerInSystem = 0;
int Customer::count = 0;

void Customer::Behavior() {
    double entered = Time;
    double enteredMLine, enteredLine;
    double r;
    int orders = 0;

    Customer::customerInSystem++;
    Customer::count++;
    do {
        Facility* f = facilityContainer->FindShortestQueueTicketMachine();
        enteredMLine = Time;
        SeizeTicketMachine(f);
        MachineTime(Time-enteredMLine);

        // Send or Receive list / Send or recive package / Other request 
        if ((r = Random()) < 0.3) {
            f = facilityContainer->QueueingSystem(1);
        } else if (r >= 0.3 && r < 0.8) {
            f = facilityContainer->QueueingSystem(2);
        } else {
            f = facilityContainer->QueueingSystem(3);
        }

        enteredLine = Time;
        SeizeClerk(f);
        LineTime(Time-enteredLine);

    } while (++orders < 3  && (r = Random()) < 0.2);   // Other requests, but 3 at most

    FullTime(Time-entered);    // Full time spent on post
    Customer::customerInSystem--;   // Customer leaves

    if (Customer::count >= 5) {
        Customer::count -= 5;
        ClerkRest *rest = new ClerkRest();
        rest->facilityContainer = this->facilityContainer;
        rest->Activate();
    }

}

void Customer::SeizeTicketMachine(Facility *f) {
    Seize(*f);
    if (Random() < 0.9) {
        Wait(Uniform(30,60));   // Usual waiting time 
    } else {
        Wait(Uniform(MIN, 3*MIN));  // Extended waiting time
    }
    Release(*f);
}

void Customer::SeizeClerk(Facility *f) {
    Seize(*f);
    Wait(Uniform(3*MIN, 15*MIN));    // Customer time spent waiting for service 
    Release(*f);
}
