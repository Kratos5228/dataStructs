#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class HashTable{
public:
    int wordCount = 0;
    int tableSize = 304099;
    
    string *arr;
    string words;
    
    int forCount = 0;
    
    HashTable(){
        arr = new string[tableSize];
        for(int i = 0; i < tableSize; i++){
            arr[i] = "";
        }
    }
    
    void read(){
        ifstream inFile;
        
        inFile.open("/Users/ramonbernal/Desktop/Spring 22'/Lab10/Lab10/dict-en-US.txt");
        
        string words;
        
        if(!inFile){                            //if statement if the file is unable to open
            cout << "Error opening data file. Exiting Program." << endl;
        }
        while(!inFile.eof()){
            inFile >> words;
            inFile.ignore(100, '\n');
            int index = hash(words, tableSize);
            if(arr[index] == ""){
                arr[index] = words;
            }else{
                while (arr[index] != "") {
                    index++;
                    if(index == tableSize){
                        index -= tableSize;
                    }
                }
                arr[index] = words;
            }
            wordCount++;
        }
        inFile.close();
    }
    
    void display(){
        for (int i = 0; i < tableSize; i++){
            cout << arr[i] << endl;
        }
    }
   
    int hash(string key, int tableSize){
        int hashValue = 0;

        for(int i = 0; i < key.length(); i++)
            hashValue = 35 * hashValue + key[i];

        hashValue %= tableSize;
        if(hashValue < 0)     // May be negative due to overflow
            hashValue += tableSize;

        return hashValue;
    }

    
    double hashInfo(){
        double info = (double) wordCount / (double) tableSize;
        return info;
    }
    
    bool spellCheck(string word){
        int index = hash(word, tableSize);
        if(arr[index] == word){
            return true;
        }else{
            while (arr[index] != "" && arr[index] != word) {
                index++;
                if(index == tableSize){
                    index -= tableSize;
                }
            }
            if(arr[index] == word){
                return true;
            }else
                return false;
            }
    }
        
    void read2(){
        ifstream inFile;
        
        inFile.open("/Users/ramonbernal/Desktop/Spring 22'/Lab10/Lab10/spellTest.txt");
        
        string words;
        
        
        if(!inFile){                            //if statement if the file is unable to open
            cout << "Error opening data file. Exiting Program." << endl;
        }
        while(!inFile.eof()){
            string lowCase = "";
            inFile >> words;
            removePunctuations(words);
    
            for(int i = 0; i < words.length(); i++){
                lowCase += tolower(words[i]);
            }
            //cout << lowCase << " " << words << endl;
                
            if(spellCheck(words) == true || spellCheck(lowCase) == true){
                cout << "";
            }else
                cout << "Error: " << words << endl;
                
        }
        inFile.close();
    }
    
    string removePunctuations(string& s) {
        string result = "";
        for (char c : s) {    //iterates through each character c in the input string s
            if (!ispunct(c)){ // If c is not a punctuation character
                result += c;
            }
        }
        s = result;
        return s;
    }
    
};

int main(){
    
    string word;
    string lowCase = "";
    HashTable dt;
    dt.read();
    
    int userChoice;
    do{
        cout << "Hash Table SpellCheck " << endl;
        cout << "1. Spellcheck a Word" << endl;
        cout << "2. Spellcheck a File" << endl;
        cout << "3. Display Hash Info" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your choice: ";
        cin >> userChoice;
        cout << endl;
        //lowCase = "";
        //word = "";
        
        switch(userChoice){
            case 1:
                lowCase = "";
                word = "";
                cout << "Enter a word to spellcheck: ";
                cin >> word;
                
                for(int i = 0; i < word.length(); i++){
                    lowCase += tolower(word[i]);
                }
                //cout << lowCase << " " << word << endl;
                
                if(dt.spellCheck(word) == true || dt.spellCheck(lowCase) == true){
                    cout << "Word was spelled correctly " << endl;
                }else
                    cout << "Word was spelled incorrectly " << endl;
                
                cout << endl;
                break;
                
            case 2:
                dt.read2();
                cout << endl;
            break;
                
            case 3:
                cout << "Current Dictionary Size: " << dt.wordCount << endl;
                cout << "Current Hash Load Factor: " << dt.hashInfo() * 100 << "%" << endl;
                cout << endl;
            break;
                
            case 4:
            break;
                
            default:
                cout << "Wrong Choice\n";
                break;
        }
    }while(userChoice != 4);
    
    return 0;
}
