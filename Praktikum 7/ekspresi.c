// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 20 Oktober 2022
// Topik: ADT Stack
// Deskripsi: Praktikum ekspresi.c

#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "wordmachine.h"

int main(){
    /* KAMUS */
    Stack expr;
    infotype val1, val2, val;
    int i;

    /* ALGORITMA */
    STARTWORD();
    if(endWord){
        printf("Ekspresi kosong\n");
    }
    else{
        CreateEmpty(&expr);
        do{
            if(currentWord.TabWord[0] == '+'){
                Pop(&expr, &val2);
                Pop(&expr, &val1);
                printf("%d + %d\n", val1, val2);
                val = val1 + val2;
            }
            else if(currentWord.TabWord[0] == '-'){
                Pop(&expr, &val2);
                Pop(&expr, &val1);
                printf("%d - %d\n", val1, val2);
                val = val1 - val2;
            }
            else if(currentWord.TabWord[0] == '*'){
                Pop(&expr, &val2);
                Pop(&expr, &val1);
                printf("%d * %d\n", val1, val2);
                val = val1 * val2;
            }
            else if(currentWord.TabWord[0] == '/'){
                Pop(&expr, &val2);
                Pop(&expr, &val1);
                printf("%d / %d\n", val1, val2);
                val = val1 / val2;
            }
            else if(currentWord.TabWord[0] == '^'){
                Pop(&expr, &val2);
                Pop(&expr, &val1);
                printf("%d ^ %d\n", val1, val2);
                val = pow(val1,val2);
            }
            else{
                val = 0;
                i = 0;
                for(;;){
                    val += (currentWord.TabWord[i] - '0');
                    i++;
                    if(i == currentWord.Length) break;
                    val *= 10;
                }
            }

            // print hasil ekspresi
            printf("%d\n", val);
            Push(&expr, val);   // push nilai ke stack

            ADVWORD();
        } while(!endWord);
        // endWord, semua ekspresi telah habis dibaca; jika diasumsikan semua ekspresi valid, isi stack yang tersisa adalah nilai hasil
        printf("Hasil=%d\n", val);
    }

    return 0;
}