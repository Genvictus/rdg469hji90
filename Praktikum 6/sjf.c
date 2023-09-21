// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 6 Oktober 2022
// Topik: ADT Queue
// Deskripsi: Praktikum sjf.c

#include <stdio.h>
#include "boolean.h"
#include "prioqueuetime.h"

int main(){
	/* KAMUS */
    int i, n, t, rt;
    infotype job;
    PrioQueueTime PQ;
    boolean isfirst;
	
	/* ALGORITMA */
	scanf("%d", &n);
    MakeEmpty(&PQ, n);
    t = 0;
    rt = 0;
    for(i=0;i<n;i++){
        scanf("%d %c", &Time(job), &Info(job));
        Enqueue(&PQ, job);

        if(rt == 0){
            Dequeue(&PQ, &job);
            printf("%d %c\n", t, Info(job));
            rt = Time(job);
        }
        rt--;
        t++;
    }

    t += rt;
    while(!IsEmpty(PQ)){
        Dequeue(&PQ, &job);
        printf("%d %c\n", t, Info(job));
        t += Time(job);
    }
}