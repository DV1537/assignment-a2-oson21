#ifndef Point_H
#define Point_H

#include "Shape.hpp"
#include "Vertex.hpp"
#include "Coordinate.hpp"
class Point : public Shape{
    Vertex verticies;
    
    public:
        Point(){};
        Point(Vertex v);
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