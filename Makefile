CXXFLAGS=-g
LDLIBS=-lX11 -lstdc++ -lm
SpacePotaters: SpacePotaters.o gfx.o

clean:
	rm -f SpacePotaters *.o
play:
	./SpacePotaters
	cat Score.txt
