#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> mvec = {1,2,3,4,5,};
    int result = std::accumulate(mvec.cbegin(), mvec.cend(), 0);
    cout << result << endl;
    return 0;
}