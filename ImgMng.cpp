#include "ImgMng.h"
#include "VECTOR2.h"


void ImgMng::SetID(std::string idName, std::string fileName)
{
	if (imgMap.find(idName) == imgMap.end())
	{
		imgMap[idName] = LoadGraph(fileName.c_str());
	}

}

void ImgMng::SetID(std::string idName, std::string fileName, VECTOR2 divSize, VECTOR2 divCnt)
{
	if (imgDivMap.find(idName) == imgDivMap.end())
	{
		imgDivMap[idName].resize(divCnt.x * divCnt.y);
		LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imgDivMap[idName][0], true);
	}
}

void ImgMng::DrawImage(std::string idName, VECTOR2 pos, VECTOR2 pos2, bool flag)
{
	if (imgMap.find(idName) == imgMap.end()) return;
	
	DrawExtendGraph(pos.x, pos.y, pos2.x, pos2.y, imgMap[idName], flag);

}

void ImgMng::DrawAnimImage(std::string idName, VECTOR2 pos, VECTOR2 divSize, VECTOR2 mag, float angle, VECTOR2 turnFlag, int animID, bool flag)
{
	if (imgDivMap.find(idName) == imgDivMap.end()) return;

	if ((animID < 0) || (imgDivMap[idName].size() <= animID)) return;

	//DrawGraph(pos.x, pos.y, imgDivMap[idName][animID], flag);
	DrawRotaGraph3(pos.x + divSize.x * mag.x / 2, pos.y + divSize.y * mag.y / 2, 
					divSize.x / 2, divSize.y / 2,
					 (double)mag.x, (double)mag.y,
					  PI * angle / 180.0 , imgDivMap[idName][animID], flag, turnFlag.x, turnFlag.y);
}