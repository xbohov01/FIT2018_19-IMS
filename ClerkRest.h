//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Clerck rest header file

#pragma once
#include "simlib.h"
#include "FacilityContainer.h"
#include "Customer.h"

class ClerkRest : public Process {
    public:
        ClerkRest(FacilityContainer *c, int count);
        void Behavior();
        FacilityContainer *facilityContainer;
        static double TimeSpent;
    private:
        int count;
};