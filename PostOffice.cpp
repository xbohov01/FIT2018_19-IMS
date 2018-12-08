//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigo02
//Main file

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include "simlib.h"
#include "CustomerGenerator.h"


int main(int argc, char *argv[])
{
    //Argument processing
    int c;
    bool laborDivision = false;
    int ticketMachines = 0;
    int simpleClerks = 0;
    int incomingClerks = 0;
    int outgoingClerks = 0;
    int otherClerks = 0;
    FacilityContainer *facilityContainer;

    if (argc < 5){
        fprintf(stderr, "Not enough arguments, consult README for correct usage\n");
        return 1;
    }

    while ((c = getopt (argc, argv, "c:m:i:o:")) != -1){
        switch (c) {
            case 'c':
                laborDivision = false;
                simpleClerks = atoi(optarg);
                break;
            case 'm':
                ticketMachines = atoi(optarg);
                break;
            case 'i':
                laborDivision = true;
                incomingClerks = atoi(optarg);
                break;
            case 'o':
                laborDivision = true;
                outgoingClerks = atoi(optarg);
                break;
            case '?':
                fprintf(stderr, "Incorrect arguments, consult README for correct usage\n");
                return 1;
            default:
                fprintf(stderr, "Argument error\n");
                return 1;
        }
    }

    facilityContainer = new FacilityContainer(laborDivision);

    //Argument check and facility inits
    if (ticketMachines <= 0){
        fprintf(stderr, "There needs to be at least one ticket machine\n");
        return 1;
    } else {
        facilityContainer->InitTicketMachines(ticketMachines);
    }

    if (laborDivision == true){
        if (outgoingClerks <= 0 || incomingClerks <= 0){
            fprintf(stderr, "If you wish to simulate labor division you have to set incoming and outgoing clerks above 0\n");
            delete facilityContainer;
            return 1;
        } else {
            facilityContainer->InitIncomingClerks(incomingClerks);
            facilityContainer->InitOutgoingClerks(outgoingClerks);
        }
    } else {
        facilityContainer->InitSimpleClerks(simpleClerks);
    }


    /* Simulation setup */
    RandomSeed(time(0)); // Setting pseudo random seed
    SetOutput("1.out");

    Init(0, WORK);
    CustomerGenerator *gen = new CustomerGenerator();
    gen->facilityContainer = facilityContainer;
    Run();

    /* Printing results */
    Customer::FullTime.Output();
    Customer::LineTime.Output();
    Customer::MachineTime.Output();
    Print("Customer amount: %d\n", Customer::amount);
    Print("Customers left unsatisfied: %d\n", Customer::unsatisfied);
    Print("Customers left: %d\n", Customer::customerInSystem);
    Print("Clerks rested: %f\n", ClerkRest::TimeSpent);

    return 0;
}