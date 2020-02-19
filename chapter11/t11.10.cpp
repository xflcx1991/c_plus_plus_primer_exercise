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

//vector可以，list不行，因为前者的iterator定义了<运算符，而后者的iterator不支持<运算符
#include <iostream>
#include <list>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::map;
using std::vector;

int main()
{
    vector<int> vec1 = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    list<int> vec2(vec1.cbegin(), vec1.cend());

    map<vector<int>::iterator, int> mmap1 = {
        {vec1.begin(), 10},
        {vec1.begin() + 1, 20},
    };

    for (const auto &item : mmap1)
    {
        cout << *item.first << "---" << item.second << endl;
    }
    //anther
    //会报错
    // map<list<int>::iterator, int> mmap2 = {
    //     {vec2.begin(), 90},
    // };

    return 0;
}
