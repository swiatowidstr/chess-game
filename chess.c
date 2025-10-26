#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Pieces blances en majuscule
//Pieces noires en minuscule
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

bool estAllie(char piece, char cible){
	if (cible == ' '){
		return false;
	}
	if ((piece >= 'A' && piece <= 'Z' && cible >= 'A' && cible <= 'Z')){
		return true;
	}
	if ((piece >= 'a' && piece <= 'z' && cible >= 'a' && cible <= 'z')){
		return true;
	}
	return false;
}

//verification des coups par catégorie de pièce
bool verifPion(char plateau[8][8], int ligD, int colD, int ligA, int colA, char piece){
	int direction;
	if (piece == 'P'){
		direction = -1;
	}
	else{
		direction = 1;
	}
	
	//verifie le cas ou le pion avance d'une case
	if (ligA == ligD + direction && colA == colD && plateau[ligA][colA] == ' '){
		return true;
	}
	//verifie le cas ou le pion mange
	if (ligA == ligD + direction && (colA == colD +1 || colA == colD -1) && plateau[ligA][colA] != ' '){
		return true;
	}
	//verifie le cas ou le pion saute deux cases la première fois qu'il joue et qu'il ne saut pas de pièce en sautant deux cases
	if (ligA == ligD + direction + direction && colA == colD && 
	plateau[ligD + direction][colD] == ' ' && 
	plateau[ligA][colA] == ' ' &&
	((piece == 'P' && ligD == 6) || (piece == 'p' && ligD == 1))){
		return true;
	}
	
	return false;
}

bool verifTour(char plateau[8][8], int ligD, int colD, int ligA, int colA, char piece){
	if (ligD != ligA && colD != colA){
		return false;
	}
	
	//on vérifie si il y a des obstacles sur la ligne quand la tour veut bouger honrizontalement
	if (colD == colA){
		int start, end;
		if (ligD < ligA){
			start = ligD +1;
			end = ligA;
		}
		else{
			start = ligA +1;
			end = ligD;
		}
		for (int i = start; i < end; i++){
			if (plateau[i][colD] != ' '){
				return false;
			}
		}
	}
	//on vérifie si il y a des obstacles sur la ligne quand la tour veut bouger verticalement
	else{
		int start, end;
		if (colD < colA){
			start = colD +1;
			end = colA;
		}
		else{
			start = colA +1;
			end = colD;
		}
		for (int j = start; j < end; j++){
			if (plateau[ligD][j] != ' ')
				return false;
		}
	}
	char cible = plateau[ligA][colA];
	if (estAllie(piece, cible)){
		return false;
	}
	return true;
}

bool verifCavalier(char plateau[8][8], int ligD, int colD, int ligA, int colA, char piece){
	
}

bool verifFou(char plateau[8][8], int ligD, int colD, int ligA, int colA, char piece){
	
}

bool verifRoi(char plateau[8][8], int ligD, int colD, int ligA, int colA, char piece){
	
}

bool verifDame(char plateau[8][8], int ligD, int colD, int ligA, int colA, char piece){
	
}


//verifie si le coup est valide en utilisant les fonctions de vérification du coup par pièce
bool verifCoup(char plateau[8][8], int ligD, int colD, int ligA, int colA){
	char piece = plateau[ligD][colD];
	
	switch (piece){
		case 'p':
		case 'P':
			return verifPion(plateau, ligD, colD, ligA, colA, piece);
			break;
			
		case 'T':
		case 't':
			return verifTour(plateau, ligD, colD, ligA, colA, piece);
			break;
			
		case 'C':
		case 'c':
			return verifCavalier(plateau, ligD, colD, ligA, colA, piece);
			break;
			
		case 'F':
		case 'f':
			return verifFou(plateau, ligD, colD, ligA, colA, piece);
			break;
			
		case 'R':
		case 'r':
			return verifRoi(plateau, ligD, colD, ligA, colA, piece);
			break;
			
		case 'D':
		case 'd':
			return verifDame(plateau, ligD, colD, ligA, colA, piece);
			break;
			
		default:
			return false;
	}
}


//vérifie si les coordonnées tapées au clavier sont correctes
bool verifCoord(char plateau[8][8], int ligD, int colD, int ligA, int colA){
	if (ligD < 0 || ligD > 7 || colD < 0 || colD > 7 || ligA < 0 || ligA > 7 || colA < 0 || colA > 7){
		printf("Erreur : coordonnées invalides\n");
		return false;
	}
	if (plateau[ligD][colD] == ' '){
		printf("Erreur : il n'y a pas de pièce a cet emplacement\n");
		return false;
	}
	if (plateau[ligA][colA] == 'R' || plateau[ligA][colA] == 'r'){
		printf("Erreur : Vous ne pouvez pas manger le Roi\n");
		return false;
	}
	return true;
}


//Lis les coordonnées
void lireCoord(int *pligD, int *pcolD, int *pligA, int *pcolA){
	char depart[3];
	char arrivee[3];
	
	printf("Entrez une case de départ : \n");
	scanf("%2s", depart);
	while (getchar() != '\n');
	
	printf("Entrez une case d'arrivee : \n");
	scanf("%2s", arrivee);
	while (getchar() != '\n');
	
	
	*pligD = 8 - (depart[1] - '0');
	*pcolD = depart[0] - 'a';
	*pligA = 8 - (arrivee[1] - '0');
	*pcolA = arrivee[0] - 'a';
}


//vérifie et réalise le coup tapé par l'utilisateur
void jouer(char plateau[8][8], char joueur){
	int ligD, colD, ligA, colA;
	lireCoord(&ligD, &colD, &ligA, &colA);
	
	
	while (!verifCoord(plateau, ligD, colD, ligA, colA)){
		lireCoord(&ligD, &colD, &ligA, &colA);
	}
	
	plateau[ligA][colA] = plateau[ligD][colD];
	plateau[ligD][colD] = ' ';
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
	char joueur = 1;
	afficherPlateau(plateau);
	jouer(plateau, joueur);
	afficherPlateau(plateau);
	return 0;
}
