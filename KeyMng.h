#pragma once
#include "DxLib.h"

#define IPKEYMNG KeyMng::GetInstance()


enum KeyData {
	KEY_UP,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_SPACE,
	KEY_F5,
	KEY_F6,
	KEY_MAX
};

class KeyMng
{
public:
	static KeyMng &GetInstance(void)
	{
		static KeyMng getInstance;
		return getInstance;
	}

	int newKey[KEY_MAX];
	int trgKey[KEY_MAX];
	int upKey[KEY_MAX];
	int oldKey[KEY_MAX];
	
	int Init(void);
	bool Update(void);

private:
	KeyMng();
	KeyMng(const KeyMng&) {};
	KeyMng &operator=(const KeyMng&) {};
	~KeyMng();

	
};

