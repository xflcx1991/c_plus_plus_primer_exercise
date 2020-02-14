#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    int num = 9;
    while (true)
    {
        //vs2019和gcc 7.4(Ubuntu 18.04)
        auto f = [&num]() -> bool {
            if (num > 0)
            {
                --num;
            }
            return num == 0 ? true : false;
        };
        bool result = f();
        if (result)
        {
            //如果减到0了，那就不循环了
            break;
        }
    }
    cout << "程序结束，num=" << num << endl;
    return 0;
}