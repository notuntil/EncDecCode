#include "Response.h"



Response::Response()
{
}

Response::Response(string encstr):m_encStr(encstr)
{
	initMessage(encstr);
}

//Response::Response(int status, int seckeyID, string clientID, string serverID, string data)
Response::Response(RespondInfo *info)
{
	//initMessage(status, seckeyID, clientID, serverID, data);
	initMessage(info);
	m_msg.SerializeToString(&m_encStr);
}


Response::~Response()
{
}

void Response::initMessage(string encstr)
{
	m_msg.ParseFromString(encstr);
}

//void Response::initMessage(int status, int seckeyID, string clientID, string serverID, string data)
void Response::initMessage(RespondInfo *info)
{
	m_msg.set_rv(info->rv);
	m_msg.set_seckeyid(info->seckeyID);
	m_msg.set_clientid(info->clientID);
	m_msg.set_serverid(info->serverID);
	m_msg.set_data(info->data);
}

string Response::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}

void * Response::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}
