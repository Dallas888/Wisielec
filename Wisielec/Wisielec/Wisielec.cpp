#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include <filesystem>
#include<cstdlib>

using namespace std;

//punktacja highscore
struct HighScore
{
    string name; // nazwa gracza 
    int score;   //wynik gracza
};


//funkcja do wczytywania i zapisywania slow z pliku
void loadWords(const string& filename, vector<string>& words)
{
    ifstream file(filename);     //otwiera plik

    if (!file.is_open())
    {
        cout << "ERROR" << endl;
        return;
    }

    string word;                //zmienna przechowujaca slowa

    while (file >> word)        // petla czyta slowa lnijka po linijce
    {
        words.push_back(word); //Dodaje slowo do wektora
    }

    file.close();
}

//funkcja do zapisywania danych gracza do pliku
void saveHighScores(const string& filename, vector<HighScore>& scores)
{
    ofstream file(filename);    //otwiera plik w trybie zapisu

    if (!file.is_open())
    {
        cout << "ERROR" << endl;
        return;
    }

    for (const auto& score : scores)
    {
        file << score.name << " " << score.score << endl;   //zapis danych do pliku
    }

    file.close();
}

//Funkcja do wczytywania wyniku 
void loadHighScores(const string& filename, vector<HighScore>& scores)
{
    ifstream file(filename);     //otwiera plik

    if (!file.is_open())
    {
        cout << "ERROR" << endl;
        return;
    }

   HighScore HS;                //zmienna przechowujaca dane

    while (file >> HS.name >> HS.score)       
    {
        scores.push_back(HS); //Dodaje wynik do wektora
    }

    file.close();
}

void displayHighScores(const vector<HighScore>& scores)
{
    cout << "Wynik: " << endl;

    for (const auto& score : scores)
    {
        cout << score.name << "-" << score.score << endl;
    }
}


//logika gry 
void playGame(const vector<string>& words, vector<HighScore>& scores)
{
    //Wybieranie losowego slowa
    srand(static_cast<unsigned>(time(0)));
    string word = words[rand() % words.size()];
    string guesseWord(word.length(), '_');          //slowo z niewidocznymi literami
    string usedLetters;                             // uzyte litery

    cout << "Zgadnij slowo:  " << guesseWord << endl;         //pokaz aktualny stan slowa

    char guess;
    cin >> guess;

    if (usedLetters.find(guess) != -1)
    {
        cout << "Ta litera zostala juz uzyta." << endl;
        //continue;
    }

    usedLetters += guess;

    if (word.find(guess) != -1)                     //jesli litera jest w slowie 
    {
        for (size_t i = 0; i < word.length(); ++i)
        {
            if (word[i] == guess)
            {
                guesseWord[i] = guess;              //ujawnia litere 
           }

        }
    }
}





//Funkcja main
int main()
{
    vector<string>words;
    vector<HighScore>highScores;

    loadWords("words.txt", words);
    loadHighScores("scores.txt", highScores);
    playGame(words, highScores);

    return 0;

}

