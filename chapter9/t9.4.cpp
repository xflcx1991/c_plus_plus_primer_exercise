#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool findValue(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value);

int main()
{
    vector<int> mvector = {1,2,3,4,5,6,7,8};
    cout << findValue(mvector.cbegin(), mvector.cend(), 9) << endl;

    return 0;
}

bool findValue(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value)
{
    bool flag = false;
    for(; begin != end; ++begin)
    {
        if(*begin == value)
        {
            flag = true;
            break;
        }
    }

    return flag;
}