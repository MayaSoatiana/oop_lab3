#include <iostream>
#include <cmath>
#include <dynamicArray.h>
#include <point.h>
#include <figure.h>
#include <triangle.h>


Triangle::Triangle() : vertices(VERTICES_COUNT, Point(0, 0)) {}

Triangle::Triangle(DynamicArray<Point> array_vertices){
   if (array_vertices.getSize() != VERTICES_COUNT){
        throw std::invalid_argument("A Triangle requires 3 vertices");
   }
   
   vertices = array_vertices;
}

Point Triangle::geometric_center() const {
    double x = 0, y = 0;
    for (size_t i = 0; i < VERTICES_COUNT; i++){
        x += vertices[i].get_x();
        y += vertices[i].get_y();
    }
    return Point(x / VERTICES_COUNT, y / VERTICES_COUNT);
}

void Triangle::print_vertices(std::ostream& out) {
    out << "Triangle:" << std::endl;
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        out << "Vertex  " << (i + 1) << ": (" 
           << vertices[i].get_x() << ", " << vertices[i].get_y() << ")" << std::endl;
    }
}

void Triangle::read_vertices(std::istream& in) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        std::cout << "enter coordinates x and y of the triangle with space in between: " << std::endl;
        double x, y;
        in >> x >> y;
        vertices.insertAt(i, Point(x, y));
    }
}

Triangle::operator double() const {
    double side = Point::distance(vertices[0], vertices[1]);
    return ((std::sqrt(3)/ 4.0) * std::pow(side, 2));
} 

Triangle& Triangle::operator=(const Triangle& other){
    if(this != &other){
        vertices = other.vertices;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other){
        vertices = std::move(other.vertices);
    } 
    return *this;
}

bool Triangle::operator==(const Triangle& other) const{
    for (size_t i = 0; i < VERTICES_COUNT; i++){
        if ((vertices[i].get_x() != other.vertices[i].get_x()) ||
            (vertices[i].get_y() != other.vertices[i].get_y())){
            return false;
        }  
    } 
    return true;
}