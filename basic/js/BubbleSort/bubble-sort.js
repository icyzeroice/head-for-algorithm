'use strict';

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

// test bubble sorting
console.log([23, 3, 7, 1, 2, 5].BubbleSort());
console.log([23, 3, 4, 1, 2, 5].BubbleSort(true));
