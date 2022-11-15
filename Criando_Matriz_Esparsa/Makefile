all: SparseMatrix.o main.o
  g++ *.o -o run
main.o: main.cpp SparseMatrix.h
  g++ -c main.cpp
sparseMatrix.o: SparseMatrix.cpp SparseMatrix.h
  g++ -c SparseMatrix.cpp
clean:
  rm *.o