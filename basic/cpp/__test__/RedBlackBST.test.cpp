#include "../lib/Key.cpp"
#include "../lib/Value.cpp"
#include "../BST/RedBlackBST.cpp"


int main(int argc, char const *argv[])
{
  Key nodeKeys[] = { Key(5), Key(2), Key(0), Key(1), Key(9), Key(8) };
  Value nodeValues[] = { Value("Five"), Value("Two"), Value("Zero"), Value("One"), Value("Nine"), Value("Eight") };

  RedBlackBST tree = RedBlackBST(nodeKeys, nodeValues);

  tree.printDLR();

  Key addonKey(11);
  Value addonVal("Eleven");

  tree.put(addonKey, addonVal);
  tree.printDLR();

  // tree.del();
  
  return 0;
}

/**

key(size)

乱序生成结果:

             2(6)
          /       \
  0(1)|1(2)       9(3)
  /  \   \         /
              5(1)|8(2)
             
*/
