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
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;

shared_ptr<vector<int>> generateVector();
shared_ptr<vector<int>> setValue(shared_ptr<vector<int>>);
void getValue(shared_ptr<vector<int>>);

int main()
{
    auto ptr = generateVector();
    getValue(setValue(ptr));
    //使用 valgrind 能看到即使没有手动delete也没有内存泄漏
    return 0;
}

shared_ptr<vector<int>> generateVector()
{
    auto p1 = std::make_shared<vector<int>>();
    return p1;
}

shared_ptr<vector<int>> setValue(shared_ptr<vector<int>> ptr)
{
    int temp = 0;
    while (cin >> temp)
    {
        ptr->push_back(temp);
    }
    return ptr;
}

void getValue(shared_ptr<vector<int>> ptr)
{
    cout << "=================================" << endl;
    for (auto item : *ptr)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "=================================" << endl;
}