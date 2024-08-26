#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int id, at, bt, ct, tt, wt, rt;
} process;
void fcfs(process p[], int n);
int main()
{
    int n;
    printf("Enter the nu,ber of:\n");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process:%d\n", i + 1);
        printf("Enter arrival:\n");
        scanf("%d", &p[i].at);
        printf("Enter arrival:\n");
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
        printf("\n");
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    fcfs(p, n);
    return 0;
}

void fcfs(process p[], int n)
{
    int elapsed = 0;
    int totwt = 0;
    int tottt = 0;
    int totrt = 0;
    float avgtt = 0;
    float avgrt = 0;
    float avgwt = 0;
    printf("\nGANTT CHART\n");
    for (int i = 0; i < n; i++)
    {
        if (p[i].at > elapsed)
            elapsed = elapsed + (p[i].at - elapsed);

        int temp = elapsed;
        p[i].rt = elapsed - p[i].at;
        elapsed = elapsed + p[i].bt;
        p[i].ct = elapsed;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
        printf("|(%d) P%d (%d)", temp, p[i].id, elapsed);
    }
    printf("\n");
    printf("Observation table:\n");
    printf("PID\t AT\t BT\t CT\t TT\t WT\t RT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt, p[i].rt);
        totrt += p[i].rt;
        tottt += p[i].tt;
        totwt += p[i].wt;
    }
    avgrt = (float)totrt / n;
    avgtt = (float)tottt / n;
    avgwt = (float)totwt / n;
    printf("AVG turn:%.2f\n", avgtt);
    printf("AvG response:%.2f\n", avgrt);
    printf("AVG waiting:%.2f\n", avgwt);
}
