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
#include <list>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::map;
using std::string;

int main()
{
    map<string, list<int>> mmap = {
        {"apple", {1, 2, 3, 4, 5}},
        {"banana", {2, 3, 4, 5, 7, 8, 9}},
        {"chery", {10, 20, 30, 40, 50}},
    };

    for (const auto &item : mmap)
    {
        cout << item.first << "-";
        for (const auto &line : item.second)
        {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}