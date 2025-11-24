#pragma once 

#include <iostream>

#include <dynamicArray.h>
#include <point.h>
#include <figure.h>

class Square : public Figure{
public: 
    static constexpr int VERTICES_COUNT = 4;

    Square();
    Square(DynamicArray<Point> array_vertices);

    Point geometric_center() const override;
    void print_vertices(std::ostream& out) override;
    void read_vertices(std::istream& in) override;
    operator double() const override; // area()

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const;     
    
    ~Square() override = default;
protected:
    DynamicArray<Point> vertices; //4
};