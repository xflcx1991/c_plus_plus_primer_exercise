#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> mvec = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
    };
    std::fill_n(mvec.begin(), mvec.size(), 0);
    for (auto item : mvec)
    {
        cout << item << endl;
    }
    return 0;
}