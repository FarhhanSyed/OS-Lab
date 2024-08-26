#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int at, bt, ct, tt, wt, rt, id, remt;
} process;
void sjf_p(process p[], int n);
int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process:%d\n", i + 1);
        printf("Enter arrival:");
        scanf("%d", &p[i].at);
        printf("Enter BURST:");
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
        p[i].remt = p[i].bt;
        printf("\n");
    }
    sjf_p(p, n);
    return 0;
}

void sjf_p(process p[], int n)
{
    int tottt = 0, totwt = 0, totrt = 0;
    float avgtt = 0, avgrt = 0, avgwt = 0;
    int elapsed = 0;
    int remainingprocess = n;
    int exec;
    int pro[100];
    int time[100];
    int j = -1, k = -1;
    time[++j] = 0;
    while (remainingprocess > 0)
    {
        exec = -1;
        int shortest = 999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= elapsed && p[i].remt > 0)
            {
                if (p[i].remt < shortest)
                {
                    exec = i;
                    shortest = p[i].remt;
                }
            }
        }
        if (exec == -1)
        {
            pro[++k] = 0;
            elapsed++;
            time[++j] = elapsed;
            printf("|(%d) IDLE (%d)", time[j - 1], time[j]);
        }
        else
        {
            if (p[exec].remt == p[exec].bt)
                p[exec].rt = elapsed - p[exec].at;

            p[exec].remt--;
            pro[++k] = p[exec].id;
            elapsed++;
            time[++j] = elapsed;

            if (p[exec].remt == 0)
            {
                p[exec].ct = elapsed;
                p[exec].tt = p[exec].ct - p[exec].at;
                p[exec].wt = p[exec].tt - p[exec].bt;
                totrt += p[exec].rt;
                totwt += p[exec].wt;
                tottt += p[exec].tt;
                remainingprocess--;
            }
            printf("|(%d) P%d (%d)|", time[j - 1], p[exec].id, time[j]);
        }
    }
    avgrt = (float)totrt / n;
    avgtt = (float)tottt / n;
    avgwt = (float)totwt / n;
    printf("\n");
    printf("Obsrvation table\n");
    printf("PId\tAT\tBT\tCT\tTT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt, p[i].rt);
    }
    printf("\nGANT CHART\t(P0-->idle time)\n");
    for (int i = 0; i <= k; i++)
        printf("|P%d|\t", pro[i]);

    printf("\n");
    for (int i = 0; i <= j; i++)
    {
        printf("%d\t", time[i]);
    }
    printf("\n");
    printf("\nAverage turnaround time:%.2f\n", avgtt);
    printf("\n Average Waiting time:%.2f\n", avgwt);
    printf("\n Average Response time:%.2f\n", avgrt);
}
