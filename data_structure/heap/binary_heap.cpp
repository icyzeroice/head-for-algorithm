#include<iostream>
using namespace std;

#define BINARY_HEAP_INITIAL_LENGTH 50

// max root binary heap
class BinaryHeap
{
private:
  // data fragment
  int _queue[BINARY_HEAP_INITIAL_LENGTH + 1];
  int _size;

  void static _swop(int *arr, int i, int j)
  {
    arr[i] = arr[i] + arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] = arr[i] - arr[j];
  };

  // private methods
  void _swim(int index)
  {
    int parentIndex;
    
    while (index > 1)
    {
      parentIndex = index / 2;

      if (_queue[parentIndex] < _queue[index])
      {
        _swop(_queue, parentIndex, index);
      }
      
      index = parentIndex;
    }
    
  };

  void _sink(int index)
  {
    int leftChild;
    int rightChild;

    // 左右节点都有
    while (index * 2 < _size)
    {
      leftChild = index * 2;
      rightChild = leftChild + 1;

      // TODO: 这里的 if 条件应该能优化下
      if (_queue[leftChild] > _queue[index] && _queue[rightChild] > _queue[index] && _queue[leftChild] >= _queue[rightChild])
      {
        _swop(_queue, leftChild, index);
        index = leftChild;
      }

      else if (_queue[leftChild] > _queue[index] && _queue[rightChild] > _queue[index] && _queue[leftChild] < _queue[rightChild])
      {
        _swop(_queue, rightChild, index);
        index = rightChild;
      }

      else if (_queue[leftChild] > _queue[index]) {
        _swop(_queue, leftChild, index);
        index = leftChild;
      }

      else if (_queue[rightChild] > _queue[index]) {
        _swop(_queue, rightChild, index);
        index = rightChild;
      }
    }

    // 只有左节点
    if (index * 2 == _size && _queue[index * 2] > _queue[index]) {
      _swop(_queue, index * 2, index);
    }
  };
  

public:
  BinaryHeap(): _size(0)
  {
    // TODO: 数组 _queue 需要初始化
    cout << "constructor initialized, set `_size` to " << _size << endl;
  };

  ~BinaryHeap()
  {
    // delete[] _queue;
    cout << "instance is to be destroyed...";
  };

  int getLength()
  {
    return _size;
  };
  
  bool insert(int item)
  {
    // TODO: need to extend the size of _queue?
    if (_size == BINARY_HEAP_INITIAL_LENGTH) {
      return false;
    }

    _size++;
    _queue[_size] = item;
    
    _swim(_size);

    return true;
  };
  
  int delMax()
  {
    if (_size == 0) {
      return 0;
    }

    int max = _queue[1];
    
    _queue[1] = _queue[_size];

    // 将最大放置尾部，注意可以实现堆排序
    _queue[_size] = max;
    _size--;

    _sink(1);

    return max;
  };

  void print() {
    cout << "Queue is: " << *_queue << "\nSize is: " << _size << endl;
  };
};

int main(int argc, char const *argv[])
{
  BinaryHeap h;

  h.insert(3);
  h.insert(2);
  h.insert(4);

  h.print();

  h.insert(5);
  h.insert(6);
  h.insert(7);

  h.print();

  h.delMax();

  h.print();

  return 0;
}
