#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void afficherPlateau(char plateau[8][8]){
	printf("  +---+---+---+---+---+---+---+---+");
	printf("\n");
	for (int i = 0; i < 8; i++){
		printf("%d ", 8-i);
		for (int j = 0; j < 8; j++){
			printf("| %c ", plateau[i][j]);
		}
		printf("|");
		printf("\n");
		printf("  +---+---+---+---+---+---+---+---+");
		printf("\n");
	}
	printf("    a   b   c   d   e   f   g   h  \n");
}

void deplacer(char plateau[8][8]){
	char depart[3];
	char arrivee[3];
	
	printf("A vous de jouer, veuillez donner une position de départ :\n");
	scanf("%2s", depart);
	int ligne = 8 - (depart[1] - '0');
	int colonne = depart[0] - 'a';
	while (ligne < 0 || ligne > 7){
		printf("Erreur : veuillez renseigner une position valide : \n");
		scanf("%2s", depart);
	}
	char pos_act = plateau[ligne][colonne];
	printf("depart : %c \n", pos_act);
	
	printf("A vous de jouer, veuillez donner une position d'arrivée :\n");
	scanf("%2s", arrivee);
	int ligne2 = 8 - (arrivee[1] - '0');
	int colonne2 = arrivee[0] - 'a';
	while (ligne2 < 0 || ligne2 > 7){
		printf("Erreur : veuillez renseigner une position valide : \n");
		scanf("%2s", arrivee);
	}
	plateau[ligne][colonne] = ' ';
	plateau[ligne2][colonne2] = pos_act;
	afficherPlateau(plateau);
}

int main(void){
	char plateau[8][8] = {
	{'T', 'C', 'F', 'R', 'D', 'F', 'C', 'T'},
	{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	{'t', 'c', 'f', 'r', 'd', 'f', 'c', 't'}
	};
	afficherPlateau(plateau);
	deplacer(plateau);
	return 0;
}
