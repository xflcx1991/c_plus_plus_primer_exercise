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

//Ubuntu 16.04 gcc 5.4 版本下
//可以从结果中清楚地看到容量是按照翻倍的策略，具体结果见最下方。
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
     vector<int> ivec;
     cout << "刚开始：" << endl;
     cout << " ivec: size: " << ivec.size()
          << " capacity: " << ivec.capacity() << endl;
     for (vector<int>::size_type ix = 0; ix != 100; ++ix)
     {
          ivec.push_back(ix);
          cout << "添加第 " << ix + 1 << " 个" << endl;
          cout << " ivec: size: " << ivec.size()
               << " capacity: " << ivec.capacity() << endl;
     }

     cout << "最终：" << endl;
     cout << " ivec: size: " << ivec.size()
          << " capacity: " << ivec.capacity() << endl;
     return 0;
}
/*
刚开始：
 ivec: size: 0 capacity: 0
添加第 1 个
 ivec: size: 1 capacity: 1
添加第 2 个
 ivec: size: 2 capacity: 2
添加第 3 个
 ivec: size: 3 capacity: 4
添加第 4 个
 ivec: size: 4 capacity: 4
添加第 5 个
 ivec: size: 5 capacity: 8
添加第 6 个
 ivec: size: 6 capacity: 8
添加第 7 个
 ivec: size: 7 capacity: 8
添加第 8 个
 ivec: size: 8 capacity: 8
添加第 9 个
 ivec: size: 9 capacity: 16
添加第 10 个
 ivec: size: 10 capacity: 16
添加第 11 个
 ivec: size: 11 capacity: 16
添加第 12 个
 ivec: size: 12 capacity: 16
添加第 13 个
 ivec: size: 13 capacity: 16
添加第 14 个
 ivec: size: 14 capacity: 16
添加第 15 个
 ivec: size: 15 capacity: 16
添加第 16 个
 ivec: size: 16 capacity: 16
添加第 17 个
 ivec: size: 17 capacity: 32
添加第 18 个
 ivec: size: 18 capacity: 32
添加第 19 个
 ivec: size: 19 capacity: 32
添加第 20 个
 ivec: size: 20 capacity: 32
添加第 21 个
 ivec: size: 21 capacity: 32
添加第 22 个
 ivec: size: 22 capacity: 32
添加第 23 个
 ivec: size: 23 capacity: 32
添加第 24 个
 ivec: size: 24 capacity: 32
添加第 25 个
 ivec: size: 25 capacity: 32
添加第 26 个
 ivec: size: 26 capacity: 32
添加第 27 个
 ivec: size: 27 capacity: 32
添加第 28 个
 ivec: size: 28 capacity: 32
添加第 29 个
 ivec: size: 29 capacity: 32
添加第 30 个
 ivec: size: 30 capacity: 32
添加第 31 个
 ivec: size: 31 capacity: 32
添加第 32 个
 ivec: size: 32 capacity: 32
添加第 33 个
 ivec: size: 33 capacity: 64
添加第 34 个
 ivec: size: 34 capacity: 64
添加第 35 个
 ivec: size: 35 capacity: 64
添加第 36 个
 ivec: size: 36 capacity: 64
添加第 37 个
 ivec: size: 37 capacity: 64
添加第 38 个
 ivec: size: 38 capacity: 64
添加第 39 个
 ivec: size: 39 capacity: 64
添加第 40 个
 ivec: size: 40 capacity: 64
添加第 41 个
 ivec: size: 41 capacity: 64
添加第 42 个
 ivec: size: 42 capacity: 64
添加第 43 个
 ivec: size: 43 capacity: 64
添加第 44 个
 ivec: size: 44 capacity: 64
添加第 45 个
 ivec: size: 45 capacity: 64
添加第 46 个
 ivec: size: 46 capacity: 64
添加第 47 个
 ivec: size: 47 capacity: 64
添加第 48 个
 ivec: size: 48 capacity: 64
添加第 49 个
 ivec: size: 49 capacity: 64
添加第 50 个
 ivec: size: 50 capacity: 64
添加第 51 个
 ivec: size: 51 capacity: 64
添加第 52 个
 ivec: size: 52 capacity: 64
添加第 53 个
 ivec: size: 53 capacity: 64
添加第 54 个
 ivec: size: 54 capacity: 64
添加第 55 个
 ivec: size: 55 capacity: 64
添加第 56 个
 ivec: size: 56 capacity: 64
添加第 57 个
 ivec: size: 57 capacity: 64
添加第 58 个
 ivec: size: 58 capacity: 64
添加第 59 个
 ivec: size: 59 capacity: 64
添加第 60 个
 ivec: size: 60 capacity: 64
添加第 61 个
 ivec: size: 61 capacity: 64
添加第 62 个
 ivec: size: 62 capacity: 64
添加第 63 个
 ivec: size: 63 capacity: 64
添加第 64 个
 ivec: size: 64 capacity: 64
添加第 65 个
 ivec: size: 65 capacity: 128
添加第 66 个
 ivec: size: 66 capacity: 128
添加第 67 个
 ivec: size: 67 capacity: 128
添加第 68 个
 ivec: size: 68 capacity: 128
添加第 69 个
 ivec: size: 69 capacity: 128
添加第 70 个
 ivec: size: 70 capacity: 128
添加第 71 个
 ivec: size: 71 capacity: 128
添加第 72 个
 ivec: size: 72 capacity: 128
添加第 73 个
 ivec: size: 73 capacity: 128
添加第 74 个
 ivec: size: 74 capacity: 128
添加第 75 个
 ivec: size: 75 capacity: 128
添加第 76 个
 ivec: size: 76 capacity: 128
添加第 77 个
 ivec: size: 77 capacity: 128
添加第 78 个
 ivec: size: 78 capacity: 128
添加第 79 个
 ivec: size: 79 capacity: 128
添加第 80 个
 ivec: size: 80 capacity: 128
添加第 81 个
 ivec: size: 81 capacity: 128
添加第 82 个
 ivec: size: 82 capacity: 128
添加第 83 个
 ivec: size: 83 capacity: 128
添加第 84 个
 ivec: size: 84 capacity: 128
添加第 85 个
 ivec: size: 85 capacity: 128
添加第 86 个
 ivec: size: 86 capacity: 128
添加第 87 个
 ivec: size: 87 capacity: 128
添加第 88 个
 ivec: size: 88 capacity: 128
添加第 89 个
 ivec: size: 89 capacity: 128
添加第 90 个
 ivec: size: 90 capacity: 128
添加第 91 个
 ivec: size: 91 capacity: 128
添加第 92 个
 ivec: size: 92 capacity: 128
添加第 93 个
 ivec: size: 93 capacity: 128
添加第 94 个
 ivec: size: 94 capacity: 128
添加第 95 个
 ivec: size: 95 capacity: 128
添加第 96 个
 ivec: size: 96 capacity: 128
添加第 97 个
 ivec: size: 97 capacity: 128
添加第 98 个
 ivec: size: 98 capacity: 128
添加第 99 个
 ivec: size: 99 capacity: 128
添加第 100 个
 ivec: size: 100 capacity: 128
最终：
 ivec: size: 100 capacity: 128
*/