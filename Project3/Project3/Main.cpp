#include "SplashScreen.h"
#include "Game.h"

int main()
{
	SplashScreen splashScreen;
	Game game;

	int gamestate = 0;
	bool gamerunning = true;

	while (gamerunning)
	{
		if (gamestate == 0)
		{
			//gamestate = splashScreen.displaySplash();
			gamestate = 1;
		}
		if (gamestate == 1)
		{
			game.run();
		}

		gamerunning = false;
	}
	return 0;
}