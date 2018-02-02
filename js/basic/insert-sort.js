'use strict';

function insertSort(_arrayList) {

  for (let unorderedIndex = 1; unorderedIndex < _arrayList.length; unorderedIndex++) {
    for (let orderedIndex = unorderedIndex - 1; orderedIndex >= 0 ; orderedIndex--) {
      console.log(_arrayList[orderedIndex], _arrayList[unorderedIndex], '\n', _arrayList);
      // here
      // <= : stable
      // <  : unstable
      if (_arrayList[orderedIndex] <= _arrayList[unorderedIndex]) {
        _arrayList.splice(orderedIndex, 0, _arrayList[unorderedIndex]);
        _arrayList.splice(orderedIndex + 1, 1);

        // optimize
        break;
      }
    }
  }

  return _arrayList;
}

function insertSortReverse(_arrayList) {

  for (let unorderedIndex = 1; unorderedIndex < _arrayList.length; unorderedIndex++) {
    for (let orderedIndex = unorderedIndex - 1; orderedIndex >= 0 ; orderedIndex--) {

      // here
      // >= : stable
      // >  : unstable
      if (_arrayList[orderedIndex] >= _arrayList[unorderedIndex]) {
        _arrayList.splice(orderedIndex, 0, _arrayList[unorderedIndex]);
        _arrayList.splice(unorderedIndex + 1, 1);
      }
    }
  }

  return _arrayList;
}

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

// test
console.log([23, 3, 7, 1, 2, 5, ].InsertSort());
console.log([23, 3, 4, 1, 2].InsertSort(true));