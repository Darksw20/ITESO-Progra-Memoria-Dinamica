#include <stdio.h>

struct Alumno {
    int id;
    int id_grupo;
    char calificacion;
};

void GenericBubbleSort(void* target[],int elementCount, int (*Comp)(void*, void*));
void GenericQuickSort(void* target[],int izquierda, int derecha,int (*Comp)(void*, void*));
int CompareAlumnos(void*, void*);
int CompareAlumnos(void*, void*);

int main(void)
{
    struct Alumno alumnos[] = {
            {683076, 1, 'F'},
            {123112, 1, 'A'},
            {123231, 3, 'A'},
            {224123, 2, 'B'},
            {441231, 1, 'A'},
            {448123, 1, 'A'},
    };

    int enteros[] = {10, 45, 3, 9, 7, 1, 2};

    void* direcciones[] = {
            alumnos,
            alumnos+1,
            alumnos+2,
            alumnos+3,
            alumnos+4,
            alumnos+5,
    };
    for(int i=0; i<7; i++)
    {
        //printf("%d\n", enteros[i]);
        struct Alumno* a = direcciones[i];
       printf("id: %d [%d] - <%c> ", a->id, a->id_grupo, a->calificacion);
    }
    //GenericBubbleSort(direcciones, 6, CompareAlumnos);
    GenericQuickSort(direcciones, 0, 7,CompareAlumnos);
    for(int i=0; i<7; i++)
    {
        //printf("%d\n", enteros[i]);
        struct Alumno* a = direcciones[i];
       printf("id: %d [%d] - <%c>\n", a->id, a->id_grupo, a->calificacion);
    }
}

int CompareAlumnos(void* a_ref, void* b_ref)
{
    struct Alumno* alumnoA = a_ref;
    struct Alumno* alumnoB = b_ref;

    if(alumnoA->id_grupo == alumnoB->id_grupo)
    {
        if(alumnoA->calificacion > alumnoB->calificacion)
            return 1;
        else if(alumnoA->calificacion == alumnoB->calificacion)
            return 0;
        else
            return -1;

    } else if(alumnoA->id_grupo > alumnoB->id_grupo)
        return 1;
    else
        return -1;

}

void GenericBubbleSort(void* target[],int elementCount, int (*Comp)(void*, void*))
{
    for(int i = 0; i<elementCount-1; i++)
        for(int j = i +1 ; j < elementCount; j++)
            if(Comp(target[i], target[j]) > 0)
            {
                // target i es mayot a target j
                void* temp = target[i];
                target[i] = target[j];
                target[j] = temp;
            }
}


void GenericQuickSort(void* target[],int izquierda, int derecha, int (*Comp)(void*, void*))
{
    int izq = izquierda, der = derecha,temporal;
    int pivote = target[(izquierda+derecha)/2];

        while (Comp(izq,der)){
            while (target[izq]<pivote){
                izq++;
            }
            while (target[der]>pivote){
                der--;
            }
        if (Comp(izq,der)){
            temporal = target[izq];
            target[izq]= target[der];
            target[der]= temporal;
            izq++;
            der--;
        }

    }
        if (Comp(izq,der))
            GenericQuickSort(target, izquierda, der);
        if (Comp(izq,der))
            GenericQuickSort(target, izq, derecha);
}