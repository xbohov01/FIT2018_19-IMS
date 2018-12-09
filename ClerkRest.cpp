//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//ClerkRest class file

#include "ClerkRest.h"

double ClerkRest::TimeSpent = 0;

ClerkRest::ClerkRest(FacilityContainer *cont, int cnt) : facilityContainer(cont), count(cnt) {
    Activate();
}; 

void ClerkRest::Behavior() {
    double r, restStart;
    Facility *f = facilityContainer->QueueingSystem(3);  // Take any clerk with the shortest queue
    if ((r=Random()) < 0.8) {   // Clerk may do other activity for some time
        Customer::count -= 5;
        restStart = Time;
        Seize(*f, DEFAULT_PRIORITY+1);  // Seize queue with higher priority than other customers (p=1)
        Wait(Uniform(2*MIN,8*MIN));
        Release(*f);
        TimeSpent += Time-restStart;
    }
}