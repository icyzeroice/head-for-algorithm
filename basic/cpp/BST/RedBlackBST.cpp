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

  Node *_max(Node *);
  Node *_min(Node *);

  void _fixup(Node *);

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
  Node *max();
  Node *min();
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
 *   L    n    =>  o     D     =>   o      D
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

  if (old->right != nullptr)
  {
    old->right->parent = old;
  }

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
 *   n      =>  A    o
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

  if (old->left != nullptr)
  {
    old->left->parent = old;
  }

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
  Value _result;

  if (comparison > 0)
  {
    _result = del(k, curr->right);
  }
  else if (comparison < 0)
  {
    _result = del(k, curr->left);
  }
  else
  {
    return performDeletion(curr);
  }

  // fix count size
  curr->setSize(1 + _getSize(curr->left) + _getSize(curr->right));
  return _result;
}

Value RedBlackBST::performDeletion(Node *z)
{
  // 1. 先执行同 BST 同样的删除操作，但是这个过程中，你需要把要删除的节点颜色保留下来
  Node *x;
  Node *y = z;
  bool isYOriginColorRed = y->isRed();
  Value _result = z->getValue();

  /**
   *  如果要删除的节点 z
   *    - 没有左子树
   * 
   *      z                    right <-(x)
   *     / \                   /   \
   *       right <-(x)    => 
   *        / \
   * 
   */
  if (z->left == nullptr)
  {
    x = z->right;
    _transplant(z, z->right);
  }

  /**
   *    - 没有右子树
   * 
   *      z                left
   *     / \              /   \
   *  left       => 
   * /   \
   * 
   * 
   */
  else if (z->right == nullptr)
  {
    x = z->left;
    _transplant(z, z->left);
  }

  /**
   * 我们默认以 *右子树最小值* 来替换当前要删除的值，所以这里需要将有两个子节点的情况变换成只有一个子节点后用 `_transplant`
   */
  else
  {
    // 因为 y 为左子树的最小值，所以 y 没有左子节点
    y = _min(z->right);
    x = y->right;

    // 记录 y 颜色
    isYOriginColorRed = y->isRed();

    // 如果 y 就是 z 的右子节点
    if (y->parent == z)
    {
      if (x != nullptr)
      {
        x->parent = y;
      }
    }
    // 如果 y 是 z 右子结点的后代，而非直接的右子结点
    else
    {
      // 删 y
      _transplant(y, y->right);
      y->right = z->right;
      z->left->parent = y;
    }

    // 删 z
    _transplant(z, y);
    y->left = z->left;
    if (y->left != nullptr)
    {
      y->left->parent;
    }

    // 保留原 z 的颜色
    z->isRed() ? y->setRed() : y->setBlack();
  }

  // 如果 y 点原来是黑色，删除可能会改变红黑树性质
  if (!isYOriginColorRed)
  {
    _fixup(x);
  }

  return _result;
}

void RedBlackBST::_transplant(Node *old, Node *neo)
{
  /**
   * 在这里 `old->parent` 只有 `old` 一个子节点
   * 
   * 1. 替换根节点
   * 
   */
  if (old == _root)
  {
    _root = neo;
  }
  
  // 2. 替换父节点的左子节点
  else if (old->parent->left == old)
  {
    old->parent->left = neo;
  }

  // 3. 替换父节点的右子节点
  else // if (parent->right == old)
  {
    old->parent->right = neo;
  }

  // 连接父节点
  if (neo != nullptr)
  {
    neo->parent = old->parent;
  }
}

// 这里不知道为什么很多地方都引入 “额外一层黑色” 来理解，但是好像并没有更容易，
// 黑黑和红黑两种情况，与黑和红两种情况又有什么区别？意义不明……
void RedBlackBST::_fixup(Node *curr)
{
  Node *sibling;

  while (curr != _root && !curr->isRed())
  {
    if (curr == curr->parent->left)
    {
      sibling = curr->parent->right;

      if (sibling->isRed())
      {
        sibling->setBlack();
        curr->parent->setRed();
        _rotateLeft(curr->parent);
        sibling = curr->parent->right;
      }

      if (!sibling->left->isRed() && !sibling->right->isRed())
      {
        sibling->setRed();
        curr = curr->parent;
      }

      else
      {
        if (!sibling->right->isRed())
        {
          sibling->left->setBlack();
          sibling->setRed();
          _rotateRight(sibling);
          sibling = curr->parent->right;
        }

        curr->parent->isRed() ? sibling->setRed() : sibling->setBlack();
        curr->parent->setBlack();
        sibling->right->setBlack();
        _rotateLeft(sibling->parent);
        sibling = _root;
      }
    }

    else {
      sibling = curr->parent->left;

      if (sibling->isRed())
      {
        sibling->setBlack();
        curr->parent->setRed();
        _rotateRight(curr->parent);
        sibling = curr->parent->left;
      }

      if (!sibling->right->isRed() && !sibling->left->isRed())
      {
        sibling->setRed();
        curr = curr->parent;
      }

      else
      {
        if (!sibling->left->isRed())
        {
          sibling->right->setBlack();
          sibling->setRed();
          _rotateLeft(sibling);
          sibling = curr->parent->left;
        }

        curr->parent->isRed() ? sibling->setRed() : sibling->setBlack();
        curr->parent->setBlack();
        sibling->left->setBlack();
        _rotateRight(sibling->parent);
        sibling = _root;
      }
    }
  }

  curr->setBlack();
}




/**
 * 其他
 * ----
 * 
 */
Node *RedBlackBST::max()
{
  return _max(_root);
}

Node *RedBlackBST::min()
{
  return _min(_root);
}

Node *RedBlackBST::_min(Node *curr)
{
  if (curr == nullptr)
  {
    return nullptr;
  }

  while(curr->left != nullptr)
  {
    curr = curr->left;
  }
  
  return curr;
}

Node *RedBlackBST::_max(Node *curr)
{
  if (curr == nullptr)
  {
    return nullptr;
  }

  while(curr->right != nullptr)
  {
    curr = curr->right;
  }
  
  return curr;
}

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
