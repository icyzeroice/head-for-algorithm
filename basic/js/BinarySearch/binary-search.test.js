const binarySearch = require('./binary-search')

test('Test Canary', () => {
  expect(1).toBe(1)
})

test('Test Quick Sort', () => {
  expect(binarySearch([], 1)).toBe(-1)
  expect(binarySearch([1], 2)).toBe(-1)
  expect(binarySearch([1, 3, 5, 6, 7], 3)).toBe(1)
})