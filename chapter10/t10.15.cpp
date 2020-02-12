#include <iostream>

using std::cout;
using std::endl;

int justTest(int left, int right)
{
    auto f = [left, right]() { return left + right; };
    return f();
}

int main()
{
    int a = justTest(41, 1);
    cout << a << endl;

    return 0;
}