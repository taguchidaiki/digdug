#pragma once
#include <vector>

#define IPSHOTMNG ShotMng::GetInstance() 


class Shot;
class VECTOR2;
class Player;

class ShotMng
{
public:
	static ShotMng& GetInstance(void)
	{
		static ShotMng getInstance;
		return getInstance;
	}

	void Create(VECTOR2, VECTOR2, int, int);
	void Delete(void);

	void Update(const PLAYER_MODE& mode);
	void Draw(void);

	std::vector<Shot*> shotList;
	int createCnt = 11;

private:
	ShotMng();
	ShotMng(const ShotMng&) {};
	ShotMng &operator=(const ShotMng&) {};
	~ShotMng();
};

