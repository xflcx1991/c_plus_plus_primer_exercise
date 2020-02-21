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
#include <set>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::set;
using std::string;

int main()
{
    multimap<string, string> authors = {
        {"Barth, John", "Sot-Weed Factor"},
        {"Barth, John", "Lost in the Funhouse"},
        {"Hawking", "The Universe in a Nutshell"},
        {"Hawking", "The Grand Design"},
        {"Hawking", "A brief history of time"},
    };
    string keyword = "Barth,f John";
    //multimap key是字典序的，value不一定，可以利用set自带的字典序来中转一道
    map<string, set<string>> tempAuthors;

    for (auto iter1 = authors.begin(); iter1 != authors.end(); ++iter1)
    {
        //简介写法来自https://blog.csdn.net/misayaaaaa/article/details/59112126
        //我本来还用find查找，分情况insert，其实下标操作能统一
        tempAuthors[iter1->first].insert(iter1->second);
    }

    //搞定，顺序打印tempAuthors即可
    for (const auto &item : tempAuthors)
    {
        cout << item.first << "的作品：";
        for (const auto &book : item.second)
        {
            cout << book << ";";
        }
        cout << endl;
    }
}