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
#include <algorithm>
#include <list>
#include <string>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    list<string> mlist;
    string word;
    while(cin >> word)
    {
        mlist.push_back(word);
    }
    cout << "现在list内容是" << endl;
    for(auto item : mlist)
    {
        cout << item << "---";
    }
    cout << endl;
    cout << "开始查找字符串" << endl;
    string goal = "apple";
    int count = std::count(mlist.cbegin(), mlist.cend(), goal);
    cout << "一共有 " << count << " 个" << endl;
    return 0;
}