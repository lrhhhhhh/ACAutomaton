#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

class Queue {
private:
    int *data;
    int head, tail, length, tot;
public:
    Queue(int length_input) {
        data = new int[length_input];
        length = length_input;
        head = 0;
        tail = -1;
        tot = 0;
    }
    ~Queue() {
        delete[] data;
    }

    bool myPush(int element) {
        if (tot < length) {
            /*tail��0��ʼ,���ֵΪcount-1*/
            /*��tot<length��tail����length+1ʱ����ζ�Ŷ����Ǽ����磬ǰ�ߵ��ڴ���Լ����������ӵ�Ԫ�أ�tail����Ϊ0*/
            tail = (tail + 1) % length;
            data[tail] = element;
            tot++;
            return true;
        }
        else {
            return false;
        }
    }


    /*���в��գ�����Լ���pop()*/
    /*ע�⣬������ֻʣ�����һ���ڵ�ʱ�����Ӻ�head���0,����Ϊ�գ�*/
    /*����tailֵû�䣬�����ڴ���洢��ÿ��Ԫ�ػ��ڣ����Կն������ʱҪ����ж�*/
    void myPop() {
        assert(tot>0);
        head = (head+1)%length;
        tot--;
    }

    void myFront() {
        assert(tot>0);
        cout<< data[head] <<endl;
    }

    void myOutput() {
        if(tot==0){
            cout<<"�����ѿգ�����"<<endl;
            return;
        }
        /*��ֹѭ�����*/
        if(tail == length-1){
            for(int i=head; i<=tail; i++)
                cout<<data[i]<<" ";
            cout<<endl;
            return;
        }
        /*���������*/
        /*head<tailʱ��i��ֵ���Ϊtail����ô(i+1)%length��ʹiһֱ����*/
        /*head>tailʱ��i��ֵ���Ϊlength-1��Ȼ��i+1��%length���0����ʱi<=tail,����i��ʱ�ı߽�Ϊtail,Ŀ��ʵ��*/
        /*head=tail����Ȼ����*/
        for (int i = head; i != tail + 1; i = (i + 1) % length)
            cout << data[i] << " ";
        cout << endl;
    }
    void PrintTail(){
        cout<<head<<" "<<tail<<endl;
    }

};
int main() {
    int n;
    n = 10;
    /*Ҫ��֤length����0, ģ0�����*/
    Queue myqueue(10);
    for (int i=0; i<n; i++) {
        myqueue.myPush(i+1);
    }


    cout<<"--------------�������-------------------------\n";
    myqueue.myOutput();
    cout<<"--------------�ָ���---------------------------\n\n\n\n\n";


    cout<<"--------------��ǰ���ж���Ԫ���ǣ�-------------\n";
    myqueue.myFront();
    cout<<"--------------�ָ���---------------------------\n\n\n\n\n";



    cout<<"--------------ִ��һ��pop()��Ķ���Ϊ��--------\n";
    myqueue.myPop();
    myqueue.myOutput();
    cout<<"--------------�ָ���---------------------------\n\n\n\n\n";


/*
    //ִ���������������2333�ŵ��������ڴ�ĵ�һ��Ԫ�ص�λ��
    cout<<"--------------ִ��һ��push()��Ķ���Ϊ��--------\n";
    myqueue.myPush(2333);
    myqueue.myOutput();
    cout<<"--------------�ָ���---------------------------\n\n\n\n\n";
*/



    cout<<"--------------������ɾ����ֻʣ��һ��------------\n";
    for(int i=0; i<n-2; i++)
        myqueue.myPop();
    myqueue.myOutput();
    cout<<"--------------�ָ���----------------------------\n\n\n\n\n";


    cout<<"--------------ɾ�����һ��Ԫ�غ������---------\n";
    myqueue.myPop();
    myqueue.myOutput();
    cout<<"--------------�ָ���----------------------------\n\n\n\n\n";


    system("pause");
    return 0;
}
