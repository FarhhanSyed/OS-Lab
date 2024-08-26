#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int at, bt, ct, tt, wt, rt, id, ft;
} Process;
void sjf_np(Process p[], int n);
int main()
{
    int n;
    printf("Enter the number of processe:\n");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process:%d\n", i + 1);
        printf("Enter arrival time:\n");
        scanf("%d", &p[i].at);
        printf("Enter burst time:\n");
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
        p[i].ft = 0;
        printf("\n");
    }
    sjf_np(p, n);
    return 0;
}

void sjf_np(Process p[], int n)
{
    int tottt = 0, totwt = 0, totrt = 0;
    int elapsed = 0;
    float avgtt = 0, avgwt = 0, avgrt = 0;
    int remainingprocess = n;
    int exec;
    while (remainingprocess > 0)
    {
        exec = -1;
        int shortest = 999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].ft == 0 && p[i].at <= elapsed)
            {
                if (p[i].bt < shortest)
                {
                    exec = i;
                    shortest = p[i].bt;
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
            p[exec].rt = elapsed - p[exec].at;
            elapsed = elapsed + p[exec].bt;
            p[exec].ct = elapsed;
            p[exec].tt = p[exec].ct - p[exec].at;
            p[exec].wt = p[exec].tt - p[exec].bt;
            printf("|(%d) P%d (%d)", temp, p[exec].id, elapsed);
            remainingprocess--;
            p[exec].ft = 1;
        }
    }
    printf("\n");
    printf("PID\t AT\t BT\t CT\t TT\t Wt\t RT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt, p[i].rt);
        tottt += p[i].tt;
        totrt += p[i].rt;
        totwt += p[i].wt;
    }
    avgrt = (float)totrt / n;
    avgtt = (float)tottt / n;
    avgwt = (float)totwt / n;
    printf("%.2f\n", avgtt);
    printf("%.2f\n", avgwt);
    printf("%.2f\n", avgrt);
}
