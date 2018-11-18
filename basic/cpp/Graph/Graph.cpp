#include<iostream>

class Graph {

private:



public:
  Graph(int V);
  Graph(char *c);
  ~Graph();

  int V();                      // get the amount of vertexes/vertices
  int E();                      // get the amount of edges
  void addEdge(int v, int w);   // add edge `v-w`
  int *adj(int v);              // vertexes next to `v`
    
  static int degree(Graph G, int v);
  static int maxDegree(Graph G);
  static int minDegree(Graph G);
  static int avgDegree(Graph G);

  static int numOfSelfLoops(Graph G);

  void print();                 // print via Adjacency List style
};

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
 */


