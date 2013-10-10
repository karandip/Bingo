#include<stdio.h>
int C[5][5]={{1,7,3,11,12},{13,14,8,5,6},{15,16,4,2,9},{17,19,18,20,21},{22,23,10,24,25}},
	P[5][5]={{17,18,1,8,4},{19,20,9,5,6},{25,10,3,2,7},{11,21,12,22,13},{14,23,15,24,16}},
	CS[5][5]={0},PS[5][5]={0},i,j,k,n,r,c=0,u=0,sr[5]={0},sc[5]={0},p=0,q=0,Rc[5]={0},
	Ru[5]={0},Cc[5]={0},Cu[5]={0},Dc[2]={0},Du[2]={0};
void cwon()
{
	for(i=0;i<5;i++)
	{
		if(CS[i][0]!=0&CS[i][1]!=0&CS[i][2]!=0&CS[i][3]!=0&CS[i][4]!=0)
		{ Rc[i]++;}
		if(CS[0][i]!=0&CS[1][i]!=0&CS[2][i]!=0&CS[3][i]!=0&CS[4][i]!=0)
		{ Cc[i]++;}
	}
	if(CS[0][0]!=0&CS[1][1]!=0&CS[2][2]!=0&CS[3][3]!=0&CS[4][4]!=0)
	{Dc[0]++;}
	if(CS[4][0]!=0&CS[3][1]!=0&CS[2][2]!=0&CS[1][3]!=0&CS[0][4]!=0)
	{Dc[1]++;}
	for(i=0;i<5;i++)
	{ if(Rc[i]==1) c++;
	if(Cc[i]==1) c++;}	if(Dc[0]==1) c++; 
	if(Dc[1]==1) c++; 
}
void uwon()
{
	for(i=0;i<5;i++)
	{
		if(PS[i][0]!=0&PS[i][1]!=0&PS[i][2]!=0&PS[i][3]!=0&PS[i][4]!=0)
		{Ru[i]++;}
		if(PS[0][i]!=0&PS[1][i]!=0&PS[2][i]!=0&PS[3][i]!=0&PS[4][i]!=0)
		{Cu[i]++;}
	}
	if(PS[0][0]!=0&PS[1][1]!=0&PS[2][2]!=0&PS[3][3]!=0&PS[4][4]!=0)
	{Du[0]++;}
	if(PS[4][0]!=0&PS[3][1]!=0&PS[2][2]!=0&PS[1][3]!=0&PS[0][4]!=0)
	{Du[1]++;}
	for(i=0;i<5;i++)
	{ if(Ru[i]==1) u++;
	if(Cu[i]==1) u++;}	if(Du[0]==1) u++; 
	if(Du[1]==1) u++; 
	//printf("\t%d %d\t",c,u);
}	
void main()
{
	int check=0;
	system("clear");
	printf("enter ur 5x5 bingo : \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&P[i][j]);
		}
	}
	do
	{
		system("clear");
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				printf("%d\t",P[i][j]);
			}
			printf(" | ");
			for(j=0;j<5;j++)
			{
				printf("%d\t",CS[i][j]);
			}
			printf("\n");
		}
		if(u==1) { printf("\t\tB\t\t"); check++;}
		if(u==2) { printf("\t\tBI\t\t"); check++; }
		if(u==3) { printf("\t\tBIN\t\t"); check++; }
		if(u==4) { printf("\t\tBING\t\t"); check++; }
		if(u==5) { printf("\t\tBINGO\t\t"); check++; }
		if(check==0) { printf("\t\t\t\t"); }
		if(c==1) printf("\t\tB\t\t");
		if(c==2) printf("\t\tBI\t\t"); 
		if(c==3) printf("\t\tBIN\t\t"); 
		if(c==4) printf("\t\tBING\t\t"); 
		if(c==5) printf("\t\tBINGO\t\t"); 
		printf("\nenter the no.");
		scanf("%d",&n);
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(C[i][j]==n)
				{CS[i][j]=n;}
				if(P[i][j]==n)
				{PS[i][j]=n;P[i][j]=0;}
			}
		}
		if(c<5) uwon();
		if(u<5) cwon();
		printf("\n");
		if(c>=5||u>=5) {goto end2;}
		
		for(i=0;i<5;i++)
		{	sr[i]=0;sc[i]=0;
			for(j=0;j<5;j++)
			{
				if(CS[i][j]==0)
				{sr[i]++;}
				if(CS[j][i]==0)
				{sc[i]++;}
			}
		}
		for(k=1;k<5;k++)
		{
			for(i=0;i<5;i++)
			{
				if(sr[i]==k)
				{
					for(j=0;j<5;j++)
					{
						if(CS[i][j]==0)
						{CS[i][j]=C[i][j]; r=C[i][j];
						goto end1;}
					}p++;
				}
				if(sc[i]==k)
				{
					for(j=0;j<5;j++)
					{
						if(CS[j][i]==0)
						{CS[j][i]=C[j][i]; r=C[j][i];
						goto end1;}
					}p++;
				}
			}
		}
		if(p==0)
		{
			for(i=0;i<5;i++)
			{
				for(j=0;j<5;j++)
				{
					if(CS[i][j]==0)
					{CS[i][j]=C[i][j]; r=C[i][j];
					goto end1;}
				}
				end1:{break;}
			}
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(P[i][j]==r)
				{P[i][j]=0;PS[i][j]=r;}
			}
		}
				//for(i=0;i<5;i++) {printf("%d %d\n",sr[i],sc[i]);}
		if (u<5) cwon();
		if(c<5) uwon();
		printf("\n");
		end2:{
			}
	}
	while(c<5&&u<5);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",P[i][j]);
		}
		printf(" | ");
		for(j=0;j<5;j++)
		{
			printf("%d\t",CS[i][j]);
		}
		printf("\n");
	}
	if(c==5) printf("BINGO of Compter\n");
	if(u==5) printf("ur BINGO \n"); 
}
	
	
