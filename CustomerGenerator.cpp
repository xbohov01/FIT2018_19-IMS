//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//CustomerGenerator source file

#include "CustomerGenerator.h"
#include "Customer.h"

void CustomerGenerator::Behavior(){
    Customer *customer = new Customer();
    customer->facilityContainer = this->facilityContainer;
    customer->Activate();

    //Sleep for 5-7 minutes
    Activate(Time+Uniform(300, 720));
}

