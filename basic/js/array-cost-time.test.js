const ARRAY_LENGTH = 10000

console.time(`declare 1 for testing array cost time`)
const arr1 = new Array(ARRAY_LENGTH).fill(0)
console.timeEnd(`declare 1 for testing array cost time`)


console.time(`declare 2 for testing array cost time`)
const arr2 = [0]
arr2[1] = 0
arr2[10] = 0
arr2[100] = 0
arr2[1000] = 0
arr2[11] = 0
arr2[111] = 0
arr2[1111] = 0
arr2[12] = 0
arr2[122] = 0
arr2[1222] = 0
arr2[ARRAY_LENGTH - 1] = 0
console.timeEnd(`declare 2 for testing array cost time`)


console.time(`declare 2 for testing array cost time`)
const arr3 = [0]
let index = ARRAY_LENGTH - 1
while (index--) {
  arr3[index] = 0
}
console.timeEnd(`declare 2 for testing array cost time`)