#ifndef vertex_H
#define vertex_H
#include "Coordinate.hpp"


class Vertex{
    
int size;    
double* x;
double* y;

public:
    Vertex() {size = 0;x = new double[size]; y = new double[size];}
    ~Vertex() {delete[] x; delete[] y;}
    void InputFileToVertices(Vertex&, const char*);
    Coordinate GetCoordinate(int);
    double GetX(int);
    double GetY(int);
    int GetSize();
    void pushBack(double, double);
    void fillarrays();
    void print();


};
#endif