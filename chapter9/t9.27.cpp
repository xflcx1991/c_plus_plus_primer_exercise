#include <iostream>
#include <forward_list>


using std::forward_list;
using std::cout;
using std::endl;

int main()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9,};
    auto prev = flst.cbefore_begin();
    auto curr = flst.cbegin();
    while(curr != flst.cend())
    {
        if(*curr % 2 != 0) //是奇数
        {
            cout << "即将删除：" << *curr << endl;
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
        
    }



    return 0;
}