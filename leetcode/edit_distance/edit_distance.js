// https://leetcode-cn.com/problems/edit-distance/description/
/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */
function minDistance(source, target) {

  if (source === target) {
    return 0
  }

  const ACTION = {
    
    // 删除
    DELETION: 1,
    
    // 插入
    INSERTION: 1,
    
    // 替换
    REPLACEMENT: 1,
  }

  const SOURCE_LEN = source.length
  const TARGET_LEN = target.length

  if (!SOURCE_LEN) {
    return TARGET_LEN * ACTION.INSERTION
  }

  if (!TARGET_LEN) {
    return SOURCE_LEN * ACTION.DELETION
  }

  /**
   * source \ target | t[0] | t[1] | ...
   *      s[0]       |  0   |  1   | ...
   *      s[1]       |  1   |
   *      ...        |  ... |
   */
  let _matrix = []
  for (let i = 0; i <= TARGET_LEN; i++) {
    _matrix[i] = []
    _matrix[i][0] = i
  }
  for (let i = 0; i <= SOURCE_LEN; i++) {
    _matrix[0][i] = i
  }

  for (let sourceIndex = 1; sourceIndex <= SOURCE_LEN; sourceIndex++) {
    for (let targetIndex = 1; targetIndex <= TARGET_LEN; targetIndex++) {
      
      if (source[sourceIndex - 1] === target[targetIndex - 1]) {
        _matrix[targetIndex][sourceIndex] = _matrix[targetIndex - 1][sourceIndex - 1]
      }

      else {
        _matrix[targetIndex][sourceIndex] = Math.min(
          // 左
          _matrix[targetIndex - 1][sourceIndex] + ACTION.DELETION,
          // 上
          _matrix[targetIndex][sourceIndex - 1] + ACTION.INSERTION,
          // 左上
          _matrix[targetIndex - 1][sourceIndex - 1] + ACTION.REPLACEMENT,
        )
      }
    }
  }

  return _matrix[TARGET_LEN][SOURCE_LEN]
};

console.log(minDistance('horse', 'ros'))