# 排序

### 冒泡排序 (Bubble Sort)

冒泡排序[^1] 就是对长度为 N 的数组遍历 N-1 次，然后每遍历一个元素都会与其相邻的元素比较，不符合排序关系的会进行交换，直到最后数组排序完成。因为这种排序会使大元素或小元素一点点往两端靠拢，有点像水中的气泡往上冒，故叫冒泡排序。

```js
'use strict';

Array.prototype.BubbleSort = function (isReverse = false) {

  console.time('bubble sort');
  let _arrayList = this,
      isPrematureEnd = true;

  /**
   * @description --swop the value of the two variable
   */
  function swopBetween(x, y, arraySpace) {
    return [arraySpace[x], arraySpace[y]] = [arraySpace[y], arraySpace[x]];
  }

  /**
   * @description --normal order
   * @param {number[]} _arrayList --target array
   * @return {number[]} --ordered array
   */
  function bubble(_arrayList) {
    for (let i = 0; i < _arrayList.length - 1; i++) {
      for (let j = 0; j < _arrayList.length - i; ++j) {
        if (_arrayList[j - 1] > _arrayList[j]) {
          swopBetween(j - 1, j, _arrayList);
          isPrematureEnd = false;
        }
      }
      if (isPrematureEnd) break;
      isPrematureEnd = true;
    }
    return _arrayList;
  }

  /**
   * @description --reverse order
   * @param {number[]} _arrayList --target array
   * @return {number[]} --reverse ordered array
   */
  function reverseBubble(_arrayList) {
    for (let i = 0; i < _arrayList.length; ++i) {
      isPrematureEnd = true;
      for (let j = _arrayList.length - i; j > 0; j--) {
        if (_arrayList[j - 1] < _arrayList[j]) {
          swopBetween(j - 1, j, _arrayList);
          isPrematureEnd = false;
        }
      }
      if (isPrematureEnd) break;
    }
    return _arrayList;
  }

  // choose bubble sorting effect
  if (!isReverse) {
    bubble(_arrayList);
  } else {
    reverseBubble(_arrayList);
  }

  console.timeEnd('bubble sort');
  return _arrayList;
};

// test bubble sorting
console.log([23, 3, 7, 1, 2, 5, ].BubbleSort());
console.log([23, 3, 4, 1, 2].BubbleSort(true));
```

### 插入排序 (Insert Sort)

### 快速排序 (Quick Sort)

### Reference
[^1]: http://gaunthan.leanote.com/post/冒泡排序 "冒泡排序"
