#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double * generateArray(int length, double min, double max);
void printArray(double * array, int length);
double calculateArithmeticalMean(double * array, int length);
int findCountOfNumbersBiggerThanNumber(double * array, int length, double number);
int findIndexOfFirstNegative(double * array, int length);
double absSumOfArrayElements(double * array, int length, int startIndex);

int main() {
    int arrayLength = 10;
    srand(time(NULL));

    double * array = generateArray(arrayLength, -15, 15);
    printArray(array, arrayLength);

    double arithmeticalMeanOfArray = calculateArithmeticalMean(array, arrayLength);
    int countOfElementsBiggerThanArithmeticalMean = findCountOfNumbersBiggerThanNumber(array, arrayLength, arithmeticalMeanOfArray);

    printf("Arithmetical mean is %lf\n", arithmeticalMeanOfArray);
    printf("The count of elements greater than the arithmetic mean is %d\n\n", countOfElementsBiggerThanArithmeticalMean);

    int indexOfFirstNegativeElement = findIndexOfFirstNegative(array, arrayLength);

    if (indexOfFirstNegativeElement != -1) {
        double absSumOfElements = absSumOfArrayElements(array, arrayLength, indexOfFirstNegativeElement);
        printf("The sum of elements after the first negative number is %lf\n", absSumOfElements);
    } else {
        printf("The sum of elements after the first negative number is 0\n");
    }

    return 0;
}

double * generateArray(int length, double min, double max) {
    double * array = (double * ) malloc(sizeof(double) * length);
    int index;

    for (index = 0; index < length; index++) {
        array[index] = (double) rand() * (max - min) / (double) RAND_MAX + min;
    }

    return array;
}

void printArray(double * array, int length) {
    int index;

    for (index = 0; index < length; index++) {
        printf("%.2lf ", array[index]);
    }

    printf("\n");
}

double calculateArithmeticalMean(double * array, int length) {
    int index;
    double sumOfNumbers = 0;

    for (index = 0; index < length; index++) {
        sumOfNumbers += array[index];
    }

    return sumOfNumbers / length;
}

int findCountOfNumbersBiggerThanNumber(double * array, int length, double number) {
    int index;
    int countOfElements = 0;

    for (index = 0; index < length; index++) {
        if (array[index] > number) {
            countOfElements++;
        }
    }

    return countOfElements;
}

int findIndexOfFirstNegative(double * array, int length) {
    int index;

    for (index = 0; index < length; index++) {
        if (array[index] < 0) {
            return index;
        }
    }

    return -1;
}

double absSumOfArrayElements(double * array, int length, int startIndex) {
    int index;
    double sumOfElements = 0;

    for (index = startIndex; index < length; index++) {
        sumOfElements += fabs(array[index]);
    }

    return sumOfElements;
}
