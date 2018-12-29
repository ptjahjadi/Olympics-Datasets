/* bstree2.h
C Header file for stage2.c by Patrick Tjahjadi */

/* Struct to contain the attributes of an athlete */
typedef struct{
    char* id;
    char* name;
    char* sex;
    char* age;
    char* height;
    char* weight;
    char* team;
    char* noc;
    char* games;
    char* year;
    char* season;
    char* city;
    char* sport;
    char* event;
    char* medal;
} value_t;

typedef struct node node_t;

// Struct to declare a node for a recursive BST and contain any duplicates
struct node{
    value_t values;
    node_t* left;
    node_t* right;
    node_t* duplicate;
};

// Function Prototypes:
void allocate_values(value_t* values);

void copy_values(value_t* values, char* line, const char* delim);

node_t* new_node (value_t values);

node_t* insert(node_t *root, value_t values);

void search(node_t *root, char *searchname, int *num_comparisons, int *found, FILE* fout);

void memory_cleanup(node_t *node, value_t *values);