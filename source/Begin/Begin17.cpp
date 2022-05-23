#include "pt4.h"

void Solve()
{
    Task("Begin17");
    double x1, x2, x3;
    pt >> x1 >> x2 >> x3;
    double ac = abs(x3 - x1);
    double bc = abs(x3 - x2);
    pt << ac << bc << ac + bc;
}
