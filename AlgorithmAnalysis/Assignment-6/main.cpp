//
//  main.cpp
//  Assignment-6
//
//  Created by Kyla Wilson on 10/26/20.
//  Copyright © 2020 Kyla Wilson. All rights reserved.
//

#include <iostream>

using namespace std;

int* generateRandomValues(int maxValue){
    int* rangeOfValues = new int[maxValue];
    
    for (int i = 0; i < maxValue; i++)
        rangeOfValues[i] = 1 + i;
    
    int* randomValues = new int[maxValue];
        
    for (int index = 0; index < maxValue; index++){
        int randIndex = rand() % (maxValue-index);
        randomValues[index] = rangeOfValues[randIndex];
        
        // swap the element at rangeOfValues[index] with rangeOfValues[maxValue-1-index]
        int temp = rangeOfValues[randIndex];
        rangeOfValues[randIndex] = rangeOfValues[maxValue-1-index];
        rangeOfValues[maxValue-1-index] = temp;
    }
    
    return randomValues;
}



int findMinColIndex(int* array, int size){
    int index = size - 1;
    
    for(int i = size - 1; i >= 1; i--)
        if(array[index] > array[i - 1])
            index = i - 1;
    
    return index;
}



int findMinRowIndexNeighborhood(int **twoDimArray, int MiddleRowIndex, int MinColIndex, int numRows, int numColumns) {
    if(MiddleRowIndex + 1 < numRows && MiddleRowIndex - 1 > 0) { // Making sure the neighbors are not out of bounds
        
        // Check which neighbor is smaller
        if(twoDimArray[MiddleRowIndex + 1][MinColIndex] <= twoDimArray[MiddleRowIndex - 1][MinColIndex]) {
        // If lower index neigbbor is smaller make the middle row equal to that row, if not do lower
            MiddleRowIndex = MiddleRowIndex + 1;
        } else {
            MiddleRowIndex = MiddleRowIndex - 1;
        }
    }
    return MiddleRowIndex;
}

int findLocalMinimumBinarySearch(int** twoDimArray, int numRows, int numColumns){
    int TopRowIndex = 0;
    int BottomRowIndex = numRows - 1;
    int midRowIndex = 0, minColIndex = 0;
    
    while(TopRowIndex <= BottomRowIndex) {
        midRowIndex = (TopRowIndex + BottomRowIndex) / 2;
        minColIndex = findMinColIndex(twoDimArray[midRowIndex], numRows);
        
        int minRowIndex = findMinRowIndexNeighborhood(twoDimArray, midRowIndex, minColIndex, numRows, numColumns);
        
        if(minRowIndex == midRowIndex) {
            return twoDimArray[minRowIndex][minColIndex];
        } else if(minRowIndex < midRowIndex) {
            BottomRowIndex = midRowIndex - 1;
        } else if(minRowIndex > midRowIndex) {
            TopRowIndex = midRowIndex + 1;
        }
    }

    return twoDimArray[midRowIndex][minColIndex];;
}

int main(){

    using namespace std::chrono;
    
    int numRows;
    int numColumns;
    
    cout << "Enter the number of rows: ";
    cin >> numRows;
    
    cout << "Enter the number of columns: ";
    cin >> numColumns;
    
    
    srand(time(NULL));
    
    double totalBinarySearchTime = 0;

    
    int** twoDimArray = new int* [numRows];
    // twoDimArray is a pointer to an array of integer pointers
    // twoDimArray stores the base address of the array of integer pointers
    
    for (int rowindex = 0; rowindex < numRows; rowindex++){
        twoDimArray[rowindex] = new int[numColumns];
        // each entry in the array of integer pointers stores the
        // base address of an array of integers
    }
    

    
    
    
    int maxValue = numRows * numColumns;
    int* randomValues = generateRandomValues(maxValue);
    
    int randIndex = 0;
    
    for (int rowindex = 0; rowindex < numRows; rowindex++){
        
        for (int colindex = 0; colindex < numColumns; colindex++){
            
            twoDimArray[rowindex][colindex] = randomValues[randIndex];
            randIndex++;
        }
        
    }
    
    
    cout << endl;
    
    for (int rowindex = 0; rowindex < numRows; rowindex++){
        
        for (int colindex = 0; colindex < numColumns; colindex++){
        
            cout << twoDimArray[rowindex][colindex] << " ";
        }
        
        cout << endl;
        
    }

    int localMinimum = findLocalMinimumBinarySearch(twoDimArray, numRows, numColumns);

    cout << "\n\nLocal Minimum: " << localMinimum << endl;
    
    delete[] twoDimArray;
    delete[] randomValues;
    
    
  
    system("pause");
    
    return 0;
    
}
