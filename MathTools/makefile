Includes=-I/usr/include -I./includes
CFlags=-std=c++17
GSL_Libs=-L/usr/lib/x86_64-linux-gnu -lgsl -lgslcblas -lm
TARGET=./bin/myCalcApp

myCalcApp: Funkcja Wymierna Wielomian Gauss IntGauss MathTools
	g++ $(CFlags) $(Includes) main.C -o $(TARGET) obj/*.o $(GSL_Libs)

Funkcja: includes/Funkcja.h src/Funkcja.C
	g++ $(CFlags) $(Includes) -c src/Funkcja.C   -o obj/Funkcja.o

Wymierna: includes/Wymierna.h src/Wymierna.C
	g++ $(CFlags) $(Includes) -c src/Wymierna.C  -o obj/Wymierna.o

Wielomian: includes/Wielomian.h src/Wielomian.C
	g++ $(CFlags) $(Includes) -c src/Wielomian.C -o obj/Wielomian.o

Gauss: includes/Gauss.h src/Gauss.C
	g++ $(CFlags) $(Includes) -c src/Gauss.C     -o obj/Gauss.o

IntGauss: includes/IntGauss.h src/IntGauss.C
	g++ $(CFlags) $(Includes) -c src/IntGauss.C  -o obj/IntGauss.o

MathTools: includes/MathTools.h src/MathTools.C
	g++ $(CFlags) $(Includes) -c src/MathTools.C -o obj/MathTools.o
	
clean:
	rm -f obj/*.o $(TARGET)
