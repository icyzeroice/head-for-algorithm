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
console.timeEnd('init');

console.time('swop1');
let t = a1;
a1 = b1;
b1 = t;
console.timeEnd('swop1');

console.time('swop2');
a2 ^= b2;
b2 ^= a2;
a2 ^= b2;
console.timeEnd('swop2');

console.time('swop3');
a3 += b3;
b3 = a3 - b3;
a3 -= b3;
console.timeEnd('swop3');

console.time('swop4');
a4 = [b4, b4 = a4];
console.timeEnd('swop4');

console.time('swop5');
[a5, b5] = [b5, a5];
console.timeEnd('swop5');