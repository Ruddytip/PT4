#include "pt4.h"

void Solve()
{
    Task("Begin24");
    double a, b, c;
    pt >> a >> b >> c;
    std::swap(a, b);
    std::swap(b, c);
    pt << a << b << c;
}
