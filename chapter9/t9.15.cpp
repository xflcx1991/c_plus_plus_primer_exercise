#include <iostream>
#include <vector>


using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> mvector1 = {1,2,3,4,5};
    vector<int> mvector2 = {2,3,4,5,6};
    cout << (mvector1 == mvector2) << endl;

    return 0;
}