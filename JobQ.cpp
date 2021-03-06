
#include<iostream>
using namespace std;
#define size 5
class JobQue
{
private:
	struct queue
	{
		int que[size];
		int front,rear;
	}q;
public:
	JobQue();
	int Qfull();
	int insert(int);
	int Qempty();
	int delet();
	void display();
};

JobQue::JobQue()
{
	q.front=-1;
	q.rear=-1;
}

int JobQue::Qfull()
{
	if(q.rear>=size-1)
		return 1;
	else
		return 0;
}

int JobQue::insert(int item)
{
	if(q.front=-1)
	{
		q.front++;
	}
	q.que[++q.rear]=item;
	return q.rear;
}

int JobQue::Qempty()
{
	if(q.front==-1 || q.front>q.rear)
		return 1;
	else
		return 0;
}

int JobQue::delet()
{
	int item;
	item=q.que[q.front];
	q.front++;
	cout<<"\n Deleted Job is: "<<item;
	return q.front;
}

void JobQue::display()
{
	int i;
	for(i=q.front;i<=q.rear;i++)
	{
		cout<<" "<<q.que[i];
	}
}

int main()
{
	int ch,item;
	char ans;
	JobQue obj;
	do
	{
		cout<<"\n Main Menu";
		cout<<"\n 1. Add Job";
		cout<<"\n 2. Delete Job";
		cout<<"\n 3. Display Job Queue";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(obj.Qfull())
				cout<<"\nCan not insert the Job";
			else
			{
				cout<<"\n Enter the job number: ";
				cin>>item;
				obj.insert(item);
			}
			break;
		case 2:
			if(obj.Qempty())
				cout<<"\n Queue is empty";
			else
			{
				obj.delet();
			}
			break;
		case 3:
			if(obj.Qempty())
				cout<<"\n Job queue is empty";
			else
				obj.display();
			break;
		default:
			cout<<"\n Wrong choice...";
		}
		cout<<"\n Do you want to continue: ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return 0;
}
