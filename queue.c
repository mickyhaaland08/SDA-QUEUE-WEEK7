/*File body untuk ADT Queue*/
//Dibuat tanggal 28-3-2013

#include "queue.h"
#include "linkmick.h"
#include "linkmick.c"

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q){
	CreateList(&(Q->front));  // Mengatur front sebagai NULL (queue kosong)
    Q->rear = NULL; 
}


/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q){
	return isEmpty(Q.front);
}

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q){
	return false; 
}

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X){
	InsVLast(&(Q->front), X);  // Masukkan ke dalam front (karena List adalah front)
    if (Q->rear == NULL) {  // Jika sebelumnya kosong, rear harus menunjuk ke elemen pertama
        Q->rear = Q->front;
    } else {
        Q->rear = Q->rear->next;  // Rear berpindah ke elemen terakhir
    }
}

/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype *X){
    if (!is_Empty(*Q)) {  
        DelVFirst(&(Q->front), X);  
        if (Q->front == NULL) {  
            Q->rear = NULL;  
        }
    }
}

void printQueue(Queue Q) {
    address P = Q.front;
    if (is_Empty(Q)) {
        printf("Antrian kosong.\n");
    } else {
        printf("Antrian saat ini: ");
        while (P != NULL) {
            printf("%d ", P->info);
            P = P->next;
        }
        printf("\n");
    }
}