//
//  main.cpp
//  Assignment-1
//
//  Created by Kyla Wilson on 8/31/20.
//  Copyright © 2020 Kyla Wilson. All rights reserved.

#include <iostream>
#include <ctime>
#include <stdlib.h>

void GenerateElementsForArr(int* arr, int maxRange, const int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = (1 + (rand() % maxRange));
    }
}

const int GetUniquenessCount(const int* arr, const int size) {
    int count = 0;

    for(int i = 0; i <= (size - 2); i++) {
        for(int j = i + 1; j <= (size - 1); j++) {
            count++;
            if (arr[i] == arr[j]) return count;
        }
    }
    return count;
}

const double DetermineAverageComparision(const int m, int size) { // This function will determine avg comparision
    double averageComparisionCount = 0.0;

    for(int round = 0; round < 10000; round++) { // Will comparsion 10000 times
        int* arr = new int[size]; // Instatiating arr

        GenerateElementsForArr(arr, m, size); // Generating elements

        // Uniqueness code here...
        averageComparisionCount += GetUniquenessCount(arr, size);

        delete[] arr; // Deleting arr
    }

    return averageComparisionCount / 10000;
}

int main(int argc, const char * argv[]) {
    srand((unsigned) time(0)); // Seed for timing

    const int M1 = 1400, M2 = 14000; // m constants

    // m1
    std::cout << "M1" << std::endl;
    for(double index = 0.1; index <= 1; index += 0.1) {
        const double avgComparsionForN1 = DetermineAverageComparision(M1, (int)(M1 * index));
        std::cout << "Avg. comparisions for N1 at " << index << ": "<< avgComparsionForN1 << std::endl;
    }

    // m2
    std::cout << "\nM2" << std::endl;
    for(double index = 0.1; index <= 1; index += 0.1) {
        const double avgComparsionForN2 = DetermineAverageComparision(M2, (int)(M2 * index));
        std::cout << "Avg. comparisions for N2 at " << index << ": "<< avgComparsionForN2 << std::endl;
    }

    return 0;
}
