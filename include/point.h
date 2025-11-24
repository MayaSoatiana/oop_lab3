#pragma once

#include <iostream>

class Point{
public: 
    Point();
    Point(double x, double y);
    Point(const Point &other);
    Point(Point &&other) noexcept;

    Point& operator=(const Point& other);
    Point& operator=(Point&& other) noexcept;

    double get_x() const;
    double get_y() const;

    void set_x(const double otherX);
    void set_y(const double otherY);

    static double distance(const Point& p1, const Point& p2);

    ~Point() noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);

private:
    double x;
    double y;
};