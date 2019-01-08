#include "Vertex.hpp"
#include "Shape.hpp"
#ifndef Triangle_H
#define Triangle_H

class Triangle: public Shape{
    Vertex verticies;
    
    public:
        Triangle(){};
        Triangle(Vertex v);
        std::string getType();
        double area();
        double circumference();
        Coordinate position();
        bool isConvex();
        double distance(Shape *);
        void setVertecies(Vertex);
        float CrossProductLength(float , float , float , float , float , float );
};

#endif