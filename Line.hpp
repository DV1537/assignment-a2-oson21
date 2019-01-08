#ifndef Line_H
#define Line_H
#include "Vertex.hpp"
#include "Shape.hpp"


class Line: public Shape{
    Vertex verticies;
    
    public:
        Line(){};
        Line(Vertex v);
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