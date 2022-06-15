#ifndef _ScoreManager
#define _ScoreManager


class ScoreManager
{
public:

	enum ScoreTypes
	{
		BASE,
		FAST,
		WIN
	};

private:
	static ScoreManager* ptrInstance;

	ScoreManager() = default;
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
	~ScoreManager() = default;

	static ScoreManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ScoreManager();
		return *ptrInstance;
	}

	int Score = 0;
	
	const int BasePoints = 5;
	const int FastPoints = 10;
	const int WinPoints = 15;

	void privAddToScore(ScoreTypes st);
	const int privGetScore()const;
	void privResetScore();

public:

	static void AddToScore(ScoreTypes st) { Instance().privAddToScore(st); }
	static const int GetScore() { return Instance().privGetScore(); }
	static void ResetScore() { Instance().privResetScore(); }

};

#endif _ScoreManager
