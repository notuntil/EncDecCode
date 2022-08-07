#pragma once
#include "Codec_.h"
#include "RespondMsg.pb.h"
class Response :
	public Codec_
{
public:
	Response();
	Response(string encstr);
	Response(int status, int seckeyID, string clientID, string serverID, string data);
	~Response();

	void initMessage(string encstr);
	void initMessage(int status, int seckeyID, string clientID, string serverID, string data);

	string encodeMsg();
	void* decodeMsg();

private:
	string m_encStr;
	RespondMsg m_msg;
};

