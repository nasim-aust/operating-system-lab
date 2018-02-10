#include<stdio.h>

int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;

    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }

    return pos;
}

int main()
{
    freopen("pageReplacementLRU.txt","r",stdin);
    int no_of_frames,no_of_pages,frames[10],pages[30],counter = 0,time[10],flag1,flag2,i,j,pos,faults = 0;

    scanf("%d", &no_of_frames);
    scanf("%d", &no_of_pages);

    printf("No. of pages: %d\n",no_of_pages);
    printf("Frame Size: %d\n",no_of_frames);

    for(i = 0; i < no_of_pages; ++i){
        scanf("%d",&pages[i]);
    }

    printf("Pages are: ");
    for(i = 0; i < no_of_pages; ++i){
        printf("%d ",pages[i]);
    }

    for(i = 0; i < no_of_frames; ++i){
        frames[i] = 999;
    }
    printf("\n");
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;

        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                   flag1 = flag2 = 1;
                   break;
               }
        }

        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == 999){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("\n");

        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
