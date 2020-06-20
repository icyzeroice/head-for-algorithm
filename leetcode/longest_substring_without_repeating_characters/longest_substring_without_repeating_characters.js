/**
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  
  var len = s.length,
      maxSubLen = len ? 1 : 0,
      subLen = 1,
      pointerIndex = 1, startIndex = 0, currentIndex = 0;

  for (; pointerIndex < len; pointerIndex++) {
    for (currentIndex = startIndex; currentIndex < pointerIndex; currentIndex++) {

      if (s.charAt(currentIndex) !== s.charAt(pointerIndex) && currentIndex === pointerIndex - 1) {
        subLen++;
      } else if (s.charAt(currentIndex) === s.charAt(pointerIndex)) {
        subLen = pointerIndex - currentIndex;
        startIndex = currentIndex + 1;
        break;
      }
    }

    if (subLen > maxSubLen) {
      maxSubLen = subLen;
    }
  }

  return maxSubLen;
};

console.log(lengthOfLongestSubstring('ajsafljjjj'));