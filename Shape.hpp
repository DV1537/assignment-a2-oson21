#ifndef Shape_H
#define Shape_H
#include "Vertex.hpp"
#include "Coordinate.hpp"
#include <string>
#include <fstream>
#include <iostream>


int CountInput(const char *fileName);

class Shape {
    Vertex verticies;
    
    public:
        
        virtual std::string getType() = 0;
        virtual double area() = 0;
        virtual double circumference() = 0;
        virtual Coordinate position() = 0;
        virtual bool isConvex() = 0;
        virtual double distance(Shape *) = 0;
        virtual void setVertecies(Vertex) = 0;
        virtual float CrossProductLength(float , float ,float , float , float , float ) = 0;
};


#endif
