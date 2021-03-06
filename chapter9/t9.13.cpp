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

//主要思路就是用两个迭代器创建拷贝
#include <iostream>
#include <vector>
#include <list>

using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    //从list<int> 初始化 vector<double>
    list<int> mlist = {1,2,3,4,5,6,7,8,9,0};
    auto head = mlist.cbegin();
    auto tail = mlist.cend();
    vector<double> mvector(head, tail);
    for(auto item : mvector)
    {
        cout << item << endl;
    }
    /////////////////////////////////
    //从vector<int>初始化vector<double>
    //做法一样
    vector<int> sourceVector = {1,2,3,4,5,6,7,8,9,0};
    auto head2 = sourceVector.cbegin();
    auto tail2 = sourceVector.cend();
    vector<double> targetVector(head2, tail2);
    for(auto item : targetVector)
    {
        cout << item << endl;
    }
}