#include <iostream>
#include <time.h>
#include <fstream>
#include <cmath>
#define random(x) (int)(((double)rand()/RAND_MAX)*pow(10,rand()%x))
using namespace std;
const int maxn=1e6;//1M
int array[maxn+5]={0};//�洢�����������
void print(fstream &outfile,int n,int A[])//���
{
	for(int i=0;i<n;i++)
	{
		outfile<<A[i]<<endl;
	}
}
int main()
{
    srand((int)time(NULL));//time seed
    string files[5]={"100.txt","1k.txt","10k.txt","100k.txt","1M.txt"};
    fstream file;
    for(int i=0;i<maxn;i++)//�������1M������
    {
        array[i]=random(7);
    }
    int k=100;
    for(int i=0;i<5;i++)//װ��5��test�ļ�
    {
        file.open(files[i],ios::out);//���ļ�
        print(file,k,array);
        file.close();//�ر��ļ�
        k*=10;
    }
    cout<<"����������ɹ���"<<endl;
    return 0;
}
