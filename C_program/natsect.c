void naturalSelection(const char* inputFile, const char* outputPrefix) {
    FILE *input, *output;
    char buffer[BUFFER_SIZE];
    char prevRecord[BUFFER_SIZE] = "";
    int runCount = 0;
    char outputFileName[256];

    input = fopen(inputFile, "r");
    if (input == NULL) {
        return;
    }

    while (fgets(buffer, sizeof(buffer), input) != NULL) {
        if (strcmp(buffer, prevRecord) < 0 || strlen(prevRecord) == 0) {
            if (runCount > 0) {
                fclose(output);
            }
            sprintf(outputFileName, "%s_%d.txt", outputPrefix, ++runCount);
            output = fopen(outputFileName, "w");
            if (output == NULL) {
                fclose(input);
                return;
            }
        }
        fputs(buffer, output);
        strcpy(prevRecord, buffer);
    }

    fclose(input);
    if (runCount > 0) {
        fclose(output);
    }
}