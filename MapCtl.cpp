#include "MapCtl.h"
#include "MapObj.h"
#include "VECTOR2.h"


void MapCtl::Create(VECTOR2 pos)
{
	mapList.clear();
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			MapObj *obj = new MapObj();
			obj->SetPos(VECTOR2(x * obj->GetSize().x + pos.x, y * obj->GetSize().y + pos.y));
			obj->SetDepth(y);
			mapList.push_back(obj);
		}
	}
}

void MapCtl::Delete(void)
{
	std::vector<MapObj*>::iterator itr = mapList.begin();
	while (itr != mapList.end()) {
		delete (*itr);
		itr = mapList.erase(itr);
	}
	
}

void MapCtl::Update(void)
{
	
}

void MapCtl::Draw(void)
{
	count = 0;
	for (auto itr = mapList.begin(); itr != mapList.end(); ++itr)
	{
		(*itr)->Draw();
		if ((*itr)->GetRemove() == true) 
		{
			//DrawCircle((*itr)->GetPos().x + (*itr)->GetSize().x / 2, (*itr)->GetPos().y + (*itr)->GetSize().y / 2, 16, 0xff0000, true, true);
			count++;
		}
	}
	DrawFormatString(200, 0, 0xffff00, "count = %d", count);
}

void MapCtl::HoleModeCheck(void)
{
	//※入る方向によってangleに変な値が入って空き方が違っている
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			//二方向を見る処理
			if (x == 0)
			{
				//左上〇
				if (y == 0)
				{
					if (mapList[x + 1 + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//アングルの設定
							mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
						}
						else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//アングルの設定
							mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
						}
					}
					else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//アングルの設定
						mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
					}
				}
				//左辺三方向を見る処理〇
				else if ((y > 0) && (y < (MAP_SIZE_Y - 1)))
				{
					if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
						}
					}
					else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
					{
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
						}
					}
				}
				//左下〇
				else if (y == (MAP_SIZE_Y - 1))
				{
					if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//アングルの設定
							mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
						}
						else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//アングルの設定
							mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
						}
					}
					else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//アングルの設定
						mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
					}
				}
			}
			else if ((x > 0) && (x < (MAP_SIZE_X - 1)))
			{
				//上辺三方向処理〇
				if (y == 0)
				{
					//左がない
					if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						//右がない
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//下がない
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
							//左右貫通
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
							}
						}
						//右がある
						else
						{
							//下がない
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
							}
							//下がある
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							}
						}
					}
					else
					{
						//右がない
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//下がない
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else
						{
							//
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
						}
					}
				}
				//中段四方向処理〇
				else if ((y > 0) && (y < (MAP_SIZE_Y - 1)))
				{
					if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(4);
								}
								else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
								}
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
								}
								else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
								}
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
								}
								else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
								}
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
								}
								else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
								}
							}
						}
					}
					else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
					{
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
								}
								else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
								}
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
								}
								else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
								}
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
								}
								else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
									mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
								}
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
								{
									mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								}
							}
						}
					}
				}
				//下辺三方向処理〇
				else if (y == (MAP_SIZE_Y - 1))
				{
					if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
								mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
							}
							else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
							else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							}
						}
					}
					else if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == false)
					{
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
							else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
						}
					}
				}
			}
			else if (x == (MAP_SIZE_X - 1))
			{
				//右上〇
				if (y == 0)
				{
					if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//アングルの設定
							mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
						}
						else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//アングルの設定
						}
					}
					else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//アングルの設定
						mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
					}
				}
				//右辺三方向を見る処理×
				else if ((y > 0) && (y < (MAP_SIZE_Y - 1)))
				{
					//上がない
					if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						//左がない
						if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//下がない
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
						}
						//左がある
						else
						{
							//下がない
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
						}
					}
					//上がある
					else
					{
						//左がない
						if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//下がない
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
							}
							//下がある
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
							}
						}
						//左がある
						else
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//アングルの設定
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
						}
					}
				}
				//右下〇
				else if (y == (MAP_SIZE_Y - 1))
				{
					if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//アングルの設定
							mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
						}
						else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//アングルの設定
							mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
						}
					}
					else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//アングルの設定
						mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
					}
				}
			}
		}
	}
}

MapCtl::MapCtl()
{
}


MapCtl::~MapCtl()
{
	Delete();
}
