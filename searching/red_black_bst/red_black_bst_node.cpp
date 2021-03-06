#ifndef CLASS_sizeODE
#define CLASS_sizeODE true

#include<iostream>
#include "./key.cpp"
#include "./value.cpp"

bool const BLACK = false;
bool const RED = true;

class Node
{
private:

  Key _key;
  Value _value;

  bool _color;

  int _size;

public:

  Node(Key k, Value v, int n);
  ~Node();

  Node *left;
  Node *right;
  Node *parent;

  void setRed();
  void setBlack();
  bool isRed();

  void setSize(int);
  int getSize();

  Key getKey();

  void setValue(Value);
  Value getValue();

  void print();
};

Node::Node(Key k, Value v, int n):
  _key(k),
  _value(v),
  _size(n),
  _color(BLACK),
  left(nullptr),
  right(nullptr),
  parent(nullptr)
{
  
};

Node::~Node()
{
  
};

bool Node::isRed()
{
  return _color;
};

void Node::setRed()
{
  _color = RED;
}

void Node::setBlack()
{
  _color = BLACK;
}

void Node::setSize(int n)
{
  _size = n;
}

int Node::getSize()
{
  return _size;
}

Key Node::getKey()
{
  return _key;
}

void Node::setValue(Value v)
{
  _value = v;
}

Value Node::getValue()
{
  return _value;
}

void Node::print()
{
  std::cout << _key.get() << '\t' << _value.get() << '\t' << _color << '\t' << _size << std::endl;
}

#endif