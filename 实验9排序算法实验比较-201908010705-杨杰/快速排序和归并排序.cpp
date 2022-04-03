#include <iostream>
#include <fstream>
#include <windows.h>
#include <cmath>
using namespace std;
int A[1000001],temp[1000001];
int count=0;
void Init(fstream &infile)
{
    int a;
    count=0;
    while(!infile.eof())
    {
        infile>>a;
        A[count]=a;
        count++;
    }
}
void print(fstream &outfile)
{
    for(int i=0;i<count;i++)
    {
        outfile<<A[i]<<endl;
    }
}
int partition(int A[],int l,int r,int p)
{
    do
    {
        while(A[++l]<p);
        while(l<r&&A[--r]>p);
        swap(A[l],A[r]);
    }
    while(l<r);
    return l;
}
void qsort(int A[],int i,int j) //�������� 
{
    if(j<=i) 
        return;
    int p=(i+j)/2;
    swap(A[p],A[j]);
    int k=partition(A,i-1,j,A[j]);
    swap(A[k],A[j]);
    qsort(A,i,k-1);
    qsort(A,k+1,j);
}
bool cmp(int x,int y)
{
    return x<y;
}
void mergesort(int A[],int temp[],int left,int right) //�鲢���� 
{
    if(left==right)
        return;
    int mid=(left+right)/2;
    mergesort(A,temp,left,mid);
    mergesort(A,temp,mid+1,right);
    for(int i=left;i<=right;i++)
        temp[i]=A[i];
    int i1=left;
    int i2=mid+1;
    for(int curr=left;curr<=right;curr++)
    {
        if(i1==mid+1)
            A[curr]=temp[i2++];
        else if(i2>right)
            A[curr]=temp[i1++];
        else if(cmp(temp[i1],temp[i2]))
            A[curr]=temp[i1++];
        else 
            A[curr]=temp[i2++];
    }
}

int main()
{
	string files[10]={"100.txt","1k.txt","10k.txt","100k.txt","1M.txt",
					"out_100.txt","out_1k.txt","out_10k.txt","out_100k.txt","out_1M.txt"};
    fstream file;
	double time=0;  
	LARGE_INTEGER nFreq,nBeginTime,nEndTime;
    for(int i=0;i<5;i++)//��5�������ļ����п�������͹鲢����
    {
        file.open(files[i],ios::in);//�򿪲����ļ�
        Init(file);//��ʼ���ļ���������������A��
        file.close();
        QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
        qsort(A,0,100*pow(10,i)); //��������
		QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
    	file.open(files[i+5],ios::out);//�򿪲����ļ�
    	cout<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ��п�������,���Ϊ"<<time*1000<<"ms"<<endl<<endl;
        file<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ��п�������,���Ϊ"<<time*1000<<"ms"<<endl;
        print(file);
        QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    	mergesort(A,temp,0,100*pow(10,i)); //�鲢����
		QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs 
    	cout<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ��й鲢����,���Ϊ"<<time*1000<<"ms"<<endl<<endl;
        file<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ��й鲢����,���Ϊ"<<time*1000<<"ms"<<endl;
        print(file);
        file.close();
	    cout<<"---------------------------------------------------------"<<endl;
    }
    return 0;
}
