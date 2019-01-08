#ifndef Coordinate_H
#define Coordinate_H
#include <iostream>

class Coordinate{
    private:
        double xValue;
        double yValue;
    public:
        void SetCoordinateX(double);
        void SetCoordinateY(double);
        double GetCoordinateY();
        double GetCoordinateX();
        friend std::ostream& operator<<(std::ostream& stream, const Coordinate c);
};
    

#endif