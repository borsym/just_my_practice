#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>     
#include <time.h>
#include <algorithm>
#include <string>
#include<limits>

using namespace std;

string startingWords[10] = {"zealous", "spiffy", "deliver", "aspiring", "humdrum", "slope", "uninterested", "magical", "structure", "attract"};
map<string, int> players;
vector<string> names;
vector<string> usedWords;
int playerNumber = 0;

string startingRandomWord(string* arr) {
    srand(time(NULL));
    int randomIndex = rand() % arr->size() + 0;
    return arr[randomIndex];
}

//I found in the internet this transform command (i think this is lambda mayne? but i tired to solve this question and i found this in the c++17 update )
void toLowerCase(string &str) {
    transform(str.begin(), str.end(),str.begin(), ::tolower );
}

void makePlayers(map<string, int> &players, int playerNumber, vector<string>* names) {
    for(int i = 0; i < playerNumber; i++) {
        string tmpName = "";
        cout << "Give me your name please: ";
        cin >> tmpName;
        players[tmpName] = 3;
        names->push_back(tmpName);
    }
}

int main() {
                                                    // if we give a number it's going to give back a true, but we need a false to enter the block (a word would give us back a false)
    while(cout << "How many players do we have? (must 2 or more then 2) " && !(cin >> playerNumber)) {
        cin.clear();  // clear the error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip the errors 
        cout << "Bad input\n";
    }

    if(playerNumber < 2) playerNumber = 2;
    
    makePlayers(players, playerNumber, &names);
    usedWords.push_back((startingRandomWord(startingWords)));
    cout << "\nThe first word is " << usedWords[0] << "\n";
    
    int index = 0;
    while (true) {
        string word;
        bool isGood = true;
        bool isGiveUp = false;

        cout << names[index] << " turn\n";
        cout << "Write down your word, if you say 'end' you give up your competition, if you say 'exit' the whole game exit\n";
        cin >> word;
        toLowerCase(word);

        if(word == "exit") {
            cout << "Thanks for gaming\n";
            break;
        }

        if(word == "end") {
            players.erase(names[index]);
            cout << names[index] <<"  given up\n\n";
            names.erase(names.begin() + index);
            isGiveUp = true;
            
            if(names.size() == 1) {
                cout << "We have a winner!\n" <<  names[0];
                break;
            }
        }

        if(!isGiveUp && count(usedWords.begin(), usedWords.end(), word)) {
            players[names[index]] = (players.at(names[index]) - 1);
            cout << "Ooops, Someone already said this word, try again you steel have '" <<usedWords.back().back() << "', " << players.at(names[index]) <<" heart left\n\n";
            isGood = false;
        }

        if(!isGiveUp && isGood && word.front() != usedWords.back().back()) {
            players[names[index]] = (players.at(names[index]) - 1);
            cout << "The biigest OOOOOOOOOOOPS, the first and last letter doesn't match the last word was: '" <<usedWords.back().back() << "', "<<  players.at(names[index]) <<" heart left\n\n";
            isGood = false;
        }
        
        if(players.at(names[index]) == 0) {
            cout << names[index] << " is out of the game\n\n";
            players.erase(names[index]);
            names.erase(names.begin() + index);

            if(names.size() == 1) {
                cout << "We have a winner!\n" <<  names[0];
                break;
            }
        }

        if(!isGiveUp && isGood) {
            usedWords.push_back(word);
            cout << "\nGood Word, Nice!\n";
            index++;
            
            if(index >= players.size()) index = 0;
        }
    }

}


