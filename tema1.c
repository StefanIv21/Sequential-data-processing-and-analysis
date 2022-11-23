#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.c"
 ////////////////////TASK1
double medie(List unu,List doi,List trei,List patru,List cinci)
{
    double medie;
    medie = (unu->elem + doi->elem + trei->elem + patru->elem + cinci->elem) / 5;
    return medie;
}
double deviatie(List unu,List doi,List trei,List patru,List cinci,double average)
{
    double deviatie;
    deviatie = sqrt((pow(unu->elem-average,2) + pow(doi->elem-average,2) + pow(trei->elem-average,2) + pow(patru->elem-average,2) + pow(cinci->elem-average,2)) / 5);
    return deviatie;
}
void task1(List head,int *nr)
{
    double  average,deviation;
    List urm1 = head;
    List urm2 = urm1->next;
    List urm3 = urm2->next;
    List urm4 = urm3->next;
    List urm5 = urm4->next;
    while(urm5 != NULL)
    { 
     average = medie(urm1,urm2,urm3,urm4,urm5);
     deviation = deviatie(urm1,urm2,urm3,urm4,urm5,average);
     if(urm3->elem>average - deviation && urm3->elem<average + deviation)
     {
        urm1 = urm2;
        urm2 = urm3;
        urm3 = urm4;
        urm4 = urm5;
        urm5 = urm5->next;
     }
     else
     {
        urm3->ok = 1;
        (*nr)--;
        urm1 = urm2;
        urm2 = urm3;
        urm3 = urm4;
        urm4 = urm5;
        urm5 = urm5->next;
     }
    }
    while(head != NULL)
    {
     if(head->ok == 1)
     {
        List stergere = head;
        head = head->next;
        deletenod(stergere);
     }
     else
     {
     head = head->next;
     } 
    }
}
//////////////////////////////TASK2
List sortare(List urm1,List urm2,List urm3,List urm4,List urm5,int alegere,List Nouaveche,List Nfinalveche)
{
  List q = NULL,p = NULL;
  insert(&q, &p, urm1->elem , urm1->timestampe);
  insert(&q, &p, urm2->elem , urm2->timestampe);
  insert(&q, &p, urm3->elem , urm3->timestampe);
  insert(&q, &p, urm4->elem , urm4->timestampe);
  insert(&q, &p, urm5->elem , urm5->timestampe);
  List current = NULL,urm = NULL;  
  double temp;  
  for(current = q; current->next != NULL; current = current->next) 
  {            
    for(urm = current->next; urm != NULL; urm = urm->next) 
    {   
      if(current->elem > urm->elem) {  
        temp = current->elem;  
        current->elem = urm->elem;  
        urm->elem  = temp;
        }  
    } 
  }  
  if(alegere == 1)
  { 
    insert(&Nouaveche, &Nfinalveche ,q->next->next->elem ,q->next->next->timestampe);
  }
  else
  {
    double mediearitm;
    List curm1 = q;
    List curm2 = q->next;
    List curm3 = curm2->next;
    List curm4 = curm3->next;
    List curm5 = curm4->next;
    mediearitm = medie(curm1, curm2, curm3, curm4, curm5);
    insert(&Nouaveche, &Nfinalveche, mediearitm, q->next->next->timestampe);
    } 
    eliberare(&q);
    return Nouaveche;
}
List filtraremediana(List head,int *nr)
{
  List Noua = NULL,Nfinal = NULL;
  List urm1 = head;
  List urm2 = urm1->next;
  List urm3 = urm2->next;
  List urm4 = urm3->next;
  List urm5 = urm4->next;
  int nrc = 0;
  while(urm5 != NULL)
  {
    Noua= sortare(urm1, urm2, urm3, urm4, urm5, 1, Noua, Nfinal);
    urm1 = urm2;
    urm2 = urm3;
    urm3 = urm4;
    urm4 = urm5;
    urm5 = urm5->next;
    nrc++;
  }
  *nr = nrc;
  eliberare(&head);
  head = Noua;
  return head;
}
List filtrarearitmetica(List head,int *nr)
{
  
  List Noua = NULL,Nfinal = NULL;
  List urm1 = head;
  List urm2 = urm1->next;
  List urm3 = urm2->next;
  List urm4 = urm3->next;
  List urm5 = urm4->next;
  int nrc = 0;
  while(urm5 != NULL)
  { 
    Noua = sortare(urm1 ,urm2 ,urm3 ,urm4 ,urm5 ,0 ,Noua ,Nfinal); 
    urm1 = urm2;
    urm2 = urm3;
    urm3 = urm4;
    urm4 = urm5;
    urm5 = urm5->next;
    nrc++;
  }
  *nr = nrc;
  eliberare(&head);
  head = Noua;
  return head;
}
/////////////////////////TASK3
void uniformizare(List first)
{
  List urm1 = first;
  List urm2 = urm1->next;
  while(urm2 != NULL)
  {
    if(urm2->timestampe - urm1->timestampe < 1001 && urm2->timestampe - urm1->timestampe > 99 )
    {
      urm2->timestampe = (urm2->timestampe + urm1->timestampe) / 2 ;
      urm2->elem = (urm1->elem + urm2->elem) / 2;
    }
    urm1 = urm2;
    urm2 = urm2->next;
  }
}
///////////////////TASK5
void statistici(List head,int val)
{
  List verificare = head;
  double max1 = -9999;
  double min1 = 99999;
  int interval1,interval2,mijloc;
  int nr;
  while(verificare != NULL)
  {
    if(verificare->elem > max1)max1 = verificare->elem;
    if(verificare->elem < min1)min1 = verificare->elem;
    verificare =  verificare->next;
  }
  if(min1 == (int)min1)
  {
    interval1 = (min1);
  }
  else
  {
   interval1 = (min1-1); 
  }
  if(min1 == (int)min1)
  {
  interval2 = (max1);
  }
  else
  {
   interval2 = (max1+1);
  }
  mijloc = interval1;
  while(mijloc < interval2 + val)
  {   
    List verificare2 = head;
    nr =  0;
    mijloc = interval1 + val;
    while(verificare2 != NULL)
    {
      if(verificare2->elem  >= interval1 && verificare2->elem <= mijloc) nr++;
      verificare2 = verificare2->next;
    }
    if(nr)
      printf("[%d, %d] %d\n",interval1,mijloc,nr);
    interval1 = mijloc;
    mijloc = mijloc+val;
  }
}
/////////////////////////////TASK4
void inseraredupa(List prev,double f,int timestampeactual)
{
  List nou = (List)malloc(sizeof(Nod));
  nou->elem = f;
  nou->timestampe = timestampeactual;
  nou->ok = 0;
  nou->next = prev->next;
  prev->next = nou;
  nou->prev = prev;
  nou->next->prev = nou;
}
double Calculc(List left,List right,int timestampeactual)
{
  double sus = timestampeactual - left->timestampe;
  double jos = right->timestampe - left->timestampe;
  double c = sus / jos;
  return c;
}
double calculw(int i ,double k)
{
  double f = i/(k-1);
  double sus = pow(f,2)*0.9+0.1; 
  double jos = 0;
  if(i == 0)
  {
    jos = (i/(k-1)) * (i/(k-1)) *0.9 +0.1  + ((i+1)/(k-1)) * ((i+1)/(k-1)) *0.9 +0.1  + ((i+2)/(k-1)) * ((i+2)/(k-1)) *0.9 +0.1;
  }
  if(i == 1)
  {
    jos = (((i-1)/(k-1)) * ((i-1)/(k-1)) *0.9 + 0.1)  + ((i/(k-1)) * (i/(k-1)) *0.9 +0.1)  + (((i+1)/(k-1)) * ((i+1)/(k-1)) *0.9 +0.1);
  }
  if(i == 2)
  {
    jos = ((i-2)/(k-1)) * ((i-2)/(k-1)) *0.9 +0.1  + ((i-1)/(k-1)) * ((i-1)/(k-1)) * 0.9 +0.1 + (i/(k-1)) * (i/(k-1)) * 0.9 +0.1;
  }
  double final;
  final = sus / jos;
  return final;
  }
