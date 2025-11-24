#include <iostream>

#include <cmath>
#include <point.h>

Point::Point(): x(0), y(0) {}

Point::Point(double x , double y ) : x(x) , y(y) {}

Point::Point(const Point &other) : x(other.x) , y(other.y) {}
    
Point::Point(Point &&other) noexcept  : x(other.x) , y(other.y){
    other.x = 0;
    other.y = 0;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point& Point::operator=(Point&& other) noexcept {
    if (this != &other) {
        x = other.x;
        y = other.y;
        other.x = 0;
        other.y = 0;
    }
    return *this;
}

double Point::get_x() const{
    return x;
}
double Point::get_y() const{
    return y;
}

void Point::set_x(const double otherX){
    x = otherX;
}
void Point::set_y(const double otherY){
    y = otherY;
}

double Point::distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}


std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

Point::~Point() noexcept {}