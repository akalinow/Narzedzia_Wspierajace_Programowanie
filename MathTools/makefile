Includes=$(shell gsl-config --cflags) -I./includes
GSL_Libs=$(shell gsl-config --libs)
CFlags=-std=c++17
MYEXE=./bin/myCalcApp

myCalcApp: obj/Funkcja.o obj/Wymierna.o obj/Wielomian.o \
           obj/Gauss.o   obj/IntGauss.o obj/MathTools.o
	g++ $(CFlags) $(Includes) main.C -o $(MYEXE) $^ $(GSL_Libs)

obj/Funkcja.o: src/Funkcja.C includes/Funkcja.h
	g++ $(CFlags) $(Includes) -c src/Funkcja.C   -o obj/Funkcja.o

obj/Wymierna.o: src/Wymierna.C includes/Wymierna.h
	g++ $(CFlags) $(Includes) -c src/Wymierna.C  -o obj/Wymierna.o

obj/Wielomian.o: src/Wielomian.C includes/Wielomian.h
	g++ $(CFlags) $(Includes) -c src/Wielomian.C -o obj/Wielomian.o

obj/Gauss.o: src/Gauss.C includes/Gauss.h
	g++ $(CFlags) $(Includes) -c src/Gauss.C     -o obj/Gauss.o

obj/IntGauss.o: src/IntGauss.C includes/IntGauss.h
	g++ $(CFlags) $(Includes) -c src/IntGauss.C  -o obj/IntGauss.o

obj/MathTools.o: src/MathTools.C includes/MathTools.h
	g++ $(CFlags) $(Includes) -c src/MathTools.C -o obj/MathTools.o

clean:
	rm -f obj/*.o $(MYEXE)
