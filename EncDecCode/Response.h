#pragma once
#include "Codec_.h"
#include "RespondMsg.pb.h"

struct RespondInfo
{
	bool rv;
	int seckeyID;
	string clientID;
	string serverID;
	string data;
};

class Response :
	public Codec_
{
public:
	Response();
	Response(string encstr);
	//Response(int status, int seckeyID, string clientID, string serverID, string data);
	Response(RespondInfo *info);
	~Response();

	void initMessage(string encstr);
	//void initMessage(int status, int seckeyID, string clientID, string serverID, string data);
	void initMessage(RespondInfo *info);

	string encodeMsg();
	void* decodeMsg();

private:
	string m_encStr;
	RespondMsg m_msg;
};

