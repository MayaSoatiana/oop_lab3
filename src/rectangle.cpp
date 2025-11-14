#include <iostream>
#include <cmath>
#include <dynamicArray.h>
#include <point.h>
#include <figure.h>
#include <rectangle.h>


Rectangle::Rectangle() : vertices(VERTICES_COUNT, Point(0, 0)) {}

Rectangle::Rectangle(DynamicArray<Point> array_vertices){
   if (array_vertices.getSize() != VERTICES_COUNT){
        throw std::invalid_argument("A Rectangle requires 4 vertices");
   }
   
   vertices = array_vertices;
}

Point Rectangle::geometric_center() const {
    double x = 0, y = 0;
    for (size_t i = 0; i < VERTICES_COUNT; i++){
        x += vertices[i].get_x();
        y += vertices[i].get_y();
    }
    return Point(x / VERTICES_COUNT, y / VERTICES_COUNT);
}

void Rectangle::print_vertices(std::ostream& out) {
    out << "Rectangle:" << std::endl;
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        out << "Vertex  " << (i + 1) << ": (" 
           << vertices[i].get_x() << ", " << vertices[i].get_y() << ")" << std::endl;
    }
}

void Rectangle::read_vertices(std::istream& in) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        std::cout << "enter coordinates x and y of the Rectangle with space in between: " << std::endl;
        double x, y;
        in >> x >> y;
        vertices.insertAt(i, Point(x, y));
    }
}

Rectangle::operator double() const {
    double width_r = Point::distance(vertices[0], vertices[1]);
    double length_r = Point::distance(vertices[1], vertices[2]);
    return width_r * length_r;
} 

Rectangle& Rectangle::operator=(const Rectangle& other){
    if(this != &other){
        vertices = other.vertices;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other){
        vertices = std::move(other.vertices);
    } 
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const{
    for (size_t i = 0; i < VERTICES_COUNT; i++){
        if ((vertices[i].get_x() != other.vertices[i].get_x()) ||
            (vertices[i].get_y() != other.vertices[i].get_y())){
            return false;
        }  
    } 
    return true;
}