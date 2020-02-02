#include "dll.h"
#include <memory.h>
#include <stdlib.h>

dll_t* get_new_dll() {
	dll_t* dll = calloc(1, sizeof(dll_t));
	dll->head = NULL;
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

}
