#include <stdio.h>
#include <math.h>
int main()
{
    int x,y,n,i,temp,j;
    while (scanf("%d %d",&x,&y)!=EOF)
    {

        if (x==0&&y==0) return 0;
        else
        {
            n=0;
            for (i=x;i<y+1;i++)
        {
            j=i*i+i+41;
            for (int a=2;a<j;a++)
            {
               if(j%a==0) n++;   //������һ��ʼ��j%a!=0������߼��Ǵ�ģ���������һ�γ�����������Ϊ�㣬����n����1�������жϵ�ʱ����n��=0���ж���������ʹ���
            }

        }
        if (n==0) printf("OK\n");
        else printf("Sorry\n");
    }
    }
    return 0;
}

