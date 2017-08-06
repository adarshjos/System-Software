#include<stdio.h>
void wait_time(int wt[],int bt[],int n,int at[]){

	wt[0]=0;

	for (int i = 1; i < n;i++)
	{

			wt[i]=wt[i-1]+bt[i-1];
			/*f(at[i]>=wt[i])
				wt[i]=0;
			else
				wt[i]=wt[i]-at[i];		*/
	}
}



void pr_sort(int pri[],int but[],int p[],int n,int ar[]){
	int pos,temp;
	for (int i = 0; i < n; i++)
	 {
	 	pos=i;
	 	for (int j = i+1; j < n;j++)
	 	{
	 		if (pri[j]<pri[pos])
	 		{
				pos=j;	 			
	 		}
	 	}
	 		temp=but[i];
	 		but[i]=but[pos];
	 		but[pos]=temp;

	 		temp=pri[i];
	 		pri[i]=pri[pos];
	 		pri[pos]=temp;

	 		temp=p[i];
	 		p[i]=p[pos];
	 		p[pos]=temp;

	 		temp=ar[i];
	 		ar[i]=ar[pos];
	 		ar[pos]=temp;
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
	int n,i,j,bt[20],tat[20],wt[20],sl,p[20],at[20],pr[20];
	float tav;
	printf("Enter the total number of processes:");
	scanf("%d",&n);
	tav=0;
	printf("\nEnter process :Burst Time   Arrival Time   Priority\n");
	for (int i = 0; i < n; i++)
	{
		printf("P[%d]:",i+1);
		scanf("%d      %d      %d",&bt[i],&at[i],&pr[i]);
		p[i]=i+1;
	}
		printf("\nEnter the time slice: ");
		scanf("%d",&sl);


	printf("\n-------First-Come First-Serve Scheduling-------\n");
	pr_sort(at,bt,p,n,pr);
	wait_time(wt,bt,n,at);
	turnaround(bt,wt,n,tat);
		 	printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
		 	
		 	for ( i = 0; i < n; ++i)
	{
	
		 printf("\n%d\t\t%d\t\t%d\t\t\t%d\t\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
		 tav+=tat[i];
	}
	tav=(float)(tav/n);
printf("\nTurnaround Average time=%f",tav);
printf("\n");

	printf("\n\n-------Shortest Job First Scheduling---------\n");
	pr_sort(bt,pr,p,n,at);
	tav=0;
	wait_time(wt,bt,n,at);
	turnaround(bt,wt,n,tat);
		 	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
		 	
		 	for ( i = 0; i < n; ++i)
	{
	
		 printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
		 tav+=tat[i];
	}
	tav=(float)(tav/n);
printf("\nTurnaround Average time=%f",tav);

printf("\n\n");

	printf("\n\n-------Priority Scheduling-------------\n");
	pr_sort(pr,bt,p,n,at);
	tav=0;
	wait_time(wt,bt,n,at);
	turnaround(bt,wt,n,tat);
	printf("\nProcess\t\tPriority\tBurst Time\tWaiting Time\tTurnaround Time");
		 	
		 	for ( i = 0; i < n; ++i)
	{
	
		 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i],pr[i],bt[i],wt[i],tat[i]);
		 tav+=tat[i];
	}
tav=(float)(tav/n);
printf("\nTurnaround Average time=%f",tav);


printf("\n\n");

printf("\n\n-------Round Robin  Scheduling(pre-emptive)----------\n");

}