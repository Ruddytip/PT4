#include "pt4.h"

void Solve()
{
    Task("Begin23");
    double a, b, c;
    pt >> a >> b >> c;
    std::swap(a, b);
    std::swap(a, c);
    pt << a << b << c;
}
