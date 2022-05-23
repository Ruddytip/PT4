#include "pt4.h"

void Solve()
{
    Task("Begin13");
    double r1, r2;
    pt >> r1 >> r2;
    double s1 = 3.14 * r1 * r1;
    double s2 = 3.14 * r2 * r2;
    double s3 = s1 - s2;
    pt << s1 << s2 << s3;
}
