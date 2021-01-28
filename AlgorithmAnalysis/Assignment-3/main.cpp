//
//  main.cpp
//  Assignment-3
//
//  Created by Kyla Wilson on 9/23/20.
//  Copyright © 2020 Kyla Wilson. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>


#include <ctime>
#include <ratio>
#include <chrono>


using namespace std;

// Implement here the DivideByHalf algorithm
int FindMinIndex(const int* arr, int leftIndex, int rightIndex) {
    if(leftIndex == rightIndex)
        return leftIndex;
    
    int middleIndex = (leftIndex + rightIndex) / 2;
    int leftMinIndex = FindMinIndex(arr, leftIndex, middleIndex);
    int rightMinIndex = FindMinIndex(arr, middleIndex + 1, rightIndex);
    
    if(arr[leftMinIndex] <= arr[rightMinIndex])
        return leftMinIndex;

    return rightMinIndex;
}

int DivideByHalf(const int* arr, int l, int r) {
    return FindMinIndex(arr, l, r);
}

// Implement here the DecreaseByOne algorithm
int MinValue(int a, int b) {
    return a <= b ? a : b;
}

int DecreaseByOne(const int* arr, int size) {
    if (size == 1) {
        return arr[0];
    }
    
    else {
        int minIndex = DecreaseByOne(arr, size - 1);
        
        if (minIndex < arr[size - 1]) {
            return minIndex;
        }
        
        else {
            return arr[size - 1];
        }
    }
    

//    if(size == 0)
//        return arr[0];
//
//    return MinValue(arr[size], DecreaseByOne(arr, size - 1));
}

int main(){

    using namespace std::chrono;
    
   srand(time(NULL));
   
   int arraySize;
   cout << "Enter an array size: ";
   cin >> arraySize;
   
   int maxValue;
   cout << "Enter max. value: ";
   cin >> maxValue;
   
   int option;
   cout << "Enter 1 for dividing the array size by half; 2 for decreasing the array size by 1" << endl;
   cin >> option;
   
   double totalTime_nano = 0;
   
   int numTrials = 1000;
   
 for (int trials = 1; trials <= numTrials; trials++){
       
   int *arrayPtr = new int[arraySize];
   
    for (int index = 0; index < arraySize; index++)
        arrayPtr[index] = 1 + ( rand() % maxValue);
    
    int minValue = -1;
    
    if (option == 1){
    
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
//
        int minIndex = DivideByHalf(arrayPtr, 0, arraySize-1);
        minValue = arrayPtr[minIndex];

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::nano> time_nano = t2 - t1;
        totalTime_nano += time_nano.count();
        
    }
    else if (option == 2){
        
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        minValue = DecreaseByOne(arrayPtr, arraySize - 1);

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::nano> time_nano = t2 - t1;
        totalTime_nano += time_nano.count();
        
    }
    else{
        
        cout << "Invalid option " ;
        return 0;
        
    }
     
//     cout << "Min. element is: " << minValue << endl;
     
        
    delete[] arrayPtr;
    
    
 }// trials loop


 cout << "Option " << option << " : Average time " << (totalTime_nano/numTrials) << " nano seconds " << endl;



system("pause");

return 0;
}

