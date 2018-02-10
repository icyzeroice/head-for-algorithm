# 插入排序 (Insert Sort)

### 原理简述

插入排序[^1] 先从数组 0 位开始，将其当做已排有序序列，然后将其之后剩余项 $${B_n}$$ 一个一个地与已排有序序列 $${A_n}$$ 中从后往前的每一项挨个比较（根据不同的语言特性，可能具体实现会有不同，如 C 语言等，比较发现 $$A_n$$ 比此剩余项 $$B_n$$ 大，就可以提前将 $$A_n$$ 往后移一格，较为高效），如果比较到某一有序项 $$A_n$$ 小于等于此剩余项，此剩余项 $$B_n$$ 就移到那个 $$A_n$$ 之后

```
  1     3     2     0
  ^-----^     ^     ^
  已排 {An}   待比较 Bn
```
2 先与 3 比较（或者先与 1 比较），发现比 3 小，就接着往前与 1 比较，发现比 2 大，于是便插到 1 之后
```
  1     2     3     0
  ^-----------^     ^
   已排的新 {An}     待比较 Bn
```

### 复杂度

|  |  |
|--|--|
| 最坏时间复杂度 | $$O(n^2)$$ |
| 最优时间复杂度 | $$O(n)$$ |
| 空间复杂度 | 总共 $$O(n)$$，需要辅助空间 $$O(1)$$ |

### 稳定性

可以稳定，可以不稳定，看具体实现。

### JavaScript 示例代码

从小到大排列，这里我们使用从前往后比较。
```js
function insertSort(_arrayList) {
  for (let unorderedIndex = 1; unorderedIndex < _arrayList.length; unorderedIndex++) {
    for (let orderedIndex = 0; orderedIndex < unorderedIndex ; orderedIndex++) {

      // 对下一行 if 代码：
      // > : 这里如果使用 > 进行比较，则是 稳定排序
      // >=  : 如果使用 >= 进行比较，则已排序和未排序序列在相等时也会进行交换，即变成 不稳定排序
      if (_arrayList[orderedIndex] > _arrayList[unorderedIndex]) {
        _arrayList.splice(orderedIndex, 0, _arrayList[unorderedIndex]);
        _arrayList.splice(unorderedIndex + 1, 1);
      }
    }
  }

  return _arrayList;
}
```
从大到小排列，我们这里采用从后往前比较。
```js
function insertSortReverse(_arrayList) {
  for (let unorderedIndex = 1; unorderedIndex < _arrayList.length; unorderedIndex++) {
    for (let orderedIndex = unorderedIndex - 1; orderedIndex >= 0 ; orderedIndex--) {
      
      // 同上
      // < : 稳定排序
      // <=  : 不稳定排序
      if (_arrayList[orderedIndex] < _arrayList[unorderedIndex]) {
        _arrayList.splice(orderedIndex, 0, _arrayList[unorderedIndex]);
        _arrayList.splice(unorderedIndex + 1, 1);
      }
    }
  }

  return _arrayList;
}
```

```js
Array.prototype.InsertSort = function (isReverse = false) {
  console.time('insert sort');
  let _arrayList = this;

  if (isReverse) {
    insertSortReverse(this);
  } else {
    insertSort(this);
  }

  console.timeEnd('insert sort');
  return _arrayList;
}
```

```js
// test under node v8.9.4, Core i7-6700
console.log([23, 3, 7, 1, 2, 5].InsertSort());        // about 0.104ms
console.log([23, 3, 4, 1, 2, 5].InsertSort(true));    // about 0.071ms
```

### Reference
[^1]: https://zh.wikipedia.org/wiki/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F "插入排序"