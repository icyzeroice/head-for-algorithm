const int INT32_HEAD = 214748364;
const int INT32_MAX_TAIL = 7;
const int INT32_MIN_TAIL = 8;


class Solution {
public:
    bool safe_number(int &quotient, int remainder, int symbol);
    int reverse(int x);
};


bool Solution::safe_number(int &quotient, int remainder, int symbol) {
    if (quotient > INT32_HEAD) {
        return false;
    }

    if ( quotient == INT32_HEAD
         && remainder > INT32_MAX_TAIL
         && symbol > 0 ) {

        return false;
    }

    if ( quotient == INT32_HEAD
         && remainder > INT32_MIN_TAIL
         && symbol < 0 ) {
        return false;
    }

    quotient = quotient * 10 + remainder;

    return true;
}


int Solution::reverse(int x) {
    // INT32_MIN * -1 > INT32_MAX
    if (x == 0 || x == INT32_MIN) {
        return 0;
    }

    const int symbol = x < 0 ? -1 : 1;
    const int step = 10;
    int result = 0;
    int abs_x = x * symbol;

    while (abs_x > 0) {
        int remainder = abs_x % step;
        abs_x = (abs_x - remainder) / step;

        if (!safe_number(result, remainder, symbol)) {
            return 0;
        }
    }

    return result * symbol;
}


// file ends here

