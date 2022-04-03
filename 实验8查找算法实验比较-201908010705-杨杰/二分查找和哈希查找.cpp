#include <iostream>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <windows.h>
using namespace std;
LARGE_INTEGER frequency;//ʱ��Ƶ��
const int maxn=1e6;//1M
bool hashtable[maxn+5]={0};//��¼������Ƿ���
int array[maxn+5]={0};//�洢�����������
int su[105]={0},fa[105]={0};
double begin_,_end,dft,dff,dfm;
void Init(fstream &infile,int A[])//���ļ����룬��������
{
	int a,i=0;
	while(!infile.eof()&&i<maxn)
	{
		infile>>a;
		A[i]=a;
		i++;
	}
}
void print(fstream &outfile,int n,int A[])//���
{
	for(int i=0;i<n;i++)
	{
		outfile<<A[i]<<' ';
	}
}
void Init(fstream &infile,int A[],bool Hash[])//���ļ�����,��������
{
	int a,i=0,key;
	fill(Hash,Hash+maxn,0);//��ʼ��hash��
	while((!infile.eof())&&i<maxn)
	{
		infile>>a;
		A[i]=a;
		key=a%maxn;
		Hash[key]=1;//key(x)=x;hash��������Ϊ����hash
		i++;
	}
}
void binarysearch(fstream& outfile,int A[],int n,int S[],int F[])//���ֲ���
{
    sort(A,A+n);//��������
    int mid,num=0,x,left,right;//�м�ֵ�ͱȽϴ���
    double mints=100,maxts=0,averages=0;
    double mintf=100,maxtf=0,averagef=0;
    bool flag;
    for(int i=0;i<200;i++)//100�γɹ�������100��ʧ�ܲ���
    {
        x=(i<100)?S[i%100]:F[i%100];//ȷ�������ҵ���x
        num=0;//��ʼ�����Ҵ���Ϊ0
        left=0,right=n-1;
        flag=0;
        QueryPerformanceCounter(&frequency);
        begin_=frequency.QuadPart;//��ó�ʼֵ

        while(left<=right)//���ֲ���
        {
            num++;//�Ƚϴ�����һ
            mid=(left+right)/2;//�Ż�mid=left+(right-left)/2;��ֹ���
            if(A[mid]==x)
            {
                flag=1;//���ҳɹ�
                break;
            }
            else if(A[mid]>x) right=mid-1;//����������������/2�����Ҳ��������
            else left=mid+1;
        }

        QueryPerformanceCounter(&frequency);
        _end=frequency.QuadPart;//�����ֵֹ
        dfm=(double)(_end-begin_);//��ֵ
        dft=dfm/dff;//��ֵ����Ƶ�ʵõ�ʱ��
        if(flag)//���ҳɹ�
        {
            cout<<"���ֲ��Ҽ�¼->"<<x<<"->�ɹ�		"<<"���Ҵ���: "<<num<<"��";
            outfile<<"���ֲ��Ҽ�¼:"<<x<<"->�ɹ�		"<<"���Ҵ���: "<<num<<"��";
            mints=min(mints,dft*1000);//��Сʱ��
            maxts=max(maxts,dft*1000);//���ʱ��
            averages+=dft*10;//ƽ��ʱ��
        }
        else
        {
            cout<<"���ֲ��Ҽ�¼->"<<x<<"->ʧ��		"<<"���Ҵ���: "<<num<<"��";
            outfile<<"���ֲ��Ҽ�¼:"<<x<<"->ʧ��		"<<"���Ҵ���: "<<num<<"��";
            mintf=min(mintf,dft*1000);//��Сʱ��
            maxtf=max(maxtf,dft*1000);//���ʱ��
            averagef+=dft*10;//ƽ��ʱ��
        }
        cout<<"����ʱ��: "<<dft*1000<<"ms"<<endl;
        outfile<<"����ʱ��: "<<dft*1000<<"ms"<<endl;
    }
    cout<<"���ֲ��ҳɹ�����С����ʱ��mints="<<mints<<"ms	    "<<"������ʱ��maxts="<<maxts<<"ms		"<<"ƽ������ʱ��averages="<<averages<<"ms\n���ҽ���\n";
    outfile<<"���ֲ��ҳɹ�����С����ʱ��mints="<<mints<<"ms		"<<"������ʱ��maxts="<<maxts<<"ms		"<<"ƽ������ʱ��averages="<<averages<<"ms\n���ҽ���\n";

    cout<<"���ֲ���ʧ�ܣ���С����ʱ��mintf="<<mintf<<"ms		"<<"������ʱ��maxtf="<<maxtf<<"ms		"<<"ƽ������ʱ��averagef="<<averagef<<"ms\n���ҽ���\n";
    outfile<<"���ֲ���ʧ�ܣ���С����ʱ��mints="<<mintf<<"ms		"<<"������ʱ��maxtf="<<maxtf<<"ms		"<<"ƽ������ʱ��averagef="<<averagef<<"ms\n���ҽ���\n";
}
void hashsearch(fstream &outfile,bool H[],int S[],int F[])//hashɢ�в���
{
    double mints=100,maxts=0,averages=0;
    double mintf=100,maxtf=0,averagef=0;
    bool flag;
    int x;
    int num=1;
    for(int i=0;i<200;i++)//100�γɹ�������100��ʧ�ܲ��� 
    {
        flag=0;
        x=(i<100)?S[i%100]:F[i%100];
        QueryPerformanceCounter(&frequency);
        begin_=frequency.QuadPart;//��ó�ʼֵ

        if(H[x]) flag=1;//���ҳɹ�

        QueryPerformanceCounter(&frequency);
        _end=frequency.QuadPart;//�����ֵֹ
        dfm=(double)(_end-begin_);//��ֵ
        dft=dfm/dff;//��ֵ����Ƶ�ʵõ�ʱ��
        if(flag)
        {
            cout<<"hash���Ҽ�¼:"<<x<<"->�ɹ�		"<<"���Ҵ���:"<<num<<" ��";
            outfile<<"hash���Ҽ�¼:"<<x<<"->�ɹ�		"<<"���Ҵ���:"<<num<<" ��";
            mints=min(mints,dft*1000);//��Сʱ��
            maxts=max(maxts,dft*1000);//���ʱ��
            averages+=dft*10;//ƽ��ʱ��
        }
        else
        {
            cout<<"hash���Ҽ�¼:"<<x<<"->ʧ��		"<<"���Ҵ���:"<<num<<" ��";
            outfile<<"hash���Ҽ�¼:"<<x<<"->ʧ��		"<<"���Ҵ���:"<<num<<" ��";
            mintf=min(mintf,dft*1000);//��Сʱ��
            maxtf=max(maxtf,dft*1000);//���ʱ��
            averagef+=dft*10;//ƽ��ʱ��
        }
        cout<<"����ʱ��: "<<dft*1000<<"ms"<<endl;
        outfile<<"����ʱ��: "<<dft*1000<<"ms"<<endl;
    }
    cout<<"hash���ҳɹ�: ��С����ʱ��mints="<<mints<<"ms	"<<"������ʱ��maxts="<<maxts<<"ms		"<<"ƽ������ʱ��averages="<<averages<<"ms\n���ҽ���\n";
    outfile<<"hash���ҳɹ�����С����ʱ��mints="<<mints<<"ms		"<<"������ʱ��maxts="<<maxts<<"ms		"<<"ƽ������ʱ��averages="<<averages<<"ms\n���ҽ���\n";

    cout<<"hash����ʧ�ܣ���С����ʱ��mintf="<<mintf<<"ms	"<<"������ʱ��maxtf="<<maxtf<<"ms		"<<"ƽ������ʱ��averagef="<<averagef<<"ms\n���ҽ���\n";
    outfile<<"hash����ʧ�ܣ���С����ʱ��mintf="<<mintf<<"ms		"<<"������ʱ��maxtf="<<maxtf<<"ms		"<<"ƽ������ʱ��averagef="<<averagef<<"ms\n���ҽ���\n";
}
int main()
{
    string files[12]={"100.txt","1k.txt","10k.txt","100k.txt","1M.txt","sucess.txt","fail.txt",
                    "out_100.txt","out_1k.txt","out_10k.txt","out_100k.txt","out_1M.txt"};
    fstream file;
    //���������ļ���������ʼ����
    QueryPerformanceFrequency(&frequency);//���ʱ��Ƶ��
	dff=(double)frequency.QuadPart;//ȡ��Ƶ��

	file.open(files[5],ios::in);
    Init(file,su);//����ɹ���������
    file.close();

    file.open(files[6],ios::in);
    Init(file,fa);//����ʧ�ܲ�������
    file.close();

    for(int i=0;i<5;i++)//��5�������ļ����ж��ֲ��Һ�hash����
    {
        file.open(files[i],ios::in);//�򿪲����ļ�
        Init(file,array,hashtable);//��ʼ���ļ���������������arr�в��ұ��hash��
        file.close();
        file.open(files[i+7],ios::out);//�򿪲����ļ�
        cout<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ���hash����,�������"<<endl;
        file<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ���hash����,�������"<<endl;
        hashsearch(file,hashtable,su,fa);

        cout<<"---------------------------------------------------------"<<endl;
        cout<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ���binary����,�������"<<endl;
        file<<"���ݹ�ģΪ"<<100*pow(10,i)<<"�����ݽ���binary����,�������"<<endl;
        binarysearch(file,array,100*pow(10,i),su,fa);
        file.close();//�ر��ļ�
    }
    return 0;
}
