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

//基于9.18修改，用list替代deque
//改动很小，引入list头文件，修改变量声明为list<string>就完了
#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string word;
    list<string> mlist;
    //输入 ctrl+D 传入 EOF 文件结束符以终止循环
    while(cin >> word)
    {
        mlist.push_back(word);
    }

    //存入完毕，打印，要求用迭代器遍历
    for(auto iter = mlist.cbegin(); iter != mlist.cend(); ++iter)
    {
        cout << (*iter) << endl;
    }

}