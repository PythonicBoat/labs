#include <stdio.h>

typedef struct {
    int at;
    int bt;
    int id;
    int wt;
    int tat;
} Process;

int main() {
    Process p[4];
    int n = 4, total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    p[0].id = 1, p[0].at = 1, p[0].bt = 3;
    p[1].id = 2, p[1].at = 2, p[1].bt = 4;
    p[2].id = 3, p[2].at = 1, p[2].bt = 2;
    p[3].id = 4, p[3].at = 4, p[3].bt = 4;

    for (int i = 0; i < n; i++) {
        p[i].wt = i == 0 ? 0 : p[i-1].bt + p[i-1].wt;
        p[i].tat = p[i].bt + p[i].wt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;'
    '

    printf("P     BT     WT     TAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d     %d     %d      %d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("Average Waiting Time= %f", avg_wt);
    printf("\nAverage Turnaround Time= %f", avg_tat);

    return 0;
}