#pragma once
#include "Codec_.h"
#include "RequestMsg.pb.h"
class Request :
	public Codec_
{
public:
	Request();
	Request(string encstr);//�����Ķ��� ���ڽ��� �ĳ���
	Request(int cmd, string clientID, string serverID, string sign, string data);//���� ����
	
	~Request();

	void initMessage(string encstr);//����ʹ��
	void initMessage(int cmd, string clientID, string serverID, string sign, string data);//����

	string encodeMsg();//����-->���л��������������л����ַ���
	void* decodeMsg();//����-->�����л����������ؽṹ��

private:
	string m_encStr;//���л��ַ���
	RequestMsg m_msg;//���л�Request�Ķ���
};

