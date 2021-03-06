
#include<iostream>
using namespace std;
#define N 10
int SentinelSearch(int A[N+1],int max,int key)
{
	int i;
	A[max]=key;
	i=0;
	while(A[i]!=key)
		i++;
	A[max]=-1;
	if(i!=max)
		return 1;
	else
		return 0;
}

int LinearSearch(int A[N],int max,int key)
{
	for(int i=0;i<max;i++)
	{
		if(A[i]==key)
			return 1;
	}
	return 0;
}

int BinarySearch(int A[N],int key,int low,int high)
{
	int mid;
	if(low>high)
		return -1;
	mid=(low+high)/2;
	cout<<mid<<endl;
	if(key>A[mid])
		return BinarySearch(A,key,mid+1,high);
	else if(key<A[mid])
		return BinarySearch(A,key,low,mid-1);
	else
		return mid;
}

int Fib(int n)
{
	int a,b,f;
	if(n<1)
		return n;
	a=0;
	b=1;
	while(b<n)
	{
		f=a+b;
		a=b;
		b=f;
	}
	return a;
}

void FibSearch(int A[N],int n,int key,int f,int b,int a)
{
	if(f<1||f>n)
		cout<<"\n Student has not attended training.";
	else if(key<A[f-1])
	{
		if(a<=0)
			cout<<"\n Student has not attended training.";
		else
			FibSearch(A,n,key,f-a,a,b-a);
	}
	else if(key>A[f])
	{
		if(b<=1)
			cout<<"\n Student has not attended training.";
		else
			FibSearch(A,n,key,f+a,b-a,a-b);
	}
	else
		cout<<"\n Student has attended training.";
}

int main()
{
	int key,ch,ch1;
	int max,result;
	char ans;
	int a[N];
	cout<<"\n Total number of students who attended training: ";
	cin>>max;
	do
	{
		cout<<"\n 1. Random";
		cout<<"\n 2. Sorted";
		cout<<"\n Enter choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n Enter roll number of students who attended training";
			for(int i=0;i<max;i++)
			{
				cin>>a[i];
			}
			cout<<"\n The roll number of the students are....";
			for(int i=0;i<max;i++)
			{
				cout<<"\n"<<a[i];
			}
			do{
				cout<<"\n Enter roll number to search: ";
				cin>>key;
				cout<<"\n 1. Linear Search";
				cout<<"\n 2. Sentinel Search";
				cout<<"\n Enter choice: ";
				cin>>ch1;
				switch(ch1)
				{
				case 1:
					if(LinearSearch(a,max-1,key)==1)
						cout<<"\n The student has attended training program";
					else
						cout<<"\n The student has not attended training program";
					break;
				case 2:
					if(SentinelSearch(a,max,key)==1)
						cout<<"\n The student has attended training program";
					else
						cout<<"\n The student has not attended training program";
					break;
				}
				cout<<"\n Do you want to continue: ";
				cin>>ans;
			}while(ans=='y');
			break;
		case 2:
			cout<<"\n Enter roll number of students who attended training in ascending order";
			for(int i=0;i<max;i++)
			{
				cin>>a[i];
			}
			cout<<"\n The roll number of the students are....";
			for(int i=0;i<max;i++)
			{
				cout<<"\n"<<a[i];
			}
			do{
				cout<<"\n Enter roll number to search: ";
				cin>>key;
				cout<<"\n 1. Binary Search";
				cout<<"\n 2. Fibonacci Search";
				cout<<"\n Enter choice: ";
				cin>>ch1;
				switch(ch1)
				{
				case 1:
					result=BinarySearch(a,key,0,max-1);
					if(result!=-1)
						cout<<"\n The student has attended training program";
					else
						cout<<"\n The student has not attended training program";
					break;
				case 2:
					FibSearch(a,max-1,key,max-1,Fib(max-1),Fib(Fib(max-1)));
					break;
				}
				cout<<"\n Do you want to continue: ";
				cin>>ans;
			}while(ans=='y');
			break;
		}
		cout<<"\n Do you want to continue: ";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
