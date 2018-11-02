#include<iostream>

struct Node {
  int id;
  char *message;
};

class PriorityQueue
{
  private:
    struct Node *_queue;
    int _size;

  public:
    PriorityQueue(void);
    PriorityQueue(int len);
    ~PriorityQueue(void);
    int size(void);
    bool isEmpty(void);
    bool insert(struct Node *node);
    bool delMax(char *key, char *value);
};

int PriorityQueue::size(void) {
  return _size;
}

bool PriorityQueue::isEmpty(void) {
  return false;
}

bool insert(struct Node *node) {
  return true;
}

bool delMax(char *key, char *value) {
  return true;
}


int main(int argc, char const *argv[])
{
  PriorityQueue noneArgsQ;
  PriorityQueue argsQ(3);

  Node n1;
  Node n2;
  n1.id = 1;
  n1.message = "guess what";

  n2.id = 2;
  n2.message = "guess how";

  noneArgsQ.insert(&n1);

  return 0;
}
