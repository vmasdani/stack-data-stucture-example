#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct Node {
  char content;
  struct Node *next;
} Node;

typedef struct Arr {
  int size;
  Node *content;
} Arr;

int select(Arr *arr);
void input_data(Arr *arr);
void show_data(Arr *arr);
void push_arr(Arr *arr, char c);
void retract(Arr *arr);
void unshift(Arr *arr);
void unshift_arr(Arr *arr, char c);

int main() {
  Arr *arr = (Arr*)malloc(sizeof(Arr));
 
  select(arr);
}

int select(Arr *arr) {
  char sel_menu;
  
  system(CLEAR);
  show_data(arr);
  printf("Select menu:\n");
  printf("1. Push data\n");
  printf("2. Retract\n");
  printf("3. Unshift\n");
  printf("4. Exit\n");

  scanf(" %c", &sel_menu);
  printf("Selected: %c\n", sel_menu);

  switch(sel_menu) {
    case '1':
      input_data(arr);
      break;
  
    case '2':
      retract(arr);
      break;

    case '3':
      unshift(arr);
      break;

    default:
      return 0;
      break;
  }

  select(arr);
}

void traverse(Node *node, int *counter_ptr) {
  printf("%c", node->content);
  ++ *counter_ptr;

  if(node->next != NULL) {
    traverse(node->next, counter_ptr);
  }
}

void show_data(Arr *arr) {
  int counter = 0;
  
  printf("Data: ");

  if(arr->content != NULL) {
    traverse(arr->content, &counter);
    
    printf(", size: %d\n", counter);
  } else {
    printf("NO DATA\n");
  }
}

void input_data(Arr *arr) {
  char c;
  
  system(CLEAR);
  printf("Input char to push back: ");
  scanf(" %c", &c);

  push_arr(arr, c);
}

void unshift(Arr *arr) {
  char c;
  
  system(CLEAR);
  printf("Input char to  unshift: ");
  scanf(" %c", &c);

  unshift_arr(arr, c);
}

void unshift_arr(Arr *arr, char c) {
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->content = c;
  
  if(arr->content == NULL) {
    arr->content = new_node;
    printf("Input: %c\n", new_node->content);
    printf("First push!\n");
  } else {
    Node *tail = arr->content;
    new_node->next = tail;

    arr->content = new_node;
  }
}

void push_arr(Arr *arr, char c) {
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->content = c;
  
  if(arr->content == NULL) {
    arr->content = new_node;
    printf("Input: %c\n", new_node->content);
    printf("First push!\n");
  } else {
    Node *cur_node = arr->content;

    while(cur_node->next != NULL) {
      cur_node = cur_node->next;
    }
    
    cur_node->next = new_node;
  }
}

void retract(Arr *arr) {
  if(arr->content != NULL) {
    Node *cur_node = arr->content;
    
    /* Check head next first */
    if(cur_node->next == NULL) {
     free(arr->content);
     arr->content = NULL;
    } else {
      while(cur_node != NULL) {
        if(cur_node->next !=  NULL) {
          if(cur_node->next->next == NULL) { /* Peep last node if empty */
            free(cur_node->next);
            cur_node->next = NULL;
          }
        }

        cur_node = cur_node->next;
      }
    }
  }
}
