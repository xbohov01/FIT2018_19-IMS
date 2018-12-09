//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//CustomerGenerator source file

#include "CustomerGenerator.h"

CustomerGenerator::CustomerGenerator(FacilityContainer *con) : facilityContainer(con) { 
    Activate();
}

void CustomerGenerator::Behavior(){
    static bool first_run = true;
    if (first_run) {
        for (int i = 0, initial = static_cast<int> (Uniform(10, 20)); i < initial; ++i){
            GenerateCustomer();
        }
        first_run = false;
    } else {
        GenerateCustomer();
    }

    //Generate next customer after 1.5-4 minutes
    Activate(Time+Uniform(1.5*MIN, 4*MIN));
}

void CustomerGenerator::GenerateCustomer(){
    Customer *customer = new Customer(facilityContainer);
}

