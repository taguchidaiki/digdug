#pragma once
#include <list>
#include <vector>

#define IPMAPCTL MapCtl::GetInstance()

constexpr int MAP_SIZE_X = 12;
constexpr int MAP_SIZE_Y = 12;

class MapObj;
class VECTOR2;

class MapCtl
{
public:
	static MapCtl &GetInstance(void)
	{
		static MapCtl getInstance;
		return getInstance;
	}

	void Create(VECTOR2);
	void Delete(void);
	void Update(void);
	void Draw(void);
	
	void HoleModeCheck(void);

	std::vector<MapObj*> mapList;
	int count = 0;

private:
	MapCtl();
	MapCtl(const MapCtl&) {};
	MapCtl &operator=(const MapCtl&) {};
	~MapCtl();
};

