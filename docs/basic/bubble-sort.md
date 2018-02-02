# 冒泡排序 (Bubble Sort)

### 原理简述

冒泡排序[^1] 就是对长度为 N 的数组遍历 N-1 次，然后每遍历一个元素都会与其相邻的元素比较，不符合排序关系的会进行交换，直到最后数组排序完成。因为这种排序会使大元素或小元素一点点往两端靠拢，有点像水中的气泡往上冒，故叫冒泡排序。

### 复杂度
| 待排列序列 | 复杂度 |
|--|--|
| 已经有序（理想，且有 flag 标识）| $$ O(n) $$ |
| 倒序（最糟糕） | $$ O(n^2) $$ |

### 稳定性

可以稳定，可以不稳定，看具体实现。

### JavaScript 示例代码

交换两个数的方法：
```js
/**
 * @description --swop the value of the two variable
 */
function swopBetween(x, y, arraySpace) {
  return [arraySpace[x], arraySpace[y]] = [arraySpace[y], arraySpace[x]];
}
```
按从小到大的顺序排列的方法：
```js
/**
 * @description --normal order
 * @param {number[]} _arrayList --target array
 * @return {number[]} --ordered array
 */
function bubble(_arrayList, isPrematureEnd) {
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
```
安从大到小的顺序排列的方法
```js
/**
 * @description --reverse order
 * @param {number[]} _arrayList --target array
 * @return {number[]} --reverse ordered array
 */
function reverseBubble(_arrayList, isPrematureEnd) {
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
```
给内置对象 Array 添加冒泡排序的方法
```js
Array.prototype.BubbleSort = function (isReverse = false) {
  
  console.time('bubble sort');
  let isPrematureEnd = true;

  // choose bubble sorting effect
  if (!isReverse) {
    bubble(this, isPrematureEnd);
  } else {
    reverseBubble(this, isPrematureEnd);
  }

  console.timeEnd('bubble sort');
  return this;
};
```

```js
// test bubble sorting
console.log([23, 3, 7, 1, 2, 5, ].BubbleSort()); // [ 1, 2, 3, 5, 7, 23 ]
console.log([23, 3, 4, 1, 2].BubbleSort(true));  // [ 23, 4, 3, 2, 1 ]
```

### Reference
[^1]: http://gaunthan.leanote.com/post/冒泡排序 "冒泡排序"
