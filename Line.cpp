#include "Line.hpp"
#include "Vertex.hpp"
#include "Shape.hpp"
#include "Coordinate.hpp"
#include <math.h> 


Line::Line(Vertex v){
    if(v.GetSize() == 2)
        for(int i = 0; i < v.GetSize();i++)
            verticies.pushBack(v.GetX(i),v.GetY(i));
    else
        std::cout << "This is not a valid Line";
}
std::string Line::getType(){
    std::string shape;
        if(verticies.GetSize() == 2)
            shape = "Line";
        else if(verticies.GetSize() >= 3)
            shape = "Polygon";
        else if(verticies.GetSize() == 1)
            shape = " Point";
        else
            shape = "This is an unvalid Shape";
    return shape;
}

double Line::area(){
    double area = 0;
    if(this->isConvex() && (verticies.GetSize() >= 3)){         
        int j = verticies.GetSize()-1;
        for (int i = 0; i < verticies.GetSize(); i++){
            area += (verticies.GetX(j)+verticies.GetX(i)) * (verticies.GetY(j)-verticies.GetY(i)); 
            j = i; 
        }
        area = abs(area/2.0);     
    }
    else
        area = -1;
    return area;
}

double Line::circumference(){
    double total = 0; 
    for(int i = 0; i <verticies.GetSize();i++){
        if(i == verticies.GetSize() - 1){
            total += sqrt(pow(verticies.GetX(i) - verticies.GetX(0),2.0) + pow(verticies.GetY(i) - verticies.GetX(0),2.0));
        }
        else{
            total += sqrt(pow(verticies.GetX(i) - verticies.GetX(i+1),2.0) + pow(verticies.GetY(i) - verticies.GetY(i+1),2.0));
        }

    }
    return total;
}

Coordinate Line::position(){
    double addedXValues = 0;
    double addedYValues = 0;
    for(int i = 0; i < verticies.GetSize();i++){
        addedXValues += verticies.GetX(i);
        addedYValues += verticies.GetY(i);
    }
    Coordinate centerCoordinate;
    centerCoordinate.SetCoordinateX(addedXValues/verticies.GetSize());
    centerCoordinate.SetCoordinateY(addedYValues/verticies.GetSize());    
return centerCoordinate;
}

bool Line::isConvex(){
    float CrossProductLength(float , float ,float , float , float , float );
    bool isShapeConvex = true;
    bool gotNegative = false;
    bool gotPositive = false;
    int numPoints = verticies.GetSize()-2;
    int B, C;
    for (int A = 0; A < numPoints; A++)
    {
        B = A + 1;
        C = B + 1;
        float crossProduct =
            CrossProductLength(
                verticies.GetX(A), verticies.GetY(A),
                verticies.GetX(B), verticies.GetY(B),
                verticies.GetX(C), verticies.GetY(C));
        if (crossProduct < 0)
        {
            gotNegative = true;
        }
        else if (crossProduct > 0)
        {
            gotPositive = true;
        }
        if (gotNegative && gotPositive) 
            isShapeConvex = false;
    }
    return isShapeConvex;        
}
   
double Line::distance(Shape *s){
    Coordinate coordinate;
    Coordinate inputCoordinate;
    inputCoordinate = s->position();
    coordinate = this->position();
    double length = inputCoordinate.GetCoordinateX() - coordinate.GetCoordinateX();
    double height = inputCoordinate.GetCoordinateY() - coordinate.GetCoordinateY();
    double distance = sqrt(pow(length, 2.0) + pow(height, 2.0));
    return distance;
}
void Line::setVertecies(Vertex v){
    for(int i = 0;i < v.GetSize();i++){
        Coordinate c = v.GetCoordinate(i);
        verticies.pushBack(c.GetCoordinateX(), c.GetCoordinateY());
    }
}

float Line::CrossProductLength(float Ax, float Ay,float Bx, float By, float Cx, float Cy){

    float BAx = Ax - Bx;
    float BAy = Ay - By;
    float BCx = Cx - Bx;
    float BCy = Cy - By;

 
    return (BAx * BCy - BAy * BCx);
}