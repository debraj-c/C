#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int guess, totalGame = 0, totalGuess = 0, bestGame = 99999;
    double guessPerGame;
    char choice;
    
    // run a loop that continues the game until the until enters N or n
    while(1) {
        cout << "I am thinking of a number between 1 and 100" << endl;
        int random = rand() % 100 + 1; // generate a random number between 1 and 100
        int guessCount = 0; // keep the count of number of guess in each game
        totalGame++; // increment the number of games playes
        
        // loop runs until player enters the correst guess
        while(1) {    
            // prompt and ask for guessed number
            cout << "Your guess? ";
            cin >> guess;
        
            guessCount++; // increment the guess counter by 1 
            
            if(guess == random && guessCount == 1) {
                // if the guess is correct in first attempt, break out of the loop after displaying message
                cout << "You got it right in " << guessCount << " guess!" << endl;
                break;
            }
            if(guess == random) {
                // if the guess is correct, break out of the loop after displaying message
                cout << "You got it right in " << guessCount << " guesses!" << endl;
                break;
            }
            else if(guess < random) // if the guess is lower than the number
                cout << "It's higher" << endl;
            else // if the guess is lower than the number
                cout << "It's lower" << endl;
        }
        // add the guess in that game to the total number of guesses
        totalGuess += guessCount;
        
        // if the guess in the game is the lowest yet
        if(guessCount < bestGame) 
            bestGame = guessCount;
        
        // prompt and take input whether player wants another game
        cout << "Do you want to play again? ";
        cin >> choice;
        
        if(choice == 'N' || choice == 'n') {
            // if player enter N or n, break out of the loop
            cout << endl;
            break;
        }
        else if(choice == 'Y' || choice == 'y') {
            // if player enters Y or y, continue the loop
            cout << endl;
            continue;
        }
    }
    
    // calculate the guesses/game
    guessPerGame = (double)totalGuess/totalGame;
    
    // display the computed stats
    cout << "Statics Result:" << endl;
    cout << "Total games\t= " << totalGame << endl;
    cout << "Total guesses\t= " << totalGuess << endl;
    cout << "Guesses/game\t= " << guessPerGame << endl;
    cout << "Best game\t= " << bestGame;
}
