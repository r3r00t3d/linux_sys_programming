/* header file for doubly linked list*/
#ifndef DLL_H
#define DLL_H
typedef struct dll_node_ {
	void* data;
	struct dll_node_* left;
	struct dll_node_* right;
} dll_node_t;

typedef struct dll_{
	dll_node_t* head;
} dll_t;

/* Public Function declaration to create and return
 *  /* a new empty doubly linked list*/
dll_t* get_new_dll();

int add_data_to_dll (dll_t* dll, void* app_data);

/* 0 on success, -1 on failure */
int remove_data_from_dll_by_data_ptr(dll_t* dll, void* data);

/*return 0 if empty, -1 if not*/
int is_dll_empty(dll_t* dll);

/* delete nodes*/
void drain_dll(dll_t* dll);
#endif