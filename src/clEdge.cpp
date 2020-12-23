#include "clEdge.h"

using namespace std;

clEdge::clEdge():t(new char[3])
{
    //ctor
}

void clEdge::Show()
{
    clLine::Show();
    outtextxy((Getx_1() + Getx_2()) / 2, (Gety_1() + Gety_2()) / 2, t);;
}

clEdge::~clEdge()
{
    //dtor
}
