function swapTwo(arr, i, j) {
  [arr[i], arr[j]] = [arr[j], arr[i]]
}

function quickPartition(arr, startIndex, endIndex) {

  let base = arr[startIndex]
  let pHead = startIndex
  let pEnd = endIndex + 1

  while (true) {
    while (arr[++pHead] <= base) {
      if (pHead >= endIndex) break
    }

    while (arr[--pEnd] >= base) {
      if (startIndex >= pEnd) break
    }

    if (pHead < pEnd) {
      swapTwo(arr, pHead, pEnd)
    } else {
      break
    }
  }

  // 此时 arr[pEnd] 会比 base 小
  if (startIndex !== pEnd) swapTwo(arr, startIndex, pEnd)

  return pEnd
}

function quickSort(arr) {
  
  if (arr.length < 2) return arr

  let pHead = typeof arguments[1] === 'number' ? arguments[1] : 0
  let pEnd = typeof arguments[2] === 'number' ? arguments[2] : (arr.length - 1)

  // 如果子数组长度为 1，不用继续排列
  if (pHead >= pEnd) return arr
  
  let mid = quickPartition(arr, pHead, pEnd)

  quickSort(arr, pHead, mid - 1)
  quickSort(arr, mid + 1, pEnd)

  return arr
}

module.exports = quickSort
