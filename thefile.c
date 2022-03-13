#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50

int main(void) {
    int numPeeps, total, eachPeepPay;
    char *nameTemp, **peep;

    nameTemp = (char *)malloc(MAX_NAME_SIZE * sizeof(char));

    printf("No' of peeps: ");
    scanf("%d", &numPeeps);

    peep = (char **)malloc(numPeeps * sizeof(char **));

    for (int i = 0; i < numPeeps; i++) {
        printf("Name of peep %d: ", i + 1);
        scanf("%s", nameTemp);
        *(peep + i) = (char *)malloc((strlen(nameTemp) + 1) * sizeof(char));
        strcpy(*(peep + i), nameTemp);
        *(*(peep + i) + strlen(nameTemp)) = '\0';
    }

    free(nameTemp);

    printf("Total: ");
    scanf("%d", &total);

    printf("Each person pays: %d\n", total / numPeeps);

    printf("Correction, %s is a lucky bastard\nOthers bout to pay %d\n", *(peep + (rand() % numPeeps)), total / (numPeeps - 1));

    return 0;
}