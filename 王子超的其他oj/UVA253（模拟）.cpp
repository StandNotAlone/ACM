#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
using namespace std;
                                    //���Է��ְ�����Ŀ��������������뷽�����Գ�����ı�ż������պ���7
                                    //color����洢������ַ�������ô����1�ĶԳ������������5
int cases[6][4]=                    //��cases[i]����洢����i���ڵײ�ʱ����������α��˳������֮�����ת�ȶ�
{
    1,2,4,3,
    0,3,5,2,
    0,1,5,4,
    0,4,5,1,
    0,2,5,3,
    1,3,4,2
};

int figure2[4]={7,8,10,9};          //������2�ĵ�һ���ڵײ�����color[6]��figure�洢��������νǱ�˳�򷽱����

int main()
{
    char color[20];
    while(scanf("%s",color)!=EOF)
    {
        int Flag=0;                 //Flag��־�������Ƿ���ת��ȼۣ������ʵ��˼��������2��1�泯�£�Ȼ������1��6�����γ��£���תȥ�ȶ�
        for(int i=0;i<6;i++)
        {
            if(color[i]==color[6]&&color[5-i]==color[11]) //������ӵĵ���Ͷ�����ɫ��ͬ��ʼ��ת�ȶ�
            {
                for(int j=0;j<4;j++)                    //��תj��90��
                {
                    int flag=1;                         //flag��־������ת����������Ƿ�ȼ�
                    for(int k=0;k<4;k++)                //�Ա�����
                    if(color[cases[i][(j+k)%4]]!=color[figure2[k]]) flag=0; //(j+k)%4Ϊ��תj�κ����ĵ�k��
                    if(flag)
                    {
                        Flag=1;
                        break;
                    }
                }
            }
        }
        if(Flag) printf("TRUE\n");
        else printf("FALSE\n");
    }
}
