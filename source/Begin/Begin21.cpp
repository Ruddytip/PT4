#include "pt4.h"
#include <cmath>

void Solve()
{
    Task("Begin21");
    double x1, y1;
    double x2, y2;
    double x3, y3;
    pt >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    pt << p * 2. << s;
}
