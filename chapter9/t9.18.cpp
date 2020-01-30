#include <iostream>
#include <deque>
#include <string>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string word;
    deque<string> mdeque;
    //输入 ctrl+D 传入 EOF 文件结束符以终止循环
    while(cin >> word)
    {
        mdeque.push_back(word);
    }

    //存入完毕，打印，要求用迭代器遍历
    for(auto iter = mdeque.cbegin(); iter != mdeque.cend(); ++iter)
    {
        cout << (*iter) << endl;
    }

}