//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Customer header file

#include "simlib.h"

class Customer : public Process {
    double arrivalTime;
    double gotTicketTime;
    private:
        void SeizeTicketMachine();
        void SeizeClerk();
};