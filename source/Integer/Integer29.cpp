#include "pt4.h"

void Solve()
{
    Task("Integer29");
    int a, b, c;
    pt >> a >> b >> c;
    int x = a / c;
    int y = b / c;
    int k = x * y;
    int s = a * b - k * c * c;
    pt << k << s;
}
