//Simulation for FIT VUT IMS 2018/19
//Authors
//Samuel Bohovic xbohov01
//Danil Grigorev xgrigoxx <<<<<<<<<<<<<<< TODO TVOJE ID

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //Argument processing
    int c;
    bool laborDivision = false;
    int machines = 0;
    int simpleClerks = 0;
    int incomingClerks = 0;
    int outgoingClerks = 0;
    int otherClerks = 0;

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
                machines = atoi(optarg);
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

    return 0;
}
