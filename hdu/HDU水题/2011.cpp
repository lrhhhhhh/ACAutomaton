#include <stdio.h>
int x[100];
int main()
{
    int m,i,j;
    double sum,k;
    while (scanf("%d",&m)!=EOF)
    {
       for (i=0;i<m;i++)
        {
            scanf("%d",&x[i]);           //����ѭ�����������Ȼ�ᵼ�´𰸲�һ��!!!!
            k=1.0;
            sum=0;

        for (j=1;j<=x[i];j++)            //��������ѭ���ڲ��Ĳ�������i��Ҫ���ı���;����Ҫ��1.0��������1
        {
            sum=sum+k*1.0/j;
            k=-k;
        }
        printf("%.2lf\n",sum);
        }
    }
    return 0;

}
