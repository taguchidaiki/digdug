#include "DxLib.h"
#include "GameTask.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	IPGAMETASK.SystemInit();
	
	while ((ProcessMessage() == 0) && (CheckHitKey(KEY_INPUT_ESCAPE) == 0))
	{
		ClsDrawScreen();

		IPGAMETASK.Update();

		ScreenFlip();
	}

	DxLib_End();
	return 0;

}
