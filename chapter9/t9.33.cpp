//运行时报错，因为insert后迭代器已经失效，后续begin迭代器的使用已处于危险的境地
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v = {0,1,2,3,4,5,6,7,8,9,};
    auto begin = v.begin();
    while(begin != v.end())
    {
        ++begin;
        v.insert(begin, 42);
        ++begin;
    }
    for(auto item : v)
    {
        cout << item << endl;
    }
    return 0;
}
