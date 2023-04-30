#pragma once
#include "raylib.h"
#include <string>

enum GameState
{
	PlayerHitByEnemy,
	AfterPlayerHit,
	WaveStart,
	NewWave,
	Over,
	InPlay,
	Pause,
	HighScores,
	MainMenu
};

class GameLogic
{

public:
	GameLogic();
	virtual ~GameLogic();

	bool Initialize();
	Model LoadModelwithTexture(std::string modelFileName);
	Model SetTextureToModel(Model model, Texture2D texture);
	void Load();
	bool BeginRun(Camera* camera);

	void Input();
	void Update(float deltaTime);
	void Draw3D();
	void Draw2D();

private:
	GameState State = MainMenu;

	void CheckEndOfLevelWave();
	void NewWaveStart();
	void PlayerWasHit();
	void ResetAfterExplode();
	void PlayerHit();
	void CheckEndOfWave();
	void NewGame();
};

