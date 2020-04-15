fsm: fsm.o FiniteStateMachine.o
	g++ -std=c++14 -Wall -o fsm fsm.o FiniteStateMachine.o

fsm.o: fsm.cpp ../FiniteStateMachine.h
	g++ -std=c++14 -Wall -c fsm.cpp

FiniteStateMachine.o: ../FiniteStateMachine.cpp ../FiniteStateMachine.h
	g++ -std=c++14 -Wall -c ../FiniteStateMachine.cpp