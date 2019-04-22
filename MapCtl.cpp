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
	//����������ɂ����angle�ɕςȒl�������ċ󂫕�������Ă���
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			//����������鏈��
			if (x == 0)
			{
				//����Z
				if (y == 0)
				{
					if (mapList[x + 1 + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//�A���O���̐ݒ�
							mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
						}
						else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//�A���O���̐ݒ�
							mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
						}
					}
					else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//�A���O���̐ݒ�
						mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
					}
				}
				//���ӎO���������鏈���Z
				else if ((y > 0) && (y < (MAP_SIZE_Y - 1)))
				{
					if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
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
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
						}
					}
				}
				//�����Z
				else if (y == (MAP_SIZE_Y - 1))
				{
					if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//�A���O���̐ݒ�
							mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
						}
						else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//�A���O���̐ݒ�
							mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
						}
					}
					else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//�A���O���̐ݒ�
						mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
					}
				}
			}
			else if ((x > 0) && (x < (MAP_SIZE_X - 1)))
			{
				//��ӎO���������Z
				if (y == 0)
				{
					//�����Ȃ�
					if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						//�E���Ȃ�
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//�����Ȃ�
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
							//���E�ђ�
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
							}
						}
						//�E������
						else
						{
							//�����Ȃ�
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
							}
							//��������
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							}
						}
					}
					else
					{
						//�E���Ȃ�
						if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//�����Ȃ�
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else
						{
							//
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
						}
					}
				}
				//���i�l���������Z
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
				//���ӎO���������Z
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
								//�A���O���̐ݒ�
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
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
							else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(0);
							}
						}
						else if (mapList[(x + 1) + y * MAP_SIZE_Y]->GetRemove() == false)
						{
							if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
						}
					}
				}
			}
			else if (x == (MAP_SIZE_X - 1))
			{
				//�E��Z
				if (y == 0)
				{
					if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//�A���O���̐ݒ�
							mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
						}
						else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//�A���O���̐ݒ�
						}
					}
					else if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//�A���O���̐ݒ�
						mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
					}
				}
				//�E�ӎO���������鏈���~
				else if ((y > 0) && (y < (MAP_SIZE_Y - 1)))
				{
					//�オ�Ȃ�
					if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						//�����Ȃ�
						if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//�����Ȃ�
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(3);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
						}
						//��������
						else
						{
							//�����Ȃ�
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(1);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
							}
						}
					}
					//�オ����
					else
					{
						//�����Ȃ�
						if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
						{
							//�����Ȃ�
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
							}
							//��������
							else
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
							}
						}
						//��������
						else
						{
							if (mapList[x + (y + 1) * MAP_SIZE_Y]->GetRemove() == true)
							{
								mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
								//�A���O���̐ݒ�
								mapList[x + y * MAP_SIZE_Y]->SetAngle(90);
							}
						}
					}
				}
				//�E���Z
				else if (y == (MAP_SIZE_Y - 1))
				{
					if (mapList[(x - 1) + y * MAP_SIZE_Y]->GetRemove() == true)
					{
						if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(2);
							//�A���O���̐ݒ�
							mapList[x + y * MAP_SIZE_Y]->SetAngle(270);
						}
						else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == false)
						{
							mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
							//�A���O���̐ݒ�
							mapList[x + y * MAP_SIZE_Y]->SetAngle(180);
						}
					}
					else if (mapList[x + (y - 1) * MAP_SIZE_Y]->GetRemove() == true)
					{
						mapList[x + y * MAP_SIZE_Y]->SetHoleMode(0);
						//�A���O���̐ݒ�
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
