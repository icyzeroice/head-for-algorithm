# ABC (Aritfitial Bee Conoly, 人工蜂群)

### 背景

人工蜂群算法是一种群智能算法，Karaboga 于 2005 年提出。

### 原理

标准 ABC 算法模拟实际蜜蜂的采蜜机制，主要由以下几部分组成 [^1]：

```sequence
Title: 人工蜂群要素

组成要素：
  蜜源 (nectar) ->> 问题潜在解题目
  employed foragers ----->> 引领蜂 (Leader)   ->> 维持优良解
  unemployed foragers -+->> 跟随蜂 (Follower) ->> 提高收敛速度
                       |
                       +->> 侦察蜂 (Scouter)  ->> 增强摆脱局部最优解的能力

基本行为：
  招募 (recruit) 蜜蜂 ->>
  放弃 (abandon) 蜜源 ->>

特点：
  角色转换 ->>
```

|  |  |
| --- | --- |
| $$D$$ | 当前问题维度 |
| $$t$$ | 指示当前搜索迭代次数 |
| $$i$$ | 表示不同的蜜源，$$i=1,2,...,NP$$，即此时蜜源总数为 $$NP$$ |
| $$d$$ | $$d \in \lbrace 1,2,3,...,D \rbrace $$，表示当前搜索维度 |
| $$limit$$ | 局部搜索最大迭代次数 |
| $$X_i^t$$ | 指第 $$t$$ 次迭代蜜源 $$i$$ 坐标，这里 $$X_i^t=[x_{i1}^t \qquad x_{i2}^t \qquad x_{iD}^t]$$ |
| $$fit_i$$ | 对应解的适应度值 |
| $$U_d$$ | 蜜源空间下限 |
| $$L_d$$ | 蜜源空间上限 |
|  |  |

1 . 蜜源 $$i$$ 的初始位置为随机生成：

$$ x_{id} = L_d + rand(0,1)(U_d - L_d) \qquad (x_{id}^t \in (U_d, L_d) $$

2 . 搜索开始，Leader 在蜜源 $$x_{id}$$ 附近搜索产生一个新的蜜源：

$$v_{id} = x_{id} + rand(-1, 1) (x_{id} - x_{jd})$$

3 . 然后在这的蜜源附近进行搜索


### 示例

比如有 32 x 32 的二值图片（白色为 0，黑色为 1），要识别上面的字母 3，

首先将这张图片抽象成 1024 维的坐标，即每一个像素表示一个维度的数据，每个维度为


蜂巢 (beehive)





[^1]: https://www.researchgate.net/publication/280232074_rengongfengqunsuanfayanjiuzongshu_Artificial_bee_colony_algorithm_A_survey "秦全德, 程适, 李丽, 等. 人工蜂群算法研究综述[J]. 智能系统学报, 2014, 9(2) : 127-135."
