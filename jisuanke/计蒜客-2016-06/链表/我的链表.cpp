#include <iostream>
#include <cstring>

using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int first_node){
		data = first_node;
		next = NULL;
	}
};

class LinkList{
private:
	Node *head;
public:
	LinkList(){
		head = NULL;
	}

	/*searchNode������Ѱ��indexǰһ���ڵ�*/
	Node *searchNode(int index){
		int tot = 1;
		Node *currentNode = head;
		/*ע��Ѱ�ҽڵ�ʱ��ʲôʱ����currentNode->next!=NULL����currentNode != NULL*/
		/*ע�⣬��tot����index-1ʱѭ����������ʱ��currentNodeΪĿ��λ�õ�ǰһ���ڵ�*/
		while(currentNode->next != NULL && tot<index-1){
			currentNode = currentNode->next;
			tot++;
		}
		/*�����ֹindexΪ���������ȵķǷ�����*/
		if(tot==index-1)
			return currentNode;
		else
            return NULL;


	}

	/*������뺯���ȿ����ڹ��������ʱ��ʹ�ã�Ҳ�����ڹ���֮�󵥶���������ڵ�*/
	/*��������if���û�ж��ࡣ�����һ���ڵ㲻�ǿսڵ㣬index�ĺ����ǲ��뵽�����е�index��λ��*/
	/*ע�⺯������ʱindex������ʱ��ֵ*/
	void insertNode(Node *node, int index){
		Node *currentNode;
		if(head==NULL){
			head = node;
			return;
		}
		/*������ֱ�Ӱѵ�һ���ڵ���Ϊ��1�ţ�����0��*/
		if(index==1){
			node->next = head;
			head = node;
			return;
		}

		currentNode = searchNode(index);

		/*�½ڵ�����������λ�õ�ԭ���ڵ��൱�ں���һλ*/
		/*currentNode->next�൱�ڲ���λ�õ�ԭ���ڵ�*/
		if(currentNode != NULL){
			node->next = currentNode->next;
			currentNode->next = node;
		}
		return;
	}

	/*currentNodeΪҪɾ���ڵ��ǰһ���ڵ�*/
	void deleteNode(int index){
	    Node *NodeOfDelete, *currentNode=head;
	    if(head==NULL)
            return;
        if(index==1){
            head = head->next;
            delete currentNode;
            return;
        }

		currentNode = searchNode(index);
		if(currentNode != NULL){
            NodeOfDelete = currentNode->next;
            currentNode->next = NodeOfDelete->next;
            delete NodeOfDelete;
		}
		return;
	}

	void outputList(){
	    int tot = 0;
		Node *currentNode = head;
		/*���������Ϊ�ձ�����*/
		while(currentNode != NULL){
			cout<<currentNode->data<<" ";
			currentNode = currentNode->next;
		}
		cout<<endl;
	}

	/*ע��˴���ı�head��ֵ*/
	void reverseList(){
        if(head==NULL)
			return;
		Node *currentNode = head->next, *nextNode;

		/*ע���head��ָ������ΪNULL*/
		head->next = NULL;
		while(currentNode != NULL){
			nextNode = currentNode->next;
			currentNode->next = head;
			head = currentNode;
			currentNode = nextNode;
		}
	}
};

int main()
{
	int n=6;

    LinkList linklist;
    for(int i=1; i<=n; i++){
        Node *node = new Node(i);
        linklist.insertNode(node, i);
    }
    cout<<"---------------����ɹ����-----------------------"<<endl;
    linklist.outputList();
    cout<<"------------------�ָ���--------------------------"<<"\n\n";



    cout<<"----------------------------------Ԫ��ɾ��--------------------------------------"<<endl;

    cout<<"ɾ����1��Ԫ�غ�Ϊ��";
    linklist.deleteNode(1);
    linklist.outputList();
    cout<<endl;

    /*ע���ʱ��5��Ԫ���Ѿ�����5�ˣ�����6 */
    cout<<"ɾ����ʱ���еĵ�5��Ԫ�غ�õ���";
    linklist.deleteNode(5);
    linklist.outputList();
    cout<<"-----------------------------------�ָ���----------------------------------------"<<"\n\n";


    cout<<"--------------------------------��ת�б����-------------------------------------"<<endl;
    /*ע�ⷭת��head����ı䣬�����ʵ��ı亯����������֤head����*/
    linklist.reverseList();
    linklist.outputList();
    cout<<"-----------------------------------�ָ���----------------------------------------"<<"\n\n";




    cout<<"--------------------------���߽�ֵ������ִ��Ԫ��ɾ��---------------------------"<<endl;

    cout<<"ɾ����1��Ԫ�غ�";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"ɾ����1��Ԫ�غ�";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"ɾ����1��Ԫ�غ�";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"ɾ����1��Ԫ�غ�";
    linklist.deleteNode(1);
    linklist.outputList();

    /*����Ϊ���֮��Ĳ���*/
    cout<<"ɾ����1��Ԫ�غ�";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"ִ��һ�η�ת:"<<endl;
    linklist.reverseList();
    linklist.outputList();

    cout<<"ɾ����1��Ԫ�غ�";
    linklist.deleteNode(1);
    linklist.outputList();


    cout<<"-----------------------------------�ָ���-----------------------------------------"<<endl;

	return 0;
}
