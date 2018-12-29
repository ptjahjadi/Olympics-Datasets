/* stage2.c

OLYMPICS DATASETS
Program constructs a binary search tree used to retrieve information about
a particular athlete. A linked list within a node is created for duplicates.

To run the program, type in the command prompt:
dict1 datafile outputfile < keyfile

Program created by Patrick Tjahjadi (890003)
September 2018, The University of Melbourrne
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree2.h"

#define MAXFIELDLEN 128 // Length of each field does not exceed 128 chars
#define MAXRECORDLEN 512 // Length of each record does not exceed 512 chars
#define DELIMITER 2 // Datasets are separated by commas

int main(int argc, char *argv[]) {

    char line[MAXRECORDLEN+1];
    char searchname[MAXFIELDLEN+1];
    const char delim[DELIMITER] = ",";
    int num_comparisons = 0;
    int found = 0;
    node_t *node = NULL;
    value_t values;
    //fp is regarded as datafile, while fout is regarded as output file
    FILE *fp, *fout;
    fp = fopen(argv[1], "r");
    fout = fopen(argv[2], "w+");
    
    // Retrieve every entry in the datafile and insert them into the BST
    while(fgets(line, MAXRECORDLEN+1, fp)){
        allocate_values(&values);
        copy_values(&values, line, delim);
        node = insert(node, values);
    }

    // Search for name(s) from the keyfile and traverse the BST
    while (scanf("%[^\n]\n", searchname) != EOF) {
        // Assign a null byte for each end-of-line to progress the while loop
        if (searchname[strlen(searchname) - 1] == '\n') {
            searchname[strlen(searchname) - 1] = '\0';
        }
        search(node, searchname, &num_comparisons, &found, fout);
        if (found == 0) {
            fprintf(fout, "%s --> NOTFOUND\n\n", searchname);
        }
        printf("%s --> %d\n", searchname, num_comparisons); 
        num_comparisons = 0;
        found = 0;
    }
    memory_cleanup(node, &values);
    fclose(fp);
    fclose(fout);
    return 0;
}