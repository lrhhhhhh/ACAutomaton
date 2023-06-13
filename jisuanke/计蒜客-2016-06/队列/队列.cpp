#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;

class Queue
{
private:
	int length;
	int head;
	int tail;
	int *data;
public:
	Queue(int _length){
		length = _length;
		data = new int[length];
		head = 0;
		/*tail��ʾ�������һ���������ڹ��캯������*/
		tail = -1;
	}
	~Queue(){
		delete []data;
	}

	/*ע��ΪʲôҪtail+1С��length�أ���Ϊtail��ʼֵΪ-1��length��СΪ0*/
	/*��length����0ʱ����ʱ���ܽ����������*/
	/*�൱�ڶ���Ԫ���±��0��ʼ��������if���������ƣ�ֻ�ܵ�length-1������ʵ�ʳ�����ȻΪlength*/
	void myPush(int element){
		if(tail+1 < length){
			tail++;
			data[tail] = element;
		}
		else
            cout<<"��������������"<<endl;
	}

	/*assert�÷�����ٶ�*/
	/*��head����ʾ���ף�pop��һ������һ*/
	/*û��Ҫÿ��pop���ͷŶ�Ӧ���ڴ棬���ֱ���������������������ڴ�*/
	void myPop(){
		if(head<=tail)
            head++;
        else
            cout<<"����Ϊ�գ�����"<<endl;
	}

	/*����pop�������ܵ��¶���Ϊ�գ����Ա����ж�head�Ƿ�С�ڵ���tail*/
	int myFront(){
		/*������Ϊ�գ���ôhead����tail*/
		assert(head<=tail);
		return data[head];
	}

	void myOutput(){
	    if(head>tail)
            cout<<"�����ѿգ������������"<<endl;
		for(int i=head; i<=tail; i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	Queue lrhQueue(10);
	/*�����i�����ֵ���ڶ��г���10*/
	for(int i=0; i<12; i++)
		lrhQueue.myPush(i+1);
	cout<<"���ӳɹ������Ϊ��"<<endl;
	lrhQueue.myOutput();
	cout<<"����Ԫ���ǣ�"<<lrhQueue.myFront()<<endl;
	cout<<"-------------------\n\n\n\n";

	for(int i=0; i<9; i++){
        cout<<"��"<<i+1<<"��pop()��Ķ���Ϊ:"<<endl;
        lrhQueue.myPop();
        lrhQueue.myOutput();
        cout<<"��ʱ����Ԫ���ǣ�"<<lrhQueue.myFront()<<endl;
        cout<<"-------------------\n\n\n\n";
	}

    cout<<"��ʱ���л�ʣ��һ��Ԫ�أ����Լ���\n\n";
    lrhQueue.myPop();
	cout<<"assertҪ�������ˣ�boom!!!\n\n";
	cout<<"����Ԫ���ǣ�"<<lrhQueue.myFront()<<endl;
	cout<<"-------------------\n\n\n\n";

	system("pause");
	return 0;
}
