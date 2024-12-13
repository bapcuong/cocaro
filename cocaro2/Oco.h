#pragma once
#include "Hcn.h"
#define DAI  40
class Oco :
    public Hcn
{
public:
    int giatri; //giatri = 0 la chua co, 1 la o, -1 la x
    Oco();
    Oco(int mx1, int my1);
    void vehinh(CClientDC* pdc);
    int tickoco(CClientDC* pdc, CPoint p, int mgiatri);


};

