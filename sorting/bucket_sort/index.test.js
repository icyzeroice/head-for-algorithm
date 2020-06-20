require('./index')

const list = [23, 3, 7, 1, 2, 5]

test('bucket sort', () => {
  expect(list.slice().BucketSort()).toEqual(list.slice().sort((a, b) => a - b))
})

// file ends here
