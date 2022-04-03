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
void qsort(int A[],int i,int j) //快速排序 
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
void mergesort(int A[],int temp[],int left,int right) //归并排序 
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
    for(int i=0;i<5;i++)//对5个测试文件进行快速排序和归并排序
    {
        file.open(files[i],ios::in);//打开测试文件
        Init(file);//初始化文件将数据填入序列A中
        file.close();
        QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);//开始计时
        qsort(A,0,100*pow(10,i)); //快速排序
		QueryPerformanceCounter(&nEndTime);//停止计时
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s  
    	file.open(files[i+5],ios::out);//打开测试文件
    	cout<<"数据规模为"<<100*pow(10,i)<<"的数据进行快速排序,结果为"<<time*1000<<"ms"<<endl<<endl;
        file<<"数据规模为"<<100*pow(10,i)<<"的数据进行快速排序,结果为"<<time*1000<<"ms"<<endl;
        print(file);
        QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);//开始计时
    	mergesort(A,temp,0,100*pow(10,i)); //归并排序
		QueryPerformanceCounter(&nEndTime);//停止计时
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s 
    	cout<<"数据规模为"<<100*pow(10,i)<<"的数据进行归并排序,结果为"<<time*1000<<"ms"<<endl<<endl;
        file<<"数据规模为"<<100*pow(10,i)<<"的数据进行归并排序,结果为"<<time*1000<<"ms"<<endl;
        print(file);
        file.close();
	    cout<<"---------------------------------------------------------"<<endl;
    }
    return 0;
}
