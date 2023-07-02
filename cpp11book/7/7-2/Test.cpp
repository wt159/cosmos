#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{
    string str = "D:\A\B\test.text";
    cout << str << endl;
    string str1 = "D:\\A\\B\\test.text";
    cout << str1 << endl;
    string str2 = R"(D:\A\B\test.text)";
    cout << str2 << endl;

    string s =
        R"(<HTML>
<HEAD>
<TITLE>This is a test</TITLE>
</HEAD>
<BODY>
<P>Hello, C++ HTML World!</P>
</BODY>
</HTML>
)";
    cout << s << endl;

    // error test没有出现在反括号后面
    // string str3 = R"test(D:\A\B\test.text)";
    // error，反括号后面的字符串和括号前面的字符串不匹配
    // string str4 = R"test(D:\A\B\test.text)testaa";
    string str5 = R"test(D:\A\B\test.text)test"; // ok
    cout << str5 << endl; // 将输出D:\A\B\test.text，括号前后的字符串被忽略
    return 0;
}
