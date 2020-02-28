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
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

int main()
{
    unique_ptr<int> p1(new int(42));
    cout << *p1 << endl;
    int *nump = new int(41); //这里有内存泄漏，无所谓了
    // p1 = nump; //no match for ‘operator=’ (operand types are ‘std::unique_ptr<int>’ and ‘int*’) 这个好理解
    // unique_ptr<int> p2 = p1; // use of deleted function 也好理解
    // unique_ptr<int> p2(p1); //use of deleted function 和上面的具体delete函数是一样的，编译器优化?

    return 0;
}