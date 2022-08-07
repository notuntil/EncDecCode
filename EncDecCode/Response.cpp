#include "Response.h"



Response::Response()
{
}

Response::Response(string encstr):m_encStr(encstr)
{
	initMessage(encstr);
}

Response::Response(int status, int seckeyID, string clientID, string serverID, string data)
{
	initMessage(status, seckeyID, clientID, serverID, data);
	m_msg.SerializeToString(&m_encStr);
}


Response::~Response()
{
}

void Response::initMessage(string encstr)
{
	m_msg.ParseFromString(encstr);
}

void Response::initMessage(int status, int seckeyID, string clientID, string serverID, string data)
{
	m_msg.set_rv(status);
	m_msg.set_seckeyid(seckeyID);
	m_msg.set_clientid(clientID);
	m_msg.set_serverid(serverID);
	m_msg.set_data(data);
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
