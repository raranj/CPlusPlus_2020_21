// Ranjana Rajagopalan
// 03/09/21
// FilePreviewer.cpp
// This program opens a file and reads the first ten lines.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// to be changed by user depending on location of file
const string WORD_FILE = "/Users/rishiiyer/Desktop/MoreThanTen.txt";
// used as a test case for less than ten lines
const string LINE_FILE = "/Users/rishiiyer/Desktop/LessThanTen.txt";
// used as a test case for error
const string ERROR_FILE = "LessThanTen.txt";

const int MAX_LINES = 10;

int main()
{
    fstream fs;
    string word;
    int i = 1; // keeps track of how many lines have been displayed
    
    fs.open(WORD_FILE); // open file
    
    if (fs.fail())
    {
        cout << "File not found. \n";
        exit(1);
    }
    
    while ((fs >> word) and (i <= MAX_LINES))
    {
        cout << word << endl;
        i++;
    }
    
    if (i < MAX_LINES) // if the file is shorter than 10 lines
    {
        cout << "The whole file has been displayed.\n";
    }
    
    fs.close(); // close the file
    
    return 0;
}
