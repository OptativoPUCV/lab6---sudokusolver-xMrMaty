#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  for(int i=0;i<9;i++){
    int fil[10]={0};
    for(int j=0;j<9;j++){
      int num=n->sudo[i][j];
      if(num!=0){
        if(fil[num]==1){
          return 0;
        }
        fil[num]=1;
      }
    }
  }

  for(int j=0;j<9;j++){
    int col[10]={0};
    for(int i=0;i<9;i++){
      int num=n->sudo[i][j];
      if(num!=0){
        if(col[num==1]){
          return 0;
        }
        col[num]=1;
      }
    }
  }

  for(int k=0;k<9;k++){
    int mat[10]={0};
    for(int i=k/3*3;i<k/3*3+3;i++){
      for(int j=k%3*3;j<k%3*3+3;j++){
        int num=n->sudo[i][j];
        if(num!=0){
          if(mat[num]==1){
            return 0;
          }
          mat[num]=1;
        }
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int fila_vacia=-1;
  int columna_vacia=-1;
  for(int fila=0;fila<9;fila++){
    for(int columna=0;columna<9;columna++){
      if(n->sudo[fila][columna] == 0){
        fila_vacia=fila;
        columna_vacia=columna;
        break;
      }
    }
    if (fila_vacia!=-1){
      break;
    }
  }
  if(fila_vacia==-1){
    return list;
  }

  for(int num=1;num<=9;num++){
    Node* adj_node=copy(n);
    adj_node->sudo[fila_vacia][columna_vacia] = num;
    if(is_valid(adj_node)){
      pushBack(list, adj_node);
    }else{
      free(adj_node);
    }
  }
  return list;
}


int is_final(Node* n){
  for (int fila=0;fila<9;fila++){
    for(int columna=0;columna<9;columna++){
      if(n->sudo[fila][columna]==0){
        return 0;
      }
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  /*
  List* stack=createList();
  pushBack(stack, initial);

  while(!is_empty(stack)){
    Node* current=(Node*)last(stack);
    popBack(stack);

    if(is_final(current)){
      clean(stack);
      return current;
    }

    int fila_vacia=-1;
    int columna_vacia=-1;
    for(int fila=0;fila<9;fila++){
      for(int columna=0;columna<9;columna++){
        if(current->sudo[fila][columna]==0){
          fila_vacia=fila;
          columna_vacia=columna;
          break;
        }
      }
      if(fila_vacia!=-1){
        break;
      }
    }

    if(fila_vacia!=-1){
      for(int num=1;num<=9;num++){
        Node* adj_node=copy(current);
        adj_node->sudo[fila_vacia][columna_vacia]=num;

        if(is_valid(adj_node)){
          pushBack(stack, adj_node);
        }else{
          free(adj_node);
        }
      }
    }
  }*/
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/