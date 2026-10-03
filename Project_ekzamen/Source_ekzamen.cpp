#include <iostream>
#include <Windows.h>
#include <vector> // для роботи з масивами
#include <filesystem> // Для роботи з файловою системою
#include <algorithm> // містить допоміжні етоди для STL
#include <string>
#include <fstream>

using namespace std;

namespace fs = filesystem;

// Завдання 1.
class FileManager
{
public:
    void showContents(const string& path)
    {
        for (const auto& entry : fs::directory_iterator(path))
        {
            cout << entry.path() << endl;
        }
    }

    void createFolder(const string& path) 
    {
        fs::create_directory(path);
    }

    void createFile(const string& path) 
    {
        ofstream file(path);
        file.close();
    }

    void deleteFolder(const string& path) 
    {
        fs::remove_all(path);
    }

    void deleteFile(const string& path) 
    {
        fs::remove(path);
    }

    void rename(const string& oldPath, const string& newPath) 
    {
        fs::rename(oldPath, newPath);
    }

    void copy(const string& source, const string& destination) 
    {
        fs::copy(source, destination, fs::copy_options::recursive);
    }

    void move(const string& source, const string& destination) 
    {
        fs::rename(source, destination);
    }

    uintmax_t getSize(const string& path) 
    {
        return fs::file_size(path);
    }

    void search(const string& path, const string& pattern) 
    {
        for (const auto& entry : 
            fs::recursive_directory_iterator(path)) 
        {
            if (entry.path().filename().string().find(pattern) 
                != string::npos) 
            {
                cout << entry.path() << endl;
            }
        }
    }
};

// Завдання 4.

//class Hangman
//{
//private:
//    string word; // Слово для відгадування
//    string guessedWord; // Поточний стан відгаданого слова
//    int maxAttempts; // Максимальна кількість спроб
//    int attemptsLeft; // Залишилося спроб
//    vector<char> guessedLetters; // Відгадані літери
//    bool isGameWon; // Чи виграли
//    bool isGameLost; // Чи програли
//public:
//    Hangman(const string& wordToGuess, int maxAttempts) : word(wordToGuess), 
//        maxAttempts(maxAttempts), attemptsLeft(maxAttempts), 
//        isGameWon(false), isGameLost(false) 
//    {
//        guessedWord = string(word.length(), '_'); // Ініціалізація відгаданого слова
//    }
//
//    void displayState() {
//        cout << "Слово: " << guessedWord << endl;
//        cout << "Залишилося спроб: " << attemptsLeft << endl;
//        cout << "Введені літери: ";
//        for (char letter : guessedLetters) 
//        {
//            cout << letter << ' ';
//        }
//        cout << endl;
//    }
//
//    void guessLetter(char letter) 
//    {
//        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) 
//        {
//            cout << "Ви вже відгадали цю літеру!" << endl;
//            return;
//        }
//
//        guessedLetters.push_back(letter);
//        bool correctGuess = false;
//
//        for (size_t i = 0; i < word.length(); ++i) 
//        {
//            if (word[i] == letter) 
//            {
//                guessedWord[i] = letter;
//                correctGuess = true;
//            }
//        }
//
//        if (!correctGuess) 
//        {
//            attemptsLeft--;
//            cout << "Невірна літера!" << endl;
//        }
//
//        checkGameStatus();
//    }
//
//    void checkGameStatus() 
//    {
//        if (guessedWord == word) 
//        {
//            isGameWon = true;
//            cout << "Вітаємо! Ви виграли! Слово було: " << word << endl;
//        }
//        else if (attemptsLeft <= 0) 
//        {
//            isGameLost = true;
//            cout << "Ви програли! Слово було: " << word << endl;
//        }
//    }
//
//    bool gameOver() const 
//    {
//        return isGameWon || isGameLost;
//    }
//};

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << "======= Завдання 1. =======\n";

    FileManager fm;
    string path = "C:/example"; // Задайте свій шлях
    fm.showContents(path);
    fm.createFolder(path + "/new_folder");
    fm.createFile(path + "/new_folder/new_file.txt");
    fm.rename(path + "/new_folder/new_file.txt", path + "/new_folder/renamed_file.txt");
    fm.copy(path + "/new_folder", path + "/copy_of_new_folder");
    fm.move(path + "/copy_of_new_folder", path + "/moved_folder");
    fm.deleteFile(path + "/new_folder/renamed_file.txt");
    fm.deleteFolder(path + "/new_folder");
    cout << "Size of moved_folder: " << fm.getSize(path + "/moved_folder") << " bytes" << endl;
    fm.search(path, "file");

    //cout << "======= Завдання 4. =======\n";

    //string wordToGuess = "hangman"; // Слово для відгадування
    //int maxAttempts = 10; // Максимальна кількість спроб

    //Hangman game(wordToGuess, maxAttempts);

    //while (!game.gameOver()) 
    //{
    //    game.displayState();
    //    cout << "Введіть літеру: ";
    //    char letter;
    //    cin >> letter;
    //    game.guessLetter(letter);
    //}

    return 0;
}