#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int _data) {
        data = _data;
        next = NULL;
    }
};
class LinkList {
private:
    Node* head;
public:
    LinkList() {
        head = NULL;
    }

    /*�ѹ����б���������룬��һ�͵ڶ���if��ì�ܣ����ֹ���������б��һ���ڵ㲻�ǿսڵ�*/
    /*���뵽��index��λ��*/
    void insert(Node *node, int index) {
        if (head == NULL) {
            head = node;
            //cout<<"node�ǣ�"<<node->data<<endl;
            return;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        Node *current_node = head;
        int count = 0;

        /*Ѱ�Ҳ����λ�á�*/
        /*����countС��index-1��Ϊ�˷�ֹ���ֲ������index����index���������ȵ����*/
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        /*ע��current_node������Ŀ�����λ�õ�ǰһ���ڵ�*/
        /*�������˼�ǣ���ǰ�ڵ�Ҫ�嵽current_node�ĺ���*/
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
        }
    }

    /*�������*/
    void output() {
        if (head == NULL) {
            return;
        }
        Node *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }

    void delete_node(int index) {
        if (head == NULL) {
            return;
        }
        Node *current_node = head;
        int count = 0;
        if (index == 0) {
            head = head->next;
            delete current_node;
            return;
        }
        while (current_node->next != NULL && count < index -1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1 && current_node->next != NULL) {
            Node *delete_node = current_node->next;
            current_node->next = delete_node->next;
            delete delete_node;
        }
    }

    void reverse(){
        if(head==NULL){
            return;
        }
        Node *next_node, *current_node;
        current_node = head->next;
        head->next = NULL;
        while(current_node!=NULL){
            next_node = current_node->next;
            current_node->next = head;
            head = current_node;
            current_node = next_node;
        }
    }

};
int main() {
    LinkList linklist;
    for (int i = 1; i <= 10; i++) {
        Node *node = new Node(i);
        linklist.insert(node, i - 1);
    }
    linklist.output();
    linklist.delete_node(3);
    linklist.output();
    linklist.reverse();
    linklist.output();
    return 0;
}
