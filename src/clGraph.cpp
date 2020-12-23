#include "clGraph.h"
#include "clEdge.h"
#include "clNode.h"
#include "clLine.h"

using namespace std;

int i, j;

clGraph::clGraph(int t, int *p): N(t), a(new int [N * N]), s(new clNode [N])
{
    double x = 350, y = 150;
    int R = 120;
    double pi = 3.1415926535, angle = 0;
    s[0].Setx(x);
    s[0].Sety(y);
    s[0].Setnum(1);
    for (i = 1; i < N; i++)
    {
        angle += 360 / N;
        x = x + R * cos(angle * pi / 180);
        s[i].Setx(x);
        y = y + R * sin(angle * pi / 180);
        s[i].Sety(y);
        s[i].Setnum(i + 1);
        cout << x << " " << y << " " << i + 1 << endl;
    }
    for (i = 0; i < N * N; i++)
        a[i] = p[i];
}

void clGraph:: Show()
{
    for (i = 0; i < N; i++)
        s[i].Show();
    for (i = 0; i < N * N; i++)
    {
        int m = i / N, k = i % N;
        if (a[i])
        {
            clEdge edg;
            edg.Setx_1(s[m].Getx());
            edg.Setx_2(s[k].Getx());
            edg.Sety_1(s[m].Gety());
            edg.Sety_2(s[k].Gety());
            edg.Setw(a[i]);
            edg.Show();
        }
    }
}

int clGraph:: MinVes(int z[], bool bo[])      //ищем соседа, не добавленного в остовное дерево с минимальным весом
{
    int min = INT_MAX;
    int minNum;
    for (i = 0; i < N; i++)
        if (bo[i] == false && z[i] < min)
        {
            min = z[i];
            minNum = i;
        }
    return minNum;
}

int clGraph:: Prima(int parent[])
{
    cout << "Edge" << " " << "Weight\n";
    for (i = 1; i < N; i++)
    {
        setcolor(5);
        clLine ln(s[parent[i]].Getx(), s[parent[i]].Gety(), s[i].Getx(), s[i].Gety());
        ln.Show();
    }
}



void clGraph:: Prima()                              //Прима
{
	int parent[N];
	int z[N];
	bool bo[N];

	for (i = 0; i < N; i++)
    {
        z[i] = INT_MAX;
        bo[i] = false;
    }

	z[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < N - 1; i++)
	{
		int m = MinVes(z, bo);
		bo[m] = true;
		for (j = 0; j < N; j++)
		    if ((a[m * N + j]) && (a[m * N + j] < z[j]) && (bo[j] == false))
			{
			    parent[j] = m;
                z[j] = a[m * N + j];
                cout << j << " " << m << " " << parent[j] << " " << z[j] << " " << a[m * N + j] << endl;
            }
	}
	Prima(parent);
}

clGraph::~clGraph()
{
    //dtor
}

