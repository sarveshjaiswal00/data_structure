
#include<stdio.h>
#include<string.h>
struct book
{
	char  name[20];
	int cost;
};

void display(struct book b[20],int n);
void sort(struct book b[20],int n);
void reverse(struct book b[20],int n);
void count(struct book b[20],int n);
void copy(struct book b[20],int n);
void dup1(struct book b[20],int n);
void dup2(struct book b[20],int n);
int main()
{
	struct book b[20];
	int n=0,ans,ch;
	setbuf(stdout,NULL);
	do
	{
		printf("\n Enter the name of book: ");
		scanf("%s",b[n].name);
		printf("\n Enter the cost: ");
		scanf("%d",&b[n].cost);
		n++;
		printf("\n Want to add more books: ");
		scanf("%d",&ans);
	}while(ans==1);
	display(b,n);
	sort(b,n);
	do
	{
		printf("\n Menu");
		printf("\n 1. Reverse withoust using temp array");
		printf("\n 2. Copy books in new array with cost less than 500");
		printf("\n 3. Delete duplicate entries using temp array");
		printf("\n 4. Delete duplicate entries withoust using temp array");
		printf("\n 5. Count number of books with cost greater than 500");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			reverse(b,n);
			break;
		case 2:
			copy(b,n);
			break;
		case 3:
			dup1(b,n);
			break;
		case 4:
			dup2(b,n);
			break;
		case 5:
			count(b,n);
			break;
		}
		printf("\n Do you want to continue: ");
		scanf("%d",&ans);
	}while(ans==1);
	return 0;
}

void display(struct book b[20],int n)
{
	int i;
	printf("\n Name \t\t Cost\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t\t%d",b[i].name,b[i].cost);
		printf("\n");
	}
}

void sort(struct book b[20],int n)
{
	int i,j,temp;
	char s[20];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(b[j].cost<b[j+1].cost)
			{
				temp=b[j].cost;
				b[j].cost=b[j+1].cost;
				b[j+1].cost=temp;
				strcpy(s,b[j].name);
				strcpy(b[j].name,b[j+1].name);
				strcpy(b[j+1].name,s);
			}
		}
	}
	printf("\n Sorting in descending order of cost...");
	display(b,n);
}

void reverse(struct book b[20],int n)
{
	int i,j,temp;
	char s[20];
	for(i=0,j=n-1;i<=i/2;i++,j--)
	{
		temp=b[i].cost;
		b[i].cost=b[j].cost;
		b[j].cost=temp;

		strcpy(s,b[i].name);
		strcpy(b[i].name,b[j].name);
		strcpy(b[j].name,s);
	}
	printf("\n Contents after reversal..");
	display(b,n);
}

void copy(struct book b[20],int n)
{
	struct book temp[20];
	int i,j=0;
	for(i=0;i<n;i++)
	{
		if(b[i].cost<500)
		{
			temp[j].cost=b[i].cost;
			strcpy(temp[j].name,b[i].name);
			j++;
		}
	}
	printf("\n Enteries with cost less than 500\n");
	display(temp,j);
}

void count(struct book b[20],int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(b[i].cost>500)
		{
			count++;
		}
	}
	printf("\n No. of books with cost more than 500 are %d",count);
}

void dup1(struct book b[20],int n)
{
	struct book temp[20];
	int i,j,k=1;
	temp[0].cost=b[0].cost;
	strcpy(temp[0].name,b[0].name);
	i=1;
	while(i<n)
	{
		j=0;
		while(j<k)
		{
			if(strcmp(b[i].name,temp[j].name)==0)
			{
				i++;
				j=0;
			}
			else
				j++;
		}
		if(j==k)
		{
			temp[k].cost=b[i].cost;
			strcpy(temp[k].name,b[i].name);
			k++;
			i++;
		}
	}
	printf("\n Array after removal of duplicates using temp array...");
	display(temp,k);
}

void dup2(struct book b1[20],int n1)
{
	int i,j,k,n=n1;
	struct book b[20];
	for(i=0;i<n;i++)
	{
		b[i].cost=b1[i].cost;
		strcpy(b[i].name,b1[i].name);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(b[i].name,b[j].name)==0)
			{
				for(k=j;k<n-1;k++)
				{
					b[k].cost=b[k+1].cost;
					strcpy(b[k].name,b[k+1].name);
				}
				n--;
			}
		}
	}
	printf("\n Array after removing duplicates without using temp array");
	display(b,n);
}
