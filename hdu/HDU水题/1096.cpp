
#include <stdio.h>
int main()
{
    int a,n,m,sum;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        sum=0;
        while (m--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
        if (i!=n-1)
        printf("\n",sum);        //��������һ�����жϣ���˼�����Ľ��������һ�С������������ðɣ��������Ľ������Ҫ��һ��
    }
    return 0;
}
