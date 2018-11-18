//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Facility contailer header file
/*
    Facility contailer serves the 
    purpose of holding lists of facilities
    and managing facilities.
    It's better than to pass too many pointers.
    Instead you pass just one pointer
    to the container.
*/

#include "simlib.h"
#include <iostream> 
#include <list> 
#include <iterator> 

using namespace std;

class FacilityContainer {
    public:
        FacilityContainer(bool divisionOn);
        ~FacilityContainer();
        Facility* FindShortestQueueTicketMachine();
        void InitTicketMachines(int amount);
        void InitSimpleClerks(int amount);
        void InitIncomingClerks(int amount);
        void InitOutgoingClerks(int amout);
        list <Facility*> TicketMachines;
        list <Facility*> SimpleClerks;
        list <Facility*> IncomingClerks;
        list <Facility*> OutgoingClerks;

    private:
        Facility* FindShortestQueueInFacilityList(list<Facility*> facilityList);
        void InitFacilityList(list<Facility*>& facilityList, int amount, string name);
        bool laborDivision;
};