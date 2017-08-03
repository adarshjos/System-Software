#include<stdio.h>
int main()
{
	int n,i,j,bt[20],tat[20],wt[20];
	printf("Enter the total number of processes:");
	scanf("%d",&n);

	printf("/nEnter process burst time\n");
	for (int i = 0; i < n; i++)
	{
		printf("P[%d]:",i+1);
		scanf("%d",&bt[i]);
	}

	wt[0]=0;
	for (int i = 1; i < n;i++)
	{
		wt[i]=0;
		for (int j = 0; j<i; j++)
		{
			wt[i]=wt[i]+bt[j];
		}
	}

	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	for (int i = 0; i < n; ++i)
	{
		tat[i]=bt[i]+wt[i];
		 printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
	}

printf("\n\n");
return 0;
	
}
