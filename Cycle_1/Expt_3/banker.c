#include<stdio.h>
#include<stdlib.h>




void print(int x[][10],int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",x[i][j]);
		}
	}	
}

void resoucrcereq(int alloc[][10],int need[][10],int avail[],int id,int m,int n){

	int resreq[10],i;
	printf("\nAdditional Resource Request  \n--------------------------\n");
	for(i=0;i<m;i++){
		printf(" Request for resource[%d]: ",i+1);
		scanf("%d",&resreq[i]);
				}

	for(i=0;i<m;i++)
		if(resreq[i] > need[id][i]){
			printf("\n Error ..Terminating\n");
			exit(0);
	}

	for(i=0;i<m;i++)
		if(resreq[i] > avail[i]){
			printf("\n Resources unavailable\n");
		exit(0);
	}


	for(i=0;i<m;i++){
		avail[i]-=resreq[i];
		alloc[id][i]+=resreq[i];
		need[id][i]-=resreq[i];
}

	printf("\n Allocation Matrix\n");
	printf("------------------------\n");
	print(alloc,n,m);
	printf("\n Need Matrix\n");
	printf("------------------------\n");
	print(need,n,m);


}


void getdata(int n,int m,int alloc[][10],int max[][10],int avail[],int need[][10]){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n Process[%d]\n",i+1);
		for(j=0;j<m;j++){
			printf(" Allocation for resource %d : ",j+1);
			scanf("%d",&alloc[i][j]);
			printf(" Maximum for resource %d : ",j+1);
			scanf("%d",&max[i][j]);
				}
			}
	printf("\n Available resources : \n");
	for(i=0;i<m;i++){
		printf(" Resource[%d] : ",i+1);
		scanf("%d",&avail[i]);
			}


	//need matrix
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j]=max[i][j]-alloc[i][j];


	printf("\n Allocation Matrix\n");
	printf("------------------------\n");
	print(alloc,n,m);
	printf("\n Maximum Requirement Matrix\n");
	printf("------------------------\n");
	print(max,n,m);
	printf("\n Need Matrix\n");
	printf("------------------------\n");
	print(need,n,m);



}


int safety(int n,int m,int alloc[][10],int avail[],int need[][10],int safety_seq[])
{
	int i,j,f[10],w[10],fflag=0,k,x=0;
	for (i = 0; i < n; i++)
	f[i]=0;
	for(i=0;i<m;i++)
		w[i]=avail[i];
	for(k=0;k<n;k++)
	{
	for (i = 0; i < n; i++)
	{
			fflag=0;
		for(j=0;j<m;j++)
		{
			if(need[i][j]>w[j])
				fflag=1;
		}
	if(fflag==0&&f[i]==0){
		for(j=0;j<m;j++)
		w[j]+=alloc[i][j];
		f[i]=1;
		safety_seq[x++]=i;
	}}

	
	if(x==n)
		{
		printf("\n\n"); 	
		for(i=0;i<n;i++)
		     printf(" P[%d] -->",safety_seq[i]);
		printf("\n A safety sequence has been detected.\n");
		return 1;
		}
}
printf("\n Deadlock has occured.\n");
return 0;
}

 int main()
{
	int i,j,m,n,flag,id;
	int alloc[10][10],max[10][10],need[10][10],avail[10],safety_seq[10],ch;
	printf("\n DEADLOCK AVOIDANCE--BANKER'S ALGORITHM\n");
	printf("\n Enter total no. of processes : ");
	scanf("%d",&n);
	printf("\n Enter total no. of resources : ");
	scanf("%d",&m);
	getdata(n,m,alloc,max,avail,need);
	flag=safety(n,m,alloc,avail,need,safety_seq);
	/*if(flag!=0){
		printf("\n\n");
		for(i=0;i<n;i++)
		     printf(" P[%d] -->",safety_seq[i]);
		printf("\n A safety sequence has been detected.\n");
	}
		else
		printf("\n Deadlock has occured.\n");
*/

	if(flag !=0 ){
		printf("\n Do you want make an additional request ? (1=Yes|0=No)");
		scanf("%d",&ch);
		if(ch == 1){
			printf("\n Enter process no. : ");
			scanf("%d",&id);
			resoucrcereq(alloc,need,avail,id-1,m,n);
			flag=safety(n,m,alloc,avail,need,safety_seq);
			if(flag == 0 )
				exit(0);
		}
	}else
exit(0);



	return 0;
}