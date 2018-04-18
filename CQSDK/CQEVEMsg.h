#pragma once
#include "cqdefine.h"
#include "CQEVEBasic.h"

#include <string>
#include <map>
namespace CQ {
	// ����
	struct Font {
		const char * ����;
		int �ֺ�,
			��ɫ,
			/*���壺1 б�壺2 �»��ߣ�4*/
			��ʽ,
			����;

		explicit Font(int);
	};
	//������Ϣ
	class regexMsg{
		//��Ϣ
		std::map<std::string, std::string> regexMap;
	public:
		regexMsg(std::string msg);
		std::string get(std::string);
		std::string operator [](std::string );
	};
	class msg;
	//��Ϣ�¼�����
	struct EVEMsg :public EVE
	{
		//������
		int subType;
		//��ϢID
		int msgId;
		//��ԴQQ
		long long fromQQ;
		//��Ϣ
		std::string message;
		//����
		Font font;

		EVEMsg(int subType, int msgId, long long fromQQ, std::string message, int font);

		//��ʵ�û�
		bool isUser() const;
		//�Ƿ���ϵͳ�û�
		bool isSystem() const;

		virtual int sendMsg(const char*) const = 0;
		virtual int sendMsg(std::string) const = 0;
		virtual msg sendMsg() const = 0;
	};
}