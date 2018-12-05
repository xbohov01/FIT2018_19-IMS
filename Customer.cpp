//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Customer class file

#include "Customer.h"


void Customer::Behavior() {
    double time = Time;
    Facility* f = facilityContainer->FindShortestQueueTicketMachine();
    Seize(*f);
    Wait(Uniform(30, 60));
    Release(*f);
}