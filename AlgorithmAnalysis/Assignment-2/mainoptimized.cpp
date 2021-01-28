//
//  main.cpp
//  Assignment-2
//
//  Created by Kyla Wilson on 9/10/20.
//  Copyright © 2020 Kyla Wilson. All rights reserved.
//

#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>//clock_t, clock, CLOCKS_PER_SEC

#include <ctime>
#include <ratio>
#include <chrono>


using namespace std;

// implementing hash tables as an array of linked lists

class Node{

    private:
        int data;
        Node* nextNodePtr;

    public:
        Node(){}

        void setData(int d){
            data = d;
        }

        int getData(){
            return data;
        }

        void setNextNodePtr(Node* nodePtr){
                nextNodePtr = nodePtr;
        }

        Node* getNextNodePtr(){
            return nextNodePtr;
        }

};

class List{

    private:
        Node *headPtr;

    public:
        List(){
            headPtr = new Node();
            headPtr->setNextNodePtr(0);
        }

        Node* getHeadPtr(){
            return headPtr;
        }

        bool isEmpty(){

            if (headPtr->getNextNodePtr() == 0)
                return true;

            return false;
        }


        void insert(int data){

            Node* currentNodePtr = headPtr->getNextNodePtr();
            Node* prevNodePtr = headPtr;

            while (currentNodePtr != 0){
                prevNodePtr = currentNodePtr;
                currentNodePtr = currentNodePtr->getNextNodePtr();
            }

            Node* newNodePtr = new Node();
            newNodePtr->setData(data);
            newNodePtr->setNextNodePtr(0);
            prevNodePtr->setNextNodePtr(newNodePtr);

        }

        void insertAtIndex(int insertIndex, int data){

            Node* currentNodePtr = headPtr->getNextNodePtr();
            Node* prevNodePtr = headPtr;

            int index = 0;

            while (currentNodePtr != 0){

                if (index == insertIndex)
                    break;

                prevNodePtr = currentNodePtr;
                currentNodePtr = currentNodePtr->getNextNodePtr();
                index++;
            }

            Node* newNodePtr = new Node();
            newNodePtr->setData(data);
            newNodePtr->setNextNodePtr(currentNodePtr);
            prevNodePtr->setNextNodePtr(newNodePtr);

        }


        int read(int readIndex){

            Node* currentNodePtr = headPtr->getNextNodePtr();
            Node* prevNodePtr = headPtr;
            int index = 0;

            while (currentNodePtr != 0){

                if (index == readIndex)
                    return currentNodePtr->getData();

                prevNodePtr = currentNodePtr;
                currentNodePtr = currentNodePtr->getNextNodePtr();

                index++;

            }

            return -1; // an invalid value indicating
                        // index is out of range

        }



        bool deleteElement(int deleteData){

            Node* currentNodePtr = headPtr->getNextNodePtr();
            Node* prevNodePtr = headPtr;
            Node* nextNodePtr = headPtr;

            while (currentNodePtr != 0){

                if (currentNodePtr->getData() == deleteData){
                    nextNodePtr = currentNodePtr->getNextNodePtr();
                    prevNodePtr->setNextNodePtr(nextNodePtr);
                    return true;
                }

                prevNodePtr = currentNodePtr;
                currentNodePtr = currentNodePtr->getNextNodePtr();

            }

            return false;

        }

        int countList(){

            Node* currentNodePtr = headPtr->getNextNodePtr();
            int numElements = 0;

            while (currentNodePtr != 0){

                numElements++;
                currentNodePtr = currentNodePtr->getNextNodePtr();

            }

            return numElements;
        }


        void IterativePrint(){

            Node* currentNodePtr = headPtr->getNextNodePtr();

            while (currentNodePtr != 0){
                cout << currentNodePtr->getData() << " ";
                currentNodePtr = currentNodePtr->getNextNodePtr();
            }

            cout << endl;

        }


        bool containsElement(int searchData){

            Node* currentNodePtr = headPtr->getNextNodePtr();

            while (currentNodePtr != 0){

                if (currentNodePtr->getData() == searchData)
                    return true;

                currentNodePtr = currentNodePtr->getNextNodePtr();
            }

            return false;

        }


};


