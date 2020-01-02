#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int myAdd(int,int);
int myMinus(int,int);
int myMultiply(int,int);
int myDivide(int,int);

using funcP1 = int(*)(int,int);

int main()
{
    vector<funcP1> myvector1 = {myAdd, myMinus, myMultiply, myDivide};
    for(auto fp : myvector1)
    {
        cout << fp(1,22) << endl;
    }
    return 0;
}

int myAdd(int argv1,int argv2)
{
    return argv1 + argv2;    
}
int myMinus(int argv1,int argv2)
{
    return argv1 - argv2;  
}
int myMultiply(int argv1,int argv2)
{
    return argv1 * argv2;
}
int myDivide(int argv1,int argv2)
{
    return argv1 / argv2;  
}