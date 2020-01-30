#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> mvector;

    // cout << mvector.at(0) << endl; //throwing an instance of 'std::out_of_range'
    cout << mvector[0] << endl;  //运行报错
    cout << mvector.front() << endl; //运行报错
    cout << *mvector.begin() << endl; //运行报错

    return 0;
}