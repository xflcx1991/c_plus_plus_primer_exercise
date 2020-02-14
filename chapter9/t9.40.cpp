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

/**
 * Ubuntu 16.04 gcc 5.4 版本下
 * 容量增长策略是翻倍
 * 猜想：
 * 这样，读入256个词时，resize后元素个数是256+128=348，没有超过容量（1024），不会重新分配内存，capacity保持1024
 * 512:512+256=768，capacity=1024
 * 1000:1000+500=1500,1024不够，翻倍后2048，足够存1500，最后capacity=2048
 * 1048:1048+524=1572,1024不够，翻倍后2048，足够存1572，最后capacity=2048
 * 下面是程序验证
 * 256:capacity=1024
 * 512:capacity=1024
 * 1000:capacity=2000，通过resize扩容并没有按照翻倍增长
 * 1048:capacity=2048,通过push_back扩容是翻倍
*/
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

#define MAXWORDNUM 1048 // 512,1000,1048，分别替换测试
#define WORD "apple"

int main()
{
    vector<string> mvec;
    mvec.reserve(1024);
    for (int i = 0; i < MAXWORDNUM; ++i)
    {
        mvec.push_back(WORD);
        cout << " mvec: size: " << mvec.size()
             << " capacity: " << mvec.capacity() << endl;
    }
    mvec.resize(mvec.size() + mvec.size() / 2);
    cout << "after resize()" << endl;
    cout << " mvec: size: " << mvec.size()
         << " capacity: " << mvec.capacity() << endl;
    return 0;
}