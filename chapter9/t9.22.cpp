//这是一个死循环，改法见下面。
//另外在循环中向一个vector插入元素会使所有指向容器的迭代器失效 P305 下方
//我假设原题是想在前半段找一个数，如果找到了，就在它前面插入一个两倍大小的数，这个前半段得始终不变，所以引入distance
//通过对distance的修改，使得原有的mid一直指向原有的中间的那个数
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> iv = {
        0, 1, 2, 100, 4, 100, 6, 7, 8, 100, 9, 10,
    };
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
    int distance = mid - iter; //确保mid始终指向原有的元素
    int some_val = 100;
    while (iter != mid)
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val);
            ++distance;
            mid = iv.begin() + distance;
            ++iter;
        }

        ++iter;
    }

    for (auto item : iv)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}