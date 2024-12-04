#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

//punktacja highscore
struct HighScore
{
    string name; // nazwa gracza 
    int score;   //wynik gracza
};


//funkcja do wczytywania i zapisywania danych 
void loadWords(const string& word, vector<string>& words)
{
    ifstream file(word); //otwiera plik

    if (!file)
    {
        cout << "cos sie zesralo" << endl;
        return;
    }

    string word; //zmienna przechowujaca slowa

    while (file >> word)        // petla czyta slowa lnijka po linijce
    {
        words.push_back(word); //Dodaje slowo do wektora
    }

}


//logika gry 






//Funkcja main
int main()
{
    vector<string>words;
    loadWords("words.txt", words);

    if (words.empty())
    {
        cout << "pustooo" << endl;
    }
    else
    {
        cout << "cos jest: " << endl;
        for (const auto& word : words)
        {
            cout << word << endl;   //wyswietlanie kazdego wczytanego slowa z wektora
        }
    }

}

