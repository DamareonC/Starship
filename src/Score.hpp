#pragma once

#include <fstream>

static u_int32_t g_Score, g_HighScore = 0;

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