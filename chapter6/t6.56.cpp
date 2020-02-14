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

int myAdd(int,int);
int myMinus(int,int);
int myMultiply(int,int);
int myDivide(int,int);

using funcP1 = int(*)(int,int);

int main()
{
    vector<funcP1> myvector1 = {myAdd, myMinus, myMultiply, myDivide};
    for(auto fp : myvector1)
    {
        cout << fp(1,22) << endl;
    }
    return 0;
}

int myAdd(int argv1,int argv2)
{
    return argv1 + argv2;    
}
int myMinus(int argv1,int argv2)
{
    return argv1 - argv2;  
}
int myMultiply(int argv1,int argv2)
{
    return argv1 * argv2;
}
int myDivide(int argv1,int argv2)
{
    return argv1 / argv2;  
}