//Auteur: Esteban Giorgis
//Titre: Bataille Navale
//Date:13.02.2019
//Description: Ce fichier est les tableaux utilisé
//Version:1.0

#ifndef BATAILLENAVALEXA_TABLEAU_H
#define BATAILLENAVALEXA_TABLEAU_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h> //pour rand

#define TORPIEUR 1
#define SOUS_MARIN 2
#define CONTRE_TORPILLEUR 3
#define CROISEUR 4
#define PORTE_AVION 5

#define POINT_VI_TORPIEUR 2
#define POINT_VI_SOUS_MARIN 3
#define POINT_DE_VI_CONTRE_TORPILLEUR 3
#define POINT_VI_CROISEUR 4
#define POINT_VIE_PORTE_AVIONS 5

#define NBR_PARTIE_TOTAL_BATEAU_MAX 17
#define NBR_MAX_DE_COUP 50
#define TABLEAU_LARGEUR 10
#define TABLEAU_LONGUEUR 10

char tableauAfficher[TABLEAU_LARGEUR][TABLEAU_LONGUEUR];

int compteurVictoir = 0;//Elle sert afaire une boucle avec celci pour pour stoper la partie quand il a tout couler
int compteur=0;//se compteur sert a mettre une fin a la partie qu'elle que soit les circonstance
int tireRestant;//variable qui affiche les tire restants



unsigned int pointViTorpieur=0;
unsigned int pointViSousMarin=0;
unsigned int pointViContreTorpilleur=0;
unsigned int pointViCroiseur=0;
unsigned int pointViPorteAvion=0;
unsigned int choixGrille;

int chiffreADroite=1;//tout les chiffre a droite 1 à 10


//tableau qui contient les bateau a coulé et est le tableau analyser par l'ordi pour ces calcules
int tableauAnnalyserParOrdi[TABLEAU_LARGEUR][TABLEAU_LONGUEUR];


//tableau qui contient les bateau a coulé et est le tableau analyser par l'ordi pour ces calcules
int tableauAnnalyserParOrdi1[TABLEAU_LARGEUR][TABLEAU_LONGUEUR] = {
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 2, 2, 2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 3, 3, 3, 0, 0, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 4, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 4, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 4, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 4, 0
};


//tableau qui contient les bateau a coulé et est le tableau analyser par l'ordi pour ces calcules
int tableauAnnalyserParOrdi2[TABLEAU_LARGEUR][TABLEAU_LONGUEUR] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 2, 2, 2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        3, 0, 0, 0, 0, 0, 0, 0, 4, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 4, 0,
        0, 0, 5, 5, 5, 5, 5, 0, 4, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 4, 0
};


//tableau qui contient les bateau a coulé et est le tableau analyser par l'ordi pour ces calcules
int tableauAnnalyserParOrdi3[TABLEAU_LARGEUR][TABLEAU_LONGUEUR] = {
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 2, 0, 0, 3, 3, 3, 0, 0, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 5, 0, 4, 4, 4, 4, 0, 0,
        0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};



//fonction qui reset quand il a gagné ou perdu
void reset(){
    compteurVictoir = 0;//Elle sert afaire une boucle avec celci pour pour stoper la partie quand il a tout couler
    compteur=0;//se compteur sert a mettre une fin a la partie qu'elle que soit les circonstance

    choixGrille=rand()%3+1;//Inscrit un nombre random a la variable choixGrille entre 1 et 3

    //ce switch fait une selection aléatoir d'un des trois tableau d'analyse
    switch(choixGrille){
        case 1:
            //boucle qui remet la vaguelette du tableau char
            for (int ligne = 0; ligne < TABLEAU_LARGEUR; ligne++) {
                for (int col = 0; col < TABLEAU_LONGUEUR; col++) {
                    tableauAnnalyserParOrdi[ligne][col]=tableauAnnalyserParOrdi1[ligne][col];
                }
            }
            break;

        case 2:
            //boucle qui remet la vaguelette du tableau char
            for (int ligne = 0; ligne < TABLEAU_LARGEUR; ligne++) {
                for (int col = 0; col < TABLEAU_LONGUEUR; col++) {
                    tableauAnnalyserParOrdi[ligne][col]=tableauAnnalyserParOrdi2[ligne][col];
                }
            }
            break;

        case 3:
            //boucle qui remet la vaguelette du tableau char
            for (int ligne = 0; ligne < TABLEAU_LARGEUR; ligne++) {
                for (int col = 0; col < TABLEAU_LONGUEUR; col++) {
                    tableauAnnalyserParOrdi[ligne][col]=tableauAnnalyserParOrdi3[ligne][col];
                }
            }
            break;

            //ce dernier case sert en cas de mauvaise valeur aléatoir due a une erreur de codage
        default:
            printf("\nProblème de valeur aléatoire!!\n");

    }


    pointViTorpieur=0;
    pointViSousMarin=0;
    pointViContreTorpilleur=0;
    pointViCroiseur=0;
    pointViPorteAvion=0;
    tireRestant=NBR_MAX_DE_COUP;//variable qui affiche les tire restants

    //boucle qui remet la vaguelette du tableau char
    for (int ligne = 0; ligne < TABLEAU_LARGEUR; ligne++) {
        for (int col = 0; col < TABLEAU_LONGUEUR; col++) {
            tableauAfficher[ligne][col] = *"~";
        }
    }
}





