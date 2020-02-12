#include <iostream>

using std::cout;
using std::endl;

int main()
{
    auto f = [](int left, int right) { return left + right; };
    int a = f(1, 3);
    cout << a << endl;

    return 0;
}