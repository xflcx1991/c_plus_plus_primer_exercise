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
using std::multimap;
using std::string;

int main()
{
    multimap<string, string> authors = {
        {"Barth, John", "Sot-Weed Factor"},
        {"Barth, John", "Lost in the Funhouse"},
        {"Hawking", "A brief history of time"},
        {"Hawking", "The Grand Design"},
        {"Hawking", "The Universe in a Nutshell"},
    };
    string keyword = "Barth,f John";
    //要求用find再用erase，那就不用 size_type erase( const key_type& key ) 形式了
    authors.erase(keyword);
    auto nums = authors.count(keyword);
    auto iter = authors.find(keyword);
    if (!nums)
    {
        //没找到
        cout << "没找到" << endl;
    }
    else
    {
        while (nums)
        {
            cout << iter->second << endl;
            iter = authors.erase(iter);
            // ++iter;
            --nums;
        }
        nums = authors.count(keyword);
        cout << nums << endl;
    }

    //打印
    auto it3 = authors.begin();
    for (it3; it3 != authors.end(); ++it3)
    {
        cout << it3->first << "的宝贝儿：" << it3->second << endl;
    }

    return 0;
}