#include <stdio.h>
int a[1000];
int main()
{
    int n;
    double p,b,c,sum;
    while (scanf("%d",&n)!=EOF)
    {
        c=100.0;
        b=0;
        sum=0;              //sum��Ȼ���Ƿ���ֵ��
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
        {
            if (a[i]<=c) c=a[i];   //��������ֵ������ֵû�䡣������
            if (a[i]>=b) b=a[i];
            sum=sum+a[i];
        }
        p=(sum*1.0-c-b)/(n-2);  //ע�⸡����
        printf("%.2lf\n",p);

    }
    return 0;
}
