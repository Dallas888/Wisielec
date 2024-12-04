#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

//zaraz sie zdenerwuje czemu nie zgrywa sie to z gitem xd

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

