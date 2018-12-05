//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Facility contailer source file

#include "FacilityContainer.h"

//Constructor
FacilityContainer::FacilityContainer(bool divisionOn){
    this->laborDivision = divisionOn;
}

//Destructor
FacilityContainer::~FacilityContainer(){
    list<Facility*>::iterator it;

    //Delete ticket machines
    if (this->TicketMachines.size() > 0){
        for(it = this->TicketMachines.begin(); it != this->TicketMachines.end(); it++){
            this->TicketMachines.remove(*it);
        }
    }

    //Delete clerks
    if (this->laborDivision == true){
        if (this->IncomingClerks.size() > 0){
            for(it = this->IncomingClerks.begin(); it != this->IncomingClerks.end(); it++){
                this->IncomingClerks.remove(*it);
            }
        }
        if (this->OutgoingClerks.size() > 0){
            for(it = this->OutgoingClerks.begin(); it != this->OutgoingClerks.end(); it++){
                this->OutgoingClerks.remove(*it);
            }
        }
    } else {
        if (this->SimpleClerks.size() > 0){
            for(it = this->SimpleClerks.begin(); it != this->SimpleClerks.end(); it++){
                this->SimpleClerks.remove(*it);
            }
        }
    }
}

//Public methods
//Queueing system method represents the functions of it's real life counterpart
//Depending on the request type given by the customer and current queueing method
//It selects the clerk to serve the request by shortest queue
Facility* FacilityContainer::QueueingSystem(int requestType){
    if (this->laborDivision == true){
        //1 = incoming 2 = outbound 3 = other
        if (requestType == 1){
            return this->FindShortestQueueInFacilityList(this->IncomingClerks);
        } else if (requestType == 2){
            return this->FindShortestQueueInFacilityList(this->OutgoingClerks);
        } else if (requestType = 3){
            //Get shortest from both
            Facility *incomingShortest = this->FindShortestQueueInFacilityList(this->IncomingClerks);
            Facility *outgoingShortest = this->FindShortestQueueInFacilityList(this->OutgoingClerks);
            //Return shorter
            if (incomingShortest->QueueLen() > outgoingShortest->QueueLen){
                return outgoingShortest;
            } else {
                return incomingShortest;
            }
        }
    } else {
        return this->FindShortestQueueInFacilityList(this->SimpleClerks);
    }
}

void FacilityContainer::InitTicketMachines(int amount){
    this->InitFacilityList(this->TicketMachines, amount, "TicketMachine");
}

void FacilityContainer::InitSimpleClerks(int amount){
    this->InitFacilityList(this->SimpleClerks, amount, "SimpleClerk");
}

void FacilityContainer::InitIncomingClerks(int amount){
    this->InitFacilityList(this->IncomingClerks, amount, "IncomingClerk");
}

void FacilityContainer::InitOutgoingClerks(int amount){
    this->InitFacilityList(this->OutgoingClerks, amount, "OutgoingClerk");
}

Facility* FacilityContainer::FindShortestQueueTicketMachine(){
    return this->FindShortestQueueInFacilityList(this->TicketMachines);
}

//Private methods
Facility* FacilityContainer::FindShortestQueueInFacilityList(list<Facility*> facilityList){
    list <Facility*>::iterator it = facilityList.begin();
    int shortest = (*it)->QueueLen();
    Facility *facilityPtr;

    if(shortest == 0){
        return *it;
    }

    for(it; it != facilityList.end(); it++){
        if (shortest > (*it)->QueueLen()){
            shortest = (*it)->QueueLen();
            facilityPtr = *it;
        }
    }

    return facilityPtr;
}

void FacilityContainer::InitFacilityList(list<Facility*>& facilityList, int amount, string name){
    //string name = "OutgoingClerk";
    string index;
    for (int i = 0; i < amount; i++){
        index = to_string(i+1);
        name.append(index);
        Facility *tmp = new Facility(name.c_str());
        facilityList.push_back(tmp);
        name = name.substr(0, name.length()-1);
    }
    return;
}