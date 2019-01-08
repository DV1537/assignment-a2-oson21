#include "Vertex.hpp"
#include <fstream>
#include <iostream>

void Vertex::InputFileToVertices(Vertex& verticies, const char *fileName) {
    
    int n = 0;
    double a = 0.0;
    const int len = 100;
    std::ifstream myReadFile;
    myReadFile.open(fileName);
    if(fileName){
    double bufferX;
    double bufferY;
        while(myReadFile >> a){
            n++;
            if((n%2 == 1)){
                bufferX = a;
            }
            else{
                bufferY = a;
                verticies.pushBack(bufferX,bufferY);
            }
        }
    }
    else{
        std::cout << "error with opening file or empty file";
    }
    
    myReadFile.close();
}
void Vertex::fillarrays(){
    
    for(int i= 0; i < size; i++){
        x[i] = 2;
        y[i] = 2;
    }

}
void Vertex::print(){

    for(int i= 0; i < size; i++){
        std::cout << "this is x number: "<< i << " " << x[i]<< std::endl;
        std::cout << "this is y number: "<< i << " " << y[i]<< std::endl;
        std::cout << "this is size of arrays: "<< size << std::endl;
    }  
}
void Vertex::pushBack(double newX, double newY){
    
    double *xBuffer = new double[size];
    double *yBuffer = new double[size];

    for(int i= 0; i < size; i++){
        xBuffer[i] = x[i];
        yBuffer[i] = y[i];
    }
    delete[] x;
    delete[] y;

    x = new double[size+1];
    y = new double[size+1];

    for(int i= 0; i < size; i++){
       x[i] = xBuffer[i];
       y[i] = yBuffer[i];
    }
    
    x[size] = newX;
    y[size] = newY;

    size++;

    delete[] xBuffer;
    delete[] yBuffer;
}
int Vertex::GetSize(){
    return size;
}
Coordinate Vertex::GetCoordinate(int position){
    Coordinate c;
    c.SetCoordinateX(x[position]);
    c.SetCoordinateY(y[position]);
    return c;
}
double Vertex::GetX(int Pos){
    if(Pos <= size)
        return x[Pos];
       else
        return -1;
}
double Vertex::GetY(int Pos){
    if(Pos <= size)
        return y[Pos];
    else
        return -1;
}