#include <stdio.h>
int main()
 {
    int n,a,b,i;
    while (scanf("%d%d",&a,&b)!=EOF)         //�ж����������һ���ΪҪ�����������ݡ���������
    {
        if (a==0&&b==0) return 0;
        printf("%d\n",a+b);
    }
        return 0;
 }
