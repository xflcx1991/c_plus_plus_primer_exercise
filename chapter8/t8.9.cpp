#include <sstream>
#include <string>
#include <iostream>

using std::string;
using std::istringstream;
using std::cout;
using std::endl;

std::istream& readDataFromStream(std::istream& is);

int main()
{
    string line = "abc 123 字符串测试";
    istringstream iss(line); 
    readDataFromStream(iss);
    
    return 0;
}