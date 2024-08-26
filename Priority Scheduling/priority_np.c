#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int at, bt, ct, tt, wt, ft, prio, id;
} process;
void priority_np(process p[], int n);
int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process:%d\n", i + 1);
        printf("Enter arrival time:");
        scanf("%d", &p[i].at);
        printf("Enter burst time:");
        scanf("%d", &p[i].bt);
        printf("Enter priority:");
        scanf("%d", &p[i].prio);
        p[i].id = i + 1;
        p[i].ft = 0;
        printf("\n");
    }
    priority_p(p, n);
    return 0;
}

void priority_np(process p[], int n)
{
    int tottt = 0, totwt = 0;
    float avgtt = 0, avgwt = 0;
    int exec, remainingprocess = n;
    int elapsed = 0;
    while (remainingprocess > 0)
    {
        exec = -1;
        int minpriority = 999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= elapsed && p[i].ft == 0)
            {
                if (p[i].prio < minpriority || p[i].prio == minpriority && p[i].at < p[exec].at)
                {
                    exec = i;
                    minpriority = p[i].prio;
                }
            }
        }
        if (exec == -1)
        {
            printf("|(%d)***(%d)", elapsed, elapsed + 1);
            elapsed++;
        }
        else
        {
            int temp = elapsed;
            elapsed += p[exec].bt;
            p[exec].ct = elapsed;
            p[exec].tt = p[exec].ct - p[exec].at;
            p[exec].wt = p[exec].tt - p[exec].bt;
            printf("|(%d) P%d (%d)", temp, p[exec].id, elapsed);
            remainingprocess--;
            p[exec].ft = 1;
        }
    }
    printf("\n");
    printf("PID\tAT\tBT\tP\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].prio, p[i].ct, p[i].tt, p[i].wt);
        tottt += p[i].tt;
        totwt += p[i].wt;
    }
    avgtt = (float)tottt / n;
    avgwt = (float)totwt / n;
    printf("turn:%.2f\n", avgtt);
    printf("Wait:%.2f\n", avgwt);
}
