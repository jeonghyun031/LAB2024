#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define BUFFER_SIZE 5

typedef struct {
    int key;
} Record;

void replacementSelection(int input[], int inputSize) {
    Record buffer[BUFFER_SIZE];
    bool written[BUFFER_SIZE];
    bool frozen[BUFFER_SIZE];
    int lastKey = INT_MIN;
    int inputIndex = 0;
    int runCount = 1;

    // 초기화
    for (int i = 0; i < BUFFER_SIZE; i++) {
        written[i] = true;
    }

    // 초기 버퍼 채우기
    int i = 0;
    do {
        if (inputIndex < inputSize) {
            buffer[i].key = input[inputIndex++];
            written[i] = false;
        }
        i++;
    } while (inputIndex < inputSize && i < BUFFER_SIZE);

    printf("Run %d: ", runCount);

    while (inputIndex < inputSize || i > 0) {
        for (int j = 0; j < BUFFER_SIZE; j++) {
            if (!written[j]) {
                frozen[j] = false;
            }
        }

        bool unfrozenRemain;
        do {
            unfrozenRemain = false;
            int smallestUnfrozen = INT_MAX;
            int smallestIndex = -1;

            for (int j = 0; j < BUFFER_SIZE; j++) {
                if (!frozen[j] && !written[j] && buffer[j].key < smallestUnfrozen) {
                    smallestUnfrozen = buffer[j].key;
                    smallestIndex = j;
                    unfrozenRemain = true;
                }
            }

            if (unfrozenRemain) {
                printf("%d ", buffer[smallestIndex].key);
                lastKey = buffer[smallestIndex].key;
                written[smallestIndex] = true;
                frozen[smallestIndex] = true;

                if (inputIndex < inputSize) {
                    buffer[smallestIndex].key = input[inputIndex++];
                    written[smallestIndex] = false;
                    if (buffer[smallestIndex].key > lastKey) {
                        frozen[smallestIndex] = false;
                    }
                } else {
                    i--;
                }
            }
        } while (unfrozenRemain);

        // 새로운 런 시작
        bool allWritten = true;
        for (int j = 0; j < BUFFER_SIZE; j++) {
            if (!written[j]) {
                allWritten = false;
                break;
            }
        }

        if (!allWritten && inputIndex < inputSize) {
            printf("\nRun %d: ", ++runCount);
        }
    }
}