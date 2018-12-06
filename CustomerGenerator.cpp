//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//CustomerGenerator source file

#include "CustomerGenerator.h"

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

    //Generate next customer after 3-6 minutes
    Activate(Time+Uniform(3*MIN, 6*MIN));
}

CustomerGenerator::CustomerGenerator(){ 
    Activate();
}

void CustomerGenerator::GenerateCustomer(){
    Customer *customer = new Customer();
    customer->facilityContainer = this->facilityContainer;
    customer->Activate();
}

