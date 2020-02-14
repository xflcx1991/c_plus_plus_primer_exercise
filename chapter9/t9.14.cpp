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

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    //要练习assign赋值，而不是迭代器初始化
    list<char *> mlist = {"apple", "banana", "chery"};
    vector<string> mvector = {"aaa", "bbb", "ccc"};
    mvector.assign(mlist.cbegin(), mlist.cend());
    for(auto item : mvector)
    {
        cout << item << endl;
    }

    return 0;
}