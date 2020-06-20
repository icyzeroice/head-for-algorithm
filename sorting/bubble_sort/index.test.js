require('./index')

// test bubble sorting
test(`Test Bubble Sort`, () => {
  expect([23, 3, 7, 1, 2, 5].BubbleSort()).toEqual([1, 2, 3, 5, 7, 23])
})


test(`Test Bubble Sort Reverse`, () => {
  expect([23, 3, 4, 1, 2, 5].BubbleSort(true)).toEqual([23, 5, 4, 3, 2, 1])
})
