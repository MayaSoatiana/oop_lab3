#pragma once 

#include <iostream>

#include <dynamicArray.h>
#include <point.h>
#include <figure.h>

class Rectangle : public Figure{
public: 
    static constexpr int VERTICES_COUNT = 4;

    Rectangle();
    Rectangle(DynamicArray<Point> array_vertices);

    Point geometric_center() const override;
    void print_vertices(std::ostream& out) override;
    void read_vertices(std::istream& in) override;
    operator double() const override; // area()

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    bool operator==(const Rectangle& other) const;     
    
    ~Rectangle() override = default;
protected:
    DynamicArray<Point> vertices; //4
};