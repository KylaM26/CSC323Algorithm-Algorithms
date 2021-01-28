//
//  main.cpp
//  BinarySearch
//
//  Created by Kyla Wilson on 10/12/20.
//

#include <iostream>
#include <vector>
#include <algorithm>


int MinBinarySearch(const std::vector<int>& vec, const int lowerBound, const int upperBound) {
    
    if (upperBound < lowerBound)
        return vec.at(0);
    
    if (upperBound == lowerBound)
        return vec.at(lowerBound);
    
    int midPoint = lowerBound + (upperBound - lowerBound) / 2;
    
    std::cout << std::endl;
    std::cout << "Left: " << lowerBound << std::endl;
    std::cout << "Right: " << upperBound << std::endl;
    std::cout << "Middle: " << midPoint << std::endl;
    std::cout << std::endl;
    
    if (midPoint < upperBound && vec.at(midPoint + 1) < vec.at(midPoint))
        return vec.at(midPoint);
    
    if (midPoint > lowerBound && vec.at(midPoint) < vec.at(midPoint - 1))
         return vec.at(midPoint);
    
    if (vec.at(upperBound) > vec.at(midPoint))
       return MinBinarySearch(vec, lowerBound, midPoint - 1);
    
    return MinBinarySearch(vec, midPoint + 1, upperBound);
}


int main(int argc, const char * argv[]) {
    std::vector<int> vec {44, 35, 34, 33, 24, 17, 2, 6, 12, 13};
    std::sort(vec.begin(), vec.end());
    
    int min = MinBinarySearch(vec, 0, vec.size() - 1);
    std::cout << "Q2) Min value: " << min << std::endl;

    return 0;
}



















































bool BinarySearch(const int target, const std::vector<int>& vec) {
    int lowerBound = 1, upperBound = vec.size();
    bool didFindTarget = false;
    
    while(!didFindTarget) {
        if(upperBound < lowerBound)
            return false;
        
        int midPoint = lowerBound + (upperBound - lowerBound) / 2;
        
        if(vec.at(midPoint) < target)
            lowerBound = midPoint + 1;
        
        if(vec.at(midPoint) > target)
            upperBound = midPoint - 1;
        
        if(vec.at(midPoint) == target)
            didFindTarget = true;
    }
    
    return didFindTarget;
}

