//
//  main.cpp
//  Assignment-5
//
//  Created by Kyla Wilson on 10/19/20.
//  Copyright © 2020 Kyla Wilson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> FindFirstAndLastOccurance(const std::vector<int>& arr, const int target) {
    
    int firstIndex = -1, lastIndex = -1;
    int left = 0, right = static_cast<int>(arr.size()) - 1;
    
    while(left <= right) { // While still searching
        int middle = left + (right - left) / 2; // Get the middle index
        
        // Print left and right index
        std::cout << "Left: " << left << ", Right: " << right << ", Mid: " << middle << std::endl;
        
        if(arr[middle] == target) {
            if(middle == 0 || arr[middle - 1] < arr[middle]) {
                firstIndex = middle;
                break;
            } else {
                right = middle - 1;
            }
        } else if(arr[middle] < target) {
            left = middle + 1;
        } else if(arr[middle] > target) {
            right = middle - 1;
        }
    }
    
    left = 0;
    right =  static_cast<int>(arr.size()) - 1;
    
    std::cout << "********************" << std::endl;
    
    while(left <= right) {
        int middle = left + (right - left) / 2;
        
//        std::cout << "Left: " << left << ", Right: " << right << std::endl;
        std::cout << "Left: " << left << ", Right: " << right << ", Mid: " << middle << std::endl;
        if(arr[middle] == target) {
            if(middle == arr.size() - 1 || arr[middle + 1] > arr[middle]) {
                lastIndex = middle;
                break;
            } else {
                left = middle + 1;
            }
        } else if(arr[middle] < target) {
            left = middle + 1;
        } else if(arr[middle] > target) {
            right = middle - 1;
        }
    }
    
    return { firstIndex , lastIndex };
}


int main() {
    std::vector<int> v { 1, 1, 3, 4, 5, 5, 5, 5, 7, 9, 9, 14 };
    const int size = static_cast<int>(v.size());
    const int target = 6;
    
    const std::pair<int, int> occurances = FindFirstAndLastOccurance(v, target);
    
    std::cout << "\nArray: \n";
    for(const int& n : v)
        std::cout << n << " ";
    
    std::cout << "\nTarget value: " << target;
    
    if(occurances.first == -1) {
        std::cout << "\nNumber does not appear in array" << std::endl;
    } else {
        std::cout << "\n\nFirst occurance at index: " << occurances.first << "\nLast occurance at index: " << occurances.second  << "\nTotal occurance count: " << occurances.second - (occurances.first - 1) << std::endl;
    }
    
    return 0;
}

