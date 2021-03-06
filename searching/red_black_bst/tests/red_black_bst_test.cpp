#include "../key.cpp"
#include "../value.cpp"
#include "../red_black_bst.cpp"


int main(int argc, char const *argv[])
{
  Key nodeKeys[] = { Key(5), Key(2), Key(0), Key(1), Key(9), Key(8) };
  Value nodeValues[] = { Value("Five"), Value("Two"), Value("Zero"), Value("One"), Value("Nine"), Value("Eight") };

  RedBlackBST tree = RedBlackBST(nodeKeys, nodeValues, 6);

  tree.printDLR();

  Key addonKey(11);
  Value addonVal("Eleven");

  tree.put(addonKey, addonVal);
  tree.printDLR();

  tree.del(addonKey);
  tree.printDLR();
  
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
