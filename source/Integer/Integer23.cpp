#include "pt4.h"

void Solve()
{
    Task("Integer23");
    int s;
    pt >> s;
    pt << (s % 3600) / 60;
}
