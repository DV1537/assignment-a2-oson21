#include "Shape.hpp"
#include "Vertex.hpp"
#include "Coordinate.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"



int main(int argc, const char *argv[]){
  Vertex v; 
  v.InputFileToVertices(v,argv[1]);

  if(v.GetSize() == 1){
    Point point(v);
    std::cout << point.area();
  }
  else if(v.GetSize() == 2){
    Line line(v);
    std::cout << line.area();
  }
  else if(v.GetSize() == 3){
    Triangle triangle(v);
    std::cout << triangle.area();
  }
  else if(v.GetSize() > 3){
    Polygon polygon(v);
    std::cout << polygon.area();
  }
  else
    std::cout << "This Shape has no valid size";


}

