#include <gtest/gtest.h>

#include <dynamicArray.h>
#include <triangle.h>
#include <square.h>
#include <rectangle.h>
#include <point.h>
#include <cmath>

class GeometricFiguresTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Equilateral triangle points (side length = 2)
        equilateralTriangle1.add(Point(0, 0));
        equilateralTriangle1.add(Point(2, 0));
        equilateralTriangle1.add(Point(1, std::sqrt(3))); // height = √3

        // Test points for squares
        squarePoints1.add(Point(0, 0));
        squarePoints1.add(Point(0, 2));
        squarePoints1.add(Point(2, 2));
        squarePoints1.add(Point(2, 0));

        // Test points for rectangles
        rectanglePoints1.add(Point(0, 0));
        rectanglePoints1.add(Point(0, 3));
        rectanglePoints1.add(Point(4, 3));
        rectanglePoints1.add(Point(4, 0));
    }

    DynamicArray<Point> equilateralTriangle1;
    DynamicArray<Point> squarePoints1;
    DynamicArray<Point> rectanglePoints1;
};

TEST_F(GeometricFiguresTest, PointCreationAndAccess) {
    Point p1(3.5, 4.2);
    EXPECT_DOUBLE_EQ(p1.get_x(), 3.5);
    EXPECT_DOUBLE_EQ(p1.get_y(), 4.2);
}

TEST_F(GeometricFiguresTest, PointDistance) {
    Point p1(0, 0);
    Point p2(3, 4);
    EXPECT_DOUBLE_EQ(Point::distance(p1, p2), 5.0);
}

TEST_F(GeometricFiguresTest, TriangleCreation) {
    EXPECT_NO_THROW(Triangle triangle(equilateralTriangle1));
    
    DynamicArray<Point> invalidPoints;
    invalidPoints.add(Point(0, 0));
    invalidPoints.add(Point(1, 1));
    EXPECT_THROW(Triangle triangle(invalidPoints), std::invalid_argument);
}

TEST_F(GeometricFiguresTest, TriangleGeometricCenter) {
    Triangle triangle(equilateralTriangle1);
    Point center = triangle.geometric_center();
    
    double expected_x = (0 + 2 + 1) / 3.0;
    double expected_y = (0 + 0 + std::sqrt(3)) / 3.0;
    
    EXPECT_NEAR(center.get_x(), expected_x, 1e-6);
    EXPECT_NEAR(center.get_y(), expected_y, 1e-6);
}

TEST_F(GeometricFiguresTest, EquilateralTriangleArea) {
    Triangle triangle(equilateralTriangle1);
    double area = static_cast<double>(triangle);
    
    double expectedArea = std::sqrt(3);
    EXPECT_NEAR(area, expectedArea, 1e-6);
}

TEST_F(GeometricFiguresTest, TriangleFromYourExample) {
    DynamicArray<Point> yourTrianglePoints;
    yourTrianglePoints.add(Point(1, 2));
    yourTrianglePoints.add(Point(5, 6));
    yourTrianglePoints.add(Point(1, 7));
    
    Triangle triangle(yourTrianglePoints);
    double area = static_cast<double>(triangle);
    EXPECT_NEAR(area, 13.8564, 1e-4);
}

TEST_F(GeometricFiguresTest, SquareCreation) {
    EXPECT_NO_THROW(Square square(squarePoints1));
}

TEST_F(GeometricFiguresTest, SquareGeometricCenter) {
    Square square(squarePoints1);
    Point center = square.geometric_center();
    
    EXPECT_NEAR(center.get_x(), 1.0, 1e-6);
    EXPECT_NEAR(center.get_y(), 1.0, 1e-6);
}

TEST_F(GeometricFiguresTest, SquareArea) {
    Square square(squarePoints1);
    double area = static_cast<double>(square);
    EXPECT_NEAR(area, 4.0, 1e-6);
}

TEST_F(GeometricFiguresTest, SquareFromYourExample) {
    DynamicArray<Point> yourSquarePoints;
    yourSquarePoints.add(Point(1, 1));
    yourSquarePoints.add(Point(1, 4));
    yourSquarePoints.add(Point(4, 4));
    yourSquarePoints.add(Point(4, 1));
    
    Square square(yourSquarePoints);
    double area = static_cast<double>(square);

    EXPECT_NEAR(area, 9.0, 1e-6);
}

TEST_F(GeometricFiguresTest, RectangleCreation) {
    EXPECT_NO_THROW(Rectangle rectangle(rectanglePoints1));
}

TEST_F(GeometricFiguresTest, RectangleGeometricCenter) {
    Rectangle rectangle(rectanglePoints1);
    Point center = rectangle.geometric_center();
    
    EXPECT_NEAR(center.get_x(), 2.0, 1e-6);
    EXPECT_NEAR(center.get_y(), 1.5, 1e-6);
}

TEST_F(GeometricFiguresTest, RectangleArea) {
    Rectangle rectangle(rectanglePoints1);
    double area = static_cast<double>(rectangle);
    
    EXPECT_NEAR(area, 12.0, 1e-6);
}

TEST_F(GeometricFiguresTest, DynamicArrayPointOperations) {
    DynamicArray<Point> points;
   
    points.add(Point(1, 2));
    points.add(Point(3, 4));
    EXPECT_EQ(points.getSize(), 2);

    EXPECT_DOUBLE_EQ(points[0].get_x(), 1.0);
    EXPECT_DOUBLE_EQ(points[0].get_y(), 2.0);
    
}

TEST_F(GeometricFiguresTest, TotalAreaCalculation) {
    DynamicArray<Figure*> figures;
    
    Triangle* triangle = new Triangle(equilateralTriangle1);
    Square* square = new Square(squarePoints1);
    Rectangle* rectangle = new Rectangle(rectanglePoints1);
    
    figures.add(triangle);
    figures.add(square);
    figures.add(rectangle);
    
    double totalArea = figures.TotalArea();
    double expectedTotal = std::sqrt(3) + 4.0 + 12.0;
    
    EXPECT_NEAR(totalArea, expectedTotal, 1e-6);
    
    for (size_t i = 0; i < figures.getSize(); ++i) {
        delete figures[i];
    }
}

TEST_F(GeometricFiguresTest, PrintFigures) {
    DynamicArray<Figure*> figures;
    
    Triangle* triangle = new Triangle(equilateralTriangle1);
    Square* square = new Square(squarePoints1);
    
    figures.add(triangle);
    figures.add(square);
    
    EXPECT_NO_THROW(figures.PrintFigures());
    for (size_t i = 0; i < figures.getSize(); ++i) {
        delete figures[i];
    }
}

TEST_F(GeometricFiguresTest, DeleteFigure) {
    DynamicArray<Figure*> figures;
    
    Triangle* triangle = new Triangle(equilateralTriangle1);
    Square* square = new Square(squarePoints1);
    
    figures.add(triangle);
    figures.add(square);
    
    EXPECT_EQ(figures.getSize(), 2);
    
    figures.DeleteFigure(0);
    EXPECT_EQ(figures.getSize(), 1);
    
    delete figures[0];
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
