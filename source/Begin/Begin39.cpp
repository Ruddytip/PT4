#include "pt4.h"
#include <cmath>

void Solve()
{
    Task("Begin39");
    double a, b, c;
    pt >> a >> b >> c;
    double d = b * b - 4 * a * c;
    double x1 = (-b + sqrt(d)) / (2. * a);
    double x2 = (-b - sqrt(d)) / (2. * a);
    if(x2 < x1) std::swap(x1, x2);
    pt << x1 << x2;
}
