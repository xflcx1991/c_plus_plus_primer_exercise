//(a)有错误，运行时会报错，因为vec的大小是0，无法拷贝值
//(b)reserve虽然扩大了容量，但是.end()没变，fill_n的时候会使得迭代器越过.end
//在linux平台上，运行结果就像是跳过了fill_n，windows单步调试时会有警告弹出说
//cannot seek vector iterator after end
//应改为vec.resize(10)
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

    cout << "=====================" << endl;

    vector<int> vec2;
    //(b) 改为resize是关键
    vec2.resize(10);
    std::fill_n(vec2.begin(), 10, 1); //改为 1 可以看到 fill_n 效果
    cout << "vec2's size: " << vec2.size() << endl;
    for (auto item : vec2)
    {
        cout << item << endl;
    }
    return 0;
}