class Hashtable{

    private:
        List* listArray;
        int tableSize;

    public:
        Hashtable(int size){
            tableSize = size;
            listArray = new List[size];
        }

        int getTableSize(){
            return tableSize;
        }

        void insert(int data){

            int hashIndex = data % tableSize;
            listArray[hashIndex].insert(data);

        }

        void deleteElement(int data){

            int hashIndex = data % tableSize;
            while (listArray[hashIndex].deleteElement(data));

        }

        bool hasElement(int data){

            int hashIndex = data % tableSize;
            return listArray[hashIndex].containsElement(data);

        }

        void printHashTable(){

            for (int hashIndex = 0; hashIndex < tableSize; hashIndex++){
                cout << "Hash Index: " << hashIndex << " : " ;
                listArray[hashIndex].IterativePrint();
            }

        }

};

const int FindLargestConsecutiveSubsequence(Hashtable* hashTable, const int* arr, const int arrSize) {
    // In this regard, you are supposed to design a strategy to prevent the algorithm from searching for the same sub sequence more than once and implement an optimized version of the algorithm incorporating the strategy.
    int largestSubsequenceLength = 0; // Will keep count of largest value
    // Make a hash table that stores the sequences, if the beginning of the sequence is found don't continue
    // If found move on to the next and increase count found and add it to found hashtable,
    // If count is not zero when the sequence hash table did not find current value
    // get the last index and check if it is greater than current
    Hashtable sequencesFound(arrSize);
    
    for(int index = 0; index < arrSize - 1; index++) { // Looping through arr
        // If hash table does not contain a value less than current value by 1, then it is not the start of a sequence but is in a subsequence.
        if(!sequencesFound.hasElement(arr[index] - 1)) { // If value is not found in sequence table already, keep going
            sequencesFound.insert(arr[index] - 1);
            
            if(!hashTable->hasElement(arr[index] - 1)) {
                int j = arr[index] + 1; // Get value that greater than current value by 1
                j += 1; // Add one
                
                while(hashTable->hasElement(j)) { // While table contains the number
                    if(!sequencesFound.hasElement(j))
                        sequencesFound.insert(j);
                    
                    j += 1;
                }
                
                if(j - arr[index] > 1) { // If the sequenceCount is larger than 1
                    
                    //                    if(index < j - 1)
                    //                        std::cout << "arr[" << index << "]" << " = " << arr[index] << std::endl;
                    
                    if(largestSubsequenceLength < j - arr[index]) // If largest is less than new value
                        largestSubsequenceLength = j - arr[index]; // Make new value the largest
                }
            }
        }
    }

    return largestSubsequenceLength;
}

int main(){

    int numElements;
    cout << "Enter the number of elements you want to store in the hash table: ";
    cin >> numElements;

    int maxValue;
    cout << "Enter the maximum value for an element: ";
    cin >> maxValue;

    int hashTableSize;
    cout << "Enter the size of the hash table: ";
    cin >> hashTableSize;

    int numTrials;
    cout << "Enter the number of trials: ";
    cin >> numTrials;

    srand(time(NULL));

    using namespace std::chrono;

  int totalLargestSequenceLength = 0; // sums up the largest sequence length found in the trials
  double totalDetectionTime = 0;

  for (int trials = 1; trials <= numTrials; trials++){

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    Hashtable hashTable(hashTableSize);

    int array[numElements];

    for (int index = 0; index < numElements; index++){
        array[index] = 1 + rand() % maxValue;
        hashTable.insert(array[index]);
    }
//
//    // Implement your algorithm here and find the largestSequenceLength for the array
      int largestSequenceLength = FindLargestConsecutiveSubsequence(&hashTable, array, numElements);

    totalLargestSequenceLength += largestSequenceLength;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double, std::milli> bruteForceDetectionTime_milli = t2 - t1;
    double detectionTime = bruteForceDetectionTime_milli.count();
    totalDetectionTime += detectionTime;

  }// trials


   cout << "Average largest sequence length: " << (totalLargestSequenceLength/numTrials) << endl;
   cout << "Average detection time (milliseconds): " << (totalDetectionTime/numTrials) << endl;

    return 0;
}

