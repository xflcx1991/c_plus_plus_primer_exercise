//要求必须处理未找到给定值的情况，但是函数不知道end是不是那个尾元素的后一个元素，函数自己怎么能知道啥是
//x.end呢？如果不知道，该返回一个啥样的迭代器呢？
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int>::const_iterator findValue(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value);

int main()
{
    vector<int> mvector = {1,2,3,4,5,6,7,8};
    vector<int>::const_iterator item = findValue(mvector.cbegin(), mvector.cend(), 3);
    if(item == mvector.cend())
    {
        //没找到
        cout << "没找到" << endl;
    }
    else
    {
        cout << *item << endl;
    }

    return 0;
}

//默认end就是容器最后一个元素后一个位置
vector<int>::const_iterator findValue(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value)
{
    vector<int>::const_iterator result = end;
    for(; begin != end; ++begin)
    {
        if(*begin == value)
        {
            result = begin;
            break;
        }
    }

    return result;
}