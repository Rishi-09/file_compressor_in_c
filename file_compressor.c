#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a file using RLE
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    if (!inFile || !outFile) {
        printf("Error opening files.\n");
        exit(1);
    }

    char currentChar, prevChar;
    int count = 0;

    // Read the first character
    prevChar = fgetc(inFile);
    if (prevChar == EOF) {
        printf("Input file is empty.\n");
        fclose(inFile);
        fclose(outFile);
        return;
    }

    count = 1;
    while ((currentChar = fgetc(inFile)) != EOF) {
        if (currentChar == prevChar) {
            count++;
        } else {
            // Write the previous character and its count
            fprintf(outFile, "%c%d", prevChar, count);
            prevChar = currentChar;
            count = 1;
        }
    }
    // Write the last character and its count
    fprintf(outFile, "%c%d", prevChar, count);

    printf("File compressed successfully.\n");
    fclose(inFile);
    fclose(outFile);
}

// Function to decompress a file compressed using RLE
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    if (!inFile || !outFile) {
        printf("Error opening files.\n");
        exit(1);
    }

    char ch;
    int count;

    while (fscanf(inFile, "%c%d", &ch, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, outFile);
        }
    }

    printf("File decompressed successfully.\n");
    fclose(inFile);
    fclose(outFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) {
        compressFile(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompressFile(argv[2], argv[3]);
    } else {
        printf("Invalid operation. Use 'compress' or 'decompress'.\n");
        return 1;
    }

    return 0;
}

