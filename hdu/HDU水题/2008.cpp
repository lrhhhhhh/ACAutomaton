#include <stdio.h>
double x[1000];
int main()
{
    int i,n,a,b,c;
    while (scanf("%d",&n)!=EOF)
    {
        if (n!=0)
        {
          a=b=c=0;
        for (i=0;i<n;i++) scanf("%lf",&x[i]);       //ע��ĵط�ʱ������С�������԰����鶨��Ϊ����ģ���Ȼ����
        for (i=0;i<n;i++)
        {
            if(x[i]<0) a+=1;
            if(x[i]==0) b+=1;
            if(x[i]>0) c+=1;
        }
        printf("%d %d %d\n",a,b,c);
        }
        else return 0;

    }
    return 0;
}
