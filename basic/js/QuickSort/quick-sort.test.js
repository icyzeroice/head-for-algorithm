const quickSort = require('./quick-sort')

test('Test Canary', () => {
  expect([1]).toEqual([1])
})

test('Test Quick Sort', () => {
  expect(quickSort([])).toEqual([])
  expect(quickSort([1])).toEqual([1])
  expect(quickSort([6, 3, 4, 1, 9])).toEqual([1, 3, 4, 6, 9])
})