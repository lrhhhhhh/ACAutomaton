#include <stdio.h>
int main()
{
    long m,n,i,x,y,temp;
    while (scanf("%ld%ld\n",&m,&n)!=EOF)
    {
        x=0;
        y=0;
        if (m>n)
            {
                temp=m;            //�Ӱ����Բ۲��ǰ���С����ģ�������
                m=n;
                n=temp;
            }
        for (i=m;i<=n;i++)
        {
            if(i%2!=0) y=y+(i*i*i);
            else x=x+(i*i);
        }
        printf("%ld %ld\n",x,y);
    }
    return 0;
}
