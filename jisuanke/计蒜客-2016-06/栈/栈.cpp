#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

template<class Type> class Stack
{
private:
	Type *data;
	int topIndex, maxSize;
public:
	Stack(int _maxSize){
	    topIndex = -1;
		maxSize = _maxSize;
		data = new Type[maxSize];

	}
	~Stack(){
		delete []data;
	}

	bool myPush(Type element){
		if (topIndex < maxSize-1){
			topIndex++;
			data[topIndex] = element;
			return true;
		}
		else{
			return false;
		}
	}

	bool myPop(){
		if(topIndex >= 0){
			cout<<data[topIndex]<<endl;
			topIndex--;
			return true;
		}
		else{
			return false;
		}
	}

	bool myTop(){
		if(topIndex >= 0){
			cout<<data[topIndex]<<endl;
			return true;
		}
		else{
			return false;
		}
	}

};

int main(){
	int n;
	cin>>n;
	Stack<int> mystack(n);
	for(int i=0; i<n; i++){
        if(mystack.myPush(i+1))
            cout<<"------------------\n��ջ�ɹ�"<<endl;
        else
            cout<<"------------------\n��ջʧ��"<<endl;
	}

    cout<<"\n��ǰջ��Ϊ��";
    mystack.myTop();
    cout<<"---------------\n\n\n";

    /*������ջ*/
    if(mystack.myPush(2333))
        cout<<"������ջ�ɹ�"<<endl;
    else
        cout<<"������ջʧ��\n\n"<<endl;


	for(int i=0; i<n; i++){
            cout<<"-----��ջԪ��Ϊ��--------"<<endl;
        if(mystack.myPop())
            cout<<"-------��ջ�ɹ�----------\n\n\n";
        else
            cout<<"-------��ջʧ��----------\n\n\n";
	}

	/*�����ջ*/
	if(mystack.myPop())
        cout<<"�����ջ�ɹ�\n\n\n";
    else
        cout<<"�����ջʧ��\n\n\n";


	system("pause");
	return 0;
}
