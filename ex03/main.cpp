#include "Point.hpp"
int main(int ac , char **av) {
    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " x y z" << std::endl;
        return 1;
    }
    Point a(std::stof(av[1]), std::stof(av[2]));
    Point b(std::stof(av[2]), std::stof(av[3]));
    Point c(std::stof(av[3]), std::stof(av[1]));
    Point point(std::stof(av[1]) + 0.5f, std::stof(av[2]) + 0.5f);
    if (bsp(a, b, c, point)) {
        std::cout << "Point is inside the triangle" << std::endl;
    } else {
        std::cout << "Point is outside the triangle" << std::endl;
    }
    return 0;
}