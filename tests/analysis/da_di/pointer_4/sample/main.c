typedef struct Factorization{
  long int *mlt;
  long int *exp;
  long int dim;
} Factorization;

int foo(Factorization **fctlist, int genexp){
  int lexp = 0;
  for(int k = 0; k < fctlist[genexp]->dim; k++){
    lexp -= fctlist[genexp]->exp[k];
  }
  return lexp;
}


