#pragma once
#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions

class raylib_game
{
public:
	//----------------------------------------------------------------------------------
	// Shared Variables Definition (global)
	// NOTE: Those variables are shared between modules through screens.h
	//----------------------------------------------------------------------------------
	GameScreen currentScreen = LOGO;
	Font font = { 0 };
	Music music = { 0 };
	Sound fxCoin = { 0 };
	Camera TheCamera = { 0 };

	static void Initialize(void);
	static void ChangeToScreen(int screen);     // Change to screen, no transition effect
	static void TransitionToScreen(int screen); // Request transition to next screen

private:

	//----------------------------------------------------------------------------------
	// Local Functions Declaration
	//----------------------------------------------------------------------------------
	static void UpdateTransition(void);         // Update transition effect
	static void DrawTransition(void);           // Draw transition effect (full-screen rectangle)

	static void UpdateDrawFrame(void);          // Update and draw one frame

};
