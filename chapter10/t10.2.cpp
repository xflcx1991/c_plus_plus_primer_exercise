#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    list<string> mlist;
    string word;
    while(cin >> word)
    {
        mlist.push_back(word);
    }
    cout << "现在list内容是" << endl;
    for(auto item : mlist)
    {
        cout << item << "---";
    }
    cout << endl;
    cout << "开始查找字符串" << endl;
    string goal = "apple";
    int count = std::count(mlist.cbegin(), mlist.cend(), goal);
    cout << "一共有 " << count << " 个" << endl;
    return 0;
}