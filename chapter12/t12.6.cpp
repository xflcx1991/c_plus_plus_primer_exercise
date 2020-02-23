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
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> *generateVector();
vector<int> *setValue(vector<int> *);
void getValue(vector<int> *);

int main()
{
    vector<int> *ptr = generateVector();
    getValue(setValue(ptr));

    delete ptr;
    ptr = nullptr;
    return 0;
}

vector<int> *generateVector()
{
    return new vector<int>();
}

vector<int> *setValue(vector<int> *ptr)
{
    int temp = 0;
    while (cin >> temp)
    {
        ptr->push_back(temp);
    }
    return ptr;
}

void getValue(vector<int> *ptr)
{
    cout << "=================================" << endl;
    for (auto item : *ptr)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "=================================" << endl;
}