#ifndef CLNODE_H
#define CLNODE_H
#include <cstdlib>
#include <clCircle.h>

using namespace std;

class clNode : public clCircle
{
public:
    clNode();
    clNode(int a, int b, int c, int i);
    virtual ~clNode();

    char* Getnum() { return num; }
    void Setnum(int val) { itoa(val, num, 10); cout << num << endl;}
    void Show();

private:
    char *num;
};

#endif
