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
        static Histogram FullTime;
        static Histogram LineTime;
        static Histogram MachineTime;
        static int customerInSystem;
        static int count;
    private:
        void SeizeTicketMachine(Facility *);
        void SeizeClerk(Facility *);
};
