#include <iostream>
#include <cmath>
#include <dynamicArray.h>
#include <point.h>
#include <figure.h>
#include <square.h>


Square::Square() : vertices(VERTICES_COUNT, Point(0, 0)) {}

Square::Square(DynamicArray<Point> array_vertices){
   if (array_vertices.getSize() != VERTICES_COUNT){
        throw std::invalid_argument("A Square requires 4 vertices");
   }
   
   vertices = array_vertices;
}

Point Square::geometric_center() const {
    double x = 0, y = 0;
    for (size_t i = 0; i < VERTICES_COUNT; i++){
        x += vertices[i].get_x();
        y += vertices[i].get_y();
    }
    return Point(x / VERTICES_COUNT, y / VERTICES_COUNT);
}

void Square::print_vertices(std::ostream& out) {
    out << "Square:" << std::endl;
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        out << "Vertex  " << (i + 1) << ": (" 
           << vertices[i].get_x() << ", " << vertices[i].get_y() << ")" << std::endl;
    }
}

void Square::read_vertices(std::istream& in) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        std::cout << "enter coordinates x and y of the Square with space in between: " << std::endl;
        double x, y;
        in >> x >> y;
        vertices.insertAt(i, Point(x, y));
    }
}

Square::operator double() const {
    return std::pow(Point::distance(vertices[0], vertices[1]), 2);
} 

Square& Square::operator=(const Square& other){
    if(this != &other){
        vertices = other.vertices;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other){
        vertices = std::move(other.vertices);
    } 
    return *this;
}

bool Square::operator==(const Square& other) const{
    for (size_t i = 0; i < VERTICES_COUNT; i++){
        if ((vertices[i].get_x() != other.vertices[i].get_x()) ||
            (vertices[i].get_y() != other.vertices[i].get_y())){
            return false;
        }  
    } 
    return true;
}