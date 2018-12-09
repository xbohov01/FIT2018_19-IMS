all: PostOffice.cpp FacilityContainer.cpp Customer.cpp CustomerGenerator.cpp ClerkRest.cpp CustomerTimeout.cpp
	g++ -std=c++11 -g -O2 -o postsim PostOffice.cpp FacilityContainer.cpp Customer.cpp CustomerGenerator.cpp ClerkRest.cpp CustomerTimeout.cpp -lsimlib -lm 

#Runs basic simulation with 2 ticket machines and 6 clerks
run:
	./postsim -m 2 -c 6

clean: 
	rm -f postsim