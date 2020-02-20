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

//在t11.7基础上改
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::set;
using std::string;
using std::vector;

int main()
{
    multimap<string, string> mulmap;
    string familyName;
    string firstName;
    while (true)
    {
        cout << "请输入家庭的姓" << endl;
        cin >> familyName;
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
            mulmap.insert({familyName, firstName});
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
    //没有内置方法能每个key只遍历一遍，先放进set里，自动过滤一道
    set<string> keyMulmap;
    for (const auto &item : mulmap)
    {
        keyMulmap.insert(item.first);
    }
    //所有unique key得到了
    for (const auto &item : keyMulmap)
    {
        cout << "家族：" << item << " 的孩子：";
        for (auto pos = mulmap.equal_range(item);
             pos.first != pos.second; ++pos.first)
        {

            cout << pos.first->second << " ";
        }
        cout << endl;
    }

    return 0;
}