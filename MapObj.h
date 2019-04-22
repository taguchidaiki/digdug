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
		M_DEAD,				//�s���~�܂�
		M_TRFIX,			//���c��
		M_CON,				//�Ȃ���p
		M_CROSS,			//�O�����p
		M_NONE,				//�����Ȃ�
		H_MAX
	};

	Depth GetDepth(void) { return depth; };
	void SetDepth(int);

	void SetHoleMode(int);

	Depth depth;
	HOLE_TYPE type;
	//removeFlag ���I���̃}�X�ɓ��̉摜������
};

