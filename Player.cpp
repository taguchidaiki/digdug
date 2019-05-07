#include "Player.h"
#include "ShotMng.h"


Player::Player()
{
	SysInit();
	Init();
}

Player::Player(VECTOR2 pos)
{
	SysInit();
	Init();
	this->pos = pos;
}


Player::~Player()
{
}

void Player::SysInit(void)
{
	IPIMGMNG.SetID("player", "image/player2.png", VECTOR2(PLAYER_SIZE_X, PLAYER_SIZE_Y), VECTOR2(7, 2));
}

void Player::Init(void)
{
	divSize = VECTOR2(PLAYER_SIZE_X, PLAYER_SIZE_Y);
	mag = VECTOR2(2.0f, 2.0f);
	lr = DIR_RIGHT;
	umd = DIR_MIDDLE;
	angle = 180;
	turnFlag = VECTOR2(true, true);
	removeFlag = REMOVE_FALSE;
	speed = 2.0;
	mov = VECTOR2(0, 0);
	moveFlag = false;
	moveTime = 15;
	mode = PLAYER_MODE::WALK;
	animCnt = 0;
}

void Player::Update(void)
{
    //�v���C���[�̓������Ɉ�a������iUP����ɉ����ꂽ����DOWN����ɉ����ꂽ�Ƃ��̑��̕t�����j
	//�L�[����
	mov = VECTOR2(0, 0);

	switch (mode)
	{
	case PLAYER_MODE::WALK:
		WalkMode();
		break;
	case PLAYER_MODE::BREAK:
		BreakMode();
		break;
	case PLAYER_MODE::PUNK:
		PunkMode();
		break;
	case PLAYER_MODE::SHOT:
		ShotMode();
		break;
	case PLAYER_MODE::END:
		EndMode();
		break;
	}
	
	//animCnt���ӂ₷����������s���́@�����@�󂷁@�p���N������@���S���̎l��ށ@
	//���̂ق��̍s���v���C���[�̍s���̓����𓊂���@���@�����𓊂���s���̎������A�j���[�V�����̃J�E���g���O�ɂ��ăJ�E���g���~�߂�
	

	//SHOT�̏����֌W
	IPSHOTMNG.Update(mode);

}

void Player::Draw(void)
{
	//DrawBox(pos.x, pos.y, pos.x + (divSize.x * mag.x), pos.y + (divSize.y * mag.y), 0xffffff, false);

	if (mode != PLAYER_MODE::END)
	{
		IPIMGMNG.DrawAnimImage("player", pos, divSize, mag, (float)angle, turnFlag, (int)mode + (animCnt / 30) % 2, true);
	}
	else 
	{
		IPIMGMNG.DrawAnimImage("player", pos, divSize, mag, (float)angle, turnFlag, (int)mode + (animCnt / 30) % 5, true);
	}

	if ((bool)turnFlag.x == true)
	{
		DrawString(0, 50, "�E����", 0xffffff,true);
	}
	else
	{
		DrawString(0, 50, "������", 0xffffff, true);
	}
	
	//SHOT�̕`�揈��
	IPSHOTMNG.Draw();
}

void Player::Move(void)
{
	if (moveTime == 0)
	{
		if (IPKEYMNG.newKey[KEY_RIGHT])
		{
			moveFlag = true;
			moveTime = 15;
			lr = DIR_RIGHT;
			umd = DIR_MIDDLE;
		}
		else if (IPKEYMNG.newKey[KEY_LEFT])
		{
			moveFlag = true;
			moveTime = 15;
			lr = DIR_LEFT;
			umd = DIR_MIDDLE;
		}
		else if (IPKEYMNG.newKey[KEY_UP])
		{
			moveFlag = true;
			moveTime = 15;
			umd = DIR_UP;
			if (lr == DIR_RIGHT) { angle = 90; }
			else { angle = 270; }
		}
		else if (IPKEYMNG.newKey[KEY_DOWN])
		{
			moveFlag = true;
			moveTime = 15;
			umd = DIR_DOWN;
			if (lr == DIR_RIGHT) { angle = 270; }
			else { angle = 90; }
		}
		else { moveFlag = false; }
	}
	else moveTime--;

	if (lr == DIR_RIGHT)
	{
		if (umd == DIR_DOWN) turnFlag = VECTOR2(true, false);
		else {
			turnFlag = VECTOR2(true, true);
			if (umd == DIR_MIDDLE) angle = 180;
		}
	}
	else if (lr = DIR_LEFT)
	{
		if (umd == DIR_DOWN) turnFlag = VECTOR2(false, false);
		else {
			turnFlag = VECTOR2(false, true);
			if (umd == DIR_MIDDLE) angle = 180;
		}
	}

	if (moveFlag == false) return;

	if (umd == DIR_MIDDLE) { mov.x += speed * (int)lr;}
	else { mov.y += speed * (int)umd; }
}

void Player::WalkMode(void)
{
	Move();
	pos += mov;

	animCnt++;

	if (IPKEYMNG.trgKey[KEY_SPACE])
	{
		animCnt = 0;
		IPSHOTMNG.Create(pos, divSize * mag, lr, umd);
		mode = PLAYER_MODE::SHOT;
	}
}

void Player::BreakMode(void)
{
	Move();
	pos += mov;

	if (moveFlag == false)
	{
		moveTime = 15;
		mode = PLAYER_MODE::WALK;
	}
	animCnt++;
}

void Player::PunkMode(void)
{
	if (IPKEYMNG.trgKey[KEY_SPACE])
	{
		animCnt += 30;
	}

	if (IPKEYMNG.trgKey[KEY_UP] || IPKEYMNG.trgKey[KEY_DOWN] || IPKEYMNG.trgKey[KEY_RIGHT] || IPKEYMNG.trgKey[KEY_LEFT])
	{
		mode = PLAYER_MODE::WALK;
	}
}

void Player::ShotMode(void)
{

	if (IPSHOTMNG.shotList.empty())
	{
		mode = PLAYER_MODE::WALK;
	}
	else
	{
		IPSHOTMNG.Create(pos, divSize * mag, lr, umd);
	}
}

void Player::EndMode(void)
{
	animCnt++;

	//�v���C���[���G�ɓ����莀�S�����Ƃ��A�v���C���[�̃��[�h�����S��Ԃɐ؂�ւ��ăJ�E���g���O�ɂ���
	//�����āA�ēx���S��ԁ{�J�E���g�̃A�j���[�V�������s���ĉ��߂ăv���C���[�̑��݂��f���[�g����
	if ((animCnt != 0) && ((int)mode + (animCnt / 30) % 6) > ((int)PLAYER_MODE::END_MAX))
	{
		removeFlag = REMOVE_TRUE;
	}
}


