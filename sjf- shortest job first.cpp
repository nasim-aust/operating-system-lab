#include <stdio.h>
int main()
{
	int p[10],bt[10],wt[10],tat[10];
	int n,i,j,temp;
	float aw=0, at=0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	for(i=0; i<n;i++)
	{
		p[i] = i;
		printf("burst time of p[%d] ",p[i]);
		scanf("%d",&bt[i]);
	}
	printf("process \t burst time\n");
	for(i=0; i<n;i++)
	{
		printf("%d\t%d\n",p[i],bt[i]);
	}
   	for (i = 0; i < n-1; i++)
	{
	       for (j = 0; j < n-i-1; j++)
		{
			if (bt[j] > bt[j+1])
			{
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;

				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;

			}
		}
	}
	printf("process \t burst time \n");
	for(i=0; i<n;i++)
	{
		printf("%d\t%d\n",p[i],bt[i]);
	}

	wt[0] = 0;
	for(i=0;i<n;i++)
	{
		wt[i] = 0;
		for(j=0; j<i; j++)
		{
			wt[i] = wt[i] + bt[j];
		}
	}

	for(i=0;i<n;i++)
	{

		tat[i] = wt[i] + bt[i];
	}

	for (i = 0; i < n-1; i++)
	{
	       for (j = 0; j < n-i-1; j++)
		{
			if (p[j] > p[j+1])
			{
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;

				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;

				temp = tat[j];
				tat[j] = tat[j+1];
				tat[j+1] = temp;

				temp = wt[j];
				wt[j] = wt[j+1];
				wt[j+1] = temp;
			}
		}
	}

	printf("process \t  burst time\t  waiting time\t  turnaround\n");
	for(i=0; i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
	}

	for(i=0; i<n; i++)
	{
		at += tat[i];
		aw += wt[i];
	}
	at /= n;
	aw /= n;
	printf("avg tat = %f\n",at);
	printf("avg wait = %f\n",aw);
	return 0;
}
