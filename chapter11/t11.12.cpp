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
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

//不考虑异常情况
int main()
{
    string word;
    int value;
    vector<pair<string, int>> mvec;
    while (true)
    {
        cout << "请输入单词，按 ctrl+D 结束" << endl;
        cin >> word;

        if (cin.eof() || cin.bad())
        { // 如果用户输入文件结束标志（或文件已被读完），
            // 或者发生读写错误，则退出循环
            break;
        }

        cout << "请输入对应的值" << endl;
        cin >> value;
        pair<string, int> tempPair = {word, value};
        mvec.push_back(tempPair);
    }

    //打印内容
    for (const auto &item : mvec)
    {
        //每个item是pair
        cout << item.first << "---" << item.second << endl;
    }

    return 0;
}