#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};

typedef struct Node* Node_ref;

// Crea un nuevo nodo con valor 'value' y retorna la referencia.
Node_ref newNode(int value);

// Imprime todos los valores de la lista
void PrintList(Node_ref node);

// Imprime todos los valores de la lista en orden inverso
void PrintListReverse(Node_ref node);

// libera la memoria de todos los elementos de una lista exceptuando el primero (first)
void DestroyList(Node_ref first);

// Agrega un nodo 'newNode' a la lista
void AddNode(Node_ref node, Node_ref newNode);

// Elimina el nodo 'nodeToRemove' de la lista, regresa 1 si se eliminó, 0 si no se eliminó.
int RemoveNode(Node_ref node, int nodeValue);

int main()
{

  // Generamos el nodo inicial de la lista
  struct Node first = {
    .value = 25,
    .next = NULL
  };
  Node_ref first_ref = &first;

  AddNode(first_ref, newNode(12));
  AddNode(first_ref, newNode(13));
  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(-123));

  PrintList(first_ref); // [25]->[12]->[13]->[5]->[-123]
  int wasRemoved = RemoveNode(first_ref, 5);

  if(wasRemoved)
    printf("\nSi eliminamos el 5!\n");
  else
    printf("\nNo eliminamos el 5!\n");

  PrintListReverse(first_ref); // [-123]->[13]->[12]->[25]
  DestroyList(first_ref); // libera la memoria de los nodos adicionales
  return 0;
}

Node_ref newNode(int value)
{
  Node_ref new = malloc(sizeof(struct Node));
  if(new == NULL)
    exit(EXIT_FAILURE);
  new->value = value;
  new->next = NULL;
  return new;
}

void PrintList(Node_ref node)
{
  while(node != NULL)
  {
    printf("[%d]->", node->value);
    node = node->next;
  }
}

void PrintListReverse(Node_ref node)
{
    Node_ref first = node;
    int listSize = 0;
    while(node->next != NULL)
    {
        node = node->next;
        listSize++;
    }
    node = first;
    for(int i = listSize;i>=0;i--){
        for(int j = 0;j<i;j++){
            node = node->next;
        }
        printf("[%d]->", node->value);
        node = first;
    }
  // DONE: Implementar esto :)
}

void DestroyList(Node_ref first)
{
  // ToDo: Implementar esto :)
}

void AddNode(Node_ref first, Node_ref newNode)
{
    while(first->next != NULL)
    {
        first = first->next;
    }
    first->next = newNode;
  // DONE: Implementar esto :)
}

int RemoveNode(Node_ref first, int nodeValue)
{
    Node_ref node = first;
    while(node->next->value != nodeValue){
        node = node->next;
    }
    node->next = node->next->next;
    node = first;
    while(node->next != NULL){
        if(node->value == nodeValue){
            return 0;
        }
        node = node->next;
    }
    return 1;
  // DONE: Implementar esto :)
}