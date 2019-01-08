#include "Vertex.hpp"
#include "Coordinate.hpp"

#include <iostream>

void Coordinate::SetCoordinateX(double x){
  xValue = x;
}
void Coordinate::SetCoordinateY(double y){
  yValue = y;
}
double Coordinate::GetCoordinateX(){
 return xValue;
}
double Coordinate::GetCoordinateY(){
 return yValue;
}
std::ostream& operator<<(std::ostream& stream, const Coordinate c){
  return stream <<"THis is x-value: " << c.xValue << std::endl <<
  "THis is y-value: " << c.yValue << std::endl;
}