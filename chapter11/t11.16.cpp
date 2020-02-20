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
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, int> mmap = {
        {"apple", 10},
        {"banana", 20},
        {"chery", 30},
    };
    //必须是.begin() 不能是.cbegin()，否则second不让修改
    auto map_it = mmap.begin();
    map_it->second = 100;

    while (map_it != mmap.cend())
    {
        cout << map_it->first << " --- " << map_it->second << endl;
        ++map_it;
    }

    return 0;
}