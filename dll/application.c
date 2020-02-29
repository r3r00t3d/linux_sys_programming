#include "dll.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person_ {
    char name[32];
    int age;
    int weight;
} person_t;

static void print_person_details(person_t* person) {
    printf("Name = %s\n", person->name);
    printf("Age = %d\n", person->age);
    printf("Weight = %d\n", person->weight);
}

static void print_person_db(dll_t* person_db) {
    if(!person_db || !person_db->head) return;

    dll_node_t* head = person_db->head;
    person_t* data = 0;

    while(head) {
        data = head->data;
        print_person_details(data);
        head = head->right;
    }

}

int main(int argc, char* argv) {
    person_t* person1 = calloc(1, sizeof(person_t));
    // pointer's lifetime is until enclosing main
    person1 = & (person_t) {
        .name = "Martyr",
        .age = 36,
        .weight = 92
    };
    person_t *person2 = calloc(1, sizeof(person_t));
    person2 = & (person_t) {
        .name = "Vicar",
        .age = 25,
        .weight = 71
    }; 
    person_t *person3 = calloc(1, sizeof(person_t));
     person3 = & (person_t) {
        .name = "Father",
        .age = 55,
        .weight = 78
    }; 

    dll_t* person_db = get_new_dll();
    add_data_to_dll(person_db, person1);
    add_data_to_dll(person_db, person2);
    add_data_to_dll(person_db, person3);

    remove_data_from_dll_by_data_ptr(person_db, person2);
    if (is_dll_empty(person_db)) {
        printf("Persondb has some data!\n");
    }

    print_person_db(person_db);

    drain_dll(person_db);

    if (!is_dll_empty(person_db)) {
        printf("Persondb is empty!\n");
    }

    print_person_db(person_db);

    return 0;

}