double calculf(List left0,List left1,List left2,List right0,List right1,List right2,double w0,double w1,double w2,double C)
{
  double f;
  f = (1-C)*(left0->elem*w0 + left1->elem*w1 + left2->elem*w2) + C*(right0->elem*w0 + right1->elem*w1 + right2->elem*w2);
  return f;
}
void completare(List head,int *nr)
{
  int timestampeactual;
  List p = head;
  List urm = p->next;
  while(urm != NULL)
  {
    if(urm->timestampe - p->timestampe > 1000)
    {
      List left0 = p->prev->prev;
      List left1 = p->prev;
      List left2 = p;
      List right0 = urm->next->next;
      List right1 = urm->next;
      List right2 = urm;
      timestampeactual = p->timestampe + 200;
      while(timestampeactual < urm->timestampe)
      {
        double C;
        C = Calculc(left2 ,right2 , timestampeactual);
        double w0,w1,w2;
        w0 = calculw(0,3);
        w1 = calculw(1,3);
        w2 = calculw(2,3);
        double f;
        f = calculf(left0 ,left1 ,left2 ,right0 ,right1 ,right2 ,w0 ,w1 ,w2 ,C);
        inseraredupa(p,f,timestampeactual);
        p = p->next;
        (*nr)++;
        timestampeactual = timestampeactual + 200;
      }
    }
    p = urm;
    urm = urm->next;
  } 
}
int main(int argc,char *argv[])
{
  List first=NULL,last=NULL;
  int n,i,nr;
  scanf("%d",&n);
  nr = n;
  for(int j=0;j<n;j++)
  {
    float y;
    int t;
    scanf("%d %f",&t,&y);
    insert(&first, &last, y, t);
  }
  i = 1;
  while(i < argc)
  {
    if(strstr(argv[i] ,"e1"))
    {
      task1(first,&nr);
    } 
    if(strstr(argv[i],"e2"))
    { 
      first=filtraremediana(first,&nr);  
    }
    if(strstr(argv[i],"e3"))
    {
      first=filtrarearitmetica(first,&nr);
    }
    if(strstr(argv[i],"c"))
    {
      completare(first,&nr);
    }
    if(strstr(argv[i],"u"))
    { 
      uniformizare(first);
    }
    if(strstr(argv[i],"st"))
    {
      char *ret;
      ret = strstr(argv[i],"st");
      char *aux = ret+2;
      int val;
      val = atoi(aux);
      statistici(first,val);
    }
    i++;
  }
  if(strstr(argv[i-1],"e3"))
  {    
    printf("%d\n",nr);
    afisare(first);
  } 
  if(strstr(argv[i-1],"e2"))
  {
    printf("%d\n",nr);
    afisare(first);
  }
  if(strstr(argv[i-1],"e1"))
  {  
    printf("%d\n",nr);
    afisare(first);
  }
  if(strstr(argv[i-1],"u"))
  {
    printf("%d\n",nr);
    afisare(first);
  }
  if(strstr(argv[i-1],"c"))
  {
    printf("%d\n",nr);
    afisare(first);
  }
  eliberare(&first); 
  return 0;
}



