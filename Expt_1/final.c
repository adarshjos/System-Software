#include<stdio.h>
void wait_time(int wt[],int bt[],int n){

	wt[0]=0;
	for (int i = 1; i < n;i++)
	{
		wt[i]=0;
		for (int j = 0; j<i; j++)
		{
			wt[i]=wt[i]+bt[j];
		}
	}
}

void sorting(int n,int bt[],int p[]){
	int pos,temp;
	for (int i = 0; i < n; i++)
	 {
	 	pos=i;
	 	for (int j = i+1; j < n;j++)
	 	{
	 		if (bt[j]<bt[pos])
	 		{
				pos=j;	 			
	 		}
	 	}
	 		temp=bt[i];
	 		bt[i]=bt[pos];
	 		bt[pos]=temp;


	 		temp=p[i];
	 		p[i]=p[pos];
	 		p[pos]=temp;
	 }
}

void turnaround(int bt[],int wt[],int n,int tat[]){
	for (int i = 0; i < n; ++i)
	{
		tat[i]=bt[i]+wt[i];
		 //printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
}



int main()
{
	int n,i,j,bt[20],tat[20],wt[20],p[20];
	printf("Enter the total number of processes:");
	scanf("%d",&n);

	printf("\nEnter process burst time\n");
	for (int i = 0; i < n; i++)
	{
		printf("P[%d]:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}

	printf("\n-------First-Come First-Serve Scheduling-------\n");
	wait_time(wt,bt,n);
	turnaround(bt,wt,n,tat);
		 	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
		 	
		 	for ( i = 0; i < n; ++i)
	{
	
		 printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}

printf("\n");

	printf("\n\n-------Shortest Job First Scheduling---------\n");
	sorting(n,bt,p);
	wait_time(wt,bt,n);
	turnaround(bt,wt,n,tat);
		 	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
		 	
		 	for ( i = 0; i < n; ++i)
	{
	
		 printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}

printf("\n\n");


}