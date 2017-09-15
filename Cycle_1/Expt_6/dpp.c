#include<stdio.h>
#include<math.h>

void eat(int [], int, int);
void stop_eating(int [], int, int);
int wait(int [], int);
int signal(int [], int);

int main()
{
	int n;
	printf("Enter the number of philosophers at the table\n");
	scanf("%d", &n);
	int s[n];
	int choice;
	int i;
	for(i=0; i<n+1; i++)
	{
		s[i] = 1;
	}
	while (1)
	{
		printf("\n-----------------------\n");
		printf(" 1:start eating\n");
		printf("2:stop eating\n");
		printf("Make your choice\n");
		scanf("%d", &choice);
		printf("-------------------------\n\n");
		switch(choice)
		{
			case 1:
				printf("Enter the philosopher number who starts eating\n");
				scanf("%d", &i);
				eat(s, i, n);
				break;
			case 2:
				printf("Enter the philospher who is supposed to stop eating\n");
				scanf("%d", &i);
				stop_eating(s, i, n);
				break;
			default:
				printf("Enter a valid choice\n");
				break;
		}
	}
	return 0;
}

void eat(int s[], int i, int n)
{
	int r;
	r = wait(s, i-1);
	if(r == 0)
		return;
	r = wait(s, (i)%(n));
	if(r == 0)
		return;
	printf("Philospher %d starts eating\n", i);
	s[i-1] = 0;
	s[(i)%(n)] = 0;
	return;
}

int wait(int s[], int i)
{
	if(s[i] == 0)
	{
		printf("Unable to execute eating process\n");
		return 0;
	}
	else
		return 1;
}

int signal(int s[], int i)
{
	if(s[i] == 1)
	{
		printf("Philospher not eating\n");
		return 0;
	}
	else
		return 1;
}

void stop_eating(int s[], int i, int n)
{
	int r;
	r = signal(s, i - 1);
	if(r == 0)
		return;
	r = signal(s, (i)%(n));
	if (r == 0)
		return;
	s[i - 1] = 1;
	s[(i)%(n)] = 1;
	printf("Philosopher %d stopped eating\n", i);
	return;
}
