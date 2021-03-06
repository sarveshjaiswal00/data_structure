
#include<stdio.h>
#include<string.h>
#define max 10
#define size 20
int main()
{
	int Union(char a[max][size], char b[max][size],char c[max][size],int ,int);
	void Intersection(char a[max][size], char b[max][size],int ,int);
	void difference(char a[max][size],char b[max][size], int,int);
	void display(char a[max][size], char b[max][size],int term1,int term2);
	char a[max][size],b[max][size],c[max][size],U[max][size];
	int i,term,term1,term2,term3;
	int ans;
	int ch;
	printf("\n How many elements are there in Universal set? ");
	scanf("%d",&term);
	printf("\n Enter the elements in Universal set");
	for(i=0;i<term;i++){
		scanf("%s",&U[i]);
	}
	printf("\n How many members play cricket? ");
	scanf("%d",&term1);
	printf("\n Enter the names of the players");
	for(i=0;i<term1;i++){
		scanf("%s",&a[i]);
	}
	printf("\n How many members play badminton? ");
	scanf("%d",&term2);
	printf("\n Enter the names of the players");
	for(i=0;i<term2;i++){
		scanf("%s",&b[i]);
	}
	do{
		printf("\n Main Menu");
		printf("\n 1. Set of students who play either cricket or badminton or both");
		printf("\n 2. Set of students who play both cricket and badminton");
		printf("\n 3. Set of students who play only cricket");
		printf("\n 4. Set of students who play only badminton");
		printf("\n 5. Set of students who play neither cricket nor badminton");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
		case 1: display(a,b,term1,term2);
			term3=Union(a,b,c,term1,term2);
			break;
		case 2:
			display(a,b,term1,term2);
			Intersection(a,b,term1,term2);
			break;
		case 3:
			display(a,b,term1,term2);
			difference(a,b,term1,term2);//(A-B)
			break;
		case 4:
			display(a,b,term1,term2);
			difference(b,a,term2,term1);//(B-A);
			break;
		case 5:
			display(a,b,term1,term2);
			difference(U,c,term,term3);
			break;
		}
		printf("\n Do you want to continue: ");
		scanf("%d",&ans);
	}while(ans==1);
	return 0;
}
void display(char a[max][size], char b[max][size],int term1,int term2)
{
	int i;
	printf("\n A={ ");
	for(i=0;i<term1;i++){
		printf("%s",a[i]);
	}
	printf(" }");
	printf("\n B={ ");
	for(i=0;i<term2;i++){
		printf("%s",b[i]);
	}
	printf(" }");
}

int Union(char a[max][size], char b[max][size],char c[max][size],int term1,int term2)
{
	int i,j,k,n,flag;
	k=0;
	flag=0;
	for(i=0;i<term1;i++){
		strcpy(c[k],a[i]);
		k++;
	}
	for(j=0;j<term2;j++){
		flag=0;
		for(i=0;i<term1;i++){
			if((strcmp(a[i],b[j]))==0)
				flag=1;
		}
		if(flag==0){
			strcpy(c[k],b[j]);
			k++;
		}
	}
	n=k;
	printf("\n Union={ ");
	for(k=0;k<n;k++){
		printf("%s",c[k]);
	}
	printf(" }");
	return n;
}

void Intersection(char a[max][size], char b[max][size],int term1,int term2)
{
	char c[max][size];
	int i,j,k,n,flag;
	k=0;
	flag=0;
	for(i=0;i<term1;i++){
		flag=1;
		for(j=0;j<term2;j++){
			if((strcmp(a[i],b[j]))==0)
				flag=0;
		}
		if(flag==0){
			strcpy(c[k],a[i]);
			k++;
		}
	}
	n=k;
	printf("\n Intersection={ ");
	for(k=0;k<n;k++){
		printf("%s",c[k]);
	}
	printf(" }");
}

void difference(char a[max][size],char b[max][size], int term1,int term2)
{
	char c[max][size];
	int i,j,k,n,flag;
	k=0;
	flag=0;
	for(i=0;i<term1;i++){
		flag=1;
		for(j=0;j<term2;j++){
			if((strcmp(a[i],b[j]))==0){
				flag=0;
				break;
			}
		}
		if(flag==1){
			strcpy(c[k],a[i]);
			k++;
		}
	}
	n=k;
	printf("\n Difference={ ");
	for(k=0;k<n;k++){
		printf("%s",c[k]);
	}
	printf(" }");
}
