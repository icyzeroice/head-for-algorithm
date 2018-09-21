
#include <iostream>
using namespace std;
#include <string>
using std::string;

class Solution {
  private:

    string _s;
    int _sLen;
  
    string _p;
    int _pLen;
  
    bool _matchState(int pS, int pP);
  
  public:
    bool isMatch(string s, string p);
};

bool Solution::_matchState(int pS, int pP) {

  // 同时完成
  if (pS == _sLen && pP == _pLen)
    return true;

  // 匹配先结束
  if ((pS != _sLen && pP == _pLen) || (pS == _sLen && pP != _pLen))
    return false;

  if (_p[pP + 1] == '*') {

    // "c", "c" 或者 "c", "." 且 s 未结束
    if (_s[pS] == _p[pP] || (_p[pP] == '.' || pS != _pLen))
        // 匹配 1 次
      return _matchState(pS + 1, pP + 2)
        // 匹配 N 次
        || _matchState(pS + 1, pP)
        // 匹配 0 次
        || _matchState(pS, pP + 2);

    else
      // 当前不能匹配，看看后面字符能否匹配
      return _matchState(pS, pP + 2);
  }

  // "c", "." 或者 "c", "c"
  if (_p[pP] == '.' || (_s[pS] == _p[pP] || pS != _pLen))
    return _matchState(pS + 1, pP + 1);

  // 不相等
  return false;
}

bool Solution::isMatch(string s, string p) {
  _s = s;
  _p = p;
  _sLen = s.size();
  _pLen = p.size();

  if (s.size() == 0 || p.size() == 0)
    return false;

  return _matchState(0, 0);
}




int main(int argc, char const *argv[]) {
  string a = "missisiipi";
  string b = "mis*is*p*.";
  
  Solution s;

  cout << s.isMatch(a, b) << endl;

  return 0;
}
