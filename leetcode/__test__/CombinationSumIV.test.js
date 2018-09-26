const { combinationSum4, combinationSum4_betterSolution } = require('../CombinationSumIV')

test(`Test CombinationSumIV`, () => {
  expect(combinationSum4([1, 2, 3], 4)).toBe(7)
  expect(combinationSum4([1, 2, 3, 4], 4)).toBe(8)
  expect(combinationSum4([3, 33, 333], 10000)).toBe(0)
})

test(`Test CombinationSumIV Better Solution`, () => {
  expect(combinationSum4_betterSolution([1, 2, 3], 4)).toBe(7)
  expect(combinationSum4_betterSolution([1, 2, 3, 4], 4)).toBe(8)
  expect(combinationSum4_betterSolution([3, 33, 333], 10000)).toBe(0)
})