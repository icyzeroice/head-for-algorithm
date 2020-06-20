// https://leetcode-cn.com/problems/combination-sum-iv/description/
/**
 * 如果简单地用回溯法，遇到负数可能会有路径不能终止，如一直 +1-1+1-1...
 * 
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function combinationSum4(nums, target) {

  // 不存储这个结果前：不知道多长时间，而且也没报 RangeError
  // 使用空间 O(N) 后，秒出 10e26 级别的结果
  const memory = [0]
  return testCombination(nums, target, memory, true)
}

/**
 * 
 * @param {Array<Number>} nums 
 * @param {Number} target
 * @param {Array<Number>} memory 
 * @param {Boolean} isFirstTime
 */
function testCombination(nums, target, memory, isFirstTime) {

  if (target === 0 && !isFirstTime) {
    return 1
  }

  else if (target < 0) {
    return 0
  }

  else if (memory[target] !== undefined) {
    return memory[target]
  }

  let sum = 0

  for (let i = 0; i < nums.length; i++) {
    sum += testCombination(nums, target - nums[i], memory, false)
  }

  memory[target] = sum
  
  return sum
}

function combinationSum4_betterSolution(nums, target) {
  const memory = new Array(target + 1).fill(0)

  memory[0] = 1
  
  for (let i = 1; i <= target; i++) {
    for (let j = 0; j < nums.length; j++) {
      if (i >= nums[j]) memory[i] += memory[i - nums[j]]
    }
  }

  return memory[target]
}

module.exports = {
  combinationSum4,
  combinationSum4_betterSolution
}