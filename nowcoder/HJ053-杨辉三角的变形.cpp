/*
找规律
*/

#include <iostream>

using namespace std;

int main(){
    long long n;
    while(cin>>n){
        if(n <= 2){
            cout<<-1<<endl;
        }
        else{
            if((n-1)%2==0){
                cout<<2<<endl;
            }
            else{
                if(n%4==0)
                    cout<<3<<endl;
                else
                    cout<<4<<endl;
            }
        }
    }

    return 0;
}