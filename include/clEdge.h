#ifndef CLEDGE_H
#define CLEDGE_H
#include "clLine.h"
#include <cstdlib>

using namespace std;

class clEdge:public clLine
{
    public:
        clEdge();
        virtual ~clEdge();

        char* Getw() { return t; }
        void Setw(int val) { itoa(val, t, 10);}
        void Show();

    protected:

    private:
        char *t;
};

#endif // CLEDGE_H
