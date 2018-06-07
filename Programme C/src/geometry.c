#include "f_annexe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

̣// calcule la distance entre le point p1 et le point p2
double DistToPoint(Point p1, Point p2){
  double d;
  d=sqrt(pow(p1.x-p2.x),2)+sqrt(pow(p1.y-p2.y),2);
}

//calcule l'angle de la ligne par rapport à la ligne oest est

double AngleLine(Line line){
  double len1,len2,p,r;
  len1=hypot(line.p1.x,line.p1.y);
  len2=hypot(line.p2.x,line.p2.y);
  if(len1==0){
    len1=0.001;
  }
  if(len2==0){
    len1=0.001;
  }
  r=cos((line.p1.x*line.p2.x+line.p1.y*line.p2.y)/(len1*len2));
  return r;
}

//calcule la longueur d'une ligne
double LigneLength(Line line){
  double l;
  l=DistToPoint(line.p1,line.p2);
  return l;
}

// renvoie le point correspondant à l'intersection entre l1 et l2
Point GetIntersectionPoint(Line l1, Line l2){
  double p0_x,p0_y,p1_x,p1_y,p2_x, p2_y,p3_x,p3_y;
  double s1_x,s1_y,s2_x,s2_y;
  double den,s,t;
  Point p;
  p0_x = l1.p1.x;
  p0_y = l1.p1.y;
  p1_x = l1.p2.x;
  p1_y = l1.p2.y;
  p2_x = l2.p1.x;
  p2_y = l2.p1.y;
  p3_x = l2.p2.x;
  p3_y = l2.p2.y;
  s1_x = p1_x - p0_x;
  s1_y = p1_y - p0_y;
  s2_x = p3_x - p2_x;
  s2_y = p3_y - p2_y;
  den = -s2_x * s1_y + s1_x * s2_y;
  if den == 0{
    den = 0.0000001;
  }
  s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / den;
  t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / den;

  if(s>=0 && s<=1 && t>=0 && t<=1){
    p.x = p0_x + (t * s1_x);
    p.y = p0_y + (t * s1_y);
    p.id = -1;
    return p;
  }
  return NULL;
}
