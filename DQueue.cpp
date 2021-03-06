
#include<iostream>
using namespace std;
#define size 5

struct queue
{
	int que[size];
	int front,rear;
}q;

class DeQue
{
public:
	DeQue();
	int Qfull();
	int Qempty();
	int insert_rear(int item);
	int delete_front();
	int insert_front(int item);
	int delete_rear();
	void display();
};
DeQue::DeQue()
{
	q.front=-1;
	q.rear=-1;
	for(int i=0;i<size;i++)
		q.que[i]=-1;
}

int DeQue::Qfull()
{
	if(q.rear==size-1)
		return 1;
	else
		return 0;
}

int DeQue::Qempty()
{
	if(q.front>q.rear || (q.front==-1 && q.rear==-1))
		return 1;
	else
		return 0;
}

int DeQue::insert_rear(int item)
{
	if(q.front==-1 && q.rear==-1)
		q.front++;
	q.que[++q.rear]=item;
	return q.rear;
}

int DeQue::delete_front()
{
	int item;
	if(q.front==-1)
		q.front++;
	item=q.que[q.front];
	q.que[q.front]=-1;
	q.front++;
	return item;
}

int DeQue::insert_front(int item)
{
	int i,j;
	if(q.front==-1)
		q.front++;
	i=q.front-1;
	while(i>=0)
	{
		q.que[i+1]=q.que[i];
		i--;
	}
	j=q.rear;
	while(j>=q.front)
	{
		q.que[j+1]=q.que[j];
		j--;
	}
	q.rear++;
	q.que[q.front]=item;
	return q.front;
}

int DeQue::delete_rear()
{
	int item;
	item=q.que[q.rear];
	q.que[q.rear]=-1;
	q.rear--;
	return item;
}

void DeQue::display()
{
	int i;
	cout<<"\n Straight queue is: \n";
	for(i=q.front;i<=q.rear;i++)
	{
		cout<<" "<<q.que[i];
	}
}

int main()
{
	int ch,item;
	char ans;
	DeQue obj;
	do
	{
		cout<<"\n Menu";
		cout<<"\n 1. Insert from rear";
		cout<<"\n 2. Delete from front";
		cout<<"\n 3. Insert from front";
		cout<<"\n 4. Delete from rear";
		cout<<"\n 5. Display";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(obj.Qfull())
				cout<<"\n Queue is full";
			else
			{
				cout<<"\n Enter the element to be inserted";
				cin>>item;
				q.rear=obj.insert_rear(item);
			}
			break;
		case 2:
			if(obj.Qempty())
				cout<<"\n Queue is empty";
			else
			{
				item=obj.delete_front();
				cout<<"\n The deleted element is "<<item;
			}
			break;
		case 3:
			if(obj.Qfull())
				cout<<"\n Queue is full";
			else
			{
				cout<<"\n Enter element to be inserted: ";
				cin>>item;
				q.front=obj.insert_front(item);
			}
			break;
		case 4:
			if(obj.Qempty())
				cout<<"\n Queue is empty";
			else
			{
				item=obj.delete_rear();
				cout<<"\n The deleted element is "<<item;
			}
			break;
		case 5:
			obj.display();
			break;
		default:
			cout<<"\n Invalid choice....";
		}
		cout<<"\n Do you want to continue: ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return 0;
}
