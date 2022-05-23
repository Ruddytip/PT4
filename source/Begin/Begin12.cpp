#include "pt4.h"
#include <cmath>

void Solve()
{
    Task("Begin12");
    double a, b;
    pt >> a >> b;
    double c = sqrt(a * a + b * b);
    pt << c << a + b + c;
}
