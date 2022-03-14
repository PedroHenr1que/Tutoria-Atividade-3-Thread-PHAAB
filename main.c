#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define QTD_THREADS 3

int maxResult, minResult;
float averageResult;
int numbers[0];

void *max(void *amount);
void *min(void *amount);
void *average(void *amount);

int main(void) {

        pthread_t threads[QTD_THREADS];
        int retCreation[QTD_THREADS];
        int amountValues;
        
        printf("Numbers amount: ");
        scanf("%d", &amountValues);

        for (int i = 0; i < amountValues; i++)
        {
                printf("\nNumber %d: ",i+1);
                scanf("%d", &numbers[i]);
        }

        pthread_create(&(threads[0]), NULL, max, (void *)(&(amountValues)));
        pthread_join(threads[0], NULL);

        pthread_create(&(threads[1]), NULL, min, (void *)(&(amountValues)));
        pthread_join(threads[1], NULL);

        pthread_create(&(threads[2]), NULL, average, (void *)(&(amountValues)));
        pthread_join(threads[2], NULL);

        printf("\nThe average values is %0.2f", averageResult);
        printf("\nThe maximum values is %d", maxResult);
        printf("\nThe minimum values is %d\n", minResult);

        return 0;
}

void *max(void *amount) {

        int *internAmount = (int *)amount;

        for (int i = 0; i < *internAmount; i++) {

                if (i == 0) {
                        maxResult = numbers[i];
                
                } else if (numbers[i] > maxResult) {
                        maxResult = numbers[i];
                        
                }    
        }

        return NULL;
}

void *min(void *amount) {

        int *internAmount = (int *)amount;

        for (int i = 0; i < *internAmount; i++) {

                if (i == 0) {
                        minResult = numbers[i];
                
                } else if (numbers[i] < minResult) {
                        minResult = numbers[i];
                        
                }    
        }

        return NULL;
}

void *average(void *amount) {
        int *internAmount = (int *)amount;
        int total = 0;

        for (int i = 0; i < *internAmount; i++) {
                total += numbers[i];
        }

        averageResult = total/(float)*internAmount;

        return NULL;
}