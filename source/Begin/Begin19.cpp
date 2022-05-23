#include "pt4.h"

void Solve()
{
    Task("Begin19");
    double x1, y1;
    double x2, y2;
    pt >> x1 >> y1 >> x2 >> y2;
    double x = abs(x2 - x1);
    double y = abs(y2 - y1);
    pt << 2 * (x + y) << x * y;
}
