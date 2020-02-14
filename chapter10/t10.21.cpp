/*************************************************************************************
* Copyright (c) 2019 xffish
* c_plus_plus_primer_exercise is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
* http://license.coscl.org.cn/MulanPSL2
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
* See the Mulan PSL v2 for more details.
*************************************************************************************/

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