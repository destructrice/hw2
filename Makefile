CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=user.o product.o product_parser.o util.o movie.o book.o clothing.o

all: amazon

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)
mydatastore.o: mydatastore.cpp mydatastore.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c mydatastore.cpp
user.o: user.cpp user.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c user.cpp
product.o: product.cpp product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product.cpp
product_parser.o: product_parser.cpp product_parser.h product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product_parser.cpp
util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c util.cpp
movie.o: movie.cpp movie.h product.h util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product.cpp
book.o: book.cpp book.h product.h util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product.cpp
clothing.o: clothing.cpp clothing.h product.h util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product.cpp


clean:
	rm -f *.o amazon
