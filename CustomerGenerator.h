//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//CustomerGenerator header file

#pragma once
#include "simlib.h"
#include "Customer.h"
#include "FacilityContainer.h"
#include "ClerkRest.h"

class CustomerGenerator : public Event {
    
    void Behavior();
    
    public:       
        FacilityContainer *facilityContainer;
        CustomerGenerator();

    private:
        void GenerateCustomer();
};