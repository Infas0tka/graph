#include <iostream>
#include <graphics.h>
#include "clCircle.h"
#include "clNode.h"
#include "clEdge.h"
#include "clGraph.h"
#include <fstream>

using namespace std;

int main()
{
    int i, j, N;
    ifstream fin("input.txt");
    fin >> N;
    int b[N][N];
    int a[N * N];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            fin >> b[i][j];

    for (i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }
    fin.close();

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i * N + j] = b[i][j];

    clGraph Gr(N, a);
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm,"");
    Gr.Show();
    readkey();
    Gr.Prima();
    readkey();
    closegraph();
    return 0;
}



