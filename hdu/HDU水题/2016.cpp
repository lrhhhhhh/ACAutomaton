#include <stdio.h>
#include <math.h>
int a[1000];
int main()
{
    int n,t,b,c,d=1,f=0;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        if (n==0) return 0;
        c=10e9;
        for (int i=0;i<n;i++)
        {
            if (a[i]<=c)
                c=a[i];
        }
        for (int j=0;j<n;j++)
        {
            if (a[j]==c)
            {
                t=a[0];
                a[0]=c;
                a[j]=t;
            }
        }
        for (int m=0;m<n;m++)
        {
        if (d==1)                            //����fû��д����==���º���ո�һֱû�õ����
         {
            printf("%d",a[m]);
            d++;
         }
         else printf(" %d",a[m]);             //�ж����������ո���
               f=1;
        }
            if (f==1) printf("\n");
            f=0;
            d=1;                               //����d�ķ���ֵ���ڿ�ͷ��ʱ���𲻵�����
      }
    return 0;
}
