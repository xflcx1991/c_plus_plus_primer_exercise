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

//使用set优点：自动去重，大数据集下查找一个元素是否存在会非常的快
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> mvec;
    string word;
    while (cin >> word)
    {
        if (std::find(mvec.cbegin(), mvec.cend(), word) == mvec.cend())
        {
            //没找到就添加
            mvec.push_back(word);
        }
    }
    cout << "============" << endl;
    //打印结果
    for (const auto &item : mvec)
    {
        cout << item << endl;
    }
    return 0;
}