#ifndef CLASS_KEY
#define CLASS_KEY true

class Key
{
private:
  int key;
public:
  Key(int);
  int get();
  void set(int);
  int compare(Key);
};

Key::Key(int init):
  key(init)
{

}

int Key::compare(Key a)
{
  if (key > a.get())
  {
    return 1;
  }

  if (key < a.get())
  {
    return -1;
  }

  // key == a.get()
  return 0;
}

void Key::set(int v)
{
  key = v;
}

int Key::get()
{
  return key;
}

#endif