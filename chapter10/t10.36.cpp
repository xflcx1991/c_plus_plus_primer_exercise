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

#include <algorithm>
#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

int main()
{
    list<int> mlist = {1, 2, 0, 3, 4, 0, 5, 6, 0, 7};
    auto iter = std::find(mlist.crbegin(), mlist.crend(), 0);
    int count = std::distance(iter, mlist.crend());
    cout << "要找的元素在第 " << count << " 个位置上" << endl;

    return 0;
}