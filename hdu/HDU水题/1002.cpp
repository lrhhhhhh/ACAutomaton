#include <stdio.h>
#include <string.h>
char s[100];
char v[100];
int p[100]={0};
int main()
{
    int a,b;
    int n;
    while (scanf("%d",&n)!=EOF)   //������=1���ǵȼ۵��𡣡�����
    {
        scanf("%s%s",s,v);
        a=strlen(s);
        b=strlen(v);

        for (int i=b-1;i>=0;i--)       // ����Ĭ��v�ıȽϳ�
        {

               p[i]=v[i]+s[i-b+a]+p[i]-96;   //�ַ���ӣ����ˣ����Ǹĳ�ASCII��Ӽ�96.�������ټ���������
               if(p[i]>=10)
               {
                   p[i-1]++;   //p[-1]����ʲô���
                   p[i]=p[i]-10;
               }               //�׵�����ѭ�������break��������ѭ����ȥ��
        }
        for (int k=0;k<b;k++)       //��ѽ��������������⣬ѭ������ĸ����ᱻ��ʮ��һ����
        printf("%d",p[k]);
    }
    return 0;
}
