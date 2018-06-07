#include "f_annexe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Liste creer_liste(void){
     return NULL;
}



int est_vide(Liste l){
    if (l==NULL) return 1;
	return 0;
}


Liste supprimer_tete(Liste l){

    if(est_vide(l)) {return NULL;}

    else{
        Liste p;
        p = l->suiv;
        free(l);
        return p;
    }
}


Liste effacerListe(Liste liste)
{
    if(liste == NULL)
    {
        /* Si la liste est vide, il n'y a rien à effacer, on retourne
        une liste vide i.e. NULL */
        return NULL;
    }
    else{
        Liste p = liste->suiv;
        free(liste);
        return effacerListe(p);
    }
}



void supprimer_liste(Liste l){
  while (est_vide(l)==0){
    supprimer_tete(l);
  }
  supprimer_tete(l);
}


Liste ajout_queue(LEXEME lexeme, Liste liste){
	/*puts("Entrée dans ajout_queue");*/
	Liste p = calloc(1, sizeof(*p));
  p->suiv = NULL;
	p->val=lexeme;
  if(liste == NULL){ return p;}
  else{
    Liste q = liste;
    while(q->suiv != NULL){
        q = q->suiv;
    }
    q->suiv = p;
    return liste;
  }
}


Liste ajout_tete (LEXEME lexeme, Liste liste){
	Liste p;
	p = calloc(1, sizeof(p));
	p->suiv = liste;
	p->val = lexeme;
	liste = p;
	return liste;
}


Liste supprimen(int n, Liste l){

    int i;
    Liste p = l;
    Liste temp = NULL;

    if(est_vide(l)){ return l;}

    if(n==1){ return supprimer_tete(l);}

    for(i=0; i<n-2 && p->suiv != NULL; i++){
        p = p->suiv;
    }

    if(p->suiv == NULL){
        printf("Cet element n'existe pas\n");
        return l;}

    else{
        temp = p->suiv;
        p->suiv = temp->suiv;}

    free(temp);
    return l;
}


Liste copie(Liste l){
    /*puts("Entrée dans copie"); */
    Liste p = l;
    Liste copie = NULL;

    if(est_vide(l)) return NULL;

    while(p->suiv != NULL){

        copie = ajout_queue(p->val,copie);
        p = p->suiv;
    }
    copie = ajout_queue(p->val,copie);
    /*puts("Sortie de copie"); */
    return copie;
}


void affiche_liste(Liste l){
	/*puts("Entrée dans affiche_liste");*/
	Liste c = l	;

	if(est_vide(l)==1){
		printf("Vide \n");
		return;
		}

	while(c->suiv != NULL){
		/*puts("Bouclage");*/
    	printf("[%s]  %s \n", c->val.type,c->val.lex);
		c=c->suiv;
    }
   }



void nbmaillon(Liste l){
	int c=0;
	if(est_vide(l)){ puts("Vide");}
	else{
		Liste q=l;
		while(q->suiv != NULL){
				c++;
    	        q = q->suiv;
    	    }
		c++;
		printf("il y a %d d'éléments\n", c);
	}
}








Liste concat(Liste l1, Liste l2){
    Liste copie1 = copie(l1);
    Liste copie2 = copie(l2);
    Liste p = copie1;
    while(p->suiv != NULL){
        p = p->suiv;
    }
    p->suiv = copie2;
    return copie1;

}
