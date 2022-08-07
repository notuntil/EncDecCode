#pragma once
#include "Codec_.h"
#include "RequestMsg.pb.h"
class Request :
	public Codec_
{
public:
	Request();
	Request(string encstr);//构建的对象 用于解码 的场景
	Request(int cmd, string clientID, string serverID, string sign, string data);//编码 场景
	
	~Request();

	void initMessage(string encstr);//解码使用
	void initMessage(int cmd, string clientID, string serverID, string sign, string data);//编码

	string encodeMsg();//编码-->序列化函数，返回序列化的字符串
	void* decodeMsg();//解码-->反序列化函数，返回结构体

private:
	string m_encStr;//序列化字符串
	RequestMsg m_msg;//序列化Request的对象
};

