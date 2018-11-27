# 字符串

# 字符串的排序

### 键索引计数法

> 适用于小整数键的简单排序法

1. 频率统计

```
value  elem

a      2
v      3
g      3
x      3
222    1
b      1

```





```js
count[0] = 0
```

```js
count[elem + 1] += 1
```

2. 将频率转换为索引

```js
// 统计得               // 转换为索引开始的位置
count[]                index[]

elem 0 1 2 3 4    ->   0 1 2 3 4
     0 0 2 1 3         0 0 2 3 6
```


3. 数据分类

```js

  1   2 3
  |   | |
  V   V V
  0 1 2 3 4 5
  1 1 2 3 3 3
```


4. 回写

复制回原数组

### 低位优先的字符串排序（LSD）

从低位到高位依次作为键，使用键索引计数法，可以让这个 `LSD` 变成稳定排序。


### 高位优先的字符串排序（MSD）

- 使用 *递归* 的思想

- 在小数组时切换到 *插入排序*

- 大量 *等值键* 会使子数组的排序变慢


### 三向快速排序

- 优势：大量重复键



# Trie

### 单词查找树

### Ternay Search Tree（三向搜索树）


# 子字符串查找

### 暴力子字符串查找算法

### KMP 字符串查找算法（Knuth-Morris-Pratt）

模式指针的回退：

  使用 *确定有限状态机*（deterministic finite state machine）

```js
// 例：
pattern       A B A B A C

target_text   A B A B A B A C


 \            0 1 2 3 4 5
  \pattern    A B A B A C
dfa\

 A            1 1 3 1 5 1
 B            0 2 0 4 0 4
 C            0 0 0 0 0 6



// `i` 表示 当前匹配到 `target_text` 中的索引
// `j` 表示 当前匹配到 `pattern` 中的索引
// dfa[a][b] 得到的是下一个要用到的 `pattern` 中的索引，来和下一个 `target_text` 字母匹配
// pseudo-code（伪代码）：
dfa[target_text[i]][j].isEqualTo(target_text[i])
  ? (j = dfa[target_text[i]][j])
  : (j = dfa[target_text[i]][j])
```

那么如何构造一个 dfa 呢？

```js
// j 为 `pattern` 当前索引
// 1. 匹配成功
dfa[pattern[j]][j] = j + 1
// 2. 匹配失败
// 重新扫描 pattern，得到要回退到的索引位置
X = dfa[pattern[j][X]]
```

```js
// DFA generator
// 初始化第一个匹配到的字符
dfa[0][0] = 1

for (let X = 0, j = 1; j < M; j++) {

  // 1. 先将不匹配的情况复制到当前列
  for (let c = 0; c < R; c++) {
    dfa[c][j] = dfa[c][X]
  }

  // 2. 当前索引匹配的情况
  dfa[pat.j][j] = j + 1;

  // 3. 更新下一个 X
  X = dfa[pat.j][X]
}
```

### Boyer-Moore 字符串查找算法

首先用 `right[]` 来记录每个字符在 `pattern` 中最右的位置。

1. 当前字符匹配失败，但在 `pattern` 中有这个字符

```js
pattern[j] !== target_text[i] && pattern.include(target_text[i])
// `pattern` 相对于 `target_text` 向右移动 `right[target_text[i]] + pattern.length - j - 1`
```

2. 当前字符匹配实拍，且在 `pattern` 中没有这个字符

```js
pattern[j] !== target_text[i] && !pattern.include(target_text[i])
// `pattern` 相对于 `target_text` 向右移动 `pattern.length`
```

3. 当前字符匹配成功

```js
// 从 `pattern` 的最右边相应位置开始，看看相应字符是否能全部匹配
```


### Rabin-Karp 指纹字符串查找算法

> 基于散列的字符串查找算法。
