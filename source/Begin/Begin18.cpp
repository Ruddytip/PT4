#include "pt4.h"

void Solve()
{
    Task("Begin18");
    double a, b, c;
    pt >> a >> b >> c;
    double ac = abs(c - a);
    double bc = abs(b - c);
    pt << ac * bc;
}
