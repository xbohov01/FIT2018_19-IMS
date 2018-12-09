# FIT2018_19-IMS

The model itself is very simple that's why this simulation is built with variable parameters in mind.
It models 8 hour work day at a post office.

Prototype argument structure
3 modes of operation
1. all clerks do all jobs
    ./postsim -c [number of clerks] -m [number of machines]

2. one group of clerks hadles incoming another outgoing mail
    ./postsim -i [number f clerks for incoming] -o [number of clerks for outgoing] -m [number of machines]
