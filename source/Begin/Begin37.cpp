#include "pt4.h"

void Solve()
{
    Task("Begin37");
    double v1, v2, s, t;
    pt >> v1 >> v2 >> s >> t;
    pt << abs(s - v1 * t - v2 * t);
}
