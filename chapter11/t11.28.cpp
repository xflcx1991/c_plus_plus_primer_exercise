/*************************************************************************************
* Copyright (c) 2020 xffish
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
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<string, int> mmap = {
        {"apple", 10},
        {"banana", 20},
        {"chery", 30},
    };
    //查找banana
    auto iter1 = mmap.find("banana");
    if (iter1 != mmap.end())
    {
        //找到了
        cout << iter1->second << endl;
    }
    iter1 = mmap.find("zoo");
    if (iter1 == mmap.end())
    {
        //没找到
        cout << "没找到" << endl;
    }

    return 0;
}