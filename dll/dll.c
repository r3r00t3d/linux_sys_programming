#include "dll.h"
#include <memory.h>
#include <stdlib.h>

dll_t* get_new_dll() {
	dll_t* dll = calloc(1, sizeof(dll_t));
	dll->head = 0;
	return dll;
}

/**
 * @brief implementation of the function to add data
 * to doubly linked list
 *
 * @param dll is a double linked list
 * @param app_data is data that will be inserted
 *
 * @return return status
 */
int add_data_to_dll (dll_t *dll, void *app_data){
	if(!dll || !app_data) return EXIT_FAILURE;

	dll_node_t* dll_new_node = calloc(1, sizeof(dll_node_t));

	dll_new_node->left = 0;
	dll_new_node->right = 0;
	dll_new_node->data = app_data;

	if(!dll->head) {
		dll->head = dll_new_node;
		return EXIT_SUCCESS;
	}

	dll_node_t* first_node = dll->head;
	dll_new_node->right = first_node;
	first_node->left = dll_new_node;
	dll->head = dll_new_node;
	return EXIT_SUCCESS;

}
