/*
 * Copyright (C) 2019-2020 String.Empty
 * ����ʱ�¼�
 * �����ܼ�ʱ��ɵ�ָ��
 */
#pragma once
#include <string>
#include <map>
#include "DiceConsole.h"
using std::string;
using std::map;

struct DiceJobDetail {
    long long fromQQ = 0;
    chatType fromChat;
    string cmd_key;
    string strMsg;
    time_t fromTime = time(NULL);
    //��ʱ������
    map<string, string> strVar = {};
    DiceJobDetail(const char* cmd):cmd_key(cmd){
        fromQQ = console.DiceMaid;
    }
    DiceJobDetail(long long qq, chatType ct, std::string msg = "", const char* cmd = "") 
        :fromQQ(qq), fromChat(ct), strMsg(msg),cmd_key(cmd) {
    }
    string operator[](const char* key){
        return strVar[key];
    }
    bool operator<(const DiceJobDetail& other)const {
        return cmd_key < other.cmd_key;
    }
};

class DiceJob : public DiceJobDetail {
    enum class Renum { NIL, Retry_For, Retry_Until };
public:
    DiceJob(DiceJobDetail detail) :DiceJobDetail(detail) {}
    Renum ren = Renum::NIL;
    void exec();
    void echo(const std::string&);
    void note(const std::string&, int);
};

class DiceScheduler {
    //�¼���ȴ��
    unordered_map<string, time_t> untilJobs;
public:
    void start();
    void end();
    void push_job(const DiceJobDetail&);
    void push_job(const char*);
    void add_job_for(unsigned int, const DiceJobDetail&);
    void add_job_for(unsigned int, const char*);
    void add_job_until(time_t, const DiceJobDetail&);
    void add_job_until(time_t, const char*);
    bool is_job_cold(const char*);
    void refresh_cold(const char*, time_t);
};
inline DiceScheduler sch;

typedef void (*cmd)(DiceJob&);