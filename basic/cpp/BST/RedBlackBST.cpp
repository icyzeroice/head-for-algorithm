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

  // for safe
  bool _isRed(Node *);
  int _getSize(Node *);

public:
  RedBlackBST();
  RedBlackBST(Key *, Value *);

  Node get();

  Node *put(Key, Value);
  Node *put(Node *, Key, Value);

  Value del(Key);

  int size();
  Node select();
  Node rank();
  Node floor();
  Node ceiling();
  Node max();
  Node min();
  Node range();

  // DLR, LDR, LRD
  void printDLR();
  void printLDR();
  void printLRD();
  void printDLR(Node *);
  void printLDR(Node *);
  void printLRD(Node *);

};

RedBlackBST::RedBlackBST():
  _root(nullptr),
  _size(0)
{
  std::cout << "RedBlackBST initialized." << std::endl;
}

RedBlackBST::RedBlackBST(Key *key, Value *val):
  _root(nullptr),
  _size(0)
{
  
  for (int i = 0; i < 6; i++)
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

Node *RedBlackBST::put(Key k, Value v)
{
  _root = put(_root, k, v);
  
  // line 102: setRed, 所以这里还需要设回 Black
  _root->setBlack();
  return _root;
}

Node *RedBlackBST::put(Node *curr, Key k, Value v)
{
  if (curr == nullptr)
  {
    curr = new Node(k, v, 1);
    curr->setRed();
    return curr;
  }

  int comparison = k.compare(curr->getKey());
  if (comparison > 0)
  {
    curr->_right = put(curr->_right, k, v);
  }
  else if (comparison < 0)
  {
    curr->_left = put(curr->_left, k, v);
  }
  else
  {
    curr->setValue(v);
  }

  // FIXME: nullptr
  if (_isRed(curr->_left) && _isRed(curr->_right))
  {
    _flipColors(curr);
  }
  else if (!_isRed(curr->_left) && _isRed(curr->_right))
  {
    curr = _rotateLeft(curr);
  }
  else if (_isRed(curr->_left) && _isRed(curr->_left->_left))
  {
    curr = _rotateRight(curr);
  }

  // compute size
  curr->setSize(1 + _getSize(curr->_left) + _getSize(curr->_right));
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
  Node *neo = old->_right;
  old->_right = neo->_left;
  neo->_left = old;

  // change color
  neo->setBlack();
  old->setRed();

  // fix node number
  neo->setSize(_getSize(old));
  old->setSize(1 + _getSize(old->_left) + _getSize(old->_right));

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
  Node *neo = old->_left;
  old->_left = neo->_right;
  neo->_right = old;

  old->setBlack();
  neo->_left->setBlack();

  neo->setRed();

  neo->setSize(_getSize(old));
  old->setSize(1 + _getSize(old->_left) + _getSize(old->_right));

  return neo;
}

void RedBlackBST::_flipColors(Node *node)
{
  node->_left->setBlack();
  node->_right->setBlack();
  node->setRed();
}

/*
Value RedBlackBST::del(Key k)
{
  
}
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

  printDLR(parent->_left);
  printDLR(parent->_right);
}