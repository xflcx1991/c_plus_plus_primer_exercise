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
#include <limits>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<string>> mmap;
    string familyName;
    string firstName;
    while (true)
    {
        cout << "请输入家庭的姓" << endl;
        cin >> familyName;
        cout << familyName << endl;
        cout << "请输入家中孩子们的名字，输入0开始重新输入新家庭，放弃输入ctrl+D结束" << endl;
        //以ctrl+D解决不了再次输入的问题，clear都不行，放弃处理这种情况遇到直接退出程序
        while (cin >> firstName)
        {
            if (cin.eof() || cin.bad())
            { // 如果用户输入文件结束标志（或文件已被读完），
                // 或者发生读写错误，则退出循环
                break;
            }
            if (firstName == "0")
            {
                break;
            }
            mmap[familyName].push_back(firstName);
        }

        if (cin.eof() || cin.bad())
        { // 如果用户输入文件结束标志（或文件已被读完），
            // 或者发生读写错误，则退出循环
            break;
        }
        cin.clear();
        //cin.sync()并不生效，文档上说要看具体的环境是否支持
        //还是用以下代码，来自 cppreference std::basic_istream::ignore条目下的示例代码
        //https://zh.cppreference.com/w/cpp/io/basic_istream/ignore
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "显示结果" << endl;
    for (const auto &item : mmap)
    {
        cout << "家族：" << item.first << " 有" << item.second.size() << " 个孩子" << endl;
        cout << "分别是：";
        for (const auto &tempName : item.second)
        {
            cout << tempName << ",";
        }
        cout << endl;
    }

    return 0;
}