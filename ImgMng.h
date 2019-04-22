#pragma once
#include "DxLib.h"
#include <map>
#include <vector>

class VECTOR2;

constexpr auto PI = 3.1415926535897932384626433832795f;
#define IPIMGMNG ImgMng::GetInstance()

class ImgMng
{
public:
	static ImgMng &GetInstance(void)
	{
		static ImgMng getInstance;
		return getInstance;
	}

	void SetID(std::string idName, std::string fileName);
	void SetID(std::string idName, std::string fileName, VECTOR2 divSize, VECTOR2 divCnt);


	void DrawImage(std::string idName, VECTOR2 pos, VECTOR2 pos2, bool flag);
	void DrawAnimImage(std::string idName, VECTOR2 pos, VECTOR2 divSize, VECTOR2 mag, float angle, VECTOR2 turnFlag, int animID, bool flag);

private:
	ImgMng() {};
	ImgMng(const ImgMng&) {};
	ImgMng &operator=(const ImgMng&) {};
	~ImgMng() {};

	std::map<std::string, int> imgMap;
	std::map<std::string, std::vector<int>> imgDivMap;
};

