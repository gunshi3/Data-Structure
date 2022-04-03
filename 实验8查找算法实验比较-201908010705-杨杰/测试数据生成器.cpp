#include <iostream>
#include <time.h>
#include <fstream>
#include <cmath>
#define random(x) (int)(((double)rand()/RAND_MAX)*pow(10,rand()%x))
using namespace std;
const int maxn=1e6;//1M
bool hashtable[maxn+5]={0};//��¼������Ƿ���
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
    string files[7]={"100.txt","1k.txt","10k.txt","100k.txt","1M.txt","sucess.txt","fail.txt"};
    fstream file;
    for(int i=0;i<maxn;i++)//�������1M������
    {
        array[i]=random(7);
        hashtable[array[i]]=1;
    }
    int k=100;
    for(int i=0;i<5;i++)//װ��5��test�ļ�
    {
        file.open(files[i],ios::out);//���ļ�
        print(file,k,array);
        file.close();//�ر��ļ�
        k*=10;
    }
    
    file.open(files[5],ios::out);
    print(file,100,array);//�ɹ����������ļ�
    file.close();

    file.open(files[6],ios::out);
    int num=0,number=0;
    while(num<100)
    {
		number=random(7);
        if(!hashtable[number])
        {
            file<<number<<endl;
            num++;
        }
    }
    file.close();
    cout<<"����������ɹ���"<<endl;
    return 0;
}
