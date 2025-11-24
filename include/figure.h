#pragma once 

#include <iostream>

#include <point.h>

class Figure{
public:
    Figure() = default;

    virtual Point geometric_center() const = 0;
    virtual void print_vertices(std::ostream& out) = 0;
    virtual void read_vertices(std::istream& in) = 0;
    virtual operator double() const = 0; // area()

    virtual ~Figure() = default;
};

inline std::ostream & operator <<(std::ostream& os, Figure &figure) {
    figure.print_vertices(os);
    return os;
}

inline std::istream & operator >>(std::istream& is, Figure &figure) {
    figure.read_vertices(is);
    return is;
}