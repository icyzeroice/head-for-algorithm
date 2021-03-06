#include<iostream>

// 无向图
class UndirectedGraph {

private:



public:

  /**
   * # 图的几种表示方法：
   * 
   * ### 邻接矩阵
   * 
   *   使用 V * V 的布尔矩阵
   *   *空间*: V * V
   *   *缺点*: 在图的顶点多时，所需空间太大
   * 
   * ### 边的数组
   * 
   *   *缺点*: 不能很快地实现度的计算
   * 
   * ### 邻接表数组
   * 
   *   *空间*: V + E
   *   每个顶点都有一个以相邻顶点为元素的数组
   *   
   *   例： 用 Bag 实现数组
   * 
   * ### 邻接集
   *  
   *   用符号表代替数组
   *   *优点*：这样就顶点就不用必须是整数型了
   * 
   * 
   */
  UndirectedGraph(int V);
  UndirectedGraph(char *c);
  ~UndirectedGraph();

  int V();                                       // get the amount of vertexes/vertices
  int E();                                       // get the amount of edges
  void addEdge(int v, int w);                    // add edge `v-w`
  int *adj(int v);                               // vertexes next to `v`
    
  static int degree(UndirectedGraph G, int v);
  static int maxDegree(UndirectedGraph G);
  static int minDegree(UndirectedGraph G);
  static int avgDegree(UndirectedGraph G);
  // 间隔的度数
  static int degreeBetween(UndirectedGraph G, int s, int v);

  static bool isMarked(UndirectedGraph G, int s, int v);   // `s` is connected with `v`
  static int countUnion(UndirectedGraph G, int s);         // amount of all the vertexes that are connected with `s`

  static int numOfSelfLoops(UndirectedGraph G);

  /**
   * # 图的查找
   * 
   * ### DFS (Deep First Search)
   * 
   *   时间复杂度： 所有顶点的度数之和
   * 
   * - 单向通道
   * - 使用 LIFO
   * 
   * ### BFS (Broad First Search)
   * 
   *   时间复杂度: 最坏 V + E 的正比
   * 
   *   - 使用 FIFO
   * 
   */
  static void dfs(UndirectedGraph G, int s);
  static void bfs(UndirectedGraph G, int s);

  void print();                                  // print via Adjacency List style
};


