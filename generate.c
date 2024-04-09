#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char** split(char* input, int* nb_strs) {
  size_t len = strlen(input);
  *nb_strs = 0;
  size_t progress = 0;

  char** output = NULL;


  for (int i = 0; i < len + 1; i++) {
    if (input[i] == ' ' || input[i] == '\0') {
      *nb_strs = *nb_strs + 1;
      output = realloc(output, *nb_strs * sizeof(char*));
      char* word = calloc(progress+1, sizeof(char));
      strncpy(word, input + (i - progress), progress);
      output[*nb_strs - 1] = word;
      progress = 0;
    }
    else {
      progress++;
    }
  }

  return output;
}

char* fileToString(char* path) {
    FILE* fptr;
    char* line = NULL;
    size_t size = 0;

    char* allLines = NULL;
    size_t totalSize = 0;

    if ((fptr = fopen(path, "r")) == NULL) {
        printf("Error :/\n");
        return NULL;
    }

    while ((getline(&line, &size, fptr)) != -1) {
        int len = strlen(line);

        if (len) {
            line[len - 1] = ' ';
            totalSize += len - 1;
            allLines = realloc(allLines, totalSize * sizeof(char));
            strcat(allLines, line);
        }
        else {printf("Go fuck urself\n");}
    }
    free(line);
    return allLines;
}

char* randomUsername(char* dic1, char* dic2) {
    srand(time(NULL));

    int nbStrings;
    char* dicChoice[2] = {dic1, dic2};

    char* username = calloc(0, 0);
    size_t usernameSize = 0;
    int r;

    char* word;
    for (int i = 0; i < 2; i++) {
        char** arr = split(dicChoice[i], &nbStrings);
        r = rand() % (nbStrings - 1);
        word = calloc(strlen(arr[r]), sizeof(char));
        strcpy(word, arr[r]);
        usernameSize += strlen(word);
        char* tmpusername = realloc(username, usernameSize * sizeof(char));
        if (tmpusername) {
            username = tmpusername;
        }
        else {printf("Buy some RAM you damn fool\n"); return "VeryPoorGuy";}
        word[0] -= 32;
        strcat(username, word);
    }
    free(word);

    return username;
}

int main(void) {
    char* adj = fileToString("adjectives.txt");
    char* nouns = fileToString("nouns.txt");
    char* user = randomUsername(adj, nouns);
    free(adj);
    free(nouns);
    printf("%s\n", user);
    free(user);
    return 0;
}
