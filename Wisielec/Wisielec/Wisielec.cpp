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


//funkcja do wczytywania i zapisywania danych 
void loadWords(const string& filename, vector<string>& words)
{
    ifstream file(filename); //otwiera plik

    if (!file.is_open())
    {
        cerr << "ERROR" << endl;
        return;
    }

    string word; //zmienna przechowujaca slowa

    while (file >> word)        // petla czyta slowa lnijka po linijce
    {
        words.push_back(word); //Dodaje slowo do wektora
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

