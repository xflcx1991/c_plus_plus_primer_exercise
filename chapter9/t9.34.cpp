//死循环。遇到奇数后，正确插入了值，然后iter指向这个插入的值，然后iter只向后走一步，还指向开始那个奇数，下一次循环发现还是奇数（肯定是）于是重复上述描述，陷入死循环。
//应该如果是奇数就iter += 2 如果是偶数就 ++iter
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9,};
    auto iter = vi.begin();
    //下面是修正后的代码
    while(iter != vi.end())
    {
        if(*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
        {
            ++iter;
        }
        //++iter;
    }
    
    for(auto item : vi)
    {
        cout << item << endl;
    }
    return 0;
}
