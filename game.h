#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>

class Game {
public:
    Game(const std::string& initialWord, const std::string& dictionaryFile, int numPlayers);
    ~Game();  // Деструктор для закрытия лог-файла
    void displayBoard() const;
    void displayScores() const;
    bool addLetter(int row, int col, char letter);
    bool isValidWord(const std::string& word) const;
    bool isGameOver() const;
    int getScore(int player) const;
    int getCurrentPlayer() const;
    void setScore(int player, int score);
    void nextTurn();
    void skipTurn();
    std::string cleanString(const std::string& input) const;

private:
    std::vector<std::vector<char>> board;
    std::vector<std::string> usedWords;
    std::unordered_set<std::string> dictionary;
    int currentPlayer;
    int skipsInRow;
    int numPlayers;
    std::vector<int> scores;
    mutable std::ofstream logFile;  // Для ведения журнала

    bool isValidPlacement(int row, int col, char letter) const;
    bool isAdjacent(int row, int col) const;
    std::vector<std::string> findWords() const;
    void loadDictionary(const std::string& dictionaryFile);
    void initLogFile();  // Метод для инициализации лог-файла
};

#endif
