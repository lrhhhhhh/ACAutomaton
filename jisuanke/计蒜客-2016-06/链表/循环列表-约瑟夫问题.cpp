#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
public:
	Node(int _data){
		data = _data;
		next = NULL;
	}
};

class LinkList
{
private:
	Node *tail;
public:
	LinkList(){
		tail = NULL;
	}

	/*ע��index�ĺ��壬���ｫ�����±꿴�ɴ�1��ʼ*/
	/*Ĭ�������n�Ϸ�*/
	void insertNode(Node *node, int index){

	    /*��ǰ����Ϊ�գ��򽫲�����Ľڵ���Ϊͷ�ڵ㣬���ҽ�����ָ��ָ���Լ����γ�ѭ��*/
		if(tail==NULL){
			tail = node;
			tail->next = tail;
			//cout<<"if(tail==NULL)"<<endl;
			return;
		}


		/*����ɹ���Ķ�����뵽������λ�õ��ж����*/
		/*tail->next��ʾ��һ���ڵ㣬��ônode->next = tail->next��node�嵽��ͷ֮ǰ���γ��µı�ͷ*/
		/*tailΪ���һ���ڵ㣬��ͷ�����ˣ�����tail->next=node*/
		if(index==1){
			node->next = tail->next;
			tail->next = node;
			return;
		}


		int tot = 1;
		Node *currentNode = tail->next;
		/*curentNode����ͷ���*/

		/*ע���ж�����*/
		while(currentNode != tail && tot < index-1){
			currentNode = currentNode->next;
			tot++;
		}


		/*���currentNode�����ֵ*/
		if(tot == index-1){
			node->next = currentNode->next;
			currentNode->next = node;
			//cout<<"if(tot==index-1):"<<endl;
		}


		/*��node���뵽��ǰ����ĩβʱ������������ж�*/
		/*�ж�ʱ��tail��û���£��������ڶ����ڵ㣬��node�������һ���ڵ�*/
		if(node == tail->next){
			tail = node;
			//cout<<"if(node==tail->next)"<<endl;
		}
	}


	void deleteNode(int index){
		int tot = 1;
		Node *currentNode, *NodeOfDelete;

		if(tail==NULL){
            //cout<<"�����ѿգ�����"<<endl;
            return;
		}

        /*�����ȵ���1ʱ*/
		if(index==1 && (tail->next)==tail) {
            NodeOfDelete = tail;
            delete NodeOfDelete;
            tail = NULL;
            return;
		}

		/*�����ȴ��ڵ���2ʱ*/
		if(index==1 && (tail->next->next)!=NULL ) {
			NodeOfDelete = tail->next;
			tail->next = NodeOfDelete->next;
			delete NodeOfDelete;
			return;
		}

		currentNode = tail->next;
		while(currentNode != tail && tot<index-1){
			currentNode = currentNode->next;
			tot++;
		}

        /*����ɾ�����һ���ڵ�ǰ����tail*/
		if(currentNode->next == tail)
            tail = currentNode;

		/*����β�ڵ�ɾ��*/
		if(tot==index-1){
			NodeOfDelete = currentNode->next;
			currentNode->next = NodeOfDelete->next;
			delete NodeOfDelete;
		}


	}

	void outputList(){
		int tot = 1;
		if(tail==NULL){
            cout<<"�����ѿգ�����"<<endl;
            return;
		}

		Node *currentNode = tail->next;
		while(currentNode != tail){
			cout<<currentNode->data<<" ";
			currentNode = currentNode->next;
		}
		/*β�ڵ�����ѭ������Ӱ����Ҫ�����*/
		cout<<currentNode->data<<endl;
		cout<<"-------------�ָ���-------------------\n\n\n";
	}
};

int main()
{
	int n;
	while(cin>>n){
        LinkList linklist;
        for(int i=1; i<=n; i++){
            Node *node = new Node(i);
            linklist.insertNode(node, i);
        }

        linklist.outputList();


        /*��������飬n��Ҫһ���Ĵ�С*/
        cout<<"ɾ����һ���ڵ�:"<<endl;
        linklist.deleteNode(1);
        linklist.outputList();

        cout<<"ɾ����3���ڵ�:"<<endl;
        linklist.deleteNode(3);
        linklist.outputList();

        cout<<"ɾ�����һ���ڵ�:"<<endl;
        linklist.deleteNode(n-2);
        linklist.outputList();

        cout<<"ɾ���б��Ҷ���ɾ�����ο������:"<<endl;
        for(int i=0; i<n;i++){
        	linklist.deleteNode(1);
        	linklist.outputList();
        }

        system("pause");
	}

	return 0;
}
