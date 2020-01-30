//有什么可分析的，还不是一样的效果，元素倒序存起来了
//只是用vector头插，效率很差
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> lst;
    auto iter = lst.begin();
    string word;
    while(cin >> word)
    {
        iter = lst.insert(iter, word);
    }

    for(auto item : lst)
    {
        cout << item << endl;
    }

    return 0;
}