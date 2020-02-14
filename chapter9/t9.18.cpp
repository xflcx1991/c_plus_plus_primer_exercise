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
#include <deque>
#include <string>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string word;
    deque<string> mdeque;
    //输入 ctrl+D 传入 EOF 文件结束符以终止循环
    while(cin >> word)
    {
        mdeque.push_back(word);
    }

    //存入完毕，打印，要求用迭代器遍历
    for(auto iter = mdeque.cbegin(); iter != mdeque.cend(); ++iter)
    {
        cout << (*iter) << endl;
    }

}