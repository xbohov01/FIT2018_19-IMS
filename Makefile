all: PostOffice.cpp FacilityContainer.cpp Customer.cpp CustomerGenerator.cpp ClerkRest.cpp CustomerTimeout.cpp
	g++ -std=c++11 -g -O2 -o postsim PostOffice.cpp FacilityContainer.cpp Customer.cpp CustomerGenerator.cpp ClerkRest.cpp CustomerTimeout.cpp -lsimlib -lm 

clean: 
	rm -f postsim