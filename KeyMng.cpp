#include "KeyMng.h"



int KeyMng::Init(void)
{
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = 0;
		trgKey[i] = 0;
		upKey[i] = 0;
		oldKey[i] = 0;
	}
	return 0;
}

bool KeyMng::Update(void)
{
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = 0;
		trgKey[i] = 0;
		upKey[i] = 0;
	}
	if (CheckHitKey(KEY_INPUT_UP)) newKey[KEY_UP] = 1;
	if (CheckHitKey(KEY_INPUT_DOWN)) newKey[KEY_DOWN] = 1;
	if (CheckHitKey(KEY_INPUT_RIGHT)) newKey[KEY_RIGHT] = 1;
	if (CheckHitKey(KEY_INPUT_LEFT)) newKey[KEY_LEFT] = 1;
	if (CheckHitKey(KEY_INPUT_SPACE)) newKey[KEY_SPACE] = 1;
	if (CheckHitKey(KEY_INPUT_F5)) newKey[KEY_F5] = 1;
	if (CheckHitKey(KEY_INPUT_F6)) newKey[KEY_F6] = 1;

	for (int i = 0; i < KEY_MAX; i++)
	{
		trgKey[i] = newKey[i] & ~oldKey[i];
		upKey[i] = ~newKey[i] & oldKey[i];
		oldKey[i] = newKey[i];
	}
	return true;
}

KeyMng::KeyMng()
{
}


KeyMng::~KeyMng()
{
}
