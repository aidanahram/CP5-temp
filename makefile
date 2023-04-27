FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3

all: main

main: main.o ClassNode.o  
	g++ -Wall -Wextra -O3 main.o ClassNode.o -o main -g

main.o: main.cpp 
	g++ -Wall -Wextra -O3 -c main.cpp -o $@ -g

ClassNode.o: ClassNode.cpp ClassNode.h
	g++ -Wall -Wextra -O3 -c ClassNode.cpp -o $@ -g

clean:
	rm -f *.o zll *.tar.gz main
