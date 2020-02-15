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
#include <iterator>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
    vector<int> mvec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //两种思路
    //①找到第3个元素和第7个元素的迭代器
    //利用copy和front_inserter
    auto iterHead = mvec.cbegin() + (3 - 1); //指向第3个元素的迭代器
    auto iterTail = mvec.cbegin() + 7;       //指向第7个元素后一个元素的迭代器

    list<int> mlist;
    std::copy(iterHead, iterTail, std::front_inserter(mlist));
    for (auto item : mlist)
    {
        cout << item << endl;
    }
    cout << "================" << endl;
    //②拿到反向迭代器
    list<int> mlist2;
    vector<int>::const_reverse_iterator criterHead(iterTail);
    vector<int>::const_reverse_iterator criterTail(iterHead);
    //assign也可以起到先有list后拷贝进去的意思
    mlist2.assign(criterHead, criterTail);
    for (auto item : mlist2)
    {
        cout << item << endl;
    }
    cout << "================" << endl;

    //③拿到反向迭代器用拷贝构造函数
    list<int> mlist3(criterHead, criterTail);
    for (auto item : mlist3)
    {
        cout << item << endl;
    }
    cout << "================" << endl;
    //④拿到反向迭代器利用copy和back_inserter
    list<int> mlist4;
    std::copy(criterHead, criterTail, std::back_inserter(mlist4));
    for (auto item : mlist4)
    {
        cout << item << endl;
    }
    cout << "================" << endl;
    //结论，我更喜欢std::copy(iterHead, iterTail, std::front_inserter(mlist));
    //因为不用转反向迭代器，另外front_inserter可以简单理解为头插法，心智负担小

    return 0;
}