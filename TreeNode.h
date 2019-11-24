#include <iostream>

using namespace std;

template <typename E>
class TreeNode{
public:
  TreeNode();
  TreeNode(int k, E v); //k= key, which in this example is also the value(data)
  ~TreeNode(); //when creating a template class destructor must be virtual

  int key;
  E value;
  TreeNode* left;
  TreeNode* right;
};

template<typename E>
TreeNode<E>::TreeNode(){
  key = 0;
  value = NULL;
  left = NULL;
  right = NULL;
}
template<typename E>
TreeNode<E>::TreeNode(int k, E v){
  key = k;
  value = v;
  left = NULL;
  right = NULL;
}
template<typename E>
TreeNode<E>::~TreeNode(){
  delete value;
  delete left;
  delete right;
}
