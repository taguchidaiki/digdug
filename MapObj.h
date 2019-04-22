#pragma once
#include "CHARA_BASE.h"


class MapObj :
	public CHARA_BASE
{
public:
	MapObj();
	~MapObj();

	void SysInit(void);
	void Init(void);
	void Update(void);
	void Draw(void);
	
	enum Depth {
		depth_1,
		depth_2,
		depth_3,
		depth_4,
		depth_MAX
	};

	enum HOLE_TYPE {
		M_DEAD,				//行き止まり
		M_TRFIX,			//横縦穴
		M_CON,				//曲がり角
		M_CROSS,			//三方向角
		M_NONE,				//何もなし
		H_MAX
	};

	Depth GetDepth(void) { return depth; };
	void SetDepth(int);

	void SetHoleMode(int);

	Depth depth;
	HOLE_TYPE type;
	//removeFlag がオンのマスに道の画像をつける
};

