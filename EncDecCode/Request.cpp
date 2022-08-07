#include "Request.h"



Request::Request()
{
}

Request::Request(string encstr):m_encStr(encstr)
{
	//m_msg.ParseFromString(encstr);//�����л�
	initMessage(encstr);
}

Request::Request(int cmd, string clientID, string serverID, string sign, string data)
{
	/*m_msg.set_cmdtype(cmd);
	m_msg.set_clientid(clientID);
	m_msg.set_serverid(serverID);
	m_msg.set_sign(sign);
	m_msg.set_data(data);*/
	initMessage(cmd, clientID, serverID, sign, data);
	m_msg.SerializeToString(&m_encStr);
}


Request::~Request()
{
}

void Request::initMessage(string encstr)
{
	m_msg.ParseFromString(encstr);
}

void Request::initMessage(int cmd, string clientID, string serverID, string sign, string data)
{
	m_msg.set_cmdtype(cmd);
	m_msg.set_clientid(clientID);
	m_msg.set_serverid(serverID);
	m_msg.set_sign(sign);
	m_msg.set_data(data);
}

string Request::encodeMsg()
{
	string output;
	if (!m_msg.SerializeToString(&output))
	{
		return NULL;
	}
	return output;
	
}

void* Request::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);

	return &m_msg;
}