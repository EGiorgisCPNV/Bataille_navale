//
// Created by Esteban on 23.03.2019.
//


#include <windows.h>
#include<stdlib.h>

#ifndef BATAILLE_NAVSAL_1_MENU_H
#define BATAILLE_NAVSAL_1_MENU_H



//fonction pour afficher le menu
void menu(){
    FILE* score;//Cette variable sera utiliser pour enrgistrer des information dans un fichier


    unsigned int choix=0;//variable pour le choix de l'utilisateur et que le numéro minimum ne soit pas négatif

    while (choix !=3) //boucle qui affiche a chaque fois le menu jusqu'a qu'il demande de jouer ou de quitter
    {

        //Pour choisir l'action de l'utilisateur
        printf("Menu\n1 - Jouer\n2 - Règle du jeu\n3 - Quitter\n\nQuel est votre choix ?\n");
        scanf("%d", &choix);


        //Les action qui suivera le choix de l'utilisateur
        switch (choix) {

            case 1:

                printf("--------------------------------------\n           Bataille navale\n--------------------------------------\n\n\n");
                int vertical=0;//variable qui stocke la valeur de la colonne horizontal
                int horizontal=0;//variable qui stocke la valeur de la colonne horizontal
                int cadrillage_horizontal;//Boucle pour noter la numérotation de 1 a 10
                int chiffreADroite=1;//tout les chiffre a droite 1 à 10


                printf("Voici la grille\n");


                //boucle pour afficher les chiffres horizontal
                for(cadrillage_horizontal=1;cadrillage_horizontal<=10;cadrillage_horizontal++) {
                    printf("     %d",cadrillage_horizontal);
                }
                //boucle qui permet d'afficher tout le tableau
                for (int ligne = 0; ligne < 10; ligne++) {
                    printf("\n");
                    if(chiffreADroite==10){      //Pour affiche les chiffre verticalement
                        printf("%d", chiffreADroite);
                        chiffreADroite=0;
                    }else{
                        printf(" %d", chiffreADroite);
                    }
                    chiffreADroite++;
                    for (int colonne = 0; colonne < 10; colonne++) {
                        printf(" | %c |", tableauAfficher[ligne][colonne]);

                    }
                }


                printf("\n\n\nLa lettre X s'affichera a l'endroit ou vous avez touché et la lettre O s'affichera ou vous avez loupé");


                //boucle qui permet de répéter a chaque fois les deux questions tant qu'il n'a pas perdu ou gagné
                while(compteur <= NBR_MAX_DE_COUP || compteurVictoir <= NBR_PARTIE_TOTAL_BATEAU_MAX) {


                    //Repete la question tant qu'il rentre une valeur qui ne correspont pas au donnée
                    while(horizontal<1 || horizontal>10) {
                        printf("\n\n\nChoisissez une position horizontal : ");
                        scanf("%d", &horizontal);
                    }

                    while(vertical<1 || vertical>10) {
                        printf("\nChoisissez une position vertical : ");
                        scanf("%d", &vertical);

                    }
                    tireRestant--;
                    system("cls");


                    //appele de la fonction du tableau
                    affichageGrille(horizontal, vertical);

                    //Condition pour la réponse final si il gagne ou pas
                    if(compteurVictoir == NBR_PARTIE_TOTAL_BATEAU_MAX){
                        printf("\n\n\n\n\n\n\nvous aver gagner bien joué !!!\nVous avez gagné en %d coups\n\n\n\n\n", compteur);
                        break;
                    }
                    if (compteur == NBR_MAX_DE_COUP && tireRestant == 0) {
                        printf("\n\n\n\n\n\n\nVous avez perdu !\nVous n'avez pas réussi a coulé tous les bateaux\n\n\n\n\n");
                        reset();
                        break;
                    }
                    horizontal=0;
                    vertical=0;
                }
                break;

            case 2:
                printf("\nVoici les règles:\n\n\nUne fois appuié sur le boutton jouer choisissez les position ou vous vouler tirer et vous avez 50 tires au maximum\nLe but est de couler tout les bateaux ennemis.\nA savoir qu'il y a 5 sorte de bateau : un bateau avec 2 point de vie, un de 3 point de vie, un de 3 point de vie et un de 4 point de vie et un de 5 point de vie\n\n\n");
                reset();
                break;


            default:

                exit(0);

        }//fin du switch

    }//fin boucle while

}//fin boucle fonction menu



#endif //BATAILLE_NAVSAL_1_MENU_H
