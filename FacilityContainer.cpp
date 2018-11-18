//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Facility contailer source file

#include "FacilityContainer.h"

FacilityContainer::FacilityContainer(bool divisionOn){
    this->laborDivision = divisionOn;
}

FacilityContainer::~FacilityContainer(){
    list<Facility*>::iterator it;

    //Delete ticket machines
    if (this->TicketMachines.size > 0){
        for(it = this->TicketMachines.begin(); it != this->TicketMachines.end(); it++){
            this->TicketMachines.remove(*it);
        }
    }

    //Delete clerks
    if (this->laborDivision == true){
        if (this->IncomingClerks.size > 0){
            for(it = this->IncomingClerks.begin(); it != this->IncomingClerks.end(); it++){
                this->IncomingClerks.remove(*it);
            }
        }
        if (this->OutgoingClerks.size > 0){
            for(it = this->OutgoingClerks.begin(); it != this->OutgoingClerks.end(); it++){
                this->OutgoingClerks.remove(*it);
            }
        }
    } else {
        if (this->SimpleClerks.size > 0){
            for(it = this->SimpleClerks.begin(); it != this->SimpleClerks.end(); it++){
                this->SimpleClerks.remove(*it);
            }
        }
    }
}

void FacilityContainer::InitTicketMachines(int amount){
    string name = "TicketMachine";
    string index;
    for (int i = 0; i < amount; i++){
        index = to_string(i+1);
        name.append(index);
        Facility *tmp = new Facility(name.c_str());
        this->TicketMachines.push_back(tmp);
        name = name.substr(0, name.length()-1);
    }
    return;
}

void FacilityContainer::InitSimpleClerks(int amount){
    string name = "SimpleClerk";
    string index;
    for (int i = 0; i < amount; i++){
        index = to_string(i+1);
        name.append(index);
        Facility *tmp = new Facility(name.c_str());
        this->SimpleClerks.push_back(tmp);
        name = name.substr(0, name.length()-1);
    }
    return;
}

void FacilityContainer::InitIncomingClerks(int amount){
    string name = "IncomingClerk";
    string index;
    for (int i = 0; i < amount; i++){
        index = to_string(i+1);
        name.append(index);
        Facility *tmp = new Facility(name.c_str());
        this->IncomingClerks.push_back(tmp);
        name = name.substr(0, name.length()-1);
    }
    return;
}

void FacilityContainer::InitOutgoingClerks(int amount){
    string name = "OutgoingClerk";
    string index;
    for (int i = 0; i < amount; i++){
        index = to_string(i+1);
        name.append(index);
        Facility *tmp = new Facility(name.c_str());
        this->OutgoingClerks.push_back(tmp);
        name = name.substr(0, name.length()-1);
    }
    return;
}

Facility* FacilityContainer::FindShortestQueueTicketMachine(){
    list <Facility*>::iterator it;
    int shortest;
    Facility *facilityPtr;

    for(it = this->TicketMachines.begin(); it != this->TicketMachines.end(); it++){
        
    }
}