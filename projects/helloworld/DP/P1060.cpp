#include<iostream>
#include<algorithm>
using namespace std;
int w[30],v[30],f[50000];//w����Ϊ��Ҫ�ȣ�v����Ϊmoney��f������dp������
int n,m;//n������Ʒ������m����Ǯ��
int main()
{
    cin>>m>>n;//����
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
        w[i]*=v[i];//w���������������Ϊ���ջ���Ҫ��*money��
    }
       //01���������յڶ���ģ�塰һά�����Ż�����
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)//ע���m��ʼ
        {
            if(j>=v[i])
            {
                f[j]=max(f[j],f[j-v[i]]+w[i]);//dp
            }
        }
    }
    cout<<f[m]<<endl;//������СΪmʱ���ֵ
    return 0;
} 