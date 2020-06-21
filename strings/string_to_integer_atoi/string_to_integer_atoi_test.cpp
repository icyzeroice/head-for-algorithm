#include "./string_to_integer_atoi.cpp"


int main(int argc, char const *argv[])
{
    Solution s;

    cout << s.myAtoi("") << endl;
    cout << s.myAtoi("100000") << endl;
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("            -42") << endl;
    cout << s.myAtoi("            -42     ") << endl;
    cout << s.myAtoi("4193 with words") << endl;
    cout << s.myAtoi("-4193 with words") << endl;
    cout << s.myAtoi("words and 987") << endl;
    cout << s.myAtoi("-91283472332") << endl;
    cout << s.myAtoi("-2147483647") << endl;
    cout << s.myAtoi("-2147483648") << endl;
    cout << s.myAtoi("-2147483649") << endl;
    cout << s.myAtoi("2147483646") << endl;
    cout << s.myAtoi("2147483647") << endl;
    cout << s.myAtoi("2147483648") << endl;


    return 0;
}

// file ends here
