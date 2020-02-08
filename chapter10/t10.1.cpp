#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> mvec = {1,2,3,4,4,2,2,1,1,1,2,9,};
    int count = std::count(mvec.cbegin(), mvec.cend(), 1);
    cout << count << endl;

    return 0;
}