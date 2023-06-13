#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *lchild, *rchild;
    Node(int _data) {
        data = _data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node(){
       if(lchild !=NULL){
        delete lchild;
       }
        if(rchild !=NULL){
        delete rchild;
       }
    }
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree(){
        if(root != NULL){
            /*ע������ϵͳ������BinaryTree������������delete root��(rootΪNode��)��ϵͳ�����Node���е������������Ӷ��ݹ�ɾ����������*/
            delete root;
        }
    }
    void build_demo(){
        root = new Node(1);
        root->lchild = new Node(2);
        root->rchild = new Node(3);
        root->lchild->lchild = new Node(4);
        root->lchild->rchild = new Node(5);
        root->rchild->rchild = new Node(6);
    }

};
int main() {
    BinaryTree binarytree;
    binarytree.build_demo();
    return 0;
}
