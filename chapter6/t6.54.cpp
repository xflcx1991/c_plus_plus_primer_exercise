#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

using funcP1 = int(*)(int,int);
//OR
typedef int (*funcP2)(int,int);
int main()
{
    vector<funcP1> myvector1();
    vector<funcP2> myvector2();
    cout << "It works" << endl;
    return 0;
}
