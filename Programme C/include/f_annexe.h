#ifndef _annexe
#define _annexe

// generic list structure



// id < 0 si le point ne fait pas parti d'une liste

typedef struct{
  int x;
  int y;
  int id;
} Point;

typedef struct{
  Point p1;
  Point p2;
  int id;
} Line;

struct maillonPoint{
	point val;
	struct maillon* suiv;
};
typedef struct maillonPoint* PointListe;

struct maillonLine{
	point val;
	struct maillon* suiv;
};
typedef struct maillonLine* LineListe;

typedef struct{
  LISTE pointListe;
  Liste lineListe;
} Shape;







LISTE creer_liste(void);
int est_vide(LISTE l);
LISTE supprimer_tete(LISTE l);
void supprimer_liste(LISTE l);
LISTE ajout_queue(LEXEME , LISTE );
LISTE ajout_tete (LEXEME, LISTE );
LISTE supprimen(int n, LISTE l);
LISTE copie(LISTE l);
void affiche_liste(LISTE l);
void nbmaillon(LISTE l);
LISTE concat(LISTE l1, LISTE l2);
instLISTE ajout_queue_inst(instruction inst, instLISTE liste);
dirLISTE ajout_queue_dir(DIRECTIVE dir, dirLISTE liste);
relocLISTE ajout_queue_reloc(relocETIQ etiq, relocLISTE liste);



#endif
