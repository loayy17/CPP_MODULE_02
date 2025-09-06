#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(this->x + other.x, this->y + other.y);
    }
    Point operator-(const Point& other) const {
        return Point(this->x - other.x, this->y - other.y);
    }
    bool operator==(const Point &other) const {
        return (x == other.x && y == other.y);
    }
    friend std::ostream &operator<<(std::ostream &out,const Point &point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point a(2, 3);
    Point b(5, 7);
    Point c(5, 7);
    Point d(5, 7);
    if(c == b){
        std::cout << "Points are equal" << std::endl;
    } else {
        std::cout << "Points are not equal" << std::endl;
    }
    std::cout << "Point a: " << a << std::endl;
    std::cout << "Point b: " << b << std::endl;
    Point sum = a + b;
    std::cout << "Sum of a and b: " << sum << std::endl
                << "Expected: (7, 10)" << std::endl;
    Point diff = b - a;
    std::cout << "Difference of b and a: " << diff << std::endl
                << "Expected: (3, 4)" << std::endl;
    std::cout <<a << " + " << b << " = " << sum << std::endl;
                return 0;
}