//fonction qui travaille et affiche la grille
void affichageGrille(int horizontal, int vertical) {


    //condition si toute les parties du bateau sont touchée indique coulé
    switch(tableauAnnalyserParOrdi[horizontal-1][vertical-1]){
        case  TORPIEUR:
            //Condition qui repete la demande de la coordonné si il a deja tiré dessus
            if(tableauAfficher[horizontal - 1][vertical - 1] == *"X" || tableauAfficher[horizontal - 1][vertical - 1] == *"O"){
                tireRestant++;
                printf("Vous avez deja touché cette case choisissez en une autre\n\n");
                //boucle pour redemander a chaque fois les coordonée tant qu'il ne sont pas dans les règles
                while(horizontal<1 || horizontal>10) {
                    printf("\n\n\nChoisissez une position horizontal: ");
                    scanf("%d", &horizontal);
                }
                while(vertical<1 || vertical>10) {
                    printf("\nChoisissez une position vertical: ");
                    scanf("%d", &vertical);

                }
            }
            else{
                pointViTorpieur++;
                compteurVictoir++;
                compteur++;
            }

            printf("\n\n\ntouché\n");
            printf("Coup restant :%d\n", tireRestant);
            //remplace la vagellette par X
            tableauAfficher[horizontal - 1][vertical - 1] = *"X";
            if(pointViTorpieur==POINT_VI_TORPIEUR){
                printf("vous avez couler le torpilleur\n");
            }

            break;

        case SOUS_MARIN:
            //Condition qui repete la demande de la coordonné si il a deja tiré dessus
            if(tableauAfficher[horizontal - 1][vertical - 1] == *"X" || tableauAfficher[horizontal - 1][vertical - 1] == *"O"){
                tireRestant++;
                printf("Vous avez deja touché cette case choisissez en une autre\n\n");
                //boucle pour redemander a chaque fois les coordonée tant qu'il ne sont pas dans les règles
                while(horizontal<1 || horizontal>10) {
                    printf("\n\n\nChoisissez une position horizontal: ");
                    scanf("%d", &horizontal);
                }
                while(vertical<1 || vertical>10) {
                    printf("\nChoisissez une position vertical: ");
                    scanf("%d", &vertical);

                }
            }
            else{
                pointViSousMarin++;
                compteurVictoir++;
                compteur++;
            }
            printf("\n\n\ntouché\n");
            printf("Coup restant :%d\n", tireRestant);
            //remplace la vagellette par X
            tableauAfficher[horizontal - 1][vertical - 1] = *"X";
            if (pointViSousMarin == POINT_VI_SOUS_MARIN) {
                printf("vous avez couler le sous-marin\n");
            }

            break;


        case CONTRE_TORPILLEUR:
            //Condition qui repete la demande de la coordonné si il a deja tiré dessus
            if(tableauAfficher[horizontal - 1][vertical - 1] == *"X" || tableauAfficher[horizontal - 1][vertical - 1] == *"O"){
                tireRestant++;
                printf("Vous avez deja touché cette case choisissez en une autre\n\n");
                //boucle pour redemander a chaque fois les coordonée tant qu'il ne sont pas dans les règles
                while(horizontal<1 || horizontal>10) {
                    printf("\n\n\nChoisissez une position horizontal: ");
                    scanf("%d", &horizontal);
                }
                while(vertical<1 || vertical>10) {
                    printf("\nChoisissez une position vertical: ");
                    scanf("%d", &vertical);

                }
            }
            else{
                pointViContreTorpilleur++;
                compteurVictoir++;
                compteur++;
            }
            printf("\n\n\ntouché\n");
            printf("Coup restant :%d\n", tireRestant);
            //remplace la vagellette par X
            tableauAfficher[horizontal - 1][vertical - 1] = *"X";
            if(pointViContreTorpilleur==POINT_DE_VI_CONTRE_TORPILLEUR){
                printf("vous avez couler le contre-torpilleur\n");
            }
            break;


        case CROISEUR:
            //Condition qui repete la demande de la coordonné si il a deja tiré dessus
            if(tableauAfficher[horizontal - 1][vertical - 1] == *"X" || tableauAfficher[horizontal - 1][vertical - 1] == *"O"){
                tireRestant++;
                printf("Vous avez deja touché cette case choisissez en une autre\n\n");
                //boucle pour redemander a chaque fois les coordonée tant qu'il ne sont pas dans les règles
                while(horizontal<1 || horizontal>10) {
                    printf("\n\n\nChoisissez une position horizontal: ");
                    scanf("%d", &horizontal);
                }
                while(vertical<1 || vertical>10) {
                    printf("\nChoisissez une position vertical: ");
                    scanf("%d", &vertical);

                }
            }
            else{
                pointViCroiseur++;
                compteurVictoir++;
                compteur++;
            }
            printf("\n\n\ntouché\n");
            printf("Coup restant :%d\n", tireRestant);
            //remplace la vagellette par X
            tableauAfficher[horizontal - 1][vertical - 1] = *"X";
            if(pointViCroiseur==POINT_VI_CROISEUR){
                printf("vous avez couler le croiseur\n");
            }
            break;

        case PORTE_AVION:
            //Condition qui repete la demande de la coordonné si il a deja tiré dessus
            if(tableauAfficher[horizontal - 1][vertical - 1] == *"X" || tableauAfficher[horizontal - 1][vertical - 1] == *"O"){
                tireRestant++;
                printf("Vous avez deja touché cette case choisissez en une autre\n\n");
                //boucle pour redemander a chaque fois les coordonée tant qu'il ne sont pas dans les règles
                while(horizontal<1 || horizontal>10) {
                    printf("\n\n\nChoisissez une position horizontal: ");
                    scanf("%d", &horizontal);
                }
                while(vertical<1 || vertical>10) {
                    printf("\nChoisissez une position vertical: ");
                    scanf("%d", &vertical);

                }
            }
            else{
                pointViPorteAvion++;
                compteurVictoir++;
                compteur++;
            }
            printf("\n\n\ntouché\n");
            printf("Coup restant :%d\n", tireRestant);
            //remplace la vagellette par X
            tableauAfficher[horizontal - 1][vertical - 1] = *"X";
            if(pointViPorteAvion==POINT_VIE_PORTE_AVIONS){
                printf("vous avez couler le porte-avions\n");

            }
            break;


        default:
            //Condition qui repete la demande de la coordonné si il a deja tiré dessus
            if(tableauAfficher[horizontal - 1][vertical - 1] == *"X" || tableauAfficher[horizontal - 1][vertical - 1] == *"O"){
                tireRestant++;
                printf("Vous avez deja touché cette case choisissez en une autre\n\n");
                //boucle pour redemander a chaque fois les coordonée tant qu'il ne sont pas dans les règles
                while(horizontal<1 || horizontal>10) {
                    printf("\n\n\nChoisissez une position horizontal: ");
                    scanf("%d", &horizontal);
                }
                while(vertical<1 || vertical>10) {
                    printf("\nChoisissez une position vertical: ");
                    scanf("%d", &vertical);

                }
            }
            else{
                compteur++;
            }
            //remplace la vagellette par O
            tableauAfficher[horizontal - 1][vertical - 1] = *"O";
            printf("\n\n\nloupé\n");
            printf("Coup restant :%d\n", tireRestant);

    }


    int cadrillage_horizontal;//Boucle pour noter la numérotation de 1 a 10

    //boucle pour afficher les chiffres horizontal
    for(cadrillage_horizontal=1;cadrillage_horizontal<=10;cadrillage_horizontal++) {
        printf("     %d",cadrillage_horizontal);
    }

    //boucle qui permet d'afficher tout le tableau
    for (int ligne = 0; ligne < 10; ligne++) {
        printf("\n");


        if (chiffreADroite == 10) {      //Pour affiche les chiffre verticalement
            printf("%d", chiffreADroite);
            chiffreADroite=0;
        } else {
            printf(" %d", chiffreADroite);
        }
        chiffreADroite++;
        for (int colonne = 0; colonne < 10; colonne++) {
            printf(" | %c |",tableauAfficher[ligne][colonne]);

        }

    }//fin de la boucle for





}//fin de ma fonction principal


#endif //BATAILLENAVALEXA_TABLEAU_H
