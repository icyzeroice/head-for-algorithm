console.time('init');
let a1 = 1,
    b1 = 2,
    a2 = 1,
    b2 = 2,
    a3 = 1,
    b3 = 2,
    a4 = 1,
    b4 = 2,
    a5 = 1,
    b5 = 2;
console.timeEnd('init'); // about 0.060ms

console.time('swop1');
let t = a1;
a1 = b1;
b1 = t;
console.timeEnd('swop1'); // about 0.020ms

console.time('swop2');
a2 ^= b2;
b2 ^= a2;
a2 ^= b2;
console.timeEnd('swop2'); // about 0.007ms, number only

console.time('swop3');
a3 += b3;
b3 = a3 - b3;
a3 -= b3;
console.timeEnd('swop3'); // about 0.003ms fastest, but can be used between numbers only

console.time('swop4');
a4 = [b4, b4 = a4];
console.timeEnd('swop4'); // about 0.020ms

console.time('swop5');
[a5, b5] = [b5, a5];
console.timeEnd('swop5'); // about 0.015ms