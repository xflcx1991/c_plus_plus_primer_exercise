//(a)有错误，运行时会报错，因为vec的大小是0，无法拷贝值
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
    {
        lst.push_back(i);
    }

    //(a) 改成back_inserter是关键
    std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));
    cout << "vec's size: " << vec.size() << endl;
    for (auto item : vec)
    {
        cout << item << endl;
    }
    return 0;
}