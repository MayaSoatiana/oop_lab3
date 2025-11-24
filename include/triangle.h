#pragma once 

#include <iostream>

#include <dynamicArray.h>
#include <point.h>
#include <figure.h>

class Triangle : public Figure{
public: 
    static constexpr int VERTICES_COUNT = 3;

    Triangle();
    Triangle(DynamicArray<Point> array_vertices);

    Point geometric_center() const override;
    void print_vertices(std::ostream& out) override;
    void read_vertices(std::istream& in) override;
    operator double() const override; // area()

    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    bool operator==(const Triangle& other) const;     
    
    ~Triangle() override = default;
protected:
    DynamicArray<Point> vertices; //3
};