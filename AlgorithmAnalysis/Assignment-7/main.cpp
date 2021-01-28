#include <iostream>
#include <fstream>

#include <string>
#include <cstring> // for string tokenizer and c-style string processing

using namespace std;

const int MinCoins(int* coins, int minNumsOfCoins, int size, int amount) {
    return 0;
}

int main(){
    //
    string coinInfoFilename;
    //    cout << "Enter filename: ";
    //    cin >> coinInfoFilename;
    
    coinInfoFilename = "/Users/incrediblekyla/Documents/Documents - Kyla’s MacBook Pro/School/Fall2020/AlgorithmAnalysis/AlgorithmAnalysis/Assignment-7/coinInfo.txt";
    
    int numCoinValues;
    cout << "Enter the number of coin values: ";
    cin >> numCoinValues;
    
    int TargetSumValue;
    cout << "Enter the target sum of the coin values: ";
    cin >> TargetSumValue;
    
    int* CoinValues = new int[numCoinValues+1];  // the + 1 is to account for coin index 0 with a value of $0
    int* MinNumCoins = new int[TargetSumValue+1]; // the + 1 is to account for index 0 with a value of $0
    int* LastCoinPicked = new int[TargetSumValue+1]; // the + 1 is to account for index 0 with an invalid value of -1
    
    CoinValues[0] = 0;
    MinNumCoins[0] = 0;
    LastCoinPicked[0] = -1;
    
    
    ifstream coinInfoFileReader(coinInfoFilename);
    
    if (!coinInfoFileReader){
        cout << "File cannot be opened!! ";
        return 0;
    }
    
    int numCharsPerLine = 25;
    
    char *line = new char[numCharsPerLine];
    // '25' is the maximum number of characters per line
    
    coinInfoFileReader.getline(line, numCharsPerLine, '\n');
    // '\n' is the delimiting character to stop reading the line
    
    while (coinInfoFileReader){
        
        char* cptr = strtok(line, " \t");
        
        string coinIndexToken(cptr);
        int coinIndex = stoi(coinIndexToken);
        
        cptr = strtok(NULL, " \t");
        
        string coinValueToken(cptr);
        int coinValue = stoi(coinValueToken);
        
        CoinValues[coinIndex] = coinValue;
        
        coinInfoFileReader.getline(line, numCharsPerLine, '\n');
        
    }
    
    
    // Implement the algorithm here and the print the output as shown in the sample screenshot
    int amount = TargetSumValue;
    int size = numCoinValues;
    
    // Filling array with place holders
    for(int i = 1; i < amount + 1; i++) {
        MinNumCoins[i] = amount + 1;
        LastCoinPicked[i] = -1;
    }
    
    
    for(int i = 1; i <= amount; i++) { // For each possible number to n
        for(int j = 1; j <= size; j++) { // For each possible coin value for each n
            if(CoinValues[j] <= i) { // If the coin is less than n
                if(MinNumCoins[i] > MinNumCoins[i - CoinValues[j]] + 1) {
                    MinNumCoins[i] = MinNumCoins[i - CoinValues[j]] + 1;
                    LastCoinPicked[i] = CoinValues[j];
                }
            }
        }
    }
    
    for(int i = 1; i <= amount; i++)
        std::cout << i << " ";
    std::cout << std::endl;
    
    std::cout << "MNC: ";
    for(int i = 0; i < amount + 1; i++)
        std::cout << MinNumCoins[i] << " ";
    std::cout << std::endl;
    
    std::cout << "LCP: ";
    for(int i = 0; i < amount + 1; i++)
        std::cout << LastCoinPicked[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Coins to be picked for target sum " << amount << std::endl;
    
    while(amount){
        cout << LastCoinPicked[amount] << ' ';
        amount -= LastCoinPicked[amount];
    }

    std::cout << std::endl;
    system("pause");
    
    return 0;
}

