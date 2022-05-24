#include "pt4.h"

void Solve()
{
    Task("Integer11");
    int d;
    pt >> d;
    int a = d / 100;
    int b = (d / 10) % 10;
    int c = d % 10;
    pt << a + b + c;
    pt << a * b * c;
}
