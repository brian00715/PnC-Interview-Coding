#include <iostream>
class Point
{
public:
    Point(double x, double y) : x(x), y(y) {}
    Point operator-(const Point &p)
    {
        return Point(x - p.x, y - p.y);
    }
    double operator*(const Point &p)
    {
        return x * p.x + y * p.y;
    }
    Point operator*(double a)
    {
        return Point(x * a, y * a);
    }
    Point operator+(const Point &p)
    {
        return Point(x + p.x, y + p.y);
    }
    double norm()
    {
        return sqrt(x * x + y * y);
    }

    Point operator/(double a)
    {
        return Point(x / a, y / a);
    }

    double x;
    double y;
};
int main(int argc, char const *argv[])
{
    Point a(1, 1), b(2, 2), c(3, 3);
    Point ab = b - a;
    Point ac = c - a;
    double dot = ab * ac;
    Point map_vec = ab / ab.norm() * dot;
    Point map = a + map_vec;
    std::cout << map.x << " " << map.y << std::endl;
    return 0;
}
