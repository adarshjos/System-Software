#include<stdio.h>
#include<stdlib.h>

int sort(int n,int q[],int head){
	int i,j,temp;
	for (i = 0; i <=n; ++i)
	{
		for(j=i;j<=n;j++){
			if(q[i]>q[j])
			    {
				    temp=q[i];
				    q[i]=q[j];
				    q[j]=temp;
			    }
		}
	}

	for (i = 0; i <=n; ++i)
	{
		if(head==q[i])
			return i;
	}


}
int fcfs(int n,int q[]){
	int j,diff,seek=0;
	for(j=0;j<n;j++)
             {
                          diff=abs(q[j+1]-q[j]);
                          seek+=diff;
                          printf(" %d to %d with Seek %d\n",q[j],q[j+1],diff);
             }
             return seek;
}

int scan(int n,int q[],int h){
	int i,hloc;
	hloc=sort(n,q,h);
	

	for (i=hloc; i>=0;i--)
			{
 				printf("%d -->",q[i]);
			}

			 printf("0 -->");
 	for(i=hloc+1;i<=n;i++)
		 {
		 printf("%d-->",q[i]);
		 }
		 return (q[hloc]+q[n]);
}



int cscan(int n,int q[],int h){
	int i,hloc;
	
	
	hloc=sort(n,q,h);
	
	if(100<=q[hloc]){
	for(i=hloc;i<=n;i++)
		 {
		 printf("%d-->",q[i]);
		 }
		  printf("0 -->");
		  for (i=0; i <=hloc; ++i)
		  {
		  	printf("%d -->",q[i]);
		  }}
		  else
		  {
		  	for(i=hloc;i>=0;i--)
		 {
		 printf("%d-->",q[i]);
		 }
		  printf("199-->");
		  for (i=n; i >=hloc; --i)
		  {
		  	printf("%d -->",q[i]);
		  }
		  }

}



void  main(){
	int q[200],i,j,h,n,ch,seektime;
	float avg;

	 printf("Enter the size of Queue\t");
             scanf("%d",&n);
             printf("Enter the Queue(0-199)\t");
             for(i=1;i<=n;i++)
             {
                          scanf("%d",&q[i]);
             }

         
             printf("Enter the initial head position\t");
             scanf("%d",&h);
             q[0]=h;
             printf("\n");
             printf("******DISK SCHEDULING*****\n");
             printf("\n**********FCFS**********\n");
	             seektime=fcfs(n,q);
	             printf("\nNo: of head movements %d\t",seektime);
	             avg=seektime/(float)n;
	             printf("\nAverage Seek Time is %f\t",avg);

	 printf("\n\n*********SCAN**********\n");
			seektime=scan(n,q,h);
		 	printf("\nNo: of head movements %d\t",seektime);
		            avg=seektime/(float)n;
		            printf("\nAverage Seek Time is %f\t",avg);

	
	printf("\n\n*********C-SCAN**********\n");
			seektime=cscan(n,q,h);
		 	printf("\nNo: of head movements 200\t");
		            avg=200/(float)n;
		            printf("\nAverage Seek Time is %f\t",avg);
		  	  printf("\n");
}