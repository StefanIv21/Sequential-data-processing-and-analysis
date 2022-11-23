
typedef struct nod{
   double elem;
   struct nod *next,*prev;
   int ok;
   int timestampe;
}Nod, *List;
void insert(List *head,List *last,double valoare,int timp)
{
  List nou = malloc(sizeof(Nod));
  nou->elem = valoare;
  nou->timestampe = timp;
  nou-> ok = 0;
  nou->next = NULL;
  if(*head == NULL)
  { 
    *head= nou;
    *last = nou;
    nou->prev = NULL;
  }
  else
  {
    List urm = *head;
    while(urm->next != NULL)
    {
      urm = urm->next;
    }
    urm->next = nou;
    nou->prev = urm;
    *last = nou;
  }  
}
void afisare(List head)
{
  do{
    printf("%d %.02lf\n", head->timestampe, head->elem);
    head = head->next;
    }while(head != NULL);
}
void eliberare(List *head)
{
  List  nod = *head;
  while (nod)
  {
    List  next = nod->next;
    free(nod);
    nod = next;
  }
}
void deletenod(List nod)
{
  if(nod->prev != NULL)
    nod->prev->next = nod->next;
  if(nod->next != NULL)
    nod->next->prev = nod->prev;
  free(nod);
}