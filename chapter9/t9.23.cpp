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

//val、val1、val2、val3 都是一样的值，即容器里那个值
//而且这四个都是容器元素值的拷贝而不是引用
//以下程序验证
#include <iostream>
#include <vector>


using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> c = {2};
    if (!c.empty())
    {
        auto val = *c.begin(), val2 = c.front();
        
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();



        cout << val << endl;
        cout << val2 << endl;
        cout << val3 << endl;
        cout << val4 << endl;

        val = 10;
        val2 = 20;
        val3 = 30;
        val4 = 40;
        cout << c.at(0) << endl;
    }
}