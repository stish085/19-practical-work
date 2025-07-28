// 19 задание 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const int totalSectors = 13;
const int winScore = 6;

int getNextSector(int current, int offset, const std::vector<bool>& used) {
    int sector = (current + offset) % totalSectors;
    if (sector == 0) sector = totalSectors;

    
    for (int i = 0; i < totalSectors; ++i) {
        int check = (sector + i - 1) % totalSectors;
        if (!used[check]) return check + 1;
    }

    return -1; 
}

std::string loadFile(const std::string& filename) {
    std::ifstream file;
    file.open(filename);
    if (!file) return "";
    std::string content, line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

std::string loadAnswer(const std::string& filename) {
    std::ifstream file;
    file.open(filename);
    std::string answer;
    file >> answer;
    file.close();
    return answer;
}

int main() {
    int playerScore = 0, viewerScore = 0;
    int currentSector = 1;
    std::vector<bool> usedSectors(totalSectors, false);

    std::cout << "The game What ? Where ? When ?  begins!" << std::endl;

    while (playerScore < winScore && viewerScore < winScore) {
        int offset;
        std::cout << std::endl << " Enter the offset for the spinning top: ";
        std::cin >> offset;

        int sector = getNextSector(currentSector, offset, usedSectors);
        if (sector == -1) {
            std::cout << "All sectors have already been played!" << std::endl;
            break;
        }

        currentSector = sector;
        usedSectors[currentSector - 1] = true;

        std::string questionFile = "C:/questions/questions" + std::to_string(currentSector) + ".txt";
        std::string answerFile = "C:/questions/answer" + std::to_string(currentSector) + ".txt";

        std::string question = loadFile(questionFile);
        std::string correctAnswer = loadAnswer(answerFile);

        if (question.empty() || correctAnswer.empty()) {
            std::cout << "  Error uploading a question or answer for a sector " << currentSector << std::endl;
            continue;
        }

        std::cout << std::endl << "A question from the sector" << currentSector << ":" << std::endl << question << std::endl;
        std::cout << "Your answer: ";
        std::string playerAnswer;
        std::cin >> playerAnswer;

       
        std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);
        std::transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

        if (playerAnswer == correctAnswer) {
            std::cout << "That's right! A point for the experts." << std::endl;
            ++playerScore;
        }
        else {
            std::cout << "Wrong. Right answer: " << correctAnswer << ". A point for the viewers."<<std::endl;
            ++viewerScore;
        }

        std::cout << "Account: Experts " << playerScore << " — The audience " << viewerScore  << std::endl;
    }

    std::cout << std::endl << "Winner: " << (playerScore == winScore ? "Experts!" : "Viewers!") << std::endl;
    return 0;
}

// все на английском поптому что на русском у меня непонятные символы
