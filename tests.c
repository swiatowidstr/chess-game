#include <stdio.h>

void afficherT(char tab[8][8], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%c  ", tab[i][j]);
		}
		printf("\n");
	}
}



int main(void){
	char tab[8][8];
	int n = 8;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			tab[i][j] = '0';
		}
	}
	tab[7][0] = 's';
	tab[1][6] = 'e';
	afficherT(tab, n);
	printf("\n");
	// verif diagonnales
	int start = tab[4][3];
	int end = tab[1][6];
	int x = 7;
	int y = 0;
	for (int i = x; i > 1; i--){
		tab[i][-i] = 'v'; 
	}
	afficherT(tab, n);
}

/*
-Diagonnale haut droite : 
ligD = 4;
colD = 3;
start = tab[ligD][colD];

ligA = 1;
colA = 6;
end = tab[ligA][colA];


-Diagonnale haut gauche :


-Diagonnale bas droite :


-Diagonnale bad gauche :

if (ligA < ligD && colA > colD){
	diagonnale haut droite
}
else if (ligA < ligD && colA < colD){
	diagonnale haut gauche;
}
else if (ligA > ligD && colA < colD){
	diagonnale bas gauche;
}
else if (ligA > ligD && colA > colD){
	diagonnale bas droite;
}


*/
