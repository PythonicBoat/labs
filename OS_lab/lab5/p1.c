#include <stdio.h>
#include <string.h>

struct process
{
    char name[20];
    int at, bt, wt, tat;
};

int main()
{
    int n = 5;
    struct process p[n];

    strcpy(p[0].name, "p1");
    strcpy(p[1].name, "p2");
    strcpy(p[2].name, "p3");
    strcpy(p[3].name, "p4");
    strcpy(p[4].name, "p5");

    p[0].at = 0, p[0].bt = 10;
    p[1].at = 3, p[1].bt = 5;
    p[2].at = 5, p[2].bt = 2;
    p[3].at = 6, p[3].bt = 6;
    p[4].at = 8, p[4].bt = 4;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    p[0].wt = 0, p[0].tat = p[0].bt;
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    int total_wt = 0, total_tat = 0;
    printf("Process\t| Arrival Time\t| Burst Time\t| Waiting Time\t| Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t| %d\t\t| %d\t\t| %d\t\t| %d\n", p[i].name, p[i].at, p[i].bt, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
