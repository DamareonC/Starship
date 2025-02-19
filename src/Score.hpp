#pragma once

#include <fstream>

inline uint32_t g_Score = 0U, g_HighScore = 0U;

static void readHighScore()
{
    std::ifstream iHighScoreFile("res/high_score.dat", std::ios::binary);

    if (!iHighScoreFile.is_open())
    {
        std::ofstream oHighScoreFile("res/high_score.dat", std::ios::binary);
        oHighScoreFile.close();
        iHighScoreFile.close();
        return;
    }

    iHighScoreFile.read(reinterpret_cast<char*>(&g_HighScore), sizeof(g_HighScore));
    iHighScoreFile.close();
}

static void saveHighScore()
{
    std::ofstream highScoreFile("res/high_score.dat", std::ios::binary);
    highScoreFile.write(reinterpret_cast<const char*>(&g_Score), sizeof(g_Score));
    highScoreFile.close();
}

static void updateScores(sf::Text& scoreText, sf::Text& highScoreText)
{
    sf::String score(sf::String(std::string("Score:").append(std::to_string(g_Score))));
    sf::String highScore(sf::String(std::string("High Score:").append(std::to_string(g_Score > g_HighScore ? g_Score : g_HighScore))));

    scoreText.setString(score);
    highScoreText.setString(highScore);
}