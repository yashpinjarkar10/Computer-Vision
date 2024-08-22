#include <stdio.h>

void WaitingTime(int processes[], int n, int WT[], int BT[]){
    WT[0] = 0;
    for(int i=1; i<n; i++){
        WT[i] = WT[i-1] + BT[i-1];
    }
    for(int i=0; i<n; i++){
        printf("WaitingTime of process_%d = %d\n", processes[i], WT[i]);
    }
}
void TurnAroundTime(int processes[], int n, int BT[], int WT[], int TAT[]){
    for(int i=0; i<n; i++){
        TAT[i] = WT[i] + BT[i];
    }
    for(int i=0; i<n; i++){
        printf("TurnAroundTime of process_%d = %d\n", processes[i], TAT[i]);
    }
}
void Average_TAT_WT_RT(int processes[], int n, int BT[]){
    int WT[n];
    int TAT[n];
    WaitingTime(processes, n, WT, BT);
    printf("\n");
    TurnAroundTime(processes, n, BT, WT, TAT);
    float S_WT = 0;
    float S_TAT = 0;
    for(int i=0; i<n; i++){
        S_WT += WT[i];
        S_TAT += TAT[i];
    }
    float Average_WT = (S_WT/n);
    float Average_TAT = (S_TAT/n);
    printf("\n");
    printf("Average Waiting Time = %.3f\n", Average_WT);
    printf("Average TurnAround Time = %.3f\n", Average_TAT);
    printf("    (Since AverageResponseTime = AverageWaitingTime)   \n");
    printf("Average Response Time = %.3f\n", Average_WT);
}
int main(){
    int n;
    printf("Enter number of processes: \n");
    scanf("%d", &n);

    int processes[n];
    int BT[n];
    // Arbitarily Arrival time of all processes is zero.

    for(int i=0; i<n; i++){
        processes[i] = i+1;
    }

    printf("Arbitarily Arrival time of all processes is zero.\n");
    printf("Enter BurstTime of all processes: \n\n");

    for (int i=0; i<n; i++){
        printf("BurstTime of process_%d = ", processes[i]);
        scanf("%d", &BT[i]);
    }
    printf("\n");
    Average_TAT_WT_RT(processes, n, BT);

    return 0;
}