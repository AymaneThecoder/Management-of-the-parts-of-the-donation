#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct donateur//Definition du structure
{
    int id_dnt;
    char* nom_dnt;
    char* prenom_dnt;
    char* adresse_dnt;
    struct donateur* suivant;
}dnt;

typedef struct profiteur {
	int cni ;
	 char nom[30] , prenom[30] , nationalite[30]  , cause[30] ;
	 struct profiteur  *suivant ;
}prf;

typedef struct donation{

	int num_donation;
    int somme;
    int num_donateur; // clé etrangère  du donateur 
    char paiment[30];
	struct donation *suivant;

}dona;

                                                  //Les focntions pour la manipulation du donateur

 int rechercher_dnt(dnt* tete, int id)//Fonction rechercher retourne "1" si Id exsite et "0" si n'exsite pas

{
    dnt* tmp = tete;

    while(tmp != NULL)
    {
        if(tmp->id_dnt == id) return 1;
        tmp =tmp->suivant;
    }
    return 0;
}
 dnt* ajouter_fichier_dnt(dnt* tete, int id, char nom[30], char prenom[30], char adresse[30], char* pos)//la fonction ajouter pour le chargement depuis un fichier\

{
    //Allocation du memoire pour la structure
    dnt* nouv_ele = (dnt*) malloc(sizeof(dnt));
    nouv_ele->nom_dnt = (char*) malloc(30 * sizeof(char));
     nouv_ele->prenom_dnt = (char*) malloc(30 * sizeof(char));
      nouv_ele->adresse_dnt = (char*) malloc(30 * sizeof(char));

    if(!rechercher_dnt(tete,id))

    {
     nouv_ele->id_dnt = id;
     strcpy(nouv_ele->nom_dnt,nom);
     strcpy(nouv_ele->adresse_dnt,adresse);
     strcpy(nouv_ele->prenom_dnt,prenom);
    if(strcmp(pos,"debut") != 0)//Tester si l'utilisateur a choisi ajout a la fin
    {

    nouv_ele->suivant = NULL;
    if(tete == NULL) return nouv_ele;

    else
    {
    dnt* tmp = tete;
    while(tmp->suivant != NULL)
    tmp = tmp->suivant;
    tmp->suivant = nouv_ele;
    return tete;
    }

    }

    else

    {
         if(tete == NULL)
       {
        nouv_ele->suivant = NULL;
         return nouv_ele;
       }

     else
    nouv_ele->suivant = tete;
    return nouv_ele;
      }

    }
   else
    {
     printf("\n\t'!Le id %d existe deja'\n", id);
      return tete;
   }

}




                                //Les fonctions du structure "Donateur"

dnt* ajouter_dnt(dnt* tete, char* pos)//Fonction ajouter (les deux cas Ajouter au debut, Ajouter a la fin))
{
    int id;
    char* nom, *prenom, *adresse;
    //Allocation du memoire pour la structure et ses fils
   dnt* nouv_ele = (dnt*) malloc(sizeof(dnt));
   nouv_ele->adresse_dnt = (char*) malloc(30 * sizeof(char));
   nouv_ele->nom_dnt = (char*) malloc(30 * sizeof(char));
   nouv_ele->prenom_dnt = (char*) malloc(30 * sizeof(char));
   char quitter[10];
   do
   {
    printf("\n\n\tEntrez id du donateur a ajouter: ");
    scanf("%d", &id);

           if(!rechercher_dnt(tete,id))

    {
    nouv_ele->id_dnt = id;
    printf("\n\t\t---------Remplissez les champs suivant---------\n");
    printf("\n\tNom, Prenom et Adresse du donateur: \n");
    printf("\n\t");
    scanf("%s%s%s", nouv_ele->nom_dnt, nouv_ele->prenom_dnt, nouv_ele->adresse_dnt);

    if(strcmp(pos,"debut") != 0)//Tester si l'utilisateur a choisi ajout a la fin
    {

    nouv_ele->suivant = NULL;
    if(tete == NULL)
    {
         printf("\n\t\t   /* Donateur avec id '%d' a bien ete ajoutee */", id);
        return nouv_ele;
    }
    else
    {
    dnt* tmp = tete;
    while(tmp->suivant != NULL)
    tmp = tmp->suivant;
    tmp->suivant = nouv_ele;
    printf("\n\t\t   /* Donateur avec id '%d' a bien ete ajoutee */", id);
    return tete;
    }

    }

    else

    {
         if(tete == NULL)
       {
        nouv_ele->suivant = NULL;
        printf("\n\t\t   /* Donateur avec id '%d' a bien ete ajoutee */", id);
       return nouv_ele;
       }

     else
    nouv_ele->suivant = tete;
     printf("\n\t\t    /* Donateur avec id '%d' a bien ete ajoutee */", id);
    return nouv_ele;
      }

    }

      printf("\n\t!Le id existe deja quitter operation (oui/non): ");
      scanf("%s", quitter);
    }while(strcmp(quitter,"non") == 0);
    return tete;
   }


dnt* ajouter_menu_dnt(dnt* tete)

{
    int choix, repeter;
    do
    {
        printf("\n\t\t1:Ajouter au 'Debut'\t     2:Ajouter a la 'Fin'\n");
        printf("\n\tJe choisi: ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1: tete = ajouter_dnt(tete,"debut");repeter = 0;break;
        case 2: tete = ajouter_dnt(tete,"fin");repeter = 0;break;
        default : printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
        }
    }while(repeter == 1);

    return tete;
}

void afficher_menu_dnt(dnt* tete)

{
    int choix, repeter;
    do
    {
        printf("\n\t\t1:Afficher 'Normal'\t     2:Afficher 'Unique'\n");
        printf("\n\tJe choisi: ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1: afficher_dnt(tete);repeter = 0;break;
        case 2:afficher_unique_dnt(tete);repeter = 0;break;
        default : printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
        }
    }while(repeter == 1);
}


void afficher_dnt(dnt* tete)//la fonction affichage

