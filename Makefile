TARGETS = vmstats vmgen vmsim
all: $(TARGETS)
                                 
clean: 
	rm -f *.o *~ $(TARGETS)


vmgen: vmgen.cpp
	g++ -o vmgen vmgen.cpp

vmstats: Algo.o
	g++ -o vmstats Algo.o vmstats.cpp

vmsim: Algo.o
	g++ -o vmsim Algo.o vmsim.cpp


Algo.o: Algo.cpp Algo.h
	g++ -c Algo.cpp
