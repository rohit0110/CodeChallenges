#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//STEP 1: Count the Number of bytes
int numOfBytes(ifstream &file) {
    int bytes = 0;
    file.seekg(0,ios::end);
    bytes = file.tellg();
    return bytes;
}

//STEP 2: Count the Number Of lines
int numOfLines(ifstream &file) {
    int lines = 0;
    string line;
    while(getline(file,line)) {
        lines++;
    }
    return lines;
}

//STEP 3: Count the Number of Words
int numOfWords(ifstream &file) {
    int words = 0;
    string word;
    while(file >> word) {
        words++;
    }
    return words;
}

//STEP 4: Count the Number of Chars
int numOfChars(ifstream &file) {
    int chars = 0;
    char ch;
    while(file.get(ch)) {
        chars++;
    }
    return chars;
}

//Check if input is valid or not
bool checkInput(string option) {
    if(option.length() != 2 || (option.length() == 2 && option[0] != '-')) return false; //notValid
    return true; //valid
}

//Main Function
int main(int argc, char* argv[]) {
    //if wrong number of arguments
    if(argc < 2 || argc > 3) {
        cerr << "Usage: " << argv[0] << "<-l | -w | -c | -m> <filename>" << endl;
        return 1;
    }

    //STEP 1,2,3,4: Correct parameters are passed
    if(argc == 3) {
        if(!checkInput(string(argv[1]))) { //if not a valid input
            cerr << "Usage: " << argv[0] << "<-l | -w | -c | -m> <filename>" << endl;
            return 1;
        }
        char option = string(argv[1])[1];
        ifstream inputfile(argv[2]);

        if(!inputfile.is_open()) {
            cerr << "Error: Cant open file" << argv[2] << endl;
            return 1;
        }

        switch(option) {
            case 'l':   cout<<numOfLines(inputfile)<<" "<<argv[2]<<endl;
                        break;
            case 'c':   cout<<numOfBytes(inputfile)<<" "<<argv[2]<<endl;;
                        break;
            case 'w':   cout<<numOfWords(inputfile)<<" "<<argv[2]<<endl;;
                        break;
            case 'm':   cout<<numOfChars(inputfile)<<" "<<argv[2]<<endl;;
                        break;
            default:    break;
        }
        inputfile.close();
    }
    return 0;
}