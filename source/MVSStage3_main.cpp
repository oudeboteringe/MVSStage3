 
#include "audio.h"
#include "game.h"
#include "input.h"
#include "Iw2D.h"
#include "mainMenu.h"
#include "pauseMenu.h"
#include "resources.h"
#include "scene.h"

// FRAME_TIME is the amount of time that a single frame should last in seconds
#define FRAME_TIME  (30.0f / 1000.0f)

int main()
{
    // Initialise the 2D graphics system
    Iw2DInit();

    // Create resources
    g_pResources = new Resources();

    // Set up input systems
    g_pInput = new Input();

    // Set up audio systems
    g_pAudio = new Audio();

    // Create scene manager
	g_pSceneManager = new SceneManager();


	// Init the game
	Game* game = new Game();
	game->SetName("game");
	game->Init();
	g_pSceneManager->Add(game);
	game->newGame();

	// Init the main menu
	MainMenu* main_menu = new MainMenu();
	main_menu->SetName("mainmenu");
	main_menu->Init();
	g_pSceneManager->Add(main_menu);

	// Init the pause menu
	PauseMenu* pause_menu = new PauseMenu();
	pause_menu->SetName("pausemenu");
	pause_menu->Init();
	g_pSceneManager->Add(pause_menu);

	// Switch to main menu scene
	g_pSceneManager->SwitchTo(main_menu);

	// Loop forever, until the user or the OS performs some action to quit the app
	while (!s3eDeviceCheckQuitRequest())
	{
		// Update input system
		g_pInput->Update();

		// Update audio system
		g_pAudio->Update();

		// Update scene manager
		g_pSceneManager->Update(FRAME_TIME);

		// Clear the drawing surface
		Iw2DSurfaceClear(0xff000000);

		// Render scene manager
		g_pSceneManager->Render();

		// Show the drawing surface
		Iw2DSurfaceShow();

		// Yield to the OS
		s3eDeviceYield(0);
	}

    // Clean-up
    delete g_pAudio;
    delete g_pInput;
    delete g_pSceneManager;
    delete g_pResources;
    Iw2DTerminate();

    return 0;
}
