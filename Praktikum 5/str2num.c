// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 28 September 2022
// Topik: Mesin Kata
// Deskripsi: Praktikum str2num.c

#include <stdio.h>
#include "wordmachine.c"
#include "boolean.h"

Word currentWord;
boolean endWord;

/*
nol 3`
satu 4`
dua 3`
tiga 4`
empat 5`
lima 4`
enam 4`
tujuh 5`
delapan 7`
sembilan 8`
sepuluh 7`
sebelas 7`
belas 5`
puluh 5`
seratus 7`
ratus 5`
seribu 6`
ribu 4`
juta 4`
miliar 6`
*/

int word2num(Word word, int ratusan, int puluhan, int satuan, boolean* isNum){
	if(endWord){
		return (ratusan*100 + puluhan*10 + satuan);
	}
	else{
		if(word.Length == 3){
			if(word.TabWord[0] == 'n' && word.TabWord[1] == 'o' && word.TabWord[2] == 'l'){
				satuan = 0;
				*isNum = true;
			}
			else if(word.TabWord[0] == 'd' && word.TabWord[1] == 'u' && word.TabWord[2] == 'a'){
				satuan = 2;
				*isNum = true;
			}
		}
		else if(word.Length == 4){
			if(word.TabWord[0] == 's' && word.TabWord[1] == 'a' && word.TabWord[2] == 't' && word.TabWord[3] == 'u'){
				satuan = 1;
				*isNum = true;
			}
			else if(word.TabWord[0] == 't' && word.TabWord[1] == 'i' && word.TabWord[2] == 'g' && word.TabWord[3] == 'a'){
				satuan= 3;
				*isNum = true;
			}
			else if(word.TabWord[0] == 'l' && word.TabWord[1] == 'i' && word.TabWord[2] == 'm' && word.TabWord[3] == 'a'){
				satuan = 5;
				*isNum = true;
			}
			else if(word.TabWord[0] == 'e' && word.TabWord[1] == 'n' && word.TabWord[2] == 'a' && word.TabWord[3] == 'm'){
				satuan = 6;
				*isNum = true;
			}
			else if(word.TabWord[0] == 'r' && word.TabWord[1] == 'i' && word.TabWord[2] == 'b' && word.TabWord[3] == 'u'){
				*isNum = true;
				return ((ratusan*100 + puluhan*10 + satuan) * 1000) + word2num(currentWord, 0, 0, 0, isNum);
			}
			else if(word.TabWord[0] == 'j' && word.TabWord[1] == 'u' && word.TabWord[2] == 't' && word.TabWord[3] == 'a'){
				*isNum = true;
				return ((ratusan*100 + puluhan*10 + satuan) * 1000000) + word2num(currentWord, 0, 0, 0, isNum);
			}
		}
		else if(word.Length == 5){
			if(word.TabWord[0] == 'e' && word.TabWord[1] == 'm' && word.TabWord[2] == 'p' && word.TabWord[3] == 'a' && word.TabWord[4] == 't'){
				satuan = 4;
				*isNum = true;
			}
			else if(word.TabWord[0] == 't' && word.TabWord[1] == 'u' && word.TabWord[2] == 'j' && word.TabWord[3] == 'u' && word.TabWord[4] == 'h'){
				satuan = 7;
				*isNum = true;
			}
			else if(word.TabWord[0] == 'b' && word.TabWord[1] == 'e' && word.TabWord[2] == 'l' && word.TabWord[3] == 'a' && word.TabWord[4] == 's'){
				puluhan = 1;
				*isNum = true;
			}
			else if(word.TabWord[0] == 'p' && word.TabWord[1] == 'u' && word.TabWord[2] == 'l' && word.TabWord[3] == 'u' && word.TabWord[4] == 'h'){
				puluhan = satuan;
				satuan = 0;
				*isNum = true;
			}
			else if(word.TabWord[0] == 'r' && word.TabWord[1] == 'a' && word.TabWord[2] == 't' && word.TabWord[3] == 'u' && word.TabWord[4] == 's'){
				ratusan = satuan;
				satuan = 0;
				*isNum = true;
			}
		}
		else if(word.Length == 6){
			if(word.TabWord[0] == 's' && word.TabWord[1] == 'e' && word.TabWord[2] == 'r' && word.TabWord[3] == 'i' && word.TabWord[4] == 'b' && word.TabWord[5] == 'u'){
				*isNum = true;
				return 1000 + word2num(currentWord, 0, 0, 0, isNum);
			}
			else if(word.TabWord[0] == 'm' && word.TabWord[1] == 'i' && word.TabWord[2] == 'l' && word.TabWord[3] == 'i' && word.TabWord[4] == 'a' && word.TabWord[5] == 'r'){
				*isNum = true;
				return ((ratusan*100 + puluhan*10 + satuan) * 1000000000) + word2num(currentWord, 0, 0, 0, isNum);
			}
		}
		else if(word.Length == 7){
			if(word.TabWord[0] == 'd' && word.TabWord[1] == 'e' && word.TabWord[2] == 'l' && word.TabWord[3] == 'a' && word.TabWord[4] == 'p' && word.TabWord[5] == 'a' && word.TabWord[6] == 'n'){
				satuan = 8;
				*isNum = true;
			}
			else if(word.TabWord[0] == 's' && word.TabWord[1] == 'e' && word.TabWord[2] == 'p' && word.TabWord[3] == 'u' && word.TabWord[4] == 'l' && word.TabWord[5] == 'u' && word.TabWord[6] == 'h'){
				puluhan = 1;
				*isNum = true;
			}
			else if(word.TabWord[0] == 's' && word.TabWord[1] == 'e' && word.TabWord[2] == 'b' && word.TabWord[3] == 'e' && word.TabWord[4] == 'l' && word.TabWord[5] == 'a' && word.TabWord[6] == 's'){
				puluhan = 1;
				satuan = 1;
				*isNum = true;
			}
			else if(word.TabWord[0] == 's' && word.TabWord[1] == 'e' && word.TabWord[2] == 'r' && word.TabWord[3] == 'a' && word.TabWord[4] == 't' && word.TabWord[5] == 'u' && word.TabWord[6] == 's'){
				ratusan = 1;
				*isNum = true;
			}
		}
		else if(word.Length == 8){
			if(word.TabWord[0] == 's' && word.TabWord[1] == 'e' && word.TabWord[2] == 'm' && word.TabWord[3] == 'b' && word.TabWord[4] == 'i' && word.TabWord[5] == 'l' && word.TabWord[6] == 'a' && word.TabWord[6] == 'n'){
				satuan = 9;
				*isNum = true;
			}
		}
		else{
			return (ratusan*100 + puluhan*10 + satuan);
		}
		if(*isNum){
			/*int i;
			for(i=0; i < currentWord.Length; i++){
				printf("%c", currentWord.TabWord[i]);
			}*/
			ADVWORD();
			return word2num(currentWord, ratusan, puluhan, satuan, isNum);
		}
	}
}

int main(){
	/* KAMUS */
	int i;
	int currentNum;
	boolean isNum;

	/* ALGORITMA */
	STARTWORD();
	isNum = false;
	currentNum = word2num(currentWord, 0, 0, 0, &isNum);
	if(!endWord){
		do{
			if(isNum){
				printf("%d ", currentNum);
			}
			for(i=0; i < currentWord.Length; i++){
				printf("%c", currentWord.TabWord[i]);
			}
			printf(" ");
			ADVWORD();
			isNum = false;
			currentNum = word2num(currentWord, 0, 0, 0, &isNum);
		}	while(!endWord);
	}
	printf("\n");
}