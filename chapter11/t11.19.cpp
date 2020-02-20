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

//在t11.11基础上添加
#include "../chapter7/t7.41.h"
#include <set>

using std::multiset;

bool compareIsbn(const Sales_data &lsd, const Sales_data &rsd)
{
    return lsd.isbn() < rsd.isbn();
}

int main()
{
    multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);
    //不用decltype
    multiset<Sales_data, bool (*)(const Sales_data &lsd, const Sales_data &rsd)> bookstore1(compareIsbn);

    auto iter = bookstore1.begin();
    //这是本题答案
    multiset<Sales_data, bool (*)(const Sales_data &lsd, const Sales_data &rsd)>::iterator iter1 = bookstore1.begin();

    return 0;
}