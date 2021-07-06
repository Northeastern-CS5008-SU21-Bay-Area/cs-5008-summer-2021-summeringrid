#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// https://www.youtube.com/watch?v=2Ti5yvumFTU&ab_channel=JacobSorber

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
    // ...add other stuff later, maybe
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char* name) {
    int length = strnlen(name, MAX_NAME);           // strnlen - determine the length of a fixed-size string
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = hash_value * name[i] % TABLE_SIZE;           // no standard to judge right or wrong here
    }
    return hash_value;
}

void init_hash_table() {
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // table is empty
}


void print_table() {
    printf("Start...\n");
    for (int i=0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);       // Question: why here integer i use %i to format? Does it should be %d?
        } else if (hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    // linear probing:
    for (int i=0; i< TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;         //Question: what's this for?
        if (hash_table[try] == NULL || 
            hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
    // if (hash_table[index] != NULL) {
    //     return false;
    // }
    // hash_table[index] = p;
    // return true;
}

// find a person if ] in the table by their name
person* hash_table_lookup(char* name) {
    int index = hash(name);
    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == DELETED_NODE) {
            return false; // not here
        }
        if (hash_table[try] != DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE)==0) {
            return hash_table[try];
        }
    }
    return NULL;
    // if (hash_table[index] != NULL &&
    // strncmp(hash_table[index]->name, name, TABLE_SIZE)==0){         // int strncmp(const char *str1, const char *str2, size_t n) compares at most the first n bytes of str1 and str2.
    //     return hash_table[index];
    // } else {
    //     return NULL;
    // }
}

person* hash_table_delete(char* name) {
    int index = hash(name);
    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE)==0) {
            person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;

    // if (hash_table[index] != NULL &&
    // strncmp(hash_table[index]->name, name, TABLE_SIZE)==0){         // int strncmp(const char *str1, const char *str2, size_t n) compares at most the first n bytes of str1 and str2.
    //     person* tmp = hash_table[index];
    //     hash_table[index] = NULL;
    //     return tmp;
    // } else {
    //     return NULL;
    // }
}

int main() {
    init_hash_table();
    print_table();
    person jacob = {.name = "Jacob", .age = 256};
    person kate = {.name = "Kate", .age = 18};
    person mpho = {.name = "Mpho", .age = 27};
    person sarah = {.name = "Sarah", .age = 17};
    person edna = {.name = "Edna", .age = 38};
    person robert = {.name = "Robert", .age = 22};
    person jane = {.name = "Jane", .age = 78};
    person lily = {.name = "Lily", .age = 9};
    person lucy = {.name = "Lucy", .age = 8};

   // when collision occurs, there'r 2 traditional ways that people handle this: one is called 'opening addressing' & one is called 'external chaining
   // opening addressing: simple way rather than search the hash function again when all hashes have been used: 'linear probing'

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&robert);
    hash_table_insert(&jane);
    hash_table_insert(&lily);
    hash_table_insert(&lucy);
    print_table();

    person* tmp = hash_table_lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }
    tmp = hash_table_lookup("George");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    hash_table_delete("Mpho");
    tmp = hash_table_lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    print_table();

    // printf("Jacob => %u\n", hash("Jacobe"));
    // printf("Natalie => %u\n", hash("Natalie"));
    // printf("Sara => %u\n", hash("Sara"));
    // printf("Mpho => %u\n", hash("Mpho"));
    // printf("Tebogo => %u\n", hash("Tebogo"));
    // printf("Ron => %u\n", hash("Ron"));
    // printf("Jane => %u\n", hash("Jane"));
    // printf("Lan => %u\n", hash("Lan"));
    // printf("Bill => %u\n", hash("Bill"));
    return 0;
}