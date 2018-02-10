#include<stdio.h>
int main()
{
    freopen("pageReplacement.txt","r",stdin);

    int elements,i,j=0,page[20],arr[20],pf=0,count=0,flag=0,value,fs;
    scanf("%d",&elements);
    scanf("%d",&fs);

    for(i=0;i<elements;i++)
    {
        scanf("%d",&page[i]);
    }

    printf("No. of pages: %d\n",elements);
    printf("Frame Size: %d\n",fs);
    printf("Pages are: ");
    for(i=0;i<elements;i++)
    {
        printf("%d ",page[i]);
    }
    printf("\n");

    for(i=0;i<fs;i++)
    {
        arr[j]=999;
    }
    j=0;
    printf("\nPage Replacement(FIFO)\n\n");
    while(count!=elements)
    {
        for(i=0;i<fs;i++)
        {
            if(arr[i] == page[count])
                flag=1;
        }
        if(flag==0)
        {
            value=page[count];
            arr[j]=value;
            j++;
            pf++;
        }
        if(j==fs)
            j=0;
        count++;

        for(i=0;i<fs;i++){
            printf("%d ",arr[i]);
        }

        if(flag==0)
            printf("\tPage fault");
        else if(flag==1)
            printf("\tNo Page fault");
        flag=0;

        printf("\n");

    }
    printf("Page Faults: %d",pf);

}
