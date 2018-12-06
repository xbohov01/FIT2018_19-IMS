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

#pragma once
#include "simlib.h"
#include <iostream> 
#include <list> 
#include <iterator> 

using namespace std;

#define MIN 60 // Zakladní jednotka času
#define HOUR MIN*60
#define WORK 10*HOUR
#define REST 14*HOUR


class FacilityContainer {
    public:
        FacilityContainer(bool divisionOn);
        ~FacilityContainer();
        Facility* FindShortestQueueTicketMachine();
        Facility* QueueingSystem(int requestType);
        void InitTicketMachines(int amount);
        void InitSimpleClerks(int amount);
        void InitIncomingClerks(int amount);
        void InitOutgoingClerks(int amout);
        list <Facility*> TicketMachines;
        list <Facility*> SimpleClerks;
        list <Facility*> IncomingClerks;
        list <Facility*> OutgoingClerks;

    private:
        Facility* FindShortestQueueInFacilityList(list<Facility*>& facilityList);
        void InitFacilityList(list<Facility*>& facilityList, int amount, string name);
        bool laborDivision;
};
