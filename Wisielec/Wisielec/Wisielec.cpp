#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include <filesystem>

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



//logika gry 






//Funkcja main
int main()
{
    vector<string>words;
    loadWords("words.txt", words);
    if (words.empty())
    {
        cout << "pusty" << endl;
    }
    else
    {
        for (const auto& word : words)
        {
            cout << word << endl;
        }
    }
    
    return 0;

}

