# Definitions of variables

Includes=-I/usr/include -I./includes
CXXFlags=-std=c++17
GSL_Libs=$(shell gsl-config --libs)
MYEXE=./bin/myCalcApp

# Here comes the main (final) rule:

myCalcApp: obj/Funkcja.o obj/Wymierna.o obj/Wielomian.o \
           obj/Gauss.o   obj/IntGauss.o obj/MathTools.o
	g++ $(CXXFlags) $(Includes) main.C -o $(MYEXE) $^ $(GSL_Libs)

# Here come the rules for compilations of class files:

obj/Funkcja.o: src/Funkcja.C includes/Funkcja.h
	g++ $(CXXFlags) $(Includes)  -c $<  -o $@

obj/Wymierna.o: src/Wymierna.C includes/Wymierna.h
	g++ $(CXXFlags) $(Includes)  -c $<  -o $@

obj/Wielomian.o: src/Wielomian.C includes/Wielomian.h
	g++ $(CXXFlags) $(Includes)  -c $<  -o $@

obj/Gauss.o: src/Gauss.C includes/Gauss.h
	g++ $(CXXFlags) $(Includes)  -c $<  -o $@

obj/IntGauss.o: src/IntGauss.C includes/IntGauss.h
	g++ $(CXXFlags) $(Includes)  -c $<  -o $@

obj/MathTools.o: src/MathTools.C includes/MathTools.h
	g++ $(CXXFlags) $(Includes)  -c $<  -o $@

# Rule for cleaning:

clean:
	rm -f obj/*.o $(MYEXE)
