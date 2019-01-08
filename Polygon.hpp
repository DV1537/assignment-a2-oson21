#include "Vertex.hpp"
#include "Shape.hpp"
#ifndef Polygon_H
#define Polygon_H

class Polygon: public Shape{
    Vertex verticies;
    
        public:
        Polygon(){};
        Polygon(Vertex v); 
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