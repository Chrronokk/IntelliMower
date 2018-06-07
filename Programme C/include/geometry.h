#ifndef _annexe
#define _annexe

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


typedef struct{
  LISTE pointListe;
  Liste lineListe;
} Shape;




#endif
