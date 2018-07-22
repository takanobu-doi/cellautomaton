TARGET = CellAutomaton

all: $(TARGET)
CellAutomaton: CellAutomaton.o Automaton.o Cell.o
	g++ -o CellAutomaton CellAutomaton.o Automaton.o Cell.o
Cell.o: Cell.hpp Cell.cpp
	g++ -c Cell.cpp
Automaton.o: Automaton.hpp Automaton.cpp
	g++ -c Automaton.cpp
clean:
	rm *.o CellAutomaton
