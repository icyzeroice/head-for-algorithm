#ifndef CLASS_VALUE
#define CLASS_VALUE true

#include<iostream>

class Value
{
private:
  char *value;

public:
  Value();
  Value(char *);
  char *get();
  void set(char *);
  void print();
};

Value::Value():
  value("uninitialized")
{

}

Value::Value(char *c):
  value(c)
{
  
}

void Value::set(char *c)
{
  value = c;
}

char *Value::get()
{
  return value;
}

void Value::print()
{
  std::cout << &value << '\t' << value << std::endl;
}

#endif
