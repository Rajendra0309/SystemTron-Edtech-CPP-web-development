#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
   
    srand(time(0));
    
    
    int playerChoice;
    int computerChoice;
    
    
    cout << "Welcome to Rock Paper Scissors!" << endl;
    cout << "Enter your choice:" << endl;
    cout << "1. Rock\n2. Paper\n3. Scissors" << endl;
    cout << "Your choice (1-3): ";
    cin >> playerChoice;
    
   
    while (playerChoice < 1 || playerChoice > 3) {
        cout << "Invalid choice! Please enter 1, 2, or 3: ";
        cin >> playerChoice;
    }
    
    
    computerChoice = rand() % 3 + 1;
    
   
    switch (computerChoice) {
        case 1:
            cout << "Computer chooses: Rock" << endl;
            break;
        case 2:
            cout << "Computer chooses: Paper" << endl;
            break;
        case 3:
            cout << "Computer chooses: Scissors" << endl;
            break;
    }
    

    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        cout << "Congratulations! You win!" << endl;
    } else {
        cout << "Computer wins! Better luck next time." << endl;
    }
    
    return 0;
}
