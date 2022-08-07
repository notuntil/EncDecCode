#include "RequestFactory.h"


RequestFactory::RequestFactory(string enc):m_encStr(enc)//输入参数为字符串时， m_flag设为0
{
	m_flag = 0;
	m_info = nullptr;
}

RequestFactory::RequestFactory(RequestInfo * info):m_info(info)//输入参数为结构体指针时，m_flag设为1
{
	m_flag = 1;
	m_encStr = "";
}

RequestFactory::~RequestFactory()
{
}

Codec_ * RequestFactory::createCodec()
{
	Codec_ *c = nullptr;
	if (m_flag == 0)
		c = new Request(m_encStr);//调用 序列化字符串创建对象
	else
		c = new Request(m_info);//调用 结构体指针创建对象
	return c;
}
