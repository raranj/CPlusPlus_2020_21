// Ranjana Rajagopalan
// 11/26/20
// hangman.cpp
// This program implements the game of Hangman.

#include <iostream>
#include <fstream> // needed to read files
#include <cstdlib> // needed for rand() function
#include <ctime> // needed to generate random seed
#include <cctype> // for tolower() function
using namespace std;

// function prototypes
void initializeGame();
void explainRules();
string getWordFromFile();
string getDisplayString(string word);
void getUserGuess(char& guess);
void guessLetters(string word, string display);
void drawHangman(int strike);

const string WORDS_FILE_NAME = "/Users/rishiiyer/Desktop/wordlist.txt"; // to be changed by user depending on location of file

int main ()
{
    string word, display;
    char playAgain;
    
    initializeGame();
    explainRules();
    
    do
    {
        system ("clear");
        
        word = getWordFromFile();
        display = getDisplayString(word);
        guessLetters(word, display);
        
        cout << "\nEnter any character to play again and enter 'q' to quit.\n";
        cin >> playAgain;
        playAgain = tolower(playAgain);
        
    } while (playAgain != 'q'); // loop keeps repeating until player wants to stop
    
}

// This function explains the rules of the game and asks if the user wants to play.
void explainRules()
{
    char choice;
    
    cout << "In this game, you will be given a mystery word.\n";
    cout << "Your job is to guess the letters the word contains in as little tries as possible.\n";
    cout << "You will have five strikes.\n";

    cout << "Enter any character to play and enter 'q' to quit.\n";
    cin >> choice;
    choice = tolower(choice);
    
    switch (choice)
    {
        case 'q': cout << "The program has been quit.\n";
            exit(0);
            break;
        default: cout << "\nGreat! Let's continue.\n";
            break;
    }
}

// This function sets a seed for a random word to be generated out of the file of words.
void initializeGame()
{
    int seed;
    
    // Regardless of the placement of the seed, there will be a random order
    // of numbers for every run because the time is constantly changing
    seed = time(0); // using time (since midnight of January 1st) as a seed for randomization of numbers
    srand(seed);
    
    system("clear");
    
    return;
}

// This function returns a word that the player should guess. The words are stored
// in a file and a random word is chosen from the file.
string getWordFromFile()
{
    const int NUM_OF_WORDS = 37; // number of words in the file
    int num;
    ifstream wordList;
    string word;
    
    num = ((rand() % NUM_OF_WORDS) + 1); // random number between 1 and NUM_OF_WORDS
    
    wordList.open(WORDS_FILE_NAME); // retrieving words from this file
    
    for (int count = 1; count <= num; count++)
    {
        wordList >> word; // finding the word that coressponds with the randomly generated number, num
    }
    
    wordList.close();
    
    return word;
}

// This function uses the mystery word as a parameter and returns a string with as many dashes
// as the length of the word.
string getDisplayString(string word)
{
    int i;
    size_t length;
    string display, dash;
    
    length = word.length(); // finding length of the word
    
    cout << "\nYour word has " << length << " letters.\n\n"; // displaying length of word to user
    dash = "_ ";
    display = "";
    for (i = 1; i <= length; i++)
    {
        display += dash; // creating a string that displays dashes for each letter of the word
    }
    
    cout << display;
    cout << endl << endl;
    
    return display;
}

// This function asks the user to input their guess and returns the guess.
void getUserGuess(char& guess)
{
    do // asks the user to input a letter
    {
        cout << "\nGuess a letter: ";
        cin >> guess;
    } while (isalpha(guess) == false); // validates the letter by checking if it is in the alphabet
    
    guess = tolower(guess);
    
    return;
}

