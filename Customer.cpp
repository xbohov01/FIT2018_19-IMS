//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Customer class file

#include "Customer.h"
#include "ClerkRest.h"
#include "CustomerTimeout.h"

Histogram Customer::FullTime("Full time spent on post", 0, 5*MIN, 50);
Histogram Customer::LineTime("Time spent in line to clerk", 0, 5*MIN, 50);
Histogram Customer::MachineTime("Time spent in line to machine", 0, 30, 20);
int Customer::customerInSystem = 0;
int Customer::count = 0;
int Customer::amount = 0;
int Customer::unsatisfied = 0;

Customer::Customer(FacilityContainer *con) : facilityContainer(con) {
    Activate();
}

void Customer::Behavior() {
    double entered = Time;
    double r;
    int orders = 0;

    Customer::amount++;
    Customer::customerInSystem++;
    Customer::count++;
    leaving = false;
    do {
        Facility* f = facilityContainer->FindShortestQueueTicketMachine();
        SeizeTicketMachine(f);

        if ((r = Random()) < 0.3) {
            f = facilityContainer->QueueingSystem(1);   // Recive package
        } else if (r >= 0.3 && r < 0.8) {
            f = facilityContainer->QueueingSystem(2);   // Send package
        } else {
            f = facilityContainer->QueueingSystem(3);   // Other request
        }

        SeizeClerk(f);
        if (leaving) leave();   // Customer waited too long
    } while (!leaving && ++orders < 3  && (r = Random()) < 0.2);   // Other requests, but 3 at most

    FullTime(Time-entered);    // Full time spent on post
    Customer::customerInSystem--;   // Customer leaves

    if (Customer::count >= 5) { // Create possibility for Clerk to do other work
        ClerkRest *rest = new ClerkRest(facilityContainer, Customer::count);
    }

}

void Customer::SeizeTicketMachine(Facility *f) {
    double enteredMLine = Time;
    Seize(*f);
    if (Random() < 0.9) {
        Wait(Uniform(10,60));   // Usual waiting time 
    } else {
        Wait(Uniform(MIN, 3*MIN));  // Extended waiting time
    }
    Release(*f);
    MachineTime(Time-enteredMLine);
}

void Customer::SeizeClerk(Facility *f) {
    double enteredLine = Time;
    CustomerTimeout *t = new CustomerTimeout(this, f);
    Seize(*f);
    delete t;
    if (f->in!=this) {
        leaving = true;
    } else {
        Wait(Uniform(3*MIN, 15*MIN));    // Customer time spent waiting for service 
        Release(*f);
    }
    LineTime(Time-enteredLine);
}

void Customer::leave() {
    if (Random() < 0.1) {
        Facility *f = facilityContainer->QueueingSystem(3); // Gets any queue to complain
        Seize(*f);
        Wait(2*MIN);  // Customer complains and asks for manager
        Release(*f);
    }
    unsatisfied++;
}
