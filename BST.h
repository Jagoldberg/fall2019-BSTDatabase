#include "TreeNode.h"
#include <iostream>

using namespace std;

template <typename E>
class BST{
private:
  TreeNode<E> *root;
public:
  BST();
  ~BST();

  bool search(int key);
  void insert(int key, E value);

  bool deleteNode(int key);

  //helper function
  bool isEmpty();
  TreeNode<E>* getMin();
  TreeNode<E>* getMax();
  void printTree();
  void recPrint(TreeNode<E> *node);
  TreeNode<E>* getSuccessor(TreeNode<E> *d);
  void deleteRecursive(TreeNode<E>* node);
};

template <typename E>
BST<E>::BST(){
  root = NULL; //empty tree
}
template <typename E>
BST<E>::~BST(){
  deleteRecursive(root);
}
template <typename E>
void BST<E>::recPrint(TreeNode<E> *node){
  if(node == NULL){
    return;
  }

  recPrint(node -> left);
  cout << node->key << endl;
  recPrint(node -> right);
}
template <typename E>
void BST<E>::printTree(){
  recPrint(root);
}
template<typename E>
TreeNode<E>* BST<E>::getMax(){
  TreeNode<E> *current = root;
  if(root = NULL){ //Empty TreeNode
    return NULL;
  }
  while(current -> right != NULL){
    current = current -> right;
  }

  return (current); // or return &(current->key)
}

template<typename E>
TreeNode<E>* BST<E>::getMin(){
  TreeNode<E> *current = root;
  if(root = NULL){ //Empty TreeNode
    return NULL;
  }
  while(current -> left != NULL){
    current = current -> left;
  }

  return (current); // or return &(current->key)
}

template<typename E>
void BST<E>::insert(int key, E value){
  TreeNode<E> *node = new TreeNode<E>(key, value);

  if(root == NULL){
    //empty Tree
    root = node;
  } else {
    //tree is not empty
    //need to find insertion location
    TreeNode<E> *current = root;
    TreeNode<E> *parent = NULL;
    while(true){
      parent = current;
      if(value < current -> key){
        current = current -> left;
        //going left
        if (current == NULL){
          //we found the insertion point
          parent -> left = node;
          break;
        }
      } else {
        current = current -> right;
        //going right
        if (current == NULL){
          //we found the insertion point
          parent -> right = node;
          break;
        }
      }
    }
  }
}

template<typename E>
bool BST<E>::search(int key){
  if(root == NULL){
    return false; //Empty Tree
  } else{
    //Tree is not empty
    TreeNode<E> *current = root;
    while(current -> key != key){
      if(key < current -> key){
        current = current -> left;
      } else {
        current = current -> right;
      }
      if(current == NULL){
        //value not found
        return false;
      }
    }
  }
  return true;
}
template<typename E>
bool BST<E>::deleteNode(int key){
  if(root == NULL){
    return false;
  }
  TreeNode<E> *current = root;
  TreeNode<E> *parent = root;
  bool isLeft = true;

  //now let's look for the node
  while(current -> key != key){
    parent = current;
    if(key < current -> key){
      current = current -> left;
      isLeft = true;
    } else {
      current = current -> right;
      isLeft = false;
    }

    if (current == NULL){
      return false;
    }
  }
  //We found the node that needs to be deleted
  //Now let's check our different cases

  //no children
  if((current -> left == NULL) && (current -> right = NULL)){
    if(current = root){
      root = NULL;
    } else if(isLeft){
      parent -> left = NULL;
    } else {
      parent -> right = NULL;
    }
  }
  //one child
  //we need to determine if child is left or right and proceed
  else if(current -> right == NULL)//has no right child
  {
    if(current == root){
      root = current -> left;
    } else if(isLeft){
      parent -> left = current -> left;
    } else {
      parent -> right = current -> left;
    }
  }
  else if(current -> left == NULL)//has no left child
  {
    if(current == root){
      root = current -> right;
    } else if(isLeft){
      parent -> left = current -> right;
    } else {
      parent -> right = current -> right;
    }
  }
  //node to be deleted has two children
  else
  {
    TreeNode<E> *successor = getSuccessor(current);
    if(current == root){
      root = successor;
    } else if (isLeft){
      parent -> left = successor;
    } else {
      parent -> right = successor;
    }

    successor -> left = current -> left;
  }
  return true;
}

template<typename E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E> *d)//d is the node to be deleted
{
  TreeNode<E> *sp = d; //sp is successor's parent and is initialized to d
  TreeNode<E> *successor = d;
  TreeNode<E> *current = d -> right; //start one right of d
  while(current != NULL){ //one right all the way left
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d -> right){
    //successor is a descendant of the right child
    sp -> left = successor -> right;
    successor -> right = d -> right;
  }
  return successor;
}

template<typename E>
void BST<E>::deleteRecursive(TreeNode<E>* node){
  if (node != NULL){
    deleteRecursive(node -> left);
    deleteRecursive(node -> right);
    delete node;
  }
}
