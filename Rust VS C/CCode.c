#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


struct justIntegers {
    int a;
    int b;
    int c;
};

struct intsAndStrs {
    int uno;
    int dos;
    char tres [20];
};

// Code for Bubble Sort for Integers
void bubbleSortInt(int array[], int size) {
  for (int count = 0; count < size - 1; ++count) {
    for (int i = 0; i < size - count - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}


//Code for Bubble Sort Strings
void bubbleSort(char* arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortStructINT (struct justIntegers intStructArray[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (intStructArray[j].a > intStructArray[j + 1].a) {
                struct justIntegers temp = intStructArray[j];
                intStructArray[j] = intStructArray[j + 1];
                intStructArray[j + 1] = temp;
            }
        }
    }
}

void bubbleSortStructSTR (struct intsAndStrs intStructArray[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(intStructArray[j].tres, intStructArray[j+1].tres) > 0) {
                struct intsAndStrs temp = intStructArray[j];
                intStructArray[j] = intStructArray[j + 1];
                intStructArray[j + 1] = temp;
            }
        }
    }
}

int main() {
// Open integer file and store the data
    FILE *intFile;
    intFile = fopen("integers.txt", "r");
    
    int a, b, c;
    int uno, dos;
    char tres;


    int countINT = 0; // Line counter (result)
    char character; 
    for (character = getc(intFile); character != EOF; character = getc(intFile))
        if (character == '\n') // Increment count if this character is newline
            countINT = countINT + 1;

// Define an array with 10000 places to store the file
    int* intArray = (int*)malloc((countINT + 1) * sizeof(int));
    struct justIntegers* intStructArray= malloc((countINT + 1) * sizeof(struct justIntegers));

    



// Scan the integer file into the array
    fseek(intFile, 0, SEEK_SET);
    int i;
    for (i = 0; i < countINT + 1; i++)
    {
         fscanf(intFile, "%d", &intArray[i]);
    }


// Set up a timer to to time the bubbleSortInt function
    clock_t timeINT;
    timeINT = clock();

    bubbleSortInt (intArray, countINT + 1);

    timeINT = clock() - timeINT;
    double time_taken_INT = ((double)timeINT)/CLOCKS_PER_SEC * 1000;
    printf("C, ");
    printf("Integers, ");
    printf("%d, ", countINT + 1);
    printf("%f\n", time_taken_INT);

// Open string file and store the data as well as prepare array
 FILE *file;
    char **lines = NULL;
    char line[1000];
    int num_lines = 0;
    file = fopen("strings.txt", "r");

    int countSTR = 0; // Line counter (result)
    char c2; 
    for (c2 = getc(file); c2 != EOF; c2 = getc(file))
        if (c2 == '\n') // Increment count if this character is newline
            countSTR = countSTR + 1;

    fseek(file, 0, SEEK_SET);
    while (fgets(line, sizeof(line), file) != NULL) {
        char *new_line = (char *)malloc((strlen(line) + 1) * sizeof(char));
        strcpy(new_line, line);
        char **temp = (char **)realloc(lines, (num_lines + 1) * sizeof(char *));
        lines = temp;
        lines[num_lines] = new_line;
        num_lines++;
    }

if (countSTR <= 50000) {


// Time and output the bubble sort algorithm
    clock_t timeSTR;
    timeSTR = clock();

    bubbleSort (lines, num_lines);

    timeSTR = clock() - timeSTR;
    double time_taken_STR = ((double)timeSTR)/CLOCKS_PER_SEC * 1000;
    
    printf("C, ");
    printf("Strings, ");
    printf("%d, ", countSTR + 1);
    printf("%f\n", time_taken_STR);

}


if (countINT <= 75000){
    fseek(intFile, 0, SEEK_SET);
    int j, counter = 0;
    for (j = 0; j < 6; j++) {   
        while (fscanf(intFile, "%d\n", &a) != EOF) {
            intStructArray[counter].a = a;
            intStructArray[counter].b = a + 1;
            intStructArray[counter].c = a + 2;
            counter++;      
        }
    }

    clock_t timeStructINT;
    timeStructINT = clock();
    bubbleSortStructINT(intStructArray, countINT);
    timeStructINT = clock() - timeStructINT;
    double time_taken_struct_int = ((double)timeStructINT)/CLOCKS_PER_SEC * 1000;
    
    printf("C, ");
    printf("StructINT, ");
    printf("%d, ", countINT + 1);
    printf("%f\n", time_taken_struct_int);

    struct intsAndStrs* intStructSTR= malloc((countINT + 1) * sizeof(struct intsAndStrs));
    fseek(intFile, 0, SEEK_SET);
    int q, counterq = 0;
    for (q = 0; q < 6; q++) {   
        while (fscanf(intFile, "%d\n", &uno) != EOF) {
            intStructSTR[counterq].uno = uno;
            intStructSTR[counterq].dos = uno + 1;
            sprintf(intStructSTR[counterq].tres, "%d", uno);

            counterq++;      
        }
    }

    clock_t timeStructSTR;
    timeStructSTR = clock();
    bubbleSortStructSTR(intStructSTR, countINT);
    timeStructSTR = clock() - timeStructSTR;
    double time_taken_struct_str = ((double)timeStructSTR)/CLOCKS_PER_SEC * 1000;

    printf("C, ");
    printf("StructSTR, ");
    printf("%d, ", countINT + 1);
    printf("%f\n", time_taken_struct_str);
}
}

