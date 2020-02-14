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
