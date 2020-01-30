//不能，因为list和forward_list的迭代器不支持算术运算， iter += 2 这里会报错
#include <iostream>
#include <list>
#include <forward_list>
#include <string>
#include <vector>

using std::vector;
using std::list;
using std::string;
using std::forward_list;
using std::cout;
using std::endl;
using std::advance;

void exampleList();
void exampleForwardList();

int main()
{
    exampleList();
    cout << "======" << endl;
    exampleForwardList();
    return 0;
}

void exampleList()
{
    list<int> vi = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    };
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            advance(iter, 2); //这是关键
        }
        else
        {
            iter = vi.erase(iter);
        }
    }

    for (auto item : vi)
    {
        cout << item << endl;
    }
}
void exampleForwardList()
{
    forward_list<int> vi = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    };
    //用常量版本更好，为了少改动316页程序，就不改了
    auto prev = vi.before_begin();
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            //和list保持一致，在原有元素前插入复制的值
            iter = vi.insert_after(prev, *iter);
            advance(iter, 2); //这是关键
            advance(prev, 2); //这是关键
        }
        else
        {
            iter = vi.erase_after(prev);
        }
    }

    for (auto item : vi)
    {
        cout << item << endl;
    }
}
