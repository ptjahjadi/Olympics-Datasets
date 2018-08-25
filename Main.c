#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFIELDLEN 128
#define MAXRECORDLEN 512
#define DELIMITER 2

typedef struct{
    value_t* values;
    node_t* left;
    node_t* right;
} node_t;

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


node_t* insert(node_t *root, value_t *values) {
    if (root == NULL) {
        root = malloc(sizeof (node_t));
        root->values = values;
        root->left = root->right = NULL;
    } else if (strcmp(root->values->name, values->name) ) {
        root->right = insert(root->right, values);  
    } else {
        root->left = insert(root->left, values);
    }

    return root;
}

node_t* search(node_t *root, char *searchname, int *num_comparisons) {
    *num_comparisons += 1;
    if (root->values->name == searchname) {
        return root;
    }
    else if (root->values->name > searchname) {
            return search(root->right, searchname);
    }
    else {
        return search(root->left, searchname);
    }
}

int main(int argc, char *argv[]) {
    char line[MAXRECORDLEN+1];
    const char delim[DELIMITER] = ",";
    char *token;
    int num_comparisons = 0;
    node_t *node = NULL;
    value_t *values;
    values = malloc(sizeof(value_t));
    FILE *fp;
    fp = fopen("testfile.txt", "r");
    while(fgets(line, MAXRECORDLEN+1, fp)){
        values->id = strtok(line, delim);
        values->name = strtok(NULL, delim);
        values->sex = strtok(NULL, delim);
        values->age = strtok(NULL, delim);
        values->height = strtok(NULL, delim);
        values->weight = strtok(NULL, delim);
        values->team = strtok(NULL, delim);
        values->noc = strtok(NULL, delim);
        values->games = strtok(NULL, delim);
        values->year = strtok(NULL, delim);
        values->season = strtok(NULL, delim);
        values->city = strtok(NULL, delim);
        values->sport = strtok(NULL, delim);
        values->event = strtok(NULL, delim);
        values->medal = strtok(NULL, delim);
        insert(node, values);
    }
    char searchname[MAXFIELDLEN+1];
    while (scanf("%s", &searchname) != NULL) {
        search(node, searchname, &num_comparisons);
        // scanf("%[^s]\n", &searchname); (without while)
    }



}