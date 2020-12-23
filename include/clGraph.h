#ifndef CLGRAPH_H
#define CLGRAPH_H
#include "CLDraw.h"
#include <graphics.h>
#include "CLDraw.h"
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "clNode.h"

using namespace std;

class clGraph : public clDraw
{
    public:
        //clGraph();
        clGraph(int N, int *a);
        virtual ~clGraph();

        int GetN() { return N; }
        void Setn(int val) { N = val; }

        void Show();
        void Prima();

    protected:

    private:
        int N;
        int *a;
        clNode *s;
        int Prima(int parent[]);
        int MinVes(int z[], bool bo[]);
};

#endif
