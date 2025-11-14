#include <iostream>
#include "dynamicArray.h"
#include "figure.h"
#include "triangle.h"
#include "rectangle.h"
#include "square.h"

int main() {
  DynamicArray<Figure *> figures;

  Triangle *trgl = new Triangle();
  std::cin >> *trgl;
  figures.add(trgl);

  Square *sqr = new Square();
  std::cin >> *sqr;
  figures.add(sqr);

  Rectangle *rctgl = new Rectangle();
  std::cin >> *rctgl;
  figures.add(rctgl);

  std::cout << "All the shapes" << std::endl;
  figures.PrintFigures();

  std::cout << "The total Area : " << figures.TotalArea() << std::endl;

  figures.DeleteFigure(0);

  return 0;
}