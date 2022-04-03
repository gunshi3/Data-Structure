#include <iostream>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <windows.h>
using namespace std;
LARGE_INTEGER frequency;//时钟频率
const int maxn=1e6;//1M
bool hashtable[maxn+5]={0};//记录随机数是否发生
int array[maxn+5]={0};//存储产生的随机数
int su[105]={0},fa[105]={0};
double begin_,_end,dft,dff,dfm;
void Init(fstream &infile,int A[])//从文件输入，函数重载
{
	int a,i=0;
	while(!infile.eof()&&i<maxn)
	{
		infile>>a;
		A[i]=a;
		i++;
	}
}
void print(fstream &outfile,int n,int A[])//输出
{
	for(int i=0;i<n;i++)
	{
		outfile<<A[i]<<' ';
	}
}
void Init(fstream &infile,int A[],bool Hash[])//从文件输入,函数重载
{
	int a,i=0,key;
	fill(Hash,Hash+maxn,0);//初始化hash表
	while((!infile.eof())&&i<maxn)
	{
		infile>>a;
		A[i]=a;
		key=a%maxn;
		Hash[key]=1;//key(x)=x;hash函数定义为线性hash
		i++;
	}
}
void binarysearch(fstream& outfile,int A[],int n,int S[],int F[])//二分查找
{
    sort(A,A+n);//升序排列
    int mid,num=0,x,left,right;//中间值和比较次数
    double mints=100,maxts=0,averages=0;
    double mintf=100,maxtf=0,averagef=0;
    bool flag;
    for(int i=0;i<200;i++)//100次成功查找与100次失败查找
    {
        x=(i<100)?S[i%100]:F[i%100];//确定待查找的数x
        num=0;//初始化查找次数为0
        left=0,right=n-1;
        flag=0;
        QueryPerformanceCounter(&frequency);
        begin_=frequency.QuadPart;//获得初始值

        while(left<=right)//二分查找
        {
            num++;//比较次数加一
            mid=(left+right)/2;//优化mid=left+(right-left)/2;防止溢出
            if(A[mid]==x)
            {
                flag=1;//查找成功
                break;
            }
            else if(A[mid]>x) right=mid-1;//避免相邻区间整形/2，查找不到的情况
            else left=mid+1;
        }

        QueryPerformanceCounter(&frequency);
        _end=frequency.QuadPart;//获得终止值
        dfm=(double)(_end-begin_);//差值
        dft=dfm/dff;//差值除以频率得到时间
        if(flag)//查找成功
        {
            cout<<"二分查找记录->"<<x<<"->成功		"<<"查找次数: "<<num<<"次";
            outfile<<"二分查找记录:"<<x<<"->成功		"<<"查找次数: "<<num<<"次";
            mints=min(mints,dft*1000);//最小时间
            maxts=max(maxts,dft*1000);//最大时间
            averages+=dft*10;//平均时间
        }
        else
        {
            cout<<"二分查找记录->"<<x<<"->失败		"<<"查找次数: "<<num<<"次";
            outfile<<"二分查找记录:"<<x<<"->失败		"<<"查找次数: "<<num<<"次";
            mintf=min(mintf,dft*1000);//最小时间
            maxtf=max(maxtf,dft*1000);//最大时间
            averagef+=dft*10;//平均时间
        }
        cout<<"查找时间: "<<dft*1000<<"ms"<<endl;
        outfile<<"查找时间: "<<dft*1000<<"ms"<<endl;
    }
    cout<<"二分查找成功：最小查找时间mints="<<mints<<"ms	    "<<"最大查找时间maxts="<<maxts<<"ms		"<<"平均查找时间averages="<<averages<<"ms\n查找结束\n";
    outfile<<"二分查找成功：最小查找时间mints="<<mints<<"ms		"<<"最大查找时间maxts="<<maxts<<"ms		"<<"平均查找时间averages="<<averages<<"ms\n查找结束\n";

    cout<<"二分查找失败：最小查找时间mintf="<<mintf<<"ms		"<<"最大查找时间maxtf="<<maxtf<<"ms		"<<"平均查找时间averagef="<<averagef<<"ms\n查找结束\n";
    outfile<<"二分查找失败：最小查找时间mints="<<mintf<<"ms		"<<"最大查找时间maxtf="<<maxtf<<"ms		"<<"平均查找时间averagef="<<averagef<<"ms\n查找结束\n";
}
void hashsearch(fstream &outfile,bool H[],int S[],int F[])//hash散列查找
{
    double mints=100,maxts=0,averages=0;
    double mintf=100,maxtf=0,averagef=0;
    bool flag;
    int x;
    int num=1;
    for(int i=0;i<200;i++)//100次成功查找与100次失败查找 
    {
        flag=0;
        x=(i<100)?S[i%100]:F[i%100];
        QueryPerformanceCounter(&frequency);
        begin_=frequency.QuadPart;//获得初始值

        if(H[x]) flag=1;//查找成功

        QueryPerformanceCounter(&frequency);
        _end=frequency.QuadPart;//获得终止值
        dfm=(double)(_end-begin_);//差值
        dft=dfm/dff;//差值除以频率得到时间
        if(flag)
        {
            cout<<"hash查找记录:"<<x<<"->成功		"<<"查找次数:"<<num<<" 次";
            outfile<<"hash查找记录:"<<x<<"->成功		"<<"查找次数:"<<num<<" 次";
            mints=min(mints,dft*1000);//最小时间
            maxts=max(maxts,dft*1000);//最大时间
            averages+=dft*10;//平均时间
        }
        else
        {
            cout<<"hash查找记录:"<<x<<"->失败		"<<"查找次数:"<<num<<" 次";
            outfile<<"hash查找记录:"<<x<<"->失败		"<<"查找次数:"<<num<<" 次";
            mintf=min(mintf,dft*1000);//最小时间
            maxtf=max(maxtf,dft*1000);//最大时间
            averagef+=dft*10;//平均时间
        }
        cout<<"查找时间: "<<dft*1000<<"ms"<<endl;
        outfile<<"查找时间: "<<dft*1000<<"ms"<<endl;
    }
    cout<<"hash查找成功: 最小查找时间mints="<<mints<<"ms	"<<"最大查找时间maxts="<<maxts<<"ms		"<<"平均查找时间averages="<<averages<<"ms\n查找结束\n";
    outfile<<"hash查找成功：最小查找时间mints="<<mints<<"ms		"<<"最大查找时间maxts="<<maxts<<"ms		"<<"平均查找时间averages="<<averages<<"ms\n查找结束\n";

    cout<<"hash查找失败：最小查找时间mintf="<<mintf<<"ms	"<<"最大查找时间maxtf="<<maxtf<<"ms		"<<"平均查找时间averagef="<<averagef<<"ms\n查找结束\n";
    outfile<<"hash查找失败：最小查找时间mintf="<<mintf<<"ms		"<<"最大查找时间maxtf="<<maxtf<<"ms		"<<"平均查找时间averagef="<<averagef<<"ms\n查找结束\n";
}
int main()
{
    string files[12]={"100.txt","1k.txt","10k.txt","100k.txt","1M.txt","sucess.txt","fail.txt",
                    "out_100.txt","out_1k.txt","out_10k.txt","out_100k.txt","out_1M.txt"};
    fstream file;
    //产生测试文件结束，开始查找
    QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;//取得频率

	file.open(files[5],ios::in);
    Init(file,su);//输入成功查找数据
    file.close();

    file.open(files[6],ios::in);
    Init(file,fa);//输入失败查找数据
    file.close();

    for(int i=0;i<5;i++)//对5个测试文件进行二分查找和hash查找
    {
        file.open(files[i],ios::in);//打开测试文件
        Init(file,array,hashtable);//初始化文件将数据填入序列arr中并且标记hash表
        file.close();
        file.open(files[i+7],ios::out);//打开测试文件
        cout<<"数据规模为"<<100*pow(10,i)<<"的数据进行hash查找,结果如下"<<endl;
        file<<"数据规模为"<<100*pow(10,i)<<"的数据进行hash查找,结果如下"<<endl;
        hashsearch(file,hashtable,su,fa);

        cout<<"---------------------------------------------------------"<<endl;
        cout<<"数据规模为"<<100*pow(10,i)<<"的数据进行binary查找,结果如下"<<endl;
        file<<"数据规模为"<<100*pow(10,i)<<"的数据进行binary查找,结果如下"<<endl;
        binarysearch(file,array,100*pow(10,i),su,fa);
        file.close();//关闭文件
    }
    return 0;
}
