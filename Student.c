
#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
	int marks;
	char attendance[2];
};
void average(struct student s[20],int n);
void high_low(struct student s[20],int n);
void most_scored(struct student s[20],int n,int max_marks);
void absent(struct student s[20],int n);
int main()
{
	struct student s[20];
	int n,i,ans,ch,max_marks;
	setbuf(stdout,NULL);
	printf("\n Enter maximum marks: ");
	scanf("%d",&max_marks);
	printf("\n Enter total number of students in class: ");
	scanf("%d",&n);
	printf("\n Enter details....");
	for(i=0;i<n;i++)
	{
		printf("\n Name: ");
		scanf("%s",s[i].name);
		printf("\n Marks: ");
		scanf("%d",&s[i].marks);
		printf("\n Attendance: ");
		scanf("%s",s[i].attendance);
	}
	for(i=0;i<n;i++)
		{
			printf("\n Name: ");
			printf("%s",s[i].name);
			printf("\n Marks: ");
			printf("%d",s[i].marks);
			printf("\n Attendance: ");
			printf("%s",s[i].attendance);
		}
	do
	{
		printf("\n Menu");
		printf("\n 1. Average Score of Class");
		printf("\n 2. Highest Score and Lowest Score");
		printf("\n 3. Marks scored by most of students");
		printf("\n 4. List of absent students");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			average(s,n);
			break;
		case 2:
			high_low(s,n);
			break;
		case 3:
			most_scored(s,n,max_marks);
			break;
		case 4:
			absent(s,n);
			break;
		default: printf("\n Enter correct choice.....");
		}
		printf("\n Do you want to continue: ");
		scanf("%d",&ans);
	}while(ans==1);
	return 0;
}

void average(struct student s[20],int n)
{
	int i,sum=0,k=0;
	float avg;
	for(i=0;i<n;i++)
	{
		if(strcmp(s[i].attendance,"AB")!=0)
		{
			sum=sum+s[i].marks;
			k++;
		}
	}
	avg=sum/k;
	printf("\n Average score is %f ",avg);
}

void high_low(struct student s[20],int n)
{
	int i;
	int max,min;
	min=999;
	max=-1;
	for(i=0;i<n;i++)
	{
		if(strcmp(s[i].attendance,"AB")!=0){
		if(s[i].marks>max)
		{
			max=s[i].marks;
		}
		if(s[i].marks<min)
		{
			min=s[i].marks;
		}
		}
	}
	printf("\n Highest score is %d",max);
	printf("\n Lowest score is %d",min);
}

void most_scored(struct student s[20],int n,int max_marks)
{
	int i,max=-1,k;
	int count[max_marks+1];
	for(i=1;i<=max_marks;i++)
	{
		count[i]=0;
	}
	for(i=0;i<n;i++)
	{
		count[s[i].marks]++;
	}
	for(i=1;i<=max_marks;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			k=i;
		}
	}
	printf("\n Marks secured by most of students is %d",k);
}

void absent(struct student s[20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(s[i].attendance,"AB")==0)
		{
			printf("\n %s",s[i].name);
		}
	}
}
