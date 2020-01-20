#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    //要练习assign赋值，而不是迭代器初始化
    list<char *> mlist = {"apple", "banana", "chery"};
    vector<string> mvector = {"aaa", "bbb", "ccc"};
    mvector.assign(mlist.cbegin(), mlist.cend());
    for(auto item : mvector)
    {
        cout << item << endl;
    }

    return 0;
}