// This function uses the mystery word and the display string with dashes to
// ask the user to guess the letters the word contains.
void guessLetters(string word, string display)
{
    const int MAX_STRIKE = 5; // number of strikes given to the user (5) is constant
    int strike = 0, tracker = 0, i;
    size_t length, wrongGuessLen;
    string wrongGuess = "";
    char guess, c, w;
    bool found, oldGuess;
    
    length = word.length();
    do
    {
        getUserGuess(guess);
        
        system("clear");
        
        found = false; // boolean variable (initialized at false) that tracks if the guess was correct or wrong
        
        for (i = 0; i < length; i++) // goes through every letter of the mystery word
        {
            c = word.at(i); //.at() function returns the character at a specified position
            
            if (c == guess) // if the letter guessed by the user is in the mystery word
            {
                found = true;
                
                if (display.at(2*i) == '_') // check if this is the first time this letter has been guessed
                {
                    tracker++; // tracker variable keeps track of how many letters have been guessed so far
                    
                    // replace the dashes in the string with the correct letter
                    display.replace((2*i), 1, 1, guess);
                }
            }
        }
        
        // variable oldGuess is used to track if the user has guessed the same incorrect letter more than once
        oldGuess = false;
        
        if (found == false) // if the letter that was guessed is not in the word
        {
            wrongGuessLen = wrongGuess.length(); //string wrongGuess displays the user all their wrong guesses
            
            // loop checks whether they have guessed the same wrong letter twice
            for (i = 0; i < wrongGuessLen; i+=2) // for each letter in the string of wrong guesses
            {
                w = wrongGuess.at(i); // assign a variable to a certain character from some position in the string
                
                if (w == guess) // if user has already guessed the letter
                {
                    cout << "\nYou have already guessed " << guess << ".\n"; // tell the user
                    strike--; // to account for strike being incremented later below
                    oldGuess = true;
                    break; //break out of the loop
                }
            }
            
            // if the user has not guessed the same letter again, add the wrong guess to the string of wrong guesses
            if (oldGuess != true)
            {
                wrongGuess.append(1, guess);
                wrongGuess.append(1, ' ');
            }
            
            // tell user that guess is wrong and display number of strikes
            strike++;
            cout << guess << " is not in the word.";
            cout << " You have " << strike << " strike(s).\n";
        }
        else // if the letter is in the word
        {
            cout << "The letter " << guess << " is in the word.\n";
        }
        
        // displays the word with dashes and letters depending on what the user has guessed so far
        cout << endl << display << endl << endl;
        
        //displays to the user all the letters that they have guessed incorrectly
        cout << "Here are all your wrong guesses: " << wrongGuess << endl << endl;
        
        if (strike >= 1)
            drawHangman(strike); // draws Hangman every time depending on how many strikes the user currently has
        
    // keep repeating unless user has used up all strikes or they have guessed the word
    } while ((strike < MAX_STRIKE) && (tracker < length));
    
    
    if (strike >= MAX_STRIKE) // if the user didn't guess the word, display that they lost
    {
        cout << "\nSorry, you lost. The word was " << word << ".\n";
        cout << "Better luck next time!\n";
    }
    
    if (tracker >= length) // if the user guessed the word within 5 strikes, display that they won
    {
        cout << "\nGood job! You guessed all the letters!\n";
        cout << "As you know, the word was " << word << ".\n";
        cout << "Thank you for playing.\n";
    }
}

// This function adds a body part to Hangman every time a wrong letter is guessed,
// using the number of strikes as a parameter.
void drawHangman(int strike)
{
    string hangman = "  O \n";
    string neck = "  | \n";
    string arms = " / \\ \n";
    string body = "  | \n";
    string legs = " / \\ \n";
    
    switch(strike)
    {
        case 2: hangman += neck;
            break;
            
        case 3: hangman += (neck + arms);
            break;
            
        case 4: hangman += (neck + arms + body);
            break;
            
        case 5: hangman += (neck + arms + body + legs);
            break;
            
        default: // should only get here if strike == 1
            break;
    }
    
    cout << hangman << endl;
    
    return;
    }
