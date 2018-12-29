/*bstree.c

C File for stage1.c by Patrick Tjahjadi */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

#define MAXFIELDLEN 128

// Memory allocate all attributes relating to the particular athlete.
void allocate_values(value_t* values){
    values->id = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->name = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->sex = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->age = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->height = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->weight = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->team = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->noc = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->games = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->year = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->season = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->city = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->sport = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->event = malloc(sizeof(char)*MAXFIELDLEN+1);
    values->medal = malloc(sizeof(char)*MAXFIELDLEN+1);
}

// Copy the values associated from each attribute of the athlete.
void copy_values (value_t* values, char* line, const char* delim){
    strcpy(values->id, strtok(line, delim));
    strcpy(values->name, strtok(NULL, delim));
    strcpy(values->sex, strtok(NULL, delim));
    strcpy(values->age, strtok(NULL, delim));
    strcpy(values->height, strtok(NULL, delim));
    strcpy(values->weight, strtok(NULL, delim));
    strcpy(values->team, strtok(NULL, delim));
    strcpy(values->noc, strtok(NULL, delim));
    strcpy(values->games, strtok(NULL, delim));
    strcpy(values->year, strtok(NULL, delim));
    strcpy(values->season, strtok(NULL, delim));
    strcpy(values->city, strtok(NULL, delim));
    strcpy(values->sport, strtok(NULL, delim));
    strcpy(values->event, strtok(NULL, delim));
    strcpy(values->medal, strtok(NULL, delim));
}

// Function creates a new node upon reaching a leaf of the BST
node_t* new_node (value_t values) {

    node_t *newnode = malloc(sizeof(node_t));
    newnode->values = values;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function inserts a new node to the BST
node_t* insert(node_t *root, value_t values) {

    if (!root){
        root = new_node(values);
    }

    /* Stage 1: Data entries with the same name are pushed to the right of 
    the node */
    else if (strcmp(root->values.name, values.name) <= 0) {
        root->right = insert(root->right, values);  
    } 

    else if (strcmp(root->values.name, values.name) > 0) {
        root->left = insert(root->left, values);
    }

    return root;
}

// Function searches for an athlete looked up from the keyfile in the BST
void search(node_t *root, char *searchname, int *num_comparisons, int *found, 
            FILE* fout) {

    // Traverse along the BST until it reaches a leaf node.
    if (!root) {
        return;
    }

    /* Stage 1: Traverse to the right of the node to search for duplicates
     if found.*/
    else if (strcmp(root->values.name, searchname) == 0) {
        *num_comparisons += 1;
        *found = 1;
        fprintf(fout, "%s −−> ID: %s Sex: %s || Age: %s || Height: %s|| "
        "Weight: %s || Team: %s || NOC: %s || Games: %s || Year: %s || "
        "Season: %s || City: %s || Sport: %s || Event: %s || Medal: %s \n",
        root->values.name, root->values.id, root->values.sex, root->values.age,\
        root->values.height, root->values.weight, root->values.team, root->values.noc,\
        root->values.games, root->values.year, root->values.season, root->values.city,\
        root->values.sport, root->values.event, root->values.medal);
        search(root->right, searchname, num_comparisons, found, fout);
    }

    else if (strcmp(root->values.name, searchname) < 0) {
        *num_comparisons += 1;
        search(root->right, searchname, num_comparisons, found, fout);
    }

    else {
        *num_comparisons += 1;
        search(root->left, searchname, num_comparisons, found, fout);
    }
}

// Function frees all memory within the node and values
void memory_cleanup(node_t *node, value_t *values){
    free(node);
    free(values->id);
    free(values->name);
    free(values->age);
    free(values->sex);
    free(values->height);
    free(values->weight);
    free(values->team);
    free(values->noc);
    free(values->games);
    free(values->year);
    free(values->season);
    free(values->city);
    free(values->sport);
    free(values->event);
    free(values->medal);
}