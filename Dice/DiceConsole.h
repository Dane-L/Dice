/*
 *  _______     ________    ________    ________    __
 * |   __  \   |__    __|  |   _____|  |   _____|  |  |
 * |  |  |  |     |  |     |  |        |  |_____   |  |
 * |  |  |  |     |  |     |  |        |   _____|  |__|
 * |  |__|  |   __|  |__   |  |_____   |  |_____    __
 * |_______/   |________|  |________|  |________|  |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018-2019 w4123���
 *
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this
 * program. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#ifndef Dice_Console
#define Dice_Console
#include <string>
#include <vector>
#include <map>
#include <set>
#include <Windows.h>

namespace Console
{
	//Master��QQ������ʱΪ0
	extern long long masterQQ;
	//������¼����ǰ����Ϣ�ռ�
	extern long long ruler;
	//ȫ��Ⱥ��Ĭ
	extern bool boolDisabledGlobal;
	//ȫ�ֽ���.ME
	extern bool boolDisabledMeGlobal;
	//��ռģʽ���������������Master���ڵ�Ⱥ������
	extern bool boolPreserve;
	//���Ի����
	extern std::map<std::string, std::string> PersonalMsg;
	//botoff��Ⱥ
	extern std::set<long long> DisabledGroup;
	//botoff��������
	extern std::set<long long> DisabledDiscuss;
	//������Ⱥ��˽��ģʽ����
	extern std::set<long long> WhiteGroup;
	//һ������
	extern int clearGroup(std::string strPara = "unpower");
	//�����
	extern void Process(std::string message);
}
#endif /*Dice_Console*/


