//Auteur: Esteban Giorgis
//Titre: Bataille Navale
//Date:13.02.2019
//Description: Jeu vidéo sur une bataille navale
//Version:1.0

#include <stdio.h>
#include "Tableau.h"
#include "Menu.h"
#include <windows.h>
#include<stdlib.h>

#pragma execution_character_set("utf-8") //Pour que le programmes reconnaice les accents

#define TABLEAU_LARGEUR 10
#define TABLEAU_LONGUEUR 10

void initialisation(){
    //boucle qui remet la vaguelette du tableau char
    for (int ligne = 0; ligne < TABLEAU_LARGEUR; ligne++) {
        for (int col = 0; col < TABLEAU_LONGUEUR; col++) {
            tableauAfficher[ligne][col] = *"~";
        }
    }
}


int main() {
    SetConsoleOutputCP(65001);//Pour que le programmes reconnaice les accents

    char Prenom[255];//variable pour le prénom
    char Nom[255];//variable pour le nom
    unsigned int choix=0;//variable pour le choix de l'utilisateur et que le numéro minimum ne soit pas négatif
    int quitter;//Cette variable sers a pouvoir quitter le programme
    FILE* score;//Cette variable sera utiliser pour enrgistrer des information dans un fichier
    score=fopen("score.txt", "r+");

    initialisation();//Initialisation des variables

    //Pour demander l'identiter de la personne
    printf("Veiller indiquer votre Nom puis Prénom\n");

    fprintf(score,"%s","Nom :");
    scanf("%s", Nom);
    fprintf(score,"%s",Nom);

    fprintf(score,"%s","Prénom :");
    scanf("%s", Prenom);
    fprintf(score,"%s",Prenom);

    fclose(score);

    printf("\nBonjour et bienvenu %s %s\n\nVous vous appreter a jouer au jeu de la bataille navale", Prenom, Nom);
    printf("\n_________________________________________________\n");


    //pour appeler la fonction qui affiche le menu
    menu();

}