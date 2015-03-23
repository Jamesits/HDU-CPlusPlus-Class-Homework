// calccir.cpp
// calculte a circle
// by James Swineson, 2015-03-23

#include <iostream>

class Circle {
private:
    const double PI = 3.1415926;
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double getArea() {
        return PI * radius * radius;
    }
    double getCircumference() {
        return 2.0 * PI * radius;
    }
};

int main() {
    std::cout << "Please input radius: ";
    double r;
    std::cin >> r;
    Circle c(r);
    std::cout << "Area: " << c.getArea() << std::endl
        << "Circumference: " << c.getCircumference() << std::endl;
        
    return 0;
}
