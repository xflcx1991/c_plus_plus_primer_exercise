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

//在t10.20上修改
//个人感觉bind真是蛋疼就用lambda不就行了
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std::placeholders;

bool searchSize(const string &str, string::size_type sz);

int main()
{
    vector<string> mvec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    //只统计有多少单词小于等于6
    string::size_type length = 6;

    auto search = std::bind(searchSize, _1, length);
    auto count = std::count_if(mvec.cbegin(), mvec.cend(), search);

    //根据count打印“word”单词的单数或者复数形式
    cout << count << endl;
}

bool searchSize(const string &str, string::size_type sz)
{
    return str.size() <= sz;
}
