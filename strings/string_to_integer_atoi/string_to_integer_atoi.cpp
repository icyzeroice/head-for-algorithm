/**
 * https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

#include <iostream>
using namespace std;


const int INT32_HEAD = 214748364;
const int INT32_MAX_TAIL = 7;
const int INT32_MIN_TAIL = 8;

const int CHAR_OFFSET_BLANK = ' ' - '0';
const int CHAR_OFFSET_PLUS = '+' - '0';
const int CHAR_OFFSET_MINUS = '-' - '0';


class Solution {
public:
    int fsm(string str);
    int myAtoi(string str);
};

int Solution::fsm(string str) {
    return 0;
}

int Solution::myAtoi(string str) {
    int len = str.size();

    if (!len) {
        return 0;
    }

    int result = 0;
    bool isNegative = false;
    bool isStart = false;

    for (int i = 0; i < len; ++i) {
        int c = str[i] - '0';

        if (c == CHAR_OFFSET_BLANK && !isStart) {
            continue;
        }

        if (c == CHAR_OFFSET_PLUS || c == CHAR_OFFSET_MINUS) {
            if (isStart) {
                break;
            } else {
                isStart = true;
                isNegative = c == CHAR_OFFSET_MINUS;
                continue;
            }
        }

        if (!isStart) isStart = true;

        if (c >= 0 && c <= 9) {
            if ((result > INT32_HEAD)
                || (result == INT32_HEAD && ((c > INT32_MAX_TAIL && !isNegative) || (c > INT32_MIN_TAIL && isNegative)))) {
                return isNegative ? INT32_MIN : INT32_MAX;
            }

            result = result * 10 + c;
            continue;
        }

        break;
    }

    return result * (isNegative ? -1 : 1);
}

// file ends here
