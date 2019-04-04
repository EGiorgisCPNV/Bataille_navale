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

//fonction qui initialise mes variable
void initialisation(){
    //boucle qui remet la vaguelette du tableau char
    for (int ligne = 0; ligne < TABLEAU_LARGEUR; ligne++) {
        for (int col = 0; col < TABLEAU_LONGUEUR; col++) {
            tableauAfficher[ligne][col] = *"~";
        }
    }

    nbPartie=0;
    tireRestant= NBR_MAX_DE_COUP;//variable qui affiche les tire restants
}


int main() {
    SetConsoleOutputCP(65001);//Pour que le programmes reconnaice les accents

    char Prenom[255];//variable pour le prénom
    char Nom[255];//variable pour le nom
    unsigned int choix=0;//variable pour le choix de l'utilisateur et que le numéro minimum ne soit pas négatif
    int quitter;//Cette variable sers a pouvoir quitter le programme
    FILE* filePt;//Cette variable sera utiliser pour enrgistrer des information dans un fichier
    filePt=fopen("score.txt", "w");

    initialisation();//Initialisation des variables

    //Pour demander l'identiter de la personne
    printf("Veiller indiquer votre Nom puis Prénom\n");


    fprintf(filePt,"%s","Nom: ");//inscrit le mot "Nom" dans le fichier
    scanf("%s", Nom);//demande puis inscrit le nom de l'utilisateur dans la variable "Nom"
    fprintf(filePt,"%s \n",Nom);//Inscritcheh le contenu de la variable "Nom" dans le fichier

    fprintf(filePt,"%s","Prénom: ");//inscrit le mot "Prenom" dans le fichier
    scanf("%s", Prenom);//demande puis inscrit le nom de l'utilisateur dans la variable "Prenom"
    fprintf(filePt,"%s\n",Prenom);//Inscrit le contenu de la variable "Prenom" dans le fichier



    printf("\nBonjour et bienvenu %s %s\n\nVous vous appreter a jouer au jeu de la bataille navale", Prenom, Nom);
    printf("\n_________________________________________________\n");


    //pour appeler la fonction qui affiche le menu
    menu(filePt);
    fclose(filePt);
}