//
//  main.cpp
//  Assignment-4
//
//  Created by Kyla Wilson on 10/5/20.
//  Copyright © 2020 Kyla Wilson. All rights reserved.
//

#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>//clock_t, clock, CLOCKS_PER_SEC

#include <ctime>
#include <ratio>
#include <chrono>
#include <cmath>


using namespace std;
int inversionsCount = 0;

void PrintArray(int* arrayPtr, int arraySize){
    
    for (int i = 0; i < arraySize; i++)
        cout << arrayPtr[i] << " ";
    
    cout << endl;

}


int Merge(int* leftSubArrayPtr, int leftArraySize, int *rightSubArrayPtr, int rightArraySize, int *arrayPtr, int arraySize){
    int ic = 0;
    
    int leftIndex = 0;
    int rightIndex = 0;
    int arrayIndex = 0;
    
    int middleIndex = ceil(arraySize / 2);
    
    while (leftIndex < leftArraySize && rightIndex < rightArraySize){
        
        if (leftSubArrayPtr[leftIndex] <= rightSubArrayPtr[rightIndex]){
            
            arrayPtr[arrayIndex] = leftSubArrayPtr[leftIndex];
            leftIndex++;
        } else{
            ic += (middleIndex - leftIndex);
            inversionsCount += (middleIndex - leftIndex);
            std::cout << "Inverted pair: " << "(" <<  rightSubArrayPtr[rightIndex] << ", " << arrayPtr[arrayIndex]  << ")" << std::endl;
            arrayPtr[arrayIndex] = rightSubArrayPtr[rightIndex];
            rightIndex++;
        }
        
        arrayIndex++;
        
    }
    
    
    if (leftIndex == leftArraySize){
        
        for (; rightIndex < rightArraySize; rightIndex++){
            arrayPtr[arrayIndex] = rightSubArrayPtr[rightIndex];
            arrayIndex++;
        }
            
    }
    else{
        
        for (; leftIndex < leftArraySize; leftIndex++){
            arrayPtr[arrayIndex] = leftSubArrayPtr[leftIndex];
            arrayIndex++;
        }
        
    }
    return ic;
}

int MergeSort(int* arrayPtr, int arraySize){
    if (arraySize > 1){
        
        int* leftSubArrayPtr = new int[arraySize/2];
        int* rightSubArrayPtr = new int[arraySize - arraySize/2];
        
        for (int i = 0; i < (arraySize/2); i++)
            leftSubArrayPtr[i] = arrayPtr[i];
        
        for (int i = arraySize/2; i < arraySize; i++)
            rightSubArrayPtr[i-(arraySize/2)] = arrayPtr[i];
        
        
        int ic1 = MergeSort(leftSubArrayPtr, arraySize/2);
        int ic2 = MergeSort(rightSubArrayPtr, arraySize - arraySize/2);
        
        int icMerge = Merge(leftSubArrayPtr, arraySize/2, rightSubArrayPtr, arraySize - arraySize/2, arrayPtr, arraySize);
        return ic1 + ic2 + icMerge;
    }
    
    return 0;
}




int main(){
    
    int arraySize;
    cout << "Enter array size: ";
    cin >> arraySize;
    
    int maxVal = 50;
    
    srand(time(NULL));
    
    int* arrayPtr = new int[arraySize];
    
    for (int i = 0; i < arraySize; i++)
        arrayPtr[i] = 1 + rand() % maxVal;
    
    cout << "Before sorting..." << endl;
    PrintArray(arrayPtr, arraySize);
    
    int ic = MergeSort(arrayPtr, arraySize);
    
    cout << "After sorting..." << endl;
    PrintArray(arrayPtr, arraySize);
    
    std::cout << "Inversion Count: " <<  ic << ", " << inversionsCount << std::endl;
    
    system("pause");
    
    return 0;
}

