#pragma once
#include "VECTOR2.h"
#include "KeyMng.h"
#include "ImgMng.h"

class CHARA_BASE
{
public:
	CHARA_BASE();
	virtual ~CHARA_BASE();

	virtual void SysInit(void) = 0;
	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	
	VECTOR2 GetPos(void){ return pos; }
	void SetPos(VECTOR2 pos) { this->pos = pos; };

	VECTOR2 GetSize(void) { return VECTOR2(divSize.x * mag.x, divSize.y * mag.y); }
	VECTOR2 GetHitSize(void) { return hitSize; }

	bool GetRemove(void) 
	{
		if (removeFlag == REMOVE_TRUE) return true;
		else return false;
	}
	void SetRemove(bool flag)
	{
		if (flag == true) removeFlag = REMOVE_TRUE;
	}

	void SetAngle(double angle) { this->angle = angle; }

	int animCnt;

protected:
	enum REMOVE_FLAG{
		REMOVE_TRUE,
		REMOVE_FALSE,
		REMOVE_MAX
	};

	enum DIR_LR {
		DIR_RIGHT = 1,
		DIR_LEFT = -1,
		DIR_LRMAX
	};

	enum DIR_UD {
		DIR_UP = -1,
		DIR_MIDDLE,
		DIR_DOWN,
		DIR_UDMAX
	};


	VECTOR2 pos, mov, divSize, mag, hitSize, turnFlag;
	REMOVE_FLAG removeFlag;
	DIR_LR lr;
	DIR_UD umd;
	double angle;
	float speed;
	
	
};

