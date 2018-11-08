# FIT2018_19-IMS

The model itself is very simple that's why this simulation is built with variable parameters in mind.
It models 8 hour work day at a post office.

Prototype argument structure
3 modes of operation
1. all clerks do all jobs
    ./postoffice -u [number of clerks]

2. one group of clerks hadles incoming another outgoing mail
    ./postoffice -i [no clerks for incoming] -o [no clerks for outgoing]

3. one group for incoming letters, outgoing letters, incoming parcels, outgoing parcels
    ./postoffice -iL [no clerks for incoming letters] -oL [no clerks for outgoing letters] -iP [no clerks for incoming parcels] -oP [no clerks for outgoing parcels]