{
    int choix,  repeter = 0;
    dnt* tmp;
    tmp = tete;
  if(tete!= NULL)
  {
      do
      {
          printf("\n\tQuel champ veux tu afficher?\n");
          printf("\n\t\t\t1:Tous\t  3:Prenom\n");
          printf("\n\t\t\t2:Nom\t  4:Adresse\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)
          {
             case 1:
        {
            printf("\n\t\t-----------Les donateurs------------\n");
      printf("\n\t\tId | Nom   | Prenom  | Adresse\n");
    while(tmp != NULL)
    {
        printf("\n\t\t%d | %s | %s | %s\n", tmp->id_dnt, tmp->nom_dnt, tmp->prenom_dnt, tmp->adresse_dnt);
        tmp = tmp->suivant;
    }
     repeter = 0;
      break;
      }

      case 2:
        {
             printf("\n\t\t-----------Les Noms------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %s\n", tmp->nom_dnt);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      case 3:
        {
           printf("\n\t\t-----------Les Prenoms------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %s\n", tmp->prenom_dnt);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      case 4:
        {
            printf("\n\t\t-----------Les Adresses------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %s\n", tmp->adresse_dnt);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      default :printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;

          }

     }while(repeter == 1);

  }
    else
        printf("\n\t\t\t\t!Rien a afficher!");
}

void afficher_unique_dnt(dnt* tete)
{
    dnt* tmp, *tmp_verif;
    int choix, repeter = 0;
    tmp = tete;
    if(tete != NULL)
        do
    {
         printf("\n\tQuel champ veux tu afficher les uniques?\n");
          printf("\n\t\t\t1:Nom\t  3:Adresse\n");
          printf("\n\t\t\t2:Prenom\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)
          {
          case 1:
            {
                printf("\n\t\t-----------Les Noms uniques------------\n");
                printf("\n\t\t\t    %s\n", tmp->nom_dnt);
               tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(strcmp(tmp_verif->nom_dnt, tmp->nom_dnt) != 0)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %s\n", tmp->nom_dnt);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

                 case 2:
            {
                printf("\n\t\t-----------Les Prenoms uniques------------\n");
                printf("\n\t\t\t    %s\n", tmp->prenom_dnt);
                tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(strcmp(tmp_verif->prenom_dnt, tmp->prenom_dnt) != 0)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %s\n", tmp->prenom_dnt);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

                 case 3:
            {
                printf("\n\t\t-----------Les Adresses uniques------------\n");
                printf("\n\t\t\t    %s\n", tmp->adresse_dnt);
                tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(strcmp(tmp_verif->adresse_dnt, tmp->adresse_dnt) != 0)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %s\n", tmp->adresse_dnt);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

        default :printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
          }
    }while(repeter == 1);

    else
        printf("\n\t\t\t\t!Rien a afficher!");
}

dnt* charger_fichier_dnt(dnt* tete)//charger les informations depuis le fichier

{
    char nom[30], prenom[30], adress[30], pos[30];
    int id;
    FILE* f;
    char nom_f[30];
    printf("\n\tEntrez le nom du fichier avec extension ('.txt' favorable): \n");
    printf("\n\t");
    scanf("%s", nom_f);
    printf("\n\tLes enregistrements seront place au (debut/fin): \n");
    printf("\n\t");
    scanf("%s", pos);
    f = fopen(nom_f,"r");
     if(f == NULL)
     {
         printf("\n\t'!Erreur lors d\'ouverture du fichier'");
         return tete;
     }

  else

     {

              if(strcmp(pos,"fin") == 0)
              while(!feof(f))
              {
                  fscanf(f, "%d %s %s %s\n", &id, nom, prenom, adress);
                  tete = ajouter_fichier_dnt(tete,id,nom,prenom,adress,"fin");
              }
              else
                if(strcmp(pos,"debut") == 0)
                 while(!feof(f))
              {
                  fscanf(f, "%d %s %s %s\n", &id, nom, prenom, adress);
                   tete = ajouter_fichier_dnt(tete,id,nom,prenom,adress,"debut");
              }

             fclose(f);
             printf("\n\t\t\t  /* Chargement avec 'succes' */");
             return tete;
         }

}

void sauvegarder_dnt(dnt* tete)//sauvegrader les information dans un fichier

{
    FILE* f;
    char* nom_f;
    nom_f = (char*) malloc(30 * sizeof(char));
    printf("\n\tEntrez le nom du fichier avec extension ('.txt' favorable): \n");
    printf("\n\t");
    scanf("%s", nom_f);
    f = fopen(nom_f,"w");
    if(f == NULL)printf("\n\t'!Erreur lors du sauvegardation'");

        else

    {
    dnt* tmp = tete;
    while(tmp != NULL)
    {
        fprintf(f, "%d %s %s %s\n", tmp->id_dnt, tmp->nom_dnt, tmp->prenom_dnt, tmp->adresse_dnt);
        tmp = tmp->suivant;
    }
    fclose(f);
      printf("\n\t\t       /* Sauvegarde avec 'succes' */");
    }
}



void reche_aff_dnt(dnt* tete)//rechercher un donateur et afficher ses information si il existe

{
  int choix, id, repeter = 0;;
  char reponse[30], quitter[10];
  dnt* tmp;
    if(tete != NULL)
    do
      {
          printf("\n\tRechercher par?\n");
          printf("\n\t\t\t1:Id\t  3:Prenom\n");
          printf("\n\t\t\t2:Nom\t  4:Adresse\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)

          {
          case 1:
            {
                do
                {
                    int trouve = 0;
                    printf("\n\tEntrez id du donateur: ");
                    scanf("%d", &id);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(tmp->id_dnt == id)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Le donateur------------\n");
                        printf("\n\t\tId |  Nom  | Prenom  | Adresse\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s\n", tmp->id_dnt, tmp->nom_dnt, tmp->prenom_dnt, tmp->adresse_dnt);


                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Le id existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
                }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
            }
          case 2:
            {
                      do
                {
                    int trouve = 0;
                    printf("\n\tEntrez nom du donateur: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->nom_dnt,reponse) == 0)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Les donateurs------------\n");
                        printf("\n\t\tId |  Nom  | Prenom  | Adresse\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s\n", tmp->id_dnt, tmp->nom_dnt, tmp->prenom_dnt, tmp->adresse_dnt);


                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Le nom existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
        else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
            }
          case 3:
            {
                       do
                {
                    int trouve = 0;
                    printf("\n\tEntrez prenom du donateur: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->prenom_dnt,reponse) == 0)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Les donateurs------------\n");
                        printf("\n\t\tId |  Nom  | Prenom  | Adresse\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s\n", tmp->id_dnt, tmp->nom_dnt, tmp->prenom_dnt, tmp->adresse_dnt);


                }
                tmp = tmp->suivant;
        }

        if(!trouve)
        {
        printf("\n\t!Le prenom existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
         else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);

            repeter = 0;
            break;
          }

          case 4:
            {
                       do
                {
                    int trouve = 0;
                    printf("\n\tEntrez adresse du donateur: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->adresse_dnt,reponse) == 0)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Les donateurs------------\n");
                        printf("\n\t\tId |  Nom  | Prenom  | Adresse\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s\n", tmp->id_dnt, tmp->nom_dnt, tmp->prenom_dnt, tmp->adresse_dnt);


                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Adresse existe pas quitter operation(oui/non): ");
       scanf("%s", quitter);
        }

        else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
          }

          default: printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;

        }


    }while(repeter == 1);

    else
        printf("\n\t\t\t\t!Rien a rechercher!");

}

void modifier_dnt(dnt* tete)
{
     int id, nouv_id, repeter = 0, rentrer, choix;
     dnt* tmp = tete;
     char quitter[30], reponse[30], nom[30], prenom[30], adresse[30];
  do
  {
       printf("\n\tEntrez le id du donateur a modifier: ");
       scanf("%d", &id);
        if(rechercher_dnt(tete,id))
  {
      do
      {
           printf("\n\tQuel champ veux tu modifier?\n");
      printf("\n\t\t\t1:Tous\t    3:Nom\n");
      printf("\n\t\t\t2:Prenom     4:Adresse\n");
      printf("\n\tJe choisi: ");
          scanf("%d", &choix);

        switch(choix)
        {
        case 1:
            {
                    rentrer = 0;
                    printf("\n\tLe nouveau nom,prenom et adresse: \n");
                    printf("\n\t");
                    scanf("%s%s%s", nom, prenom, adresse);
                while(tmp != NULL)
                {
                    if(tmp->id_dnt == id)
                    {
                        strcpy(tmp->nom_dnt,nom);
                        strcpy(tmp->prenom_dnt,prenom);
                        strcpy(tmp->adresse_dnt,adresse);

                    }

                      tmp = tmp->suivant;
                }
                  repeter = 0;
                  break;
            }

        case 3:
            {
                printf("\n\tLe nouveau nom: ");
                scanf("%s", reponse);
                while(tmp != NULL)
                {
                    if(tmp->id_dnt == id)
                      strcpy(tmp->nom_dnt,reponse);
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
        case 2:
            {
                printf("\n\tLe nouveau prenom: ");
                scanf("%s", reponse);
                while(tmp != NULL)
                {
                    if(tmp->id_dnt == id)
                      strcpy(tmp->prenom_dnt,reponse);
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
            case 4:
            {
                printf("\n\tLa nouvelle adresse: ");
                scanf("%s", reponse);
                while(tmp != NULL)
                {
                    if(tmp->id_dnt == id)
                      strcpy(tmp->adresse_dnt,reponse);
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
             default :printf("\n\tEntrez un valide nombre!\n"); repeter = 1; break;

        }

      }while(repeter == 1);
      if(rentrer != 2)
     printf("\n\t\t   /* Donateur avec id '%d' a bien ete modifie */\n", id);
     else
         printf("\n\t\t   /* Donateur avec id '%d' pas modifie */\n", id);
     break;
  }
  printf("\n\t!Le id existe pas quitter operation (oui/non): ");
  scanf("%s", quitter);
  }while(strcmp(quitter,"oui") != 0);

}

dnt* supprimer_id_dnt(dnt* tete)//fonction qui supprime une occurence dans la chaine

{
    dnt *tmp_b, *tmp_ele, *tmp_a;
    tmp_ele = tete;
    tmp_b = tete;
    int id, repeter, choix;
   char quitter[10];
      do

      {

    printf("\n\tEntrez id du donateur a supprimer: ");
    scanf("%d", &id);
              if(rechercher_dnt(tete,id))
     {
         do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur avec id '%d'?\n", id);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);

                if(tmp_ele->id_dnt != id)//Isoler le cas ou element souhaitte supprimee est au premier position
    {
        tmp_ele = tmp_ele->suivant;
        while(tmp_ele->id_dnt != id)
    {
        tmp_b = tmp_ele;
        tmp_ele = tmp_ele->suivant;
    }

    tmp_a = tmp_ele->suivant;//le suivant du element avant element souhaite supprimee va pointer sur le suivant du element qui est apres
    free(tmp_ele);
    tmp_b->suivant = tmp_a;
     printf("\n\t\t   /* Donateur avec id '%d' a bien ete supprime */", id);
    return tete;
    }
    else
    {
            tmp_ele = tete->suivant;
           free(tete);
    printf("\n\t\t   /* Donateur avec id '%d' a bien ete supprimee */", id);
           return tmp_ele;
    }

     }

   else
       printf("\n\t!Le id existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
      }while(strcmp(quitter,"non") == 0);
     return tete;
}

dnt* supp_un_dnt(dnt* tete, char champ[30], char ele[30])//la focntion qui supprime un element d'apres son (Nom,Prenom,Adresse)

{
    dnt* tmp = tete, *tmp_ap, *tmp_av = tete;
   int choix, repeter;
    if(strcmp(champ,"nom") == 0)
    {
         do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur  avec le nom '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);

            if(strcmp(tete->nom_dnt,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->nom_dnt,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donateur avec nom '%s' a bien ete supprimee */", ele);
        return tete;
    }

    else
    {
        tmp_ap = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donateur avec nom '%s' a bien ete supprimee */", ele);
         return tmp_ap;
    }
    }

        if(strcmp(champ,"prenom") == 0)
    {
         do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur  avec prenom '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);
            if(strcmp(tete->prenom_dnt,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->prenom_dnt,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donateur avec prenom '%s' a bien ete supprimee */", ele);
        return tete;
    }

    else
    {
        tmp_ap = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donateur avec prenom '%s' a bien ete supprimee */", ele);
         return tmp_ap;
    }
    }

        if(strcmp(champ,"adresse") == 0)
    {
           do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur  avec adresse '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);
            if(strcmp(tete->adresse_dnt,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->adresse_dnt,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donateur avec adresse '%s' a bien ete supprimee */", ele);
        return tete;
    }

    else
    {
        tmp_ap = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donateur avec adresse '%s' a bien ete supprimee */", ele);
         return tmp_ap;
    }
    }


}

dnt* supp_N_dnt(dnt* tete, char champ[30], char ele[30])//La fonction qui supprime 'N' element en utilisant la fonction 'supp_un'

{
    dnt* tmp = tete;
    int trouve = 0;

    if(strcmp(champ,"nom") == 0)
    {
         while(tmp != NULL)
    {
        if(strcmp(tmp->nom_dnt,ele) == 0) //Connaiter le nombre d'occurence d'un element pour le supprimer
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
    {
        for(int i = 0; i < trouve; i++) //Appeler la focnbtion qui supprime un occurence 'N' fois
        tete = supp_un_dnt(tete,"nom",ele);
        return tete;
    }
    else
    {
        printf("\n\t\t\t    'Nom existe pas!'");
        return tete;
    }
    }

   else
    if(strcmp(champ,"prenom") == 0)
   {
        while(tmp != NULL)
    {
        if(strcmp(tmp->prenom_dnt,ele) == 0)
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
     {
       tete = supp_un_dnt(tete,"prenom",ele);
        return tete;
      }
    else
    {
         printf("\n\t\t\t    'Prenom existe pas!'");
        return tete;
    }
   }
      else
    if(strcmp(champ,"adresse")  == 0)
   {
        while(tmp != NULL)
    {
        if(strcmp(tmp->adresse_dnt,ele) == 0)
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
     {
       tete = supp_un_dnt(tete,"adresse",ele);
        return tete;
      }
    else
    {
         printf("\n\t\t\t    'Adresse existe pas!'");
        return tete;
    }
   }


}

dnt* supprimer_menu_dnt(dnt* tete)

{
    int choix, repeter;
    char ele[30];
    do
    {
    printf("\n\tSupprimer element par:\n");
    printf("\n\t\t\t1:Id\t  3:Prenom\n");
    printf("\n\t\t\t2:Nom\t  4:Adresse\n");
    printf("\n\tJe choisi: ");
          scanf("%d", &choix);
    switch(choix)
    {
        case 1:tete = supprimer_id_dnt(tete);repeter = 0;break;
        case 2:
            {
                             printf("\n\tNom: ");
                              scanf("%s", ele);
                             tete = supp_N_dnt(tete,"nom",ele);
                 repeter = 0;break;
            }
            case 3:
            {

                             printf("\n\tPrenom: ");
                              scanf("%s", ele);
                             tete = supp_N_dnt(tete,"prenom",ele);
                 repeter = 0;break;
            }
            case 4:
            {
                             printf("\n\tAdresse: ");
                              scanf("%s", ele);
                             tete = supp_N_dnt(tete,"adresse",ele);
                       repeter = 0;break;
            }

        default: printf("\n\tEntrez un valide nombre!\n");repeter = 1;break;
    }
    }while(repeter == 1);

    return tete;
}

void menu_donateur(dnt* tete_dnt,prf* tete_prf,dona* tete_dona,char nomUti[30])//menu du donateur
{

      int choix;
   do
   {
       printf("\n\n\t===============================================================\n");
       printf("\n\t\t\t      // Gestion donateur //\n");
       printf("\n\t===============================================================\n\n");
       printf("\n\n\t    Maison > Gestion Donateur\n\n");
       printf("\n\t\t\t\t\t\t\t   -0) Maison\n\n");
       printf("\n\t           Ajouter ->    (1)\t   Charger ->     (5) \n\n");
       printf("\n\t           Afficher ->   (2)\t   Supprimer ->   (6)\n\n");
       printf("\n\t           Rechercher -> (3)\t   Modifier ->    (7)\n\n");
       printf("\n\t           Operations -> (4)\t   Sauvegarder -> (8)\n");
       printf("\n\t\t\t        ---------------\n");
       printf("\n\t\t\t\t Je choisi: ");
       scanf("%d", &choix);
       switch(choix)
       {
           case 1:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Ajouter\n\n"); tete_dnt = ajouter_menu_dnt(tete_dnt);break;
           case 5:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Charger Depuis un Fichier\n\n"); tete_dnt = charger_fichier_dnt(tete_dnt); break;
           case 2:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Aficher\n\n"); afficher_menu_dnt(tete_dnt);break;
           case 6:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Supprimer\n\n");tete_dnt = supprimer_menu_dnt(tete_dnt);break;
           case 3:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Rechercher\n\n");reche_aff_dnt(tete_dnt);break;
           case 7:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Modifier\n\n");modifier_dnt(tete_dnt);break;
           case 4:system("cls"); menu_operation_dnt(tete_dnt,tete_prf,
                                                    nomUti);break;
           case 8:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Sauvegarder\n\n");sauvegarder_dnt(tete_dnt);break;
           case 0:system("cls"); menu_principale(tete_dnt,tete_prf,tete_dona,nomUti);break;
           default : printf("\n\t**Veuillez entrez un valide nombre de la liste\n");menu_donateur(tete_dnt,tete_prf,tete_dona,nomUti);break;
       }

    }while(choix != 0);
}

void menu_operation_dnt(dnt* tete_dnt,prf* tete_prf,dona* tete_dona,char nomUti[30])

{
      int choix;
   do
   {
       printf("\n\n\t===============================================================\n");
       printf("\n\t\t\t      // Operations //\n");
       printf("\n\t===============================================================\n\n");
       printf("\n\t\t\t\t\t\t\t   -0) Maison\n\n");
       printf("\n\t   -1) Compter nombre du occurence\n");
       printf("\n\t   -2) Compter totale\n");
       printf("\n\t   -3) Calculer 'Avg'\n");
       printf("\n\t   -4) Calculer 'Min'\n");
       printf("\n\t   -5) Calculer 'Max'\n");
       printf("\n\t   -6) Retourner\n");
       printf("\n\t\t   ---------------\n");
       printf("\n\t\t     Je choisi: ");
       scanf("%d", &choix);
       switch(choix)
       {
           case 1: system("cls"); printf("\n\n\tMaison > Gestion Donateur > Operations > Compter_Occurence\n\n"); compter_occ_dnt(tete_dnt);break;
           case 2: system("cls"); printf("\n\n\tMaison > Gestion Donateur > Operations > Compter_Totale\n\n"); compter_tot_dnt(tete_dnt); break;
           case 3: system("cls"); printf("\n\n\tMaison > Gestion Donateur > Operations > Calculer 'Avg'\n\n");cal_avg_dnt(tete_dnt);break;
           case 4: system("cls"); printf("\n\n\tMaison > Gestion Donateur > Operations > Calculer 'Min'\n\n");cal_min_dnt(tete_dnt);break;
           case 5: system("cls"); printf("\n\n\tMaison > Gestion Donateur > Operations > Calculer 'Max'\n\n");cal_max_dnt(tete_dnt);break;
           case 6: menu_donateur(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 0: menu_principale(tete_dnt,tete_prf,nomUti);break;
           default : printf("\n\t**Veuillez entrez un valide nombre de la liste\n");menu_donateur(tete_dnt,tete_prf,tete_dona,nomUti);break;
       }
   }while(choix != 0);
}

                                       //Les fonction pour les operations//

void compter_occ_dnt(dnt* tete)//L afonction qui calcule nombe ocuurence d'un champ

{

    char champ[30];
     int choix, repeter, id, nbr = 0;
      dnt* tmp = tete;

    do
    {
    printf("\n\tCalculer occurence d'un:\n");
    printf("\n\t\t\t1:Id\t3:Prenom\n");
    printf("\n\t\t\t2:Nom\t4:Adresse\n");
    printf("\n\tJe choisi: ");
          scanf("%d", &choix);
    switch(choix)
    {
    case 1:
        {
        printf("\n\tId: ");
        scanf("%d", &id);

        while(tmp != NULL)
        {
            if(tmp->id_dnt == id)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucun donateurs qui ont le id '%d' */", id);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a un donateur qui a le nom '%d' */", id);
        else
        printf("\n\t\t   /* Il y a %d donateurs qui ont le nom '%d' */", nbr, id);
        repeter = 0;
        break;
        }
    case 2:
        {
            printf("\n\tNom: ");
        scanf("%s", champ);

        while(tmp != NULL)
        {
            if(strcmp(tmp->nom_dnt,champ) == 0)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucun donateurs qui ont le nom '%s' */", champ);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a un donateur qui a le nom '%s' */", champ);
        else
        printf("\n\t\t   /* Il y a %d donateurs qui ont le nom '%s' */", nbr, champ);
        repeter = 0;
        break;
        }
    case 3:
        {
            printf("\n\tPrenom: ");
        scanf("%s", champ);
        while(tmp != NULL)
        {
            if(strcmp(tmp->prenom_dnt,champ) == 0)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucun donateurs qui ont le prenom '%s' */", champ);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a un donateur qui a le prenom '%s' */", champ);
            else
        printf("\n\t\t  /* Il y a %d donateurs qui ont le prenom '%s' */", nbr, champ);
        repeter = 0;
        break;
        }
    case 4:
        {
            printf("\n\tAdresse: ");
        scanf("%s", champ);
        while(tmp != NULL)
        {
            if(strcmp(tmp->adresse_dnt,champ) == 0)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucun donateurs qui resident a '%s' */", champ);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a un donateur qui reside a '%s' */", champ);
            else
        printf("\n\t\t   /* Il y a %d donateurs qui resident a  '%s' */", nbr, champ);
        repeter = 0;
        break;
        }
    default :printf("\n\tEntrez un valide nombre!\n"); repeter = 1; break;
    }
    }while(repeter == 1);

}

void compter_tot_dnt(dnt* tete)//La fonction qui calcule le nombre de donateurs

{
     dnt* tmp = tete;
     int nbr = 0;
     while(tmp != NULL)
     {
         nbr++;
         tmp = tmp->suivant;
     }

    printf("\n\t\t\t    /* Il y a %d donateurs */", nbr);

}

void cal_min_dnt(dnt* tete)//La fonction qui calcule le min d'un champ donne

{
   printf("\n\t'Ooops! Il semble que cette calcul est initile pour cette structure,\n");
    printf("\n\t  Veuillez essayer avec la table 'Donation'.'");
}

void cal_max_dnt(dnt* tete)//La fonction qui calcule le max d'un champ donne

{
    printf("\n\t'Ooops! Il semble que cette calcul est initile pour cette structure,\n");
    printf("\n\t  Veuillez essayer avec la table 'Donation'.'");
}

void cal_avg_dnt(dnt* tete) //la fonction qui calcule 'Avg' d'un champ des entiers

{
    printf("\n\t'Ooops! Il semble que cette calcul est initile pour cette structure,\n");
    printf("\n\t  Veuillez essayer avec une autre structure.'");
}



        //----------------------------------------------------------------------------------------------------------------------------\\



prf* ajouter_fichier_prf(prf* tete, int cni, char nom[30], char prenom[30], char nationalite[30], char cause[30], char* pos)//la fonction ajouter pour le chargement depuis un fichier\

{
    //Allocation du memoire pour la structure
    prf* nouv_ele = (prf*) malloc(sizeof(prf));
    if(!rechercher_prf(tete,cni))

    {
     nouv_ele->cni = cni;
     strcpy(nouv_ele->nom,nom);
     strcpy(nouv_ele->nationalite,nationalite);
     strcpy(nouv_ele->prenom,prenom);
     strcpy(nouv_ele->cause,cause);
    if(strcmp(pos,"debut") != 0)//Tester si l'utilisateur a choisi ajout a la fin
    {

    nouv_ele->suivant = NULL;
    if(tete == NULL) return nouv_ele;

    else
    {
    prf* tmp = tete;
    while(tmp->suivant != NULL)
    tmp = tmp->suivant;
    tmp->suivant = nouv_ele;
    return tete;
    }

    }

    else

    {
         if(tete == NULL)
       {
         nouv_ele->suivant = NULL;
         return nouv_ele;
       }

     else
    nouv_ele->suivant = tete;
    return nouv_ele;
      }

    }
   else
    {
     printf("\n\t'!Le cni %d existe deja'\n", cni);
      return tete;
   }

}

prf* ajouter_prf(prf* tete, char* pos)//Fonction ajouter (les deux cas Ajouter au debut, Ajouter a la fin))
{
    int cni;
    //Allocation du memoire pour la structure et ses fils
   prf* nouv_ele = (prf*) malloc(sizeof(prf));
   char quitter[10];
   do
   {
    printf("\n\n\tEntrez cni du profiteur a ajouter: ");
    scanf("%d", &cni);

           if(!rechercher_prf(tete,cni))

    {
    nouv_ele->cni = cni;
    printf("\n\t\t---------Remplissez les champs suivant---------\n");
    printf("\n\tNom, Prenom,Nationalite et cause du profiteur: \n");
    printf("\n\t");
    scanf("%s%s%s%s", nouv_ele->nom, nouv_ele->prenom, nouv_ele->nationalite, nouv_ele->cause);

    if(strcmp(pos,"debut") != 0)//Tester si l'utilisateur a choisi ajout a la fin
    {

    nouv_ele->suivant = NULL;
    if(tete == NULL)
    {
         printf("\n\t\t   /* Profiteur avec cni'%d' a bien ete ajoutee */", cni);
        return nouv_ele;
    }
    else
    {
    prf* tmp = tete;
    while(tmp->suivant != NULL)
    tmp = tmp->suivant;
    tmp->suivant = nouv_ele;
    printf("\n\t\t   /* Profiteur avec cni'%d' a bien ete ajoutee */", cni);
    return tete;
    }

    }

    else

    {
         if(tete == NULL)
       {
        nouv_ele->suivant = NULL;
        printf("\n\t\t   /* Profiteur avec cni'%d' a bien ete ajoutee */", cni);
       return nouv_ele;
       }

     else
    nouv_ele->suivant = tete;
     printf("\n\t\t   /* Profiteur avec cni'%d' a bien ete ajoutee */", cni);
    return nouv_ele;
      }

    }

      printf("\n\t!Le cni existe deja quitter operation (oui/non): ");
      scanf("%s", quitter);
    }while(strcmp(quitter,"non") == 0);
    return tete;
   }

prf* ajouter_menu_prf(prf* tete)

{
    int choix, repeter;
    do
    {
        printf("\n\t\t1:Ajouter au 'Debut'\t     2:Ajouter a la 'Fin'\n");
        printf("\n\tJe choisi: ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1: tete = ajouter_prf(tete,"debut");repeter = 0;break;
        case 2: tete = ajouter_prf(tete,"fin");repeter = 0;break;
        default : printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
        }
    }while(repeter == 1);

    return tete;
}

void afficher_menu_prf(prf* tete)

{
    int choix, repeter;
    do
    {
        printf("\n\t\t1:Afficher 'Normal'\t     2:Afficher 'Unique'\n");
        printf("\n\tJe choisi: ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1: afficher_prf(tete);repeter = 0;break;
        case 2:afficher_unique_prf(tete);repeter = 0;break;
        default : printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
        }
    }while(repeter == 1);
}

void afficher_prf(prf* tete)//la fonction affichage

{
    int choix,  repeter = 0;
    prf* tmp;
    tmp = tete;
  if(tete!= NULL)
  {
      do
      {
          printf("\n\tQuel champ veux tu afficher?\n");
          printf("\n\t\t\t1:Tous\t  3:Prenom\n");
          printf("\n\t\t\t2:Nom\t  4:Nationalite\n");
          printf("\n\t\t\t5:Cause\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)
          {
             case 1:
        {
            printf("\n\t\t-----------Les Profiteurs------------\n");
      printf("\n\t\tCni | Nom   | Prenom  | Nationalite | Cause\n");
    while(tmp != NULL)
    {
        printf("\n\t\t%d | %s | %s | %s | %s\n", tmp->cni, tmp->nom, tmp->prenom, tmp->nationalite, tmp->cause);
        tmp = tmp->suivant;
    }
     repeter = 0;
      break;
      }

      case 2:
        {
             printf("\n\t\t-----------Les Noms------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %s\n", tmp->nom);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      case 3:
        {
           printf("\n\t\t-----------Les Prenoms------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %s\n", tmp->prenom);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      case 4:
        {
            printf("\n\t\t-----------Les Nationalites------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %s\n", tmp->nationalite);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      default :printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;

          }

     }while(repeter == 1);

  }
    else
        printf("\n\t\t\t\t!Rien a afficher!");
}

void afficher_unique_prf(prf* tete)
{
    prf* tmp, *tmp_verif;
    int choix, repeter = 0;
    tmp = tete;
    if(tete != NULL)
        do
    {
         printf("\n\tQuel champ veux tu afficher les uniques?\n");
          printf("\n\t\t\t1:Nom\t  2:Prenom\n");
          printf("\n\t\t\t3:Nationalite\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)
          {
          case 1:
            {
                printf("\n\t\t-----------Les Noms uniques------------\n");
                printf("\n\t\t\t    %s\n", tmp->nom);
               tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(strcmp(tmp_verif->nom, tmp->nom) != 0)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %s\n", tmp->nom);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

                 case 2:
            {
                printf("\n\t\t-----------Les Prenoms uniques------------\n");
                printf("\n\t\t\t    %s\n", tmp->prenom);
                tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(strcmp(tmp_verif->prenom, tmp->prenom) != 0)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %s\n", tmp->prenom);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

                 case 3:
            {
                printf("\n\t\t-----------Les Nationalites uniques------------\n");
                printf("\n\t\t\t    %s\n", tmp->nationalite);
                tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(strcmp(tmp_verif->nationalite, tmp->nationalite) != 0)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %s\n", tmp->nationalite);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

        default :printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
          }
    }while(repeter == 1);

    else
        printf("\n\t\t\t\t!Rien a afficher!");
}

prf* charger_fichier_prf(prf* tete)//charger les informations depuis le fichier

{
    char nom[30], prenom[30], nationalite[30], cause[30], pos[30];
    int cni;
    FILE* f;
    char nom_f[30];
    printf("\n\tEntrez le nom du fichier avec extension ('.txt' favorable): \n");
    printf("\n\t");
    scanf("%s", nom_f);
    printf("\n\tLes enregistrements seront place au (debut/fin): \n");
    printf("\n\t");
    scanf("%s", pos);
    f = fopen(nom_f,"r");
     if(f == NULL)
     {
         printf("\n\t'!Erreur lors d\'ouverture du fichier'");
         return tete;
     }

  else

     {

              if(strcmp(pos,"fin") == 0)
              while(!feof(f))
              {
                  fscanf(f, "%d %s %s %s %s\n", &cni, nom, prenom, nationalite, cause);
                  tete = ajouter_fichier_prf(tete,cni,nom,prenom,nationalite,cause,"fin");
              }
              else
                if(strcmp(pos,"debut") == 0)
                 while(!feof(f))
              {
                  fscanf(f, "%d %s %s %s %s\n", &cni, nom, prenom, nationalite,cause);
                  tete = ajouter_fichier_prf(tete,cni,nom,prenom,nationalite,cause,"debut");
              }

             fclose(f);
             printf("\n\t\t\t  /* Chargement avec 'succes' */");
             return tete;
         }

}

void sauvegarder_prf(prf* tete)//sauvegrader les information dans un fichier

{
    FILE* f;
    char* nom_f;
    nom_f = (char*) malloc(30 * sizeof(char));
    printf("\n\tEntrez le nom du fichier avec extension ('.txt' favorable): \n");
    printf("\n\t");
    scanf("%s", nom_f);
    f = fopen(nom_f,"w");
    if(f == NULL)printf("\n\t'!Erreur lors du sauvegardation'");

        else

    {
    prf* tmp = tete;
    while(tmp != NULL)
    {
        fprintf(f, "%d %s %s %s %s\n", tmp->cni, tmp->nom, tmp->prenom, tmp->nationalite, tmp->cause);
        tmp = tmp->suivant;
    }
    fclose(f);
      printf("\n\t\t       /* Sauvegarde avec 'succes' */");
    }
}

void reche_aff_prf(prf* tete)//rechercher un donateur et afficher ses information si il existe

{
  int choix, cni, repeter = 0;;
  char reponse[30], quitter[10];
  prf* tmp;
    if(tete != NULL)
    do
      {
          printf("\n\tRechercher par?\n");
          printf("\n\t\t\t1:Cni\t  3:Prenom\n");
          printf("\n\t\t\t2:Nom\t  4:Nationalite\n");
          printf("\n\t\t\t5:Cause\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)

          {
          case 1:
            {
                do
                {
                    int trouve = 0;
                    printf("\n\tEntrez le cni: ");
                    scanf("%d", &cni);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(tmp->cni == cni)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Le profiteur------------\n");
                        printf("\n\t\tCni |  Nom  | Prenom  | Nationalite | Cause\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s | %s\n", tmp->cni, tmp->nom, tmp->prenom, tmp->nationalite, tmp->cause);


                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Le cni existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
                }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
            }
          case 2:
            {
                      do
                {
                    int trouve = 0;
                    printf("\n\tEntrez le nom: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->nom,reponse) == 0)
                {
                   if(!trouve)
                    {
                        printf("\n\t\t-----------Le profiteur------------\n");
                        printf("\n\t\tCni |  Nom  | Prenom  | Nationalite | Cause\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s | %s\n", tmp->cni, tmp->nom, tmp->prenom, tmp->nationalite, tmp->cause);


                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Le nom existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
        else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
            }
          case 3:
            {
                       do
                {
                    int trouve = 0;
                    printf("\n\tEntrez le prenom: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->prenom,reponse) == 0)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Le profiteur------------\n");
                        printf("\n\t\tCni |  Nom  | Prenom  | Nationalite | Cause\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s | %s\n", tmp->cni, tmp->nom, tmp->prenom, tmp->nationalite, tmp->cause);


                }
                tmp = tmp->suivant;
        }

        if(!trouve)
        {
        printf("\n\t!Le prenom existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
         else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);

            repeter = 0;
            break;
          }

          case 4:
            {
                       do
                {
                    int trouve = 0;
                    printf("\n\tEntrez la nationalite: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->nationalite,reponse) == 0)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Le profiteur------------\n");
                        printf("\n\t\tCni |  Nom  | Prenom  | Nationalite | Cause\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s | %s\n", tmp->cni, tmp->nom, tmp->prenom, tmp->nationalite, tmp->cause);

                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Nationalite existe pas quitter operation(oui/non): ");
       scanf("%s", quitter);
        }

        else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
          }


          case 5:
            {
                       do
                {
                    int trouve = 0;
                    printf("\n\tEntrez la cause: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->cause,reponse) == 0)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------Les profiteurs------------\n");
                        printf("\n\t\tCni |  Nom  | Prenom  | Nationalite | Cause\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %s | %s | %s | %s\n", tmp->cni, tmp->nom, tmp->prenom, tmp->nationalite, tmp->cause);

                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Cause existe pas quitter operation(oui/non): ");
       scanf("%s", quitter);
        }

        else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
          }

          default: printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;

        }


    }while(repeter == 1);

    else
        printf("\n\t\t\t\t!Rien a rechercher!");

}

void modifier_prf(prf* tete)
{
     int cni, nouv_cni, repeter = 0, rentrer, choix;
     prf* tmp = tete;
     char quitter[30], reponse[30], nom[30], prenom[30], nationalite[30], cause[30];
  do
  {
       printf("\n\tEntrez le cni du profiteur a modifier: ");
       scanf("%d", &cni);
        if(rechercher_prf(tete,cni))
  {
      do
      {
           printf("\n\tQuel champ veux tu modifier?\n");
      printf("\n\t\t\t1:Tous\t   3:Nom\n");
      printf("\n\t\t\t2:Prenom    4:Nationalite\n");
      printf("\n\t\t\t5:Cause\n");
      printf("\n\tJe choisi: ");
          scanf("%d", &choix);

        switch(choix)
        {
        case 1:
            {
                    rentrer = 0;
                    printf("\n\tLes nouveau Nom,Prenom,Nationalite et Cause: \n");
                    printf("\n\t");
                    scanf("%s%s%s%s", nom, prenom, nationalite, cause);
                while(tmp != NULL)
                {
                    if(tmp->cni == cni)
                    {
                        strcpy(tmp->nom,nom);
                        strcpy(tmp->prenom,prenom);
                        strcpy(tmp->nationalite,nationalite);
                       strcpy(tmp->cause,cause);
                    }

                      tmp = tmp->suivant;
                }
                repeter = 0;
                  break;
            }

        case 2:
            {
                printf("\n\tLe nouveau prenom: ");
                scanf("%s", reponse);
                while(tmp != NULL)
                {
                    if(tmp->cni == cni)
                      strcpy(tmp->nom,reponse);
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
        case 3:
            {
                printf("\n\tLe nouveau nom: ");
                scanf("%s", reponse);
                while(tmp != NULL)
                {
                    if(tmp->cni == cni)
                      strcpy(tmp->nom,reponse);
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
            case 4:
            {
                printf("\n\tLa nouvelle nationalite: ");
                scanf("%s", reponse);
                while(tmp != NULL)
                {
                    if(tmp->cni == cni)
                      strcpy(tmp->nationalite,reponse);
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
             case 5:
            {
                printf("\n\tLa nouvelle cause: ");
                scanf("%s", reponse);
                while(tmp != NULL)
                {
                    if(tmp->cni == cni)
                      strcpy(tmp->cause,reponse);
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
             default :printf("\n\tEntrez un valide nombre!\n"); repeter = 1; break;

        }

      }while(repeter == 1);
      if(rentrer != 2)
     printf("\n\t\t   /* Donateur avec cni '%d' a bien ete modifie */\n", cni);
     else
         printf("\n\t\t   /* Donateur avec cni '%d' pas modifie */\n", cni);
     break;
  }
  printf("\n\t!Le id existe pas quitter operation (oui/non): ");
  scanf("%s", quitter);
  }while(strcmp(quitter,"oui") != 0);

}

prf* supprimer_cni_prf(prf* tete)//fonction qui supprime une occurence dans la chaine

{
    prf *tmp_av, *tmp_ele, *tmp_ap;
    tmp_ele = tete;
    tmp_av = tete;
    int cni, repeter, choix;
   char quitter[10];
      do

      {

    printf("\n\tEntrez cni du profiteur a supprimer: ");
    scanf("%d", &cni);
              if(rechercher_prf(tete,cni))
     {
         do
       {
           printf("\n\tVoulez vous vraiment supprimer le profiteur avec cni '%d'?\n", cni);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);

                if(tmp_ele->cni != cni)//Isoler le cas ou element souhaitte supprimee est au premier position
    {
        tmp_ele = tmp_ele->suivant;
        while(tmp_ele->cni != cni)
    {
        tmp_av = tmp_ele;
        tmp_ele = tmp_ele->suivant;
    }

    tmp_ap = tmp_ele->suivant;//le suivant du element avant element souhaite supprimee va pointer sur le suivant du element qui est apres
    free(tmp_ele);
    tmp_av->suivant = tmp_ap;
     printf("\n\t\t   /* Donateur avec cni '%d' a bien ete supprime */", cni);
    return tete;
    }
    else
    {
            tmp_ele = tete->suivant;
           free(tete);
    printf("\n\t\t   /* Donateur avec cni '%d' a bien ete supprimee */", cni);
           return tmp_ele;
    }

     }

   else
       printf("\n\t!Le cni existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
      }while(strcmp(quitter,"non") == 0);
     return tete;
}

prf* supp_un_prf(prf* tete, char champ[30], char ele[30])//la focntion qui supprime un element d'apres son (Nom,Prenom,Adresse)

{
    prf* tmp = tete, *tmp_ap, *tmp_av = tete;
   int choix, repeter;
    if(strcmp(champ,"nom") == 0)
    {
         do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur  avec le nom '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);

            if(strcmp(tete->nom,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->nom,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donateur avec nom '%s' a bien ete supprimee */", ele);
        return tete;
    }

    else
    {
        tmp_av = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donateur avec nom '%s' a bien ete supprimee */", ele);
         return tmp_av;
    }
    }

        if(strcmp(champ,"prenom") == 0)
    {
         do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur  avec prenom '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);
            if(strcmp(tete->prenom,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->prenom,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donateur avec prenom '%s' a bien ete supprimee */", ele);
        return tete;
    }

    else
    {
        tmp_av = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donateur avec prenom '%s' a bien ete supprimee */", ele);
         return tmp_av;
    }
    }

        if(strcmp(champ,"nationalite") == 0)
    {
           do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur  avec nationalite '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);
            if(strcmp(tete->nationalite,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->nationalite,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donateur avec adresse '%s' a bien ete supprimee */", ele);
        return tete;
    }

    else
    {
        tmp_ap = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donateur avec adresse '%s' a bien ete supprimee */", ele);
         return tmp_ap;
    }
    }

            if(strcmp(champ,"cause") == 0)
    {
           do
       {
           printf("\n\tVoulez vous vraiment supprimer le donateur qui a la cause '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);
            if(strcmp(tete->cause,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->cause,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donateur qui a cause '%s' a bien ete supprimee */", ele);
        return tete;
    }

    else
    {
        tmp_ap = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donateur avec adresse '%s' a bien ete supprimee */", ele);
         return tmp_ap;
    }
    }


}

prf* supp_N_prf(prf* tete, char champ[30], char ele[30])//La fonction qui supprime 'N' element en utilisant la fonction 'supp_un'

{
    prf* tmp = tete;
    int trouve = 0;

    if(strcmp(champ,"nom") == 0)
    {
         while(tmp != NULL)
    {
        if(strcmp(tmp->nom,ele) == 0) //Connaiter le nombre d'occurence d'un element pour le supprimer
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
    {
        for(int i = 0; i < trouve; i++) //Appeler la focnbtion qui supprime un occurence 'N' fois
        tete = supp_un_dnt(tete,"nom",ele);
        return tete;
    }
    else
    {
        printf("\n\t\t\t    'Nom existe pas!'");
        return tete;
    }
    }

   else
    if(strcmp(champ,"prenom") == 0)
   {
        while(tmp != NULL)
    {
        if(strcmp(tmp->prenom,ele) == 0)
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
     {
       tete = supp_un_dnt(tete,"prenom",ele);
        return tete;
      }
    else
    {
         printf("\n\t\t\t    'Prenom existe pas!'");
        return tete;
    }
   }
      else
    if(strcmp(champ,"nationalite")  == 0)
   {
        while(tmp != NULL)
    {
        if(strcmp(tmp->nationalite,ele) == 0)
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
     {
       tete = supp_un_dnt(tete,"nationalite",ele);
        return tete;
      }
    else
    {
         printf("\n\t\t\t    'nationalite existe pas!'");
        return tete;
    }
   }
         else
    if(strcmp(champ,"cause")  == 0)
   {
        while(tmp != NULL)
    {
        if(strcmp(tmp->cause,ele) == 0)
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
     {
       tete = supp_un_dnt(tete,"cause",ele);
        return tete;
      }
    else
    {
         printf("\n\t\t\t    'cause existe pas!'");
        return tete;
    }
   }


}

prf* supprimer_menu_prf(prf* tete)

{
    int choix, repeter;
    char ele[30];
    do
    {
    printf("\n\tSupprimer element par:\n");
    printf("\n\t\t\t1:Cni\t  3:Prenom\n");
    printf("\n\t\t\t2:Nom\t  4:Nationalite\n");
    printf("\n\t\t\t5:Cause\n");
    printf("\n\tJe choisi: ");
          scanf("%d", &choix);
    switch(choix)
    {
        case 1:tete = supprimer_cni_prf(tete);repeter = 0;break;
        case 2:
            {
                printf("\n\tNom: ");
                scanf("%s", ele);
                tete = supp_N_prf(tete,"nom",ele);
                repeter = 0;
                break;
            }
            case 3:
            {
                 printf("\n\tPrenom: ");
                scanf("%s", ele);
                tete = supp_N_prf(tete,"prenom",ele);
                 repeter = 0;
                break;
            }
            case 4:
            {
                 printf("\n\tNationalite: ");
                scanf("%s", ele);
                tete = supp_N_prf(tete,"nationalite",ele);
                 repeter = 0;
                break;
            }
   case 5:
            {
                 printf("\n\tCause: ");
                scanf("%s", ele);
                tete = supp_N_prf(tete,"cause",ele);
                 repeter = 0;
                break;
            }
        default: printf("\n\tEntrez un valide nombre!\n");repeter = 1;break;
    }
    }while(repeter == 1);

    return tete;
}

void menu_profiteur(dnt* tete_dnt,prf* tete_prf,dona* tete_dona,char nomUti[30])//menu du donateur
{

      int choix;
   do
   {
       printf("\n\n\t===============================================================\n");
       printf("\n\t\t\t      // Gestion profiteur //\n");
       printf("\n\t===============================================================\n\n");
       printf("\n\n\t    Maison > Gestion Profiteur\n\n");
       printf("\n\t\t\t\t\t\t\t   -0) Maison\n\n");
       printf("\n\t           Ajouter ->    (1)\t   Charger ->     (5) \n\n");
       printf("\n\t           Afficher ->   (2)\t   Supprimer ->   (6)\n\n");
       printf("\n\t           Rechercher -> (3)\t   Modifier ->    (7)\n\n");
       printf("\n\t           Operations -> (4)\t   Sauvegarder -> (8)\n");
       printf("\n\t\t\t        ---------------\n");
       printf("\n\t\t\t\t Je choisi: ");
       scanf("%d", &choix);
       switch(choix)
       {
           case 1:system("cls"); printf("\n\n\t    Maison > Gestion Profiteur > Ajouter\n\n"); tete_prf = ajouter_menu_prf(tete_prf);break;
           case 5:system("cls"); printf("\n\n\t    Maison > Gestion Profiteur > Charger Depuis un Fichier\n\n"); tete_prf = charger_fichier_prf(tete_prf); break;
           case 2:system("cls"); printf("\n\n\t    Maison > Gestion Profiteur > Aficher\n\n"); afficher_menu_prf(tete_prf);break;
           case 6:system("cls"); printf("\n\n\t    Maison > Gestion Profiteur > Supprimer\n\n");tete_prf = supprimer_menu_prf(tete_prf);break;
           case 3:system("cls"); printf("\n\n\t    Maison > Gestion Profiteur > Rechercher\n\n");reche_aff_prf(tete_prf);break;
           case 7:system("cls"); printf("\n\n\t    Maison > Gestion Profiteur > Modifier\n\n");modifier_prf(tete_prf);break;
           case 4:system("cls"); menu_operation_prf(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 8:system("cls"); printf("\n\n\t    Maison > Gestion Donateur > Sauvegarder\n\n");sauvegarder_prf(tete_prf);break;
           case 0:system("cls"); menu_principale(tete_dnt,tete_prf,tete_dona,nomUti);break;
           default : printf("\n\t**Veuillez entrez un valide nombre de la liste\n");menu_profiteur(tete_dnt,tete_prf,tete_dona,nomUti);break;
       }

    }while(choix != 0);
}

int rechercher_prf(prf* tete, int cni)//Fonction rechercher retourne "1" si Id exsite et "0" si n'exsite pas

{
    prf* tmp = tete;
    while(tmp != NULL)
    {
        if(tmp->cni == cni) return 1;
        tmp =tmp->suivant;
    }
    return 0;
}

void menu_operation_prf(dnt* tete_dnt,prf* tete_prf,dona* tete_dona,char nomUti[30])

{
      int choix;
   do
   {
       printf("\n\n\t===============================================================\n");
       printf("\n\t\t\t      // Operations //\n");
       printf("\n\t===============================================================\n\n");
       printf("\n\t\t\t\t\t\t\t   -0) Maison\n\n");
       printf("\n\t   -1) Compter nombre du occurence\n");
       printf("\n\t   -2) Compter totale\n");
       printf("\n\t   -3) Calculer 'Avg'\n");
       printf("\n\t   -4) Calculer 'Min'\n");
       printf("\n\t   -5) Calculer 'Max'\n");
       printf("\n\t   -6) Retourner\n");
       printf("\n\t\t   ---------------\n");
       printf("\n\t\t     Je choisi: ");
       scanf("%d", &choix);
       switch(choix)
       {
           case 1: system("cls"); printf("\n\n\tMaison > Gestion Profiteur > Operations > Compter_Occurence\n\n"); compter_occ_prf(tete_prf);break;
           case 2: system("cls"); printf("\n\n\tMaison > Gestion Profiteur > Operations > Compter_Totale\n\n"); compter_tot_prf(tete_prf); break;
           case 3: system("cls"); printf("\n\n\tMaison > Gestion Profiteur > Operations > Calculer 'Avg'\n\n");cal_avg_prf(tete_prf);break;
           case 4: system("cls"); printf("\n\n\tMaison > Gestion Profiteur > Operations > Calculer 'Min'\n\n");cal_min_prf(tete_prf);break;
           case 5: system("cls"); printf("\n\n\tMaison > Gestion Profiteur > Operations > Calculer 'Max'\n\n");cal_max_prf(tete_prf);break;
           case 6: menu_profiteur(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 0: menu_principale(tete_dnt,tete_prf,nomUti);break;
           default : printf("\n\t**Veuillez entrez un valide nombre de la liste\n");menu_operation_prf(tete_dnt,tete_prf,tete_dona,nomUti);break;
       }
   }while(choix != 0);
}

                                       //Les fonction pour les operations//

void compter_occ_prf(prf* tete)//L afonction qui calcule nombe ocuurence d'un champ

{

    char champ[30];
     int choix, repeter, id, nbr = 0;
      prf* tmp = tete;

    do
    {
    printf("\n\tCalculer occurence d'un:\n");
    printf("\n\t\t\t1:Nom\t3:Nationalite\n");
    printf("\n\t\t\t2:Prenom\n");
    printf("\n\tJe choisi: ");
          scanf("%d", &choix);
    switch(choix)
    {
    case 1:
        {
            printf("\n\tNom: ");
        scanf("%s", champ);

        while(tmp != NULL)
        {
            if(strcmp(tmp->nom,champ) == 0)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucun profiteur qui ont le nom '%s' */", champ);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a un profiteur qui a le nom '%s' */", champ);
        else
        printf("\n\t\t   /* Il y a %d profiteurs qui ont le nom '%s' */", nbr, champ);
        repeter = 0;
        break;
        }
    case 2:
        {
            printf("\n\tPrenom: ");
        scanf("%s", champ);
        while(tmp != NULL)
        {
            if(strcmp(tmp->prenom,champ) == 0)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucun profiteurs qui ont le prenom '%s' */", champ);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a un profiteur qui a le prenom '%s' */", champ);
            else
        printf("\n\t\t  /* Il y a %d profiteurs qui ont le prenom '%s' */", nbr, champ);
        repeter = 0;
        break;
        }
    case 3:
        {
            printf("\n\tNationalite: ");
        scanf("%s", champ);
        while(tmp != NULL)
        {
            if(strcmp(tmp->nationalite,champ) == 0)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucun profiteurs qui resident a '%s' */", champ);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a un profiteur qui reside a '%s' */", champ);
            else
        printf("\n\t\t   /* Il y a %d profiteurs qui resident a  '%s' */", nbr, champ);
        repeter = 0;
        break;
        }
    default :printf("\n\tEntrez un valide nombre!\n"); repeter = 1; break;
    }
    }while(repeter == 1);

}

void compter_tot_prf(prf* tete)//La fonction qui calcule le nombre de donateurs

{
     prf* tmp = tete;
     int nbr = 0;
     while(tmp != NULL)
     {
         nbr++;
         tmp = tmp->suivant;
     }

    printf("\n\t\t\t    /* Il y a %d profiteurs */", nbr);

}



void cal_min_prf(prf* tete)//La fonction qui calcule le min d'un champ donne

{
    printf("\n\t'Ooops! Il semble que cette calcul est initile pour cette structure,\n");
    printf("\n\t  Veuillez essayer avec la table 'Donation'.'");
}

void cal_max_prf(prf* tete)//La fonction qui calcule le max d'un champ donne

{
    printf("\n\t'Ooops! Il semble que cette calcul est initile pour cette structure,\n");
    printf("\n\t  Veuillez essayer avec la table 'Donation'.'");
}

void cal_avg_prf(prf* tete) //la fonction qui calcule 'Avg' d'un champ des entiers

{
    printf("\n\t'Ooops! Il semble que cette calcul est initile pour cette structure,\n");
    printf("\n\t  Veuillez essayer avec la table 'Donation'.'");
}


               //----------------------------------------------------------------------------------------------------------------------------------------\\



 int rechercher_dona(dona *tete,int num_donation)// fonction rechercher si une valueur de num_donation est repeter
 {

 	dona *temp=tete;// on inisialize le temp a la tet de liste
 	while(temp!=NULL)
        {

 		if(temp->num_donation==num_donation){
 		return 1;

		}
       temp=temp->suivant;//on cremment temp;
     }
  return 0;
}

dona* ajouter_fichier_dona(dona* tete_dona,dnt* tete_dnt,int num_dona, int num_donateur, char paiment[30], int somme, char* pos)//la fonction ajouter pour le chargement depuis un fichier\

{
    //Allocation du memoire pour la structure
    dona* nouv_ele = (dona*) malloc(sizeof(dona));
    if(!rechercher_dona(tete_dona,num_dona) && rechercher_dnt(tete_dnt,num_donateur))

    {
     nouv_ele->num_donation = num_dona;
     nouv_ele->num_donateur = num_donateur;
     nouv_ele->somme = somme;
     strcpy(nouv_ele->paiment,paiment);
    if(strcmp(pos,"debut") != 0)//Tester si l'utilisateur a choisi ajout a la fin
    {

    nouv_ele->suivant = NULL;
    if(tete_dona == NULL) return nouv_ele;

    else
    {
    dona* tmp = tete_dona;
    while(tmp->suivant != NULL)
    tmp = tmp->suivant;
    tmp->suivant = nouv_ele;
    return tete_dona;
    }

    }

    else

    {
         if(tete_dona == NULL)
       {
         nouv_ele->suivant = NULL;
         return nouv_ele;
       }

     else
    nouv_ele->suivant = tete_dona;
    return nouv_ele;
      }

    }
   else
    {
     printf("\n\t'!Numero du donation deja existe Ou sa donateur existe pas'\n");
      return tete_dona;
   }

}

dona* ajouter_dona(dona* tete_dona,dnt* tete_dnt,char* pos)//Fonction ajouter (les deux cas Ajouter au debut, Ajouter a la fin))
{
    int num_dona,num_dnt;
    //Allocation du memoire pour la structure et ses fils
   dona* nouv_ele = (dona*) malloc(sizeof(dona));
   char quitter[10];
   do
   {
    printf("\n\n\tEntrez numero du donation et celui du donateur: \n");
    printf("\n\t");
    scanf("%d%d", &num_dona, &num_dnt);

           if(!rechercher_dona(tete_dona,num_dona) && rechercher_dnt(tete_dnt,num_dnt))

    {
    nouv_ele->num_donation = num_dona;
    nouv_ele->num_donateur = num_dnt;
    printf("\n\t\t---------Remplissez les champs suivant---------\n");
    printf("\n\tPaiment e la somme du donation: \n");
    printf("\n\t");
    scanf("%s%d",nouv_ele->paiment, &nouv_ele->somme);

    if(strcmp(pos,"debut") != 0)//Tester si l'utilisateur a choisi ajout a la fin
    {

    nouv_ele->suivant = NULL;
    if(tete_dona == NULL)
    {
         printf("\n\t\t   /* Donation avec numero '%d' a bien ete ajoutee */", num_dona);
        return nouv_ele;
    }
    else
    {
    dona* tmp = tete_dona;
    while(tmp->suivant != NULL)
    tmp = tmp->suivant;
    tmp->suivant = nouv_ele;
    printf("\n\t\t   /* Donation avec numero '%d' a bien ete ajoutee */", num_dona);
    return tete_dona;
    }

    }

    else

    {
         if(tete_dona == NULL)
       {
        nouv_ele->suivant = NULL;
        printf("\n\t\t   /* Donation avec numero '%d' a bien ete ajoutee */", num_dona);
       return nouv_ele;
       }

     else
    nouv_ele->suivant = tete_dona;
     printf("\n\t\t   /* Donation avec numero '%d' a bien ete ajoutee */", num_dona);
    return nouv_ele;
      }

    }

       printf("\n\t'!Numero du donation deja existe Ou sa donateur existe pas'\n\n\
        quitter(oui/non):");
      scanf("%s", quitter);
    }while(strcmp(quitter,"non") == 0);
    return tete_dona;
   }

dona* charger_fichier_dona(dona* tete_dona, dnt* tete_dnt)//charger les informations depuis le fichier

{
    char paiment[30],pos[30];
    int num_dona,num_dnt,somme;
    FILE* f;
    char nom_f[30];
    printf("\n\tEntrez le nom du fichier avec extension ('.txt' favorable): \n");
    printf("\n\t");
    scanf("%s", nom_f);
    printf("\n\tLes enregistrements seront place au (debut/fin): \n");
    printf("\n\t");
    scanf("%s", pos);
    f = fopen(nom_f,"r");
     if(f == NULL)
     {
         printf("\n\t'!Erreur lors d\'ouverture du fichier'");
         return tete_dona;
     }

  else

     {

              if(strcmp(pos,"fin") == 0)
              while(!feof(f))
              {
                  fscanf(f, "%d %d %s %d\n", &num_dona, &num_dnt, paiment, &somme);
                  tete_dona = ajouter_fichier_dona(tete_dona,tete_dnt,num_dona,num_dnt,paiment,somme,"fin");
              }
              else
                if(strcmp(pos,"debut") == 0)
                 while(!feof(f))
              {
                  fscanf(f, "%d %d %s %d\n", &num_dona, &num_dnt, paiment, &somme);
                  tete_dona = ajouter_fichier_dona(tete_dona,tete_dnt,num_dona,num_dnt,paiment,somme,"debut");
              }

             fclose(f);
             printf("\n\t\t\t  /* Chargement avec 'succes' */");
             return tete_dona;
         }

}

dona* ajouter_menu_dona(dona* tete_dona,dnt* tete_dnt)

{
    int choix, repeter;
    do
    {
        printf("\n\t\t1:Ajouter au 'Debut'\t     2:Ajouter a la 'Fin'\n");
        printf("\n\tJe choisi: ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1: tete_dona = ajouter_dona(tete_dona,tete_dnt,"debut");repeter = 0;break;
        case 2: tete_dona = ajouter_dona(tete_dona,tete_dnt,"fin");repeter = 0;break;
        default : printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
        }
    }while(repeter == 1);

    return tete_dona;
}

void afficher_menu_dona(dona* tete)

{
    int choix, repeter;
    do
    {
        printf("\n\t\t1:Afficher 'Normal'\t     2:Afficher 'Unique'\n");
        printf("\n\tJe choisi: ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1: afficher_dona(tete);repeter = 0;break;
        case 2:afficher_unique_dona(tete);repeter = 0;break;
        default : printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
        }
    }while(repeter == 1);
}

void afficher_dona(dona* tete)//la fonction affichage

{
    int choix,  repeter = 0;
    dona* tmp;
    tmp = tete;
  if(tete!= NULL)
  {
      do
      {
          printf("\n\tQuel champ veux tu afficher?\n");
          printf("\n\t\t\t1:Tous\t  3:Somme\n");
          printf("\n\t\t\t2:Paiment\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)
          {
             case 1:
        {
            printf("\n\t\t-----------Les Donations------------\n");
      printf("\n\t\tNum donation | Num donateur   | Paiment  | Somme\n");
    while(tmp != NULL)
    {
        printf("\n\t\t%d | %d | %s | %d\n", tmp->num_donation, tmp->num_donateur, tmp->paiment, tmp->somme);
        tmp = tmp->suivant;
    }
     repeter = 0;
      break;
      }

      case 2:
        {
             printf("\n\t\t-----------Les Paiments------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %s\n", tmp->paiment);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      case 3:
        {
           printf("\n\t\t-----------Les Sommes------------\n");
            while(tmp != NULL)
        {
          printf("\n\t\t\t    %d\n", tmp->somme);
          tmp = tmp->suivant;
         }
        repeter = 0;
         break;
        }

      default :printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;

          }

     }while(repeter == 1);

  }
    else
        printf("\n\t\t\t\t!Rien a afficher!");
}

void afficher_unique_dona(dona* tete)
{
    dona* tmp, *tmp_verif;
    int choix, repeter = 0;
    tmp = tete;
    if(tete != NULL)
        do
    {
         printf("\n\tQuel champ veux tu afficher les uniques?\n");
          printf("\n\t\t\t1:Paiment\t  2:Somme\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)
          {
          case 1:
            {
                printf("\n\t\t-----------Les Paiments uniques------------\n");
                printf("\n\t\t\t    %s\n", tmp->paiment);
               tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(strcmp(tmp_verif->paiment, tmp->paiment) != 0)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %s\n", tmp->paiment);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

                 case 2:
            {
                printf("\n\t\t-----------Les Sommes uniques------------\n");
                printf("\n\t\t\t    %d\n", tmp->somme);
                tmp = tete->suivant;
                while(tmp != NULL)
    {
        int trouve = 0;
        tmp_verif = tete;
         while(tmp_verif != tmp)
         {
             if(tmp_verif->somme != tmp->somme)
              tmp_verif = tmp_verif->suivant;
            else
            {
                trouve++;
                break;
            }

         }
           if(!trouve)
           printf("\n\t\t\t    %d\n", tmp->somme);
          tmp = tmp->suivant;
    }
        repeter = 0;
        break;

            }

        default :printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;
          }
    }while(repeter == 1);

    else
        printf("\n\t\t\t\t!Rien a afficher!");
}

void sauvegarder_dona(dona* tete)//sauvegrader les information dans un fichier

{
    FILE* f;
    char* nom_f;
    nom_f = (char*) malloc(30 * sizeof(char));
    printf("\n\tEntrez le nom du fichier avec extension ('.txt' favorable): \n");
    printf("\n\t");
    scanf("%s", nom_f);
    f = fopen(nom_f,"w");
    if(f == NULL)printf("\n\t'!Erreur lors du sauvegardation'");

        else

    {
    dona* tmp = tete;
    while(tmp != NULL)
    {
        fprintf(f, "%d %d %s %d\n", tmp->num_donation, tmp->num_donateur, tmp->paiment, tmp->somme);
        tmp = tmp->suivant;
    }
    fclose(f);
      printf("\n\t\t       /* Sauvegarde avec 'succes' */");
    }
}

void reche_aff_dona(dona* tete)//rechercher un donateur et afficher ses information si il existe

{
  int choix, num_dona,num_dnt,somme,repeter = 0;;
  char reponse[30], quitter[10];
  dona* tmp;
    if(tete != NULL)
    do
      {
          printf("\n\tRechercher par?\n");
          printf("\n\t\t\t1:Num donation\t  3:Paiment\n");
          printf("\n\t\t\t2:Num donateur\t  4:Somme\n");
          printf("\n\tJe choisi: ");
          scanf("%d", &choix);
          switch(choix)

          {
          case 1:
            {
                do
                {
                    int trouve = 0;
                    printf("\n\tEntrez num donation: ");
                    scanf("%d", &num_dona);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(tmp->num_donation == num_dona)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------La donation------------\n");
                        printf("\n\t\tNum donation |  Num donateur  | Paiment  | Somme\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %d | %s | %d\n", tmp->num_donation, tmp->num_donateur, tmp->paiment, tmp->somme);

                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!La num donation existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
        else
            strcpy(quitter,"oui");
        }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
            }
          case 2:
            {
                      do
                {
                    int trouve = 0;
                    printf("\n\tEntrez le num donateur: ");
                    scanf("%d", &num_dnt);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(tmp->num_donateur == num_dnt)
                {
                   if(!trouve)
                    {
                        printf("\n\t\t-----------La donation------------\n");
                        printf("\n\t\tNum donation |  Num donateur  | Paiment  | Somme\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %d | %s | %d\n", tmp->num_donation, tmp->num_donateur, tmp->paiment, tmp->somme);


                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Le num donateur existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
        else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
            }
          case 3:
            {
                       do
                {
                    int trouve = 0;
                    printf("\n\tEntrez le paiment: ");
                    scanf("%s", reponse);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(strcmp(tmp->paiment,reponse) == 0)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------La donation------------\n");
                        printf("\n\t\tCni |  Nom  | Prenom  | Nationalite | Cause\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %d | %s | %d \n", tmp->num_donation,tmp->num_donateur, tmp->paiment,tmp->somme);


                }
                tmp = tmp->suivant;
        }

        if(!trouve)
        {
        printf("\n\t!Le paiment existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
        }
         else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);

            repeter = 0;
            break;
          }

          case 4:
            {
                       do
                {
                    int trouve = 0;
                    printf("\n\tEntrez la somme: ");
                    scanf("%d", &somme);
                    tmp = tete;

        while(tmp != NULL)
        {
            if(tmp->somme == somme)
                {
                    if(!trouve)
                    {
                        printf("\n\t\t-----------La donation------------\n");
                        printf("\n\t\tCni |  Nom  | Prenom  | Nationalite | Cause\n");
                    }
                    trouve++;
                    printf("\n\t\t%d | %d | %s | %d\n", tmp->num_donation, tmp->num_donateur, tmp->paiment, tmp->somme);

                }
                tmp = tmp->suivant;
        }
        if(!trouve)
        {
        printf("\n\t!Somme existe pas quitter operation(oui/non): ");
       scanf("%s", quitter);
        }

        else
            strcpy(quitter,"oui");
            }while(strcmp(quitter,"non") == 0);
            repeter = 0;
            break;
          }

          default: printf("\n\t\tEntrez un valide nombre!\n");repeter = 1;break;

        }


    }while(repeter == 1);

    else
        printf("\n\t\t\t\t!Rien a rechercher!");

}

void modifier_dona(dona* tete)
{
     int num_dona,somme, rentrer, choix,repeter;
     dona* tmp = tete;
     char paiment[30],quitter[30], reponse[30];
  do
  {
       printf("\n\tEntrez num du donation a modifier: ");
       scanf("%d", &num_dona);
        if(rechercher_dona(tete,num_dona))
  {
      do
      {
           printf("\n\tQuel champ veux tu modifier?\n");
      printf("\n\t\t\t1:Paiment\t  2:Somme\n");
      printf("\n\t\t\t3:Tous");
      printf("\n\tJe choisi: ");
          scanf("%d", &choix);

        switch(choix)
        {
        case 1:
            {
                    printf("\n\tLe nouveau paiment: ");
                    scanf("%s", paiment);
                while(tmp != NULL)
                {
                    if(tmp->num_donation == num_dona)

                       strcpy(tmp->paiment,paiment);
                      tmp = tmp->suivant;
                }
                  repeter = 0;
                  break;
            }

        case 2:
            {
                printf("\n\tLe nouveau somme: ");
                scanf("%d", &somme);
                while(tmp != NULL)
                {
                    if(tmp->num_donation == num_dona)
                      tmp->somme = somme;
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }
        case 3:
            {
                printf("\n\tLes nouveau Paiment et Somme: ");
                scanf("%s%d", paiment,&somme);
                while(tmp != NULL)
                {
                    if(tmp->num_donation == num_dona)
                    {
                        tmp->somme = somme;
                        strcpy(tmp->paiment,paiment);
                    }
                      tmp = tmp->suivant;
                }
                repeter = 0;
                break;
            }

             default :printf("\n\tEntrez un valide nombre!\n"); repeter = 1; break;

        }

      }while(repeter == 1);
      if(rentrer != 2)
     printf("\n\t\t   /* Donation avec num '%d' a bien ete modifie */\n", num_dona);
     else
         printf("\n\t\t   /* Donation avec num'%d' pas modifie */\n", num_dona);
     break;
  }
  printf("\n\t!La num donation existe pas quitter operation (oui/non): ");
  scanf("%s", quitter);
  }while(strcmp(quitter,"oui") != 0);

}

dona* supprimer_num_dona(dona* tete_dona, dnt* tete_dnt)//fonction qui supprime une occurence dans la chaine

{
    dona *tmp_av, *tmp_ele, *tmp_ap;
    tmp_ele = tete_dona;
    tmp_av = tete_dona;
    int num_dona,num_dnt, repeter, choix;
   char quitter[10];
      do

      {

    printf("\n\tEntrez num du donation a supprimer: ");
    scanf("%d", &num_dona);
        if(rechercher_dona(tete_dona,num_dona))
     {
         while(tmp_ele != NULL)
         {
             if(tmp_ele->num_donation == num_dona)
             {
                  num_dnt = tmp_ele->num_donateur;
                  break;
             }

             tmp_ele = tmp_ele->suivant;
         }
        if(!rechercher_dnt(tete_dnt,num_dnt))
        {
             do
       {
           tmp_ele = tete_dona;
           printf("\n\tVoulez vous vraiment supprimer la donation avec num '%d'?\n",num_dona);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete_dona;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);

                if(tmp_ele->num_donation != num_dona)//Isoler le cas ou element souhaitte supprimee est au premier position
    {
        tmp_ele = tmp_ele->suivant;
        while(tmp_ele->num_donation != num_dona)
    {
        tmp_av = tmp_ele;
        tmp_ele = tmp_ele->suivant;
    }

    tmp_ap = tmp_ele->suivant;//le suivant du element avant element souhaite supprimee va pointer sur le suivant du element qui est apres
    free(tmp_ele);
    tmp_av->suivant = tmp_ap;
     printf("\n\t\t   /* Donation avec num '%d' a bien ete supprime */", num_dona);
    return tete_dona;
    }
    else
    {
            tmp_ele = tete_dona->suivant;
           free(tete_dona);
    printf("\n\t\t   /* Donation avec num '%d' a bien ete supprime */", num_dona);
           return tmp_ele;
    }

     }
     else
        printf("\n\t!Un donateur existe avec le num donateur de cette donation'");
         return tete_dona;
        }

   else
       printf("\n\t!La num donation existe pas quitter operation (oui/non): ");
       scanf("%s", quitter);
      }while(strcmp(quitter,"non") == 0);
     return tete_dona;
}

dona* supp_un_dona(dona* tete_dona,dnt* tete_dnt, char champ[30], char ele[30], int ele_somme)//la focntion qui supprime un element d'apres son (Nom,Prenom,Adresse)

{
    dona* tmp = tete_dona, *tmp_ap, *tmp_av = tete_dona;
   int choix,num_dnt, repeter;
    if(strcmp(champ,"paiment") == 0)
    {
         while(tmp != NULL)
         {
             if(strcmp(tmp->paiment,ele) == 0)
                num_dnt = tmp->num_donateur;
             tmp = tmp->suivant;
         }
         if(!rechercher_dnt(tete_dnt,num_dnt))
         {
        do
       {
           tmp = tete_dona;
           printf("\n\tVoulez vous vraiment supprimer la donation  avec le paiment '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete_dona;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);

            if(strcmp(tete_dona->paiment,ele) != 0)
    {
        tmp = tmp->suivant;
    while(strcmp(tmp->paiment,ele) != 0)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donation avec paiment '%s' a bien ete supprimee */", ele);
        return tete_dona;
    }

    else
    {
        tmp_av = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donation avec paiment '%s' a bien ete supprimee */", ele);
         return tmp_av;
    }
         }
         printf("\n\t'Un donateur a la num donateur de cette donation!'");
         return tete_dona;
    }

        if(strcmp(champ,"somme") == 0)
    {
        tmp = tete_dona;
         while(tmp != NULL)
         {
             if(tmp->somme == ele_somme)
                num_dnt = tmp->num_donateur;
             tmp = tmp->suivant;
         }

         if(!rechercher_dnt(tete_dnt,num_dnt))
         {
              do
       {
           tmp = tete_dona;
           printf("\n\tVoulez vous vraiment supprimer le donateur  avec prenom '%s'?\n", ele);
           printf("\n\t\t\t1:Oui\t  2:Non\n");
           printf("\n\tJe choisi: ");
           scanf("%d", &choix);
           switch(choix)
           {
               case 1: repeter = 0;break;
               case 2: return tete_dona;
               default: printf("\n\t'Entrez un valide nombre!'");repeter = 1;break;
           }
       }while(repeter == 1);
            if(tete_dona->somme != ele_somme)
    {
        tmp = tmp->suivant;
    while(tmp->somme!= ele_somme)
    {
        tmp_av = tmp;
        tmp = tmp->suivant;
    }
        tmp_ap = tmp->suivant;
        tmp_av->suivant = tmp_ap;
        free(tmp);
        printf("\n\t\t /* Donation avec somme '%d' a bien ete supprimee */", ele_somme);
        return tete_dona;
    }

    else
    {
        tmp_av = tmp->suivant;
         free(tmp);
         printf("\n\t\t /* Donation avec somme '%d' a bien ete supprimee */", ele_somme);
         return tmp_av;
    }
    }
         printf("\n\t'Un donateur a la num donateur de cette donation!'");
         return tete_dona;
    }

}

dona* supp_N_dona(dona* tete_dona,dnt* tete_dnt,char champ[30], char ele[30], int ele_somme)//La fonction qui supprime 'N' element en utilisant la fonction 'supp_un'

{
    dona* tmp = tete_dona;
    int trouve = 0;

    if(strcmp(champ,"paiment") == 0)
    {
         while(tmp != NULL)
    {
        if(strcmp(tmp->paiment,ele) == 0) //Connaiter le nombre d'occurence d'un element pour le supprimer
            trouve++;
        tmp = tmp->suivant;
    }

    if(trouve)
    {
        for(int i = 0; i < trouve; i++) //Appeler la focnbtion qui supprime un occurence 'N' fois
        tete_dona = supp_un_dona(tete_dona,tete_dnt,"paiment",ele,0);
        return tete_dona;
    }
    else
    {
        printf("\n\t\t\t    'Paiment existe pas!'");
        return tete_dona;
    }
    }

   else
    if(strcmp(champ,"somme") == 0)
   {
        while(tmp != NULL)
    {
        if(tmp->somme == ele_somme)
            trouve++;
            tmp = tmp->suivant;
    }

    if(trouve)
     {
       tete_dona = supp_un_dona(tete_dona,tete_dnt,"somme",ele,ele_somme);
        return tete_dona;
      }
    else
    {
         printf("\n\t\t\t    'Somme existe pas!'");
        return tete_dona;
    }
   }

}

dona* supprimer_menu_dona(dona* tete_dona,dnt* tete_dnt)

{
    int choix, repeter;
    char ele[30];
    int ele_somme;
    do
    {
    printf("\n\tSupprimer element par:\n");
    printf("\n\t\t\t1:Num donation\t  3:Paiment\n");
    printf("\n\t\t\t2:Somme\n");
    printf("\n\tJe choisi: ");
          scanf("%d", &choix);
    switch(choix)
    {
        case 1:tete_dona = supprimer_num_dona(tete_dona,tete_dnt);repeter = 0;break;
        case 2:
            {
                printf("\n\tSomme: ");
                scanf("%d", &ele_somme);
                tete_dona = supp_N_dona(tete_dona,tete_dnt,"somme",NULL,ele_somme);
                repeter = 0;
                break;
            }
                case 3:
            {
                printf("\n\tPaiment: ");
                scanf("%s", ele);
                tete_dona = supp_N_dona(tete_dona,tete_dnt,"paiment",ele,0);
                repeter = 0;
                break;
            }

        default: printf("\n\tEntrez un valide nombre!\n");repeter = 1;break;
    }
    }while(repeter == 1);

    return tete_dona;
}

void menu_donation(dnt* tete_dnt,prf* tete_prf,dnt* tete_dona,char nomUti[30])//menu du donateur
{

      int choix;
   do
   {
       printf("\n\n\t===============================================================\n");
       printf("\n\t\t\t      // Gestion donation //\n");
       printf("\n\t===============================================================\n\n");
       printf("\n\n\t    Maison > Gestion Donation\n\n");
       printf("\n\t\t\t\t\t\t\t   -0) Maison\n\n");
       printf("\n\t           Ajouter ->    (1)\t   Charger ->     (5) \n\n");
       printf("\n\t           Afficher ->   (2)\t   Supprimer ->   (6)\n\n");
       printf("\n\t           Rechercher -> (3)\t   Modifier ->    (7)\n\n");
       printf("\n\t           Operations -> (4)\t   Sauvegarder -> (8)\n");
       printf("\n\t\t\t        ---------------\n");
       printf("\n\t\t\t\t Je choisi: ");
       scanf("%d", &choix);
       switch(choix)
       {
           case 1:system("cls"); printf("\n\n\t    Maison > Gestion Donation > Ajouter\n\n"); tete_dona = ajouter_menu_dona(tete_dona,tete_dnt);break;
           case 5:system("cls"); printf("\n\n\t    Maison > Gestion Donation > Charger Depuis un Fichier\n\n"); tete_dona = charger_fichier_dona(tete_dona,tete_dnt); break;
           case 2:system("cls"); printf("\n\n\t    Maison > Gestion Donation > Aficher\n\n"); afficher_menu_dona(tete_dona);break;
           case 6:system("cls"); printf("\n\n\t    Maison > Gestion Donation > Supprimer\n\n");tete_dona = supprimer_menu_dona(tete_dona,tete_dnt);break;
           case 3:system("cls"); printf("\n\n\t    Maison > Gestion Donation > Rechercher\n\n");reche_aff_dona(tete_dona);break;
           case 7:system("cls"); printf("\n\n\t    Maison > Gestion DDonation > Modifier\n\n");modifier_dona(tete_dona);break;
           case 4:system("cls"); menu_operation_dona(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 8:system("cls"); printf("\n\n\t    Maison > Gestion Donation > Sauvegarder\n\n");sauvegarder_dona(tete_dona);break;
           case 0:system("cls"); menu_principale(tete_dnt,tete_prf,tete_dona,nomUti);break;
           default : printf("\n\t**Veuillez entrez un valide nombre de la liste\n");menu_donateur(tete_dnt,tete_prf,tete_dona,nomUti);break;
       }

    }while(choix != 0);
}

void menu_operation_dona(dnt* tete_dnt,prf* tete_prf,dona* tete_dona,char nomUti[30])

{
      int choix;
   do
   {
       printf("\n\n\t===============================================================\n");
       printf("\n\t\t\t      // Operations //\n");
       printf("\n\t===============================================================\n\n");
       printf("\n\t\t\t\t\t\t\t   -0) Maison\n\n");
       printf("\n\t   -1) Compter nombre du occurence\n");
       printf("\n\t   -2) Compter totale\n");
       printf("\n\t   -3) Calculer 'Avg'\n");
       printf("\n\t   -4) Calculer 'Min'\n");
       printf("\n\t   -5) Calculer 'Max'\n");
       printf("\n\t   -6) Retourner\n");
       printf("\n\t\t   ---------------\n");
       printf("\n\t\t     Je choisi: ");
       scanf("%d", &choix);
       switch(choix)
       {
           case 1: system("cls"); printf("\n\n\tMaison > Gestion Donation > Operations > Compter_Occurence\n\n"); compter_occ_dona(tete_dona);break;
           case 2: system("cls"); printf("\n\n\tMaison > Gestion Donation > Operations > Compter_Totale\n\n"); compter_tot_dona(tete_dona); break;
           case 3: system("cls"); printf("\n\n\tMaison > Gestion Donation > Operations > Calculer 'Avg'\n\n");cal_avg_dona(tete_dona);break;
           case 4: system("cls"); printf("\n\n\tMaison > Gestion Donation > Operations > Calculer 'Min'\n\n");cal_min_dona(tete_dona);break;
           case 5: system("cls"); printf("\n\n\tMaison > Gestion Donation > Operations > Calculer 'Max'\n\n");cal_max_dona(tete_dona);break;
           case 6: menu_donation(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 0: menu_principale(tete_dnt,tete_prf,tete_dona,nomUti);break;
           default : printf("\n\t**Veuillez entrez un valide nombre de la liste\n");menu_operation_dona(tete_dnt,tete_prf,tete_dona,nomUti);break;
       }
   }while(choix != 0);
}

                                       //Les fonction pour les operations//

void compter_occ_dona(dona* tete)//L afonction qui calcule nombe ocuurence d'un champ

{

    char champ[30];
     int choix, repeter, num_dnt, nbr = 0;
      dona* tmp = tete;

    do
    {
    printf("\n\tCalculer occurence d'un:\n");
    printf("\n\t\t\t1:Num donateur\t3:Paiment\n");
    printf("\n\t\t\t2:Somme\n");
    printf("\n\tJe choisi: ");
          scanf("%d", &choix);
    switch(choix)
    {
    case 1:
        {
            printf("\n\tNum donateur: ");
        scanf("%d", &num_dnt);

        while(tmp != NULL)
        {
            if(tmp->num_donateur == num_dnt)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucune donateur qui a le numero '%d' */", num_dnt);
            else
            if(nbr == 1)
            printf("\n\t\t/* Il y a un donateur qui a le numero '%d' */", num_dnt);
        else
        printf("\n\t\t/* Il y a %d donateurs qui ont le numero '%d' */", nbr,num_dnt);
        repeter = 0;
        break;
        }
    case 2:
        {
            printf("\n\tSomme: ");
        scanf("%d", &num_dnt);
        while(tmp != NULL)
        {
            if(tmp->somme == num_dnt)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucune donations avec la somme '%d' */", num_dnt);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a une donation qui avec la somme '%d' */", num_dnt);
            else
        printf("\n\t\t  /* Il y a %d donations avec la somme '%d' */", nbr,num_dnt);
        repeter = 0;
        break;
        }
    case 3:
        {
            printf("\n\tPaiment: ");
        scanf("%s", champ);
        while(tmp != NULL)
        {
            if(strcmp(tmp->paiment,champ) == 0)
                nbr++;
              tmp = tmp->suivant;
        }
        if(nbr == 0)
            printf("\n\t\t/* Il y a aucune donation qui a paiment '%s' */", champ);
            else
            if(nbr == 1)
            printf("\n\t\t   /* Il y a une donation qui a paiment '%s' */", champ);
            else
        printf("\n\t\t   /* Il y a %d donations qui ont paiment '%s' */", nbr,champ);
        repeter = 0;
        break;
        }
    default :printf("\n\tEntrez un valide nombre!\n"); repeter = 1; break;
    }
    }while(repeter == 1);

}

void compter_tot_dona(dona* tete)//La fonction qui calcule le nombre de donateurs

{
     dona* tmp = tete;
     int nbr = 0;
     while(tmp != NULL)
     {
         nbr++;
         tmp = tmp->suivant;
     }

    printf("\n\t\t\t    /* Il y a %d donations */", nbr);

}

void cal_min_dona(dona* tete)//La fonction qui calcule le min d'un champ donne

{
    if(tete != NULL)
   {
       dona* tmp = tete->suivant;
    int repeter, min_somme;
    printf("\n\t'La Calcule est applique sur la colonne 'Somme''\n");
        min_somme = tete->somme;
        while(tmp != NULL)
        {
                if(tmp->somme < min_somme) min_somme = tmp->somme;
                tmp = tmp->suivant;
        }
    printf("\n\t\t le minimum du somme est '%d' */", min_somme);
   }
   else
    printf("\n\t'Ooops! La table est vide'");
}

void cal_max_dona(dona* tete)//La fonction qui calcule le max d'un champ donne

{
if(tete != NULL)
   {
       dona* tmp = tete->suivant;
    int repeter, max_somme;
    printf("\n\t'La Calcule est applique sur la colonne 'Somme''\n");
        max_somme = tete->somme;
        while(tmp != NULL)
        {
                if(tmp->somme > max_somme) max_somme = tmp->somme;
                tmp = tmp->suivant;
        }
    printf("\n\t\t le maximum du somme est '%d' */", max_somme);
   }
   else
    printf("\n\t'Ooops! La table est vide'");
}

void cal_avg_dona(dona* tete)//La fonction qui calcule le max d'un champ donne

{
if(tete != NULL)
   {
       dona* tmp = tete->suivant;
    int repeter, somme = 0, nbr = 0;
    printf("\n\t'La Calcule est applique sur la colonne 'Somme''\n");
        while(tmp != NULL)
        {
                 somme +=tmp->somme;
                 nbr++;
                tmp = tmp->suivant;
        }
    float moy = somme / nbr;
    printf("\n\t\t le moyen du somme est '%f' */", moy);
   }
   else
    printf("\n\t'Ooops! La table est vide'");
}



                               //Les focntions pour la partie d'authentification

int rech_Uti(char* nomUti, char* motPass) //Cette fonction est utilise pour verifier si l'utilisateur existe ou non\
                                              il est utilise lors  d'Authentification' et le creation du compte utilisateur

{
    char nom[30], prenom[30], adresse[30], nom_utilis[30], mot_de_pass[30];
     int age, nom_trouve = 0, pass_trouve = 0;
    FILE* f = fopen("utilisateurs.txt", "r");
    if(f == NULL) printf("\n\tErreur lors du lecture du ficheir!");
    else
    while(!feof(f))
    {
        fscanf(f,"%s %s %s %d %s %s\n", nom, prenom, adresse, &age, nom_utilis, mot_de_pass);
        if(strcmp(nom_utilis,nomUti) == 0)nom_trouve = 1;
        if(strcmp(mot_de_pass,motPass) == 0)pass_trouve = 1;
    }
      if(nom_trouve == 1 && pass_trouve == 0)return -1;
      if(nom_trouve == 0 && pass_trouve == 1)return 1;
      if(nom_trouve == 1 && pass_trouve == 1)return 0;
      if(nom_trouve == 0 && pass_trouve == 0)return 2;
    fclose(f);
}

void sauv_info_recup(dnt* tete_dnt, prf* tete_prf, dona* tete_dona)
{
    dnt* tmp_dnt = tete_dnt;
    prf* tmp_prf = tete_prf;
    dona* tmp_dona = tete_dona;
    FILE* f_dnt, *f_prf, *f_dona;
    f_dnt = fopen("info_recup_dnt.txt","w");
    f_prf = fopen("info_recup_prf.txt","w");
    f_dona = fopen("info_recup_dona.txt","w");
    if(f_dnt == NULL || f_prf == NULL || f_dona == NULL)
        printf("\n\t!Erreur lors du recuperation des informations\n");
    while(tmp_dnt != NULL)
    {
        fprintf(f_dnt,"%d %s %s %s\n",tmp_dnt->id_dnt, tmp_dnt->nom_dnt, tmp_dnt->prenom_dnt, tmp_dnt->adresse_dnt);
        tmp_dnt = tmp_dnt->suivant;
    }
    while(tmp_prf != NULL)
    {
        fprintf(f_prf, "%d %s %s %s %s\n", tmp_prf->cni, tmp_prf->nom, tmp_prf->prenom, tmp_prf->nationalite, tmp_prf->cause);
        tmp_prf = tmp_prf->suivant;
    }
    while(tmp_dona != NULL)
    {
        fprintf(f_dona ,"%d %d %s %d\n", tmp_dona->num_donation, tmp_dona->num_donateur, tmp_dona->paiment, tmp_dona->somme);
        tmp_dona = tmp_dona->suivant;
    }
    fclose(f_dnt);
    fclose(f_prf);
    fclose(f_dona);
}

dnt* charger_info_recup_dnt(dnt* tete)

{
    char nom[30], prenom[30], adress[30], pos[30];
    int id;
    FILE* f;
    f = fopen("info_recup_dnt.txt","r");
     if(f == NULL)
     {
         printf("\n\t'!Erreur lors de recuperation des inofrmations du table 'Donateur''\n");
         return tete;
     }

  else

     {
         fseek(f,0,SEEK_END);
         if(ftell(f) == 0)
         {
             printf("\n\t'!Il y'a aucuns informations a recuperer dans la table 'Donateur''\n");
         }
         else
         {

             rewind(f);
              while(!feof(f))
              {
                  fscanf(f, "%d %s %s %s\n", &id, nom, prenom, adress);
                   tete = ajouter_fichier_dnt(tete,id,nom,prenom,adress,"fin");
              }

             fclose(f);
             printf("\n\t        'La table 'Donateur' a bien ete recupere'\n");
         }

         fclose(f);
         return tete;
}

}

prf* charger_info_recup_prf(prf* tete)

{
        char nom[30], prenom[30], nationalite[30], cause[30], pos[30];
    int cni;
    FILE* f;
    f = fopen("info_recup_prf.txt","r");
     if(f == NULL)
     {
         printf("\n\t'!Erreur lors de recuperation des inofrmations du table 'Profiteur''\n");
         return tete;
     }

  else

     {
         fseek(f,0,SEEK_END);
         if(ftell(f) == 0)
         {
             printf("\n\t'!Il y'a aucuns informations a recuperer dans la table 'Profiteur''\n");
         }
         else
        {
            rewind(f);
             while(!feof(f))
              {
                  fscanf(f, "%d %s %s %s %s\n", &cni, nom, prenom, nationalite,cause);
                  tete = ajouter_fichier_prf(tete,cni,nom,prenom,nationalite,cause,"fin");
              }

             fclose(f);
             printf("\n\t        'La table 'Profiteur' a bien ete recupere'\n");
    }
                fclose(f);
             return tete;
    }
}

dona* charger_info_recup_dona(dona* tete_dona, dnt* tete_dnt)
{
       char paiment[30],pos[30];
    int num_dona,num_dnt,somme;
    FILE* f;
    f = fopen("info_recup_dona.txt","r");
     if(f == NULL)
     {
         printf("\n\t'!Erreur lors de recuperation des inofrmations du table 'Donation''\n\n");
         return tete_dona;
     }

  else

     {
         fseek(f,0,SEEK_END);
         if(ftell(f) == 0)
         {
             printf("\n\t'!Il y'a aucuns informations a recuperer dans la table 'Donation''\n");
         }
         else
         {
              while(!feof(f))
              {
                  fscanf(f, "%d %d %s %d\n", &num_dona, &num_dnt, paiment, &somme);
                  tete_dona = ajouter_fichier_dona(tete_dona,tete_dnt,num_dona,num_dnt,paiment,somme,"fin");
              }

             fclose(f);
             printf("\n\t        'La table 'Donation' a bien ete recupere'\n\n");
         }
                fclose(f);
             return tete_dona;
         }
}
 void cree_utilis()
 {
     char nom[30], prenom[30], adresse[30], nom_utilis[30], mot_de_pass[30];
     int age, trouve, verif;
     FILE* f;

     printf("\n\n\n\t----------------Remplissez les champs suivant----------------\n\n");
     printf("\n\t    Partie 1/2*\n");
     printf("\n\t  Nom: ");
     scanf("%s", nom);
     printf("\n\t  Prenom: ");
     scanf("%s", prenom);
     printf("\n\t  Adresse: ");
     scanf("%s", adresse);
     printf("\n\t  Age: ");
     scanf("%d", &age);
      printf("\n\t    Partie 2/2*\n");


      do
      {
      printf("\n\t  Nom d'utilisateur: ");
      scanf("%s", nom_utilis);
      printf("\n\t  Mot de passe: ");
      scanf("%s", mot_de_pass);
      verif = rech_Uti(nom_utilis,mot_de_pass);
      if(verif == 1)
      {
           printf("\n\n\t'!Mot de passe existe deja essayez evec un autre'\n");
           printf("\n\t        -----------------------------------\n");
           trouve = 1;
      }
     else
        if(verif == -1)
     {
         printf("\n\n\t'!Nom d'utilisateur existe deja essayez evec un autre'\n");
         printf("\n\t        -----------------------------------\n");
        trouve = 1;
     }
     else
        if(verif == 0)
     {
         printf("\n\n\t'!Mot de passe et Nom d'utilisateur existent deja,\n\n\
          Essayez evec un autre'\n");
          printf("\n\t        -----------------------------------\n");
         trouve = 1;
     }
     else
       {
         f = fopen("utilisateurs.txt", "a");
       if(f == NULL) printf("\n\tErreur lors du lecture du ficheir!");
       else
       {
      fprintf(f,"%s %s %s %d %s %s\n\n", nom, prenom, adresse, age, nom_utilis, mot_de_pass);
      fclose(f);
      trouve = 0;
       }
       }

      }while(trouve == 1);
   printf("\n\n\t\t\t/* Compte cree avec 'succes' */\n");
 }

void login(dnt* tete_dnt,prf* tete_prf,dona* tete_dona)

{
    char nom_uti[30], motPass[30];
    int rentrer;
    printf("\n\n\n\t----------------Remplissez les champs suivant----------------\n\n");
    do
    {
    rentrer = 0;
    printf("\n\t  Nom d'utilisateur: ");
    scanf("%s", nom_uti);
    printf("\n\t  Mot de pass: ");
    scanf("%s", motPass);
    int verif = rech_Uti(nom_uti,motPass);
    if(verif == -1)
    {
        printf("\n\n\t'!Le mot de passe est incorrecte'\n");
        printf("\n\t     ----------------------\n");
        rentrer = 1;
    }

    else
        if(verif == 1)
    {
        printf("\n\n\t'!Le nom d'utilisateur est incorrecte'\n");
        printf("\n\t     ----------------------------\n");
        rentrer = 1;
    }
    else
        if(verif == 2)
    {
        printf("\n\n\t'!Le nom d'utilisateur et le mot de passe sont incorrectes'\n");
        printf("\n\t        --------------------------------------------\n");
        rentrer = 1;
    }
    else
        if(verif == 0)
        {
       tete_dnt = charger_info_recup_dnt(tete_dnt);
       tete_prf = charger_info_recup_prf(tete_prf);
       tete_dona = charger_info_recup_dona(tete_dona,tete_dnt);
       menu_principale(tete_dnt,tete_prf,tete_dona,nom_uti);
        }
    }while(rentrer == 1);
}

 void login_menu(dnt* tete_dnt, prf* tete_prf,dona* tete_dona)

 {
    int choix, repeter;
     
   do
   {
           printf("\n\n\n\t===============================================================\n");
       printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2// Bienvenue dans votre  Base Donne //\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
       printf("\n\t===============================================================\n\n");
      printf("\n\t   -1) Creer un compte\n");
    printf("\n\t   -2) Se connecter\n");
    {
    	system("color 3");
	 printf("\n\t   -0) Quitter\n");}
    printf("\n\t   -0) Quitter\n");
    printf("\n\t\t\t    Je choisi: ");
    scanf("%d", &choix);

    switch(choix)
    {
        case 1: system("cls"); cree_utilis();repeter = 0;break;
        case 2:system("cls"); login(tete_dnt,tete_prf,tete_dona); repeter = -1;break;
        case 0:return;
        default :printf("\n\tEntrez un valide nomber");repeter = 1;break;
    }
   }while(repeter != -1);
 }

 void uti_info(char nomUti[30], dnt* tete_dnt, prf* tete_prf,dona* tete_dona)

 {

     char nom[30], prenom[30], adress[30], motPass[30], nom_uti[30];
     int age;
     FILE* f = fopen("utilisateurs.txt", "r");
     if(f == NULL)
     {
         printf("\n\t'!Ereur lors du lecture du fichier");
         return;
     }
     printf("\n\n\n\t   Maison > Mon Compte > Mes Informations\n");
     printf("\n\n\t\t   --------Voila vos informations--------\n\n");
     while(!feof(f))
     {
         fscanf(f, "%s %s %s %d %s %s\n", nom, prenom, adress, &age, nom_uti, motPass);
         if(strcmp(nom_uti, nomUti) == 0)
         {
            printf("\n\t\t    *Nom: %s\t\t*Prenom: %s\n", nom, prenom);
            printf("\n\t\t    *Adresse: %s\t\t*Age: %d\n", adress, age);
            printf("\n\t*Nom d'utilisateur: %s\t      *Mot de passe: %s\n\n", nomUti, motPass);
         }
     }

     fclose(f);
     printf("\n\tEntrez quelque chose pour retourner: ");
     scanf("%s", nom);
     printf("\n\t\t\t---------------------------------");
     if(strlen(nom) != 0)
        menu_compte(nomUti,tete_dnt,tete_prf,tete_dona);
 }

 void menu_compte(char nomUti[30], dnt* tete_dnt, prf* tete_prf,dona* tete_dona)

 {
     int choix, repeter;
     dnt* tete2 = NULL;
     printf("\n\n\n\t         Maison > Mon Compte\n");
     printf("\t\t\t\t\t\t\t       '%s' \n\n", nomUti);
     do
     {
     		system("color 3");
     printf("\n\t      -1) Mes informations\n");
     printf("\n\t      -2) Deconnexion\n");
     printf("\n\t      -0) Retourner\n");
     printf("\n\t\t\t    Je choisi: ");
     scanf("%d", &choix);

       switch(choix)
       {
           case 1: system("cls"); uti_info(nomUti, tete_dnt, tete_prf,tete_dona);repeter = 0;break;
           case 2: system("cls"); login_menu(NULL,NULL,NULL);repeter = 0; break;
           case 0: system("cls"); menu_principale(tete_dnt,tete_prf,tete_dona,nomUti);repeter = 0;break;
          default :printf("\n\tEntrez un valide nomber");repeter = 1;break;
       }
     }while(repeter == 1);

 }

 void menu_propos(dnt* tete_dnt,prf* tete_prf,dona* tete_dona,char nomUti[30])//menu du propos
{
     char nom[30];
     	system("color 3");
     printf("\n\n\n\t      Maison > A Propos\n");
     printf("\n\n\t  Historique");
     printf("\n\t  ------\n");
     printf("\n\t  Ce projet a ete cree en occasion du fin du semestre \n\n\
       de module \"Langage 'C'\", Et pour bien maitriser les bases\n\n\
       du programmation\n");
     printf("\n\n\t  Les Technologies");
     printf("\n\t  --------\n");
     printf("\n\t  Ce projet nous a encourage a utilise plusieurs \n\n\
       technologies comme les structures des donnes a savoir \n\n\
       'Les structures', 'Les fichiers', 'Les chaines lies'...\n");
     printf("\n\n\t  Les Contributeurs");
     printf("\n\t  --------\n");
     printf("\n\t  Ce projet a ete cree par 3 contributeurs:\n\n\
       *Adniden Taha\n\n\
       *El Hamraoui Aymane\n\n\
       *Ajarai Ayoub\n\n");
    printf("\n\tEntrez quelque chose pour retourner: ");
     scanf("%s", nom);
     printf("\n\t\t\t---------------------------------");
     if(strlen(nom) != 0)
        menu_principale(tete_dnt,tete_prf,tete_dona,nomUti);

}

void menu_principale(dnt* tete_dnt,prf* tete_prf,dona* tete_dona,char nomUti[30])//le menu principale du programme
{
    int choix, click;;
    	system("color 3");
       printf("\n\n\n\t===============================================================\n");
       printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2// Bienvenue '%s' //\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n", nomUti);
       printf("\n\t===============================================================\n\n");
       printf("\n\t    Maison\n\n");
        printf("\n\t\t\t\t\t-4) A propos\t-5) Mon compte\n\n");
       printf("\n\t\t-1) Gestion de Donateur\n");
      
       printf("\n\t\t-2) Gestion de Donation\n");
       printf("\n\t\t-3) Gestion de Profiteur\n");
       printf("\n\t\t-0) Quitter\n\n");
       printf("\n\t\t     ---------------\n");
       printf("\n\t\t\tJe choisi: ");
       scanf("%d", &choix);
       switch(choix)
       {
           case 1: system("cls"); menu_donateur(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 2: system("cls"); menu_donation(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 3: system("cls"); menu_profiteur(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 4: system("cls"); menu_propos(tete_dnt,tete_prf,tete_dona,nomUti);break;
           case 5: system("cls"); menu_compte(nomUti,tete_dnt,tete_prf,tete_dona);break;
           case 0: sauv_info_recup(tete_dnt,tete_prf,tete_dona);printf("\n\t\t----------\n\n\n\nThis C Mini Project is developed by Aymane,Ayoub and Taha, thank you everyone!-----------\n");break;
           default : printf("\n\t'Veuillez entrez un valide nombre de la liste!'\n");menu_principale(tete_dnt,tete_prf,tete_dona,nomUti);break;
       }
}

main()
{
     dnt* tete_dnt = NULL;
     prf* tete_prf = NULL;
     dona* tete_dona = NULL;
     login_menu(tete_dnt,tete_prf,tete_dona);
}
