#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void elimDups(vector<int> &mvec);

int main()
{
    vector<int> mvec = {10, 20, -1, 2, 3, 4, 5, 10, 100, 20};
    elimDups(mvec);

    return 0;
}

void elimDups(vector<int> &mvec)
{
    std::sort(mvec.begin(), mvec.end());
    auto iter = std::unique(mvec.begin(), mvec.end());
    mvec.erase(iter, mvec.cend());
    for (auto item : mvec)
    {
        cout << item << endl;
    }
}