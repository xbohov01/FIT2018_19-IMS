//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Customer header file

#pragma once
#include "simlib.h"
#include "FacilityContainer.h"

class Customer : public Process {
    public:
        void Behavior();
        FacilityContainer *facilityContainer;
    private:
        void SeizeTicketMachine();
        void SeizeClerk();
};
