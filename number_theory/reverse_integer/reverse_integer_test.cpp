#include <iostream>
#include "./reverse_integer.cpp"


int main(int argc, char const *argv[]) {
    Solution s;

    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(120) << std::endl;
    std::cout << s.reverse(-120) << std::endl;
    std::cout << s.reverse(-120000) << std::endl;
    std::cout << s.reverse(120000) << std::endl;
    std::cout << s.reverse(12001200) << std::endl;
    std::cout << s.reverse(-12001200) << std::endl;
    std::cout << s.reverse(-2147483648) << std::endl;
    std::cout << s.reverse(INT32_MIN - 1) << std::endl;
    std::cout << s.reverse(INT32_MAX + 1) << std::endl;
    std::cout << s.reverse(INT32_MIN) << std::endl;
    std::cout << s.reverse(INT32_MAX) << std::endl;
    std::cout << s.reverse(7463847412) << std::endl;
    std::cout << s.reverse(-8463847412) << std::endl;

    return 0;
}


// file ends here

