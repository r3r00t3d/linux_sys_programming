#include "dll.h"
#include <stdlib.h>
#include <memory.h>

/* 0 on success, -1 on failure */
int remove_data_from_dll_by_data_ptr(dll_t* dll, void* data){
  if (!dll || !data) {
    return EXIT_FAILURE;
  }

  dll_node_t* start = dll->head;
  while(start) {
    if (start->data == data) {
      if (start->left) start->left->right = start->right; 
      if (start->right) start->right->left = start->left;
      free(start);
      return EXIT_SUCCESS;
    }
    start = start->right;
  }
  return EXIT_FAILURE;
}

/*return 0 if empty, -1 if not*/
int is_dll_empty(dll_t* dll) {
  if(!dll->head) {
    return 0;
  } else {
    return -1;
  }
 
}

/* delete nodes*/
void drain_dll(dll_t* dll){
  dll_node_t* head = dll->head;
  while(head) {
    dll_node_t* temp_node = head;
    head = head->right;
    free(temp_node);
  }
  dll->head = 0;
}