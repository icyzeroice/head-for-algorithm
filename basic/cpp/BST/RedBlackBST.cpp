#include<iostream>

#include "../lib/Key.cpp"
#include "../lib/Value.cpp"
#include "RedBlackBSTNode.cpp"

class RedBlackBST {

private:
  // properties
  Node *_root;
  int _size;

  // methods
  Node *_rotateLeft(Node *);
  Node *_rotateRight(Node *);
  void _flipColors(Node *);
  
  void _transplant(Node *, Node *);

  // for safe
  bool _isRed(Node *);
  int _getSize(Node *);

public:
  RedBlackBST();
  RedBlackBST(Key *, Value *, int);

  Node get();

  Node *put(Key, Value);
  Node *put(Node *, Key, Value, Node *);

  Value del(Key);
  Value del(Key, Node *);
  Value performDeletion(Node *);

  // int size();
  // Node select();
  // Node rank();
  // Node floor();
  // Node ceiling();
  // Node max();
  // Node min();
  // Node range();

  // DLR, LDR, LRD
  void printDLR();
  void printDLR(Node *);

  void printLDR();
  void printLDR(Node *);

  void printLRD();
  void printLRD(Node *);

};

RedBlackBST::RedBlackBST():
  _root(nullptr),
  _size(0)
{
  std::cout << "RedBlackBST initialized." << std::endl;
}

RedBlackBST::RedBlackBST(Key *key, Value *val, int n):
  _root(nullptr),
  _size(0)
{
  
  for (int i = 0; i < n; i++)
  {
    put(key[i], val[i]);
  }
  
  std::cout << "RedBlackBST initialized." << std::endl;
}

bool RedBlackBST::_isRed(Node *node)
{
  if (node == nullptr)
  {
    return BLACK;
  }
  
  return node->isRed();
}

int RedBlackBST::_getSize(Node *node)
{
  if (node == nullptr)
  {
    return 0;
  }

  return node->getSize();
}






/**
 * 插入 Insertion
 * ----
 * 
 */
Node *RedBlackBST::put(Key k, Value v)
{
  /**
   * 
   */
  _root = put(_root, k, v, nullptr);
  
  // line 102: setRed, 所以这里还需要设回 Black
  _root->setBlack();
  return _root;
}

Node *RedBlackBST::put(Node *curr, Key k, Value v, Node *parent)
{
  if (curr == nullptr)
  {
    curr = new Node(k, v, 1);
    curr->setRed();
    curr->parent = parent;
    return curr;
  }

  int comparison = k.compare(curr->getKey());
  if (comparison > 0)
  {
    curr->right = put(curr->right, k, v, curr);
  }
  else if (comparison < 0)
  {
    curr->left = put(curr->left, k, v, curr);
  }
  else
  {
    curr->setValue(v);
  }

  // FIXME: nullptr
  if (_isRed(curr->left) && _isRed(curr->right))
  {
    _flipColors(curr);
  }
  else if (!_isRed(curr->left) && _isRed(curr->right))
  {
    curr = _rotateLeft(curr);
  }
  else if (_isRed(curr->left) && _isRed(curr->left->left))
  {
    curr = _rotateRight(curr);
  }

  // compute size
  curr->setSize(1 + _getSize(curr->left) + _getSize(curr->right));
  return curr;
}

// 此时右为红链接，左旋转
/**
 *      o              n                n
 *    /  \\red          \            //   \
 *   L    n    ->  o     D     ->   o      D
 *  / \  / \      / \   |\        /  \    / \
 *      C   D    L   C           L    C
 *     / \ / \  |\   |\         / \  / \
 * 
 */
Node *RedBlackBST::_rotateLeft(Node *old)
{
  // switch link
  Node *neo = old->right;
  old->right = neo->left;
  neo->left = old;

  neo->parent = old->parent;
  old->parent = neo;
  old->right->parent = old;

  // change color
  neo->setBlack();
  old->setRed();

  // fix node number
  neo->setSize(_getSize(old));
  old->setSize(1 + _getSize(old->left) + _getSize(old->right));

  // return new node pointer
  return neo;
}

// 此时左为连续两个红链接，右旋转
/**
 *      o          n
 *    // \       // \
 *   n      ->  A    o
 * // \             / \
 * A   B           B
 *     
 * 
 */
Node *RedBlackBST::_rotateRight(Node *old)
{
  Node *neo = old->left;
  old->left = neo->right;
  neo->right = old;

  neo->parent = old->parent;
  old->parent = neo;
  old->left->parent = old;

  old->setBlack();
  neo->left->setBlack();

  neo->setRed();

  neo->setSize(_getSize(old));
  old->setSize(1 + _getSize(old->left) + _getSize(old->right));

  return neo;
}

void RedBlackBST::_flipColors(Node *node)
{
  node->left->setBlack();
  node->right->setBlack();
  node->setRed();
}






/**
 * TODO: 单纯的查找节点，好像可以抽离出来，和 insert 共用一个
 * 
 * 删除 Removal
 * ----
 *
 */
Value RedBlackBST::del(Key k)
{
  return del(k, _root);
}

Value RedBlackBST::del(Key k, Node *curr)
{
  int comparison = k.compare(curr->getKey());

  if (comparison > 0)
  {
    return del(k, curr->right);
  }
  else if (comparison < 0)
  {
    return del(k, curr->left);
  }
  else
  {
    return performDeletion(curr);
  }
}

Value RedBlackBST::performDeletion(Node *z)
{
  // 1. 先执行同 BST 同样的删除操作，但是这个过程中，你需要把要删除的节点颜色保留下来
  Node *y = z;
  bool originColor = z->isRed();

  /**
   *  如果要删除的节点 z
   *    - 没有左子树
   * 
   *      z               left
   *     / \              /   \
   *       left    ->
   *        / \
   * 
   */
  if (z->left == nullptr)
  {
    // _transplant()
  }

  return z->getValue();
}

void RedBlackBST::_transplant(Node *old, Node *neo)
{
  // 我们默认以右子树最小值来替换当前要删除的值
  // 1. 替换根节点
  if (old == _root)
  {
    _root = neo;
  }
  
  // 2. 
  else if (old->parent->left == old)
  {
    old->parent->left = neo;
  }

  // 3. 
  else // if (parent->right == old)
  {
    old->parent->right = neo;
  }
}






/**
 * 其他
 * ----
 * 
 */
void RedBlackBST::printDLR()
{
  std::cout << "----- DLR -----" << std::endl;
  printDLR(_root);
}

void RedBlackBST::printDLR(Node *parent)
{
  if (parent == nullptr)
  {
    return;
  }
  
  parent->print();

  printDLR(parent->left);
  printDLR(parent->right);
}