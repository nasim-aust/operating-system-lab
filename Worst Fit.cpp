#include<stdio.h>
int main()
{
    int i,j,memR,memH,count=0,flag=0,req[100],hole[100],val=0,k,memory,sum=0;

    //freopen("file.txt","r",stdin);

    printf("Enter no of Memory  Requests: ");
    scanf("%d",&memR);

    printf("Enter the process requests: ");
    for(i=0; i<memR; i++)
    {
        scanf("%d",&req[i]);
    }

    printf("Enter no of Memory  Hole: ");
    scanf("%d",&memH);

    printf("Enter the Memory Holes: ");
    for(i=0; i<memH; i++)
    {
        scanf("%d",&hole[i]);
    }

    printf("Memory Requests\n");
    for(i=0; i<memR; i++)
    {
        printf("%d\n",req[i]);
    }

    printf("Memory Holes\n");
    for(i=0; i<memH; i++)
    {
        printf("%d\n",hole[i]);
    }
    printf("\nOutput\n");
    while(count<memR)
    {
        memory=req[count];
        for(i=0; i<memH; i++)
        {
            if(memory<=hole[i])
            {
                if(val<hole[i])
                {
                    val=hole[i];
                    k=i;

                }
            }
        }
        printf("\nmax:%d\n",hole[k]);

        if((hole[k]-memory)>=0)
        {
            hole[k]=hole[k]-memory;
            printf("\n");
            for(i=0; i<memH; i++)
            {
                printf("%d\n",hole[i]);
            }

            printf("\n");
        }
        else
            flag=1;

        if(flag==1)
            break;
        memory=0;
        //else if((hole[k]-memory)<0)
            //printf("unallocated\n");


        //printf("%d ",hole[k]);
        //printf("%d ",val);
        count++;
    }

    for(i=0;i<memH;i++)
        sum=sum+hole[i];

    printf("\nExternal Fragmentation: %d\n",sum);
}
