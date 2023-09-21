// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 22 September 2022
// Topik: Mesin Kata
// Deskripsi: Pra-praktikum wordmachine.c

/* File: wordmachine.c */
/* Definisi Word Machine: Model Akuisisi Versi I */

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

#define NMax 50
#define BLANK ' '

boolean endWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	while(currentChar == BLANK){
        ADV();
    }
    // currentChar != BLANK
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	START();
    IgnoreBlanks();
    if(currentChar == MARK){
        endWord = true;                 // EndWord = true ketika karakter bukan blank pertama yang dibaca adalah MARK
    } else {
        endWord = false;                // inisialisasi Endword = false, mulai salin kata dari awal
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	IgnoreBlanks();
    if(currentChar == MARK){
        endWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

	/* KAMUS LOKAL */
	int i;

	/* ALGORITMA */
    i = 0;
	for(;;){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;

        if((currentChar == MARK) || (currentChar == BLANK) || (i == NMax)){
            break;
        }
    }
    // currentChar == MARK atau currentChar == BLANK atau i == NMax
    currentWord.Length = i;

    if(i == NMax){                                  // jika panjang kata melebihi NMax, "potong" sisa kata -> lanjutkan hingga MARK
        while((currentChar != MARK) && (currentChar != BLANK)){
            ADV();
        }
    }
}

void LowerCase(){

/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */

/* F.S. currentword menjadi lowercase di setiap karakternya */

  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i=0; i < currentWord.Length; i++){
    if(65 <= currentWord.TabWord[i] && currentWord.TabWord[i] <= 90){
      currentWord.TabWord[i] += 32;
    }
  }

}