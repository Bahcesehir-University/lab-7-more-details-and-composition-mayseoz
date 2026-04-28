#include <iostream>

#include <string>

#include <cmath>
 
 
// ============================================================

// CLASS DEFINITIONS

// ============================================================
 
 
class Point {

private:

double x;

double y;

public:

// TODO 1: Constructor with member initializer list (double x, double y)

Point(double x, double y) : x(x), y(y) {}
 
 
// TODO 2: const getter for x

double getX() const { return x; }
 
 
// TODO 3: const getter for y

double getY() const { return y; }
 
 
// TODO 4: const display()

void display() const { std::cout << "(" << x << ", " << y << ")"; }
 
 
// TODO 5: declare Rectangle as friend class

friend class Rectangle;

};
 
 
 
class Rectangle {

private:

Point topLeft;

Point bottomRight;

public:

// TODO 6: constructor with member initializer list

Rectangle(double x1, double y1, double x2, double y2)

: topLeft(x1, y1), bottomRight(x2, y2) {}
 
 
// TODO 7: const getWidth()

double getWidth() const { return std::abs(bottomRight.x - topLeft.x); }
 
 
// TODO 8: const getHeight()

double getHeight() const { return std::abs(topLeft.y - bottomRight.y); }
 
 
// TODO 9: const getArea()

double getArea() const { return getWidth() * getHeight(); }
 
 
// TODO 10: const display()

void display() const {

std::cout << "Rectangle[";

topLeft.display();

std::cout << " to ";

bottomRight.display();

std::cout << "]";

}
 
 
// TODO 11: declare isSameSize as friend function

friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);

};
 
 
 
// TODO 12: implement isSameSize

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {

const double EPS = 1e-9;

return std::abs(r1.getArea() - r2.getArea()) < EPS;

}
 
 
 
class ConstDemo {

private:

int value;

public:

// TODO 13: constructor with member initializer list

ConstDemo(int v) : value(v) {}
 
 
// TODO 14: const getValue()

int getValue() const { return value; }
 
 
// TODO 15: NON-const doubleValue() — multiplies value by 2

void doubleValue() { value *= 2; }
 
 
// TODO 16: const constGetDouble() — returns value * 2 without modifying

int constGetDouble() const { return value * 2; }

};
 
 
 
// ============================================================

// MAIN

// ============================================================

int main() {

// TODO 17-21: demo code

std::cout << "--- Rectangle & Point Test ---" << std::endl;
 
 
Rectangle rect1(0, 10, 5, 0);

Rectangle rect2(2, 5, 7, -5);
 
 
rect1.display();

std::cout << "\nArea of rect1: " << rect1.getArea() << std::endl;
 
 
rect2.display();

std::cout << "\nArea of rect2: " << rect2.getArea() << std::endl;
 
 
std::cout << "Are rect1 and rect2 the same size? "
<< (isSameSize(rect1, rect2) ? "Yes" : "No") << std::endl;
 
 
std::cout << "\n--- ConstDemo Test ---" << std::endl;
 
 
ConstDemo demo(10);

std::cout << "Original demo value: " << demo.getValue() << std::endl;
 
 
demo.doubleValue();

std::cout << "After doubleValue(): " << demo.getValue() << std::endl;
 
 
const ConstDemo constDemo(100);

std::cout << "\nConst obj initial value: " << constDemo.getValue() << std::endl;
 
 
std::cout << "Const obj constGetDouble() result: "
<< constDemo.constGetDouble() << std::endl;
 
 
std::cout << "Const obj value remains unchanged: "
<< constDemo.getValue() << std::endl;
 
 
return 0;

}
 
