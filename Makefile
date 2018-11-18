all: PostOffice.cpp FacilityContainer.cpp Customer.cpp
	g++ -std=c++11 -g -O2 -o postsim PostOffice.cpp FacilityContainer.cpp Customer.cpp -lsimlib -lm 

clean: 
	rm -f postsim