

#include<iostream>
using namespace std;
#define max 20
class Sort
{
	float a[max];
	int n;
public:
	Sort();
	void get_data();
	void BubbleSort();
	void SelectionSort();
	void display();
};
Sort::Sort()
{
	for(int i=0;i<max;i++)
	{
		a[i]=0;
	}
}

void Sort::BubbleSort()
{
	int i,j;
	float temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void Sort::SelectionSort()
{
	int i,j;
	float temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void Sort::get_data()
{
	cout<<"\n Enter number of students: ";
	cin>>n;
	cout<<"\n Enter the percentage marks of students....";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void Sort::display()
{
	cout<<"\n The percentage of top five students: ";
	for(int i=n-1;i>=n-5;i--)
	{
		cout<<"\n"<<a[i];
	}
}

int main()
{
	Sort s;
	int ch;
	char ans;
	do
	{
		cout<<"\n Menu options";
		cout<<"\n 1. Selection Sort";
		cout<<"\n 2. Bubble Sort";
		cout<<"\n Enter choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			s.get_data();
			s.SelectionSort();
			s.display();
			break;
		case 2:
			s.get_data();
			s.BubbleSort();
			s.display();
			break;
		}
		cout<<"\n Do you want to continue: ";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
