//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//CustomerTimeout header file

#pragma once
#include "simlib.h"
#include "FacilityContainer.h"
#include "Customer.h"

class CustomerTimeout : public Event {
    
    void Behavior();
    
    public:       
        Customer *customer;
        Facility *facility;
        CustomerTimeout(Customer *c, Facility *f);

};