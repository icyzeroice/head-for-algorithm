# 桶排序（Bucket Sort）

### 原理简述

排序前根据待排序序列数字特征，按一定范围划分一定数量的 **桶**，每个桶有自己的范围，然后将待排序序列数字依次放入符合范围条件的桶内，再给每个桶内的数字单独排序，最后拆开桶，将数字按顺序排列好。

其中，桶排序最简单的一种划分 **桶** 的方式是，每个不同的数字为一个桶，这样，将数字放入桶内时只需记下相应数字有几个即可，最后按桶的顺序依次重复输出相应次数个数字即可完成排序。(此处有点类似基数排序)


### 特点

比较快速、简单，但是需要开辟较多空间作为桶，是典型的牺牲空间节约时间。


### JavaScript 实现

```js
'use strict';

(function () {

  /**
   * 
   * @param {Array} arr integer range 1 to ~
   * 
   */
  function bucketSort(arr) {
    let arr_ordered = [], arr_bucket = [];

    // create buckets
    for (let i of arr) {
      !arr_bucket[i] && (arr_bucket[i] = 0);
      arr_bucket[i]++;
    }
    
    for (let j in arr_bucket) {
      while(arr_bucket[j] > 0) {
        arr_ordered.push(j);
        arr_bucket[j]--;
      }
    }

    return arr_ordered;
  }

  Array.prototype.BucketSort = function () {
    return bucketSort(this);
  }

})()

console.log([23, 3, 7, 1, 2, 5].BucketSort());
```