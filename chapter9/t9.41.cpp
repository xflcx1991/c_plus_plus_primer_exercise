#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<char> mvec = {
        'H', 'e', 'l', 'l', 'o',
    };

    string str(mvec.cbegin(), mvec.cend());
    cout << str << endl;

    return 0;
}