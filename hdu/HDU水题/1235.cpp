#include <stdio.h>
int a[1000];
int main()
{
    int N,M,i,sum=0;
    while (scanf("%d",&N)!=EOF)
    {
        if(N==0)
            return 0;
        for (i=0;i<N;i++) scanf("%d",&a[i]);
        scanf("%d",&M);
        for (i=0;i<N;i++)
        {
            if (a[i]==M)
            sum++;
        }
        printf("%d\n",sum);
        sum=0;             //����û�з���0��Ȼ��Ӱ����һ���������������ǰ�治��sum=0���𡣡�����


    }
    return 0;
}
