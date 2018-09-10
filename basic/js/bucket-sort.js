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

console.log([23, 3, 7, 1, 2, 5].BucketSort())