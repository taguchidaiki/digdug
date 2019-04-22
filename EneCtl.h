#pragma once
#include<vector>

#define IPENECTL EneCtl::GetInstance()

class ENEMY_BASE;

class EneCtl
{
public:
	static EneCtl &GetInstance(void)
	{
		static EneCtl getInstance;
		return getInstance;
	}

	void Create(void);
	void Delete(void);
	void Update(void);
	void Draw(void);

	void RemoveCheck(void);

	std::vector<ENEMY_BASE*> enemyList;

private:
	EneCtl();
	EneCtl(const EneCtl&) {};
	EneCtl &operator=(const EneCtl&) {};
	~EneCtl();

};

