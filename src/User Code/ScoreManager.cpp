#include "ScoreManager.h"

ScoreManager* ScoreManager::ptrInstance = nullptr;

void ScoreManager::privAddToScore(ScoreTypes st)
{
	switch (st)
	{
	case ScoreManager::BASE:
		Score += BasePoints;
		break;
	case ScoreManager::FAST:
		Score += FastPoints;
		break;
	case ScoreManager::WIN:
		Score += WinPoints;
		break;
	default:
		break;
	}
}

const int ScoreManager::privGetScore() const
{
	return Score;
}

void ScoreManager::privResetScore()
{
	Score = 0;
}
