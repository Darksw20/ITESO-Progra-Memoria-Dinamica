#include <stdio.h>

struct Alumno {
  int id;
  int id_grupo;
  char calificacion;
};
struct Alumno alumnos[] = {
    {683076, 1, 'F'},
    {123112, 1, 'A'},
    {224123, 2, 'B'},
    {441231, 1, 'A'},
    {123231, 3, 'A'},
    {448123, 1, 'A'},
  };
void* direcciones[] = {
  alumnos,
  alumnos+1,
  alumnos+2,
  alumnos+3,
  alumnos+4,
  alumnos+5,
};
int size = *(&direcciones + 1) - direcciones;

void bubbleSort(void* target[], int size, int (*Comp)(void*, void*));
void insertionSort(void* target[], int size, int (*Comp)(void*, void*));
void selectionSort(void* target[], int size, int (*Comp)(void*, void*));
void mergeSort(void* target[], int size, int (*Comp)(void*, void*));
void quickSort(void* target[], int low, int high, int (*Comp)(void*, void*));
void printElements(void* target[], int size);
int compareAlumnos(void*, void*);

int main(void){
  printf("Datos antes de ordenar %d:\n",size);
  printElements(direcciones,size);
  printf("------------------------\n");
  printf("Datos despues de ordenar:\n");
  //bubbleSort(direcciones, size, compareAlumnos);
  //insertionSort(direcciones, size, compareAlumnos);
  //selectionSort(direcciones, size, compareAlumnos);
  //mergeSort(direcciones, size, compareAlumnos);
  quickSort(direcciones, 0, size-1, compareAlumnos);
  
}



void bubbleSort(void* target[], int size, int (*Comp)(void*, void*)){
  for(int i = 0; i<size-1; i++){
    for(int j = i +1 ; j < size; j++){
      if(Comp(target[i], target[j]) > 0){
        void* temp = target[i];
        target[i] = target[j];
        target[j] = temp;
      }
    }
  }    
}
void insertionSort(void* target[], int size, int (*Comp)(void*, void*)){

}
void selectionSort(void* target[], int size, int (*Comp)(void*, void*)){

}
void mergeSort(void* target[], int size, int (*Comp)(void*, void*)){

}
void quickSort(void* target[],int low, int high, int (*Comp)(void*, void*)){
  int izq = low, der = high, pi = (low+high)/2;
  void* pivote = target[pi];
  printf("m*izq=%d   der=%d    pi=%d*\n",izq,der,pi);
  while(Comp(target[izq],target[der])>0){
    printf("i*izq=%d   der=%d    pi=%d*\n",izq,der,pi);
    while(Comp(target[izq],pivote)<0){
      izq++;
    }
    printf("d*izq=%d   der=%d    pi=%d*\n",izq,der,pi);
    while(Comp(target[der],pivote)<0){
      der--;
    }
    printf("c*izq=%d   der=%d    pi=%d*\n",izq,der,pi);
    if (Comp(target[izq],target[der])<=0){
        void* temporal = target[izq];
        target[izq]= target[der];
        target[der]= temporal;
        izq++;
        der--;
        printf("De %d a %d\n",izq,der);
    }
  }
  printf("r1*izq=%d   der=%d    pi=%d*\n",izq,der,pi);
  if (Comp(target[der],target[low])>0)
      quickSort(target, low, der,Comp);

  printf("r2*izq=%d   der=%d    pi=%d*\n",izq,der,pi);
  if (Comp(target[high],target[izq])>0)
      quickSort(target, izq, high,Comp);
  printElements(direcciones,size);
}
/**
 * compareAlumnos compara a_ref y b_ref
 * Donde los resultados son:
 * 1    =   A es mayor
 * 0    =   A y B son iguales
 * -1   =   B
 * */
int compareAlumnos(void* a_ref, void* b_ref){
  struct Alumno* alumnoA = a_ref;
  struct Alumno* alumnoB = b_ref;
  printf("\tA: id: %d [%d] - <%c> -- ",alumnoA->id,alumnoA->id_grupo,alumnoA->calificacion);
  printf("B: id: %d [%d] - <%c>\n",alumnoB->id,alumnoB->id_grupo,alumnoB->calificacion);
  
  /*
  if(alumnoA->id_grupo==alumnoB->id_grupo&&alumnoA->calificacion==alumnoB->calificacion){
    printf(".0\n");
    return 0;
  }else{
    if(alumnoA->id_grupo > alumnoB->id_grupo &&alumnoA->calificacion > alumnoB->calificacion){
      printf(".1\n");
      return 1;
    }else{
      printf(".-1\n");
      return -1;
    }
  }
  */
  if(alumnoA->id_grupo == alumnoB->id_grupo){
    if(alumnoA->calificacion > alumnoB->calificacion){
      printf("\t.1\n");
      return 1;
    }
    else if(alumnoA->calificacion == alumnoB->calificacion){
      printf("\t.0\n");
      return 0;
    }
    else{
      printf("\t.-1\t");
       printf("%d - %c > ",alumnoA->id_grupo,alumnoA->calificacion);
       printf("%d - %c\n",alumnoB->id_grupo,alumnoB->calificacion);
      return -1;
    }
  }else if(alumnoA->id_grupo > alumnoB->id_grupo){
    printf("\t.1\n");
    return 1;
  }
  else{
    printf("\t.-1\n");
    printf("\t%d - %c > ",alumnoA->id_grupo,alumnoA->calificacion);
    printf("%d - %c\n",alumnoB->id_grupo,alumnoB->calificacion);
    return -1;
  }
}

void printElements(void* target[], int size){
  for(int i=0; i<size; i++){
    struct Alumno* a = target[i];
    //printf("%p\n",target[i]);
    printf("%d - id: %d [%d] - <%c>\n", i,a->id, a->id_grupo, a->calificacion);
  }
}