# -Page-replacement-simulator

Algo.h - it is a header file and it contain definition of functions which are implemented in Algo.cpp file.

Algo.cpp - functions of lru, opt and fifo are implemented in this file.

vmgen.cpp - it will generate data using given arguments.

vmdim.cpp - it will simulate given algorithm for given data and size of physical frames.

Vmstates.cpp - it will give statistic data using given data for all algorithm. So, we can compare each algorithms' performance.

There is Makefile for compiling all codes.

So, make command for compile.

>>make 

It will create vmgen , vmdim and vmstats executable files.

For run vmsim, give input argument like:

physical_page_frames Input_file Algorithm(lru/fifo/opt) 

>>./vmsim 5 data.txt lru

For run vmgen, give input argument like: 

physical_page_frames Sequence_Length File_name

>>./vmgen 10 200 data.txt

For run vmstats, give input argument like:

min_frames max_frames increment_frames out_filename

>>./vmstats 5 50 5 data.txt
