#include "GameLogic.h"
#include <string>
#include <raymath.h>

GameLogic::GameLogic()
{
}

GameLogic::~GameLogic()
{
}

bool GameLogic::Initialize()
{
	SetWindowTitle("Intergalactic Pizza Delivery Pre-Alpha");

	return false;
}

Model GameLogic::LoadModelwithTexture(std::string modelFileName)
{
	std::string path = "models/";

	std::string namePNG = path;
	namePNG.append(modelFileName);
	namePNG.append(".png");

	std::string nameOBJ = path;
	nameOBJ.append(modelFileName);
	nameOBJ.append(".obj");
	Image image = { 0 };
	Model loadModel = { 0 };

	if (FileExists(const_cast<char*>(nameOBJ.c_str())) &&
		FileExists(const_cast<char*>(namePNG.c_str())))
	{
		loadModel = SetTextureToModel(LoadModel(const_cast<char*>(nameOBJ.c_str())),
			LoadTexture(const_cast<char*>(namePNG.c_str())));
	}
	else
	{
		TraceLog(LOG_ERROR, "***********************  Image  :%s missing. ***********************\n",
			const_cast<char*>(nameOBJ.c_str()));
		TraceLog(LOG_ERROR, "***********************  Image  :%s missing. ***********************\n",
			const_cast<char*>(namePNG.c_str()));
	}

	return loadModel;
}

Model GameLogic::SetTextureToModel(Model model, Texture2D texture)
{
	if (IsTextureReady(texture))
	{
		model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
	}

	return model;
}

void GameLogic::Load()
{
	//Load all the models and textures used by the Land class, including the UI.


	//********* Sounds ***************
}

bool GameLogic::BeginRun(Camera* camera)
{

	return false;
}

void GameLogic::Input()
{
	if (State == InPlay || State == WaveStart)
	{

	}

	if (IsKeyPressed(KEY_P))
	{
		if (State == InPlay)
		{
			State = Pause;
		}
		else if (State == Pause)
		{
			State = InPlay;
		}
	}

	if (IsGamepadAvailable(0))
	{
		if (IsGamepadButtonPressed(0, 13))
		{	//Back Button is 13
			if (State == InPlay)
			{
				State = Pause;
			}
			else if (State == Pause)
			{
				State = InPlay;
			}
		}
	}

	if (State == MainMenu)
	{
		if (IsKeyPressed(KEY_N))
		{
			NewGame();
		}

		if (IsGamepadAvailable(0))
		{	//Start Button is 15

			if (IsGamepadButtonPressed(0, 15))
			{
				NewGame();
			}
		}
	}
}

void GameLogic::Update(float deltaTime)
{
	if (State == InPlay)
	{

	}
	else if (State == PlayerHitByEnemy)
	{

	}
	else if (State == AfterPlayerHit)
	{

	}
	else if (State == WaveStart)
	{

	}
	else if (State == NewWave)
	{

	}
	else
	{

	}
}

void GameLogic::Draw3D()
{
	if (State != NewWave)
	{


		if (State == InPlay || State == PlayerHitByEnemy)
		{

		}
	}
}

void GameLogic::Draw2D()
{
	if (State == Pause)
	{
		DrawText("Paused", (int)((GetScreenWidth() * 0.5f) - ((40 * 7) * 0.25f)),
			(int)(GetScreenHeight() * 0.5f), 40, GRAY);
	}
	else if (State == WaveStart)
	{

	}
	else if (State == MainMenu)
	{
		DrawText("Press N to start", (int)((GetScreenWidth() * 0.5f) - ((30 * 17) * 0.25f)),
			(int)(GetScreenHeight() * 0.5f), 30, GRAY);


	}
	else
	{

	}
}

void GameLogic::PlayerHit()
{

}

void GameLogic::CheckEndOfWave()
{
}

void GameLogic::CheckEndOfLevelWave()
{

}

void GameLogic::NewWaveStart()
{

}

void GameLogic::NewGame()
{
	State = WaveStart;

}

void GameLogic::ResetAfterExplode()
{

}

void GameLogic::PlayerWasHit()
{

}
