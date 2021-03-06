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
#include <vector>

using std::cout;
using std::endl;
using std::vector;

using funcP1 = int(*)(int,int);
//OR
typedef int (*funcP2)(int,int);
int main()
{
    vector<funcP1> myvector1();
    vector<funcP2> myvector2();
    cout << "It works" << endl;
    return 0;
}
