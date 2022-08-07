#include "RespondFactory.h"
#include <iostream>

RespondFactory::RespondFactory(string enc):m_encStr(enc) //�������Ϊ�ַ���ʱ�� m_flag��Ϊ0
{
	m_flag = 0;
	m_info = nullptr;
}

RespondFactory::RespondFactory(RespondInfo * info):m_info(info) //�������Ϊ�ṹ��ָ��ʱ��m_flag��Ϊ1
{
	m_flag = 1;
	m_encStr = "";
//	std::cout << "ResFac" << std::endl;
}

RespondFactory::~RespondFactory()
{
}

Codec_ * RespondFactory::createCodec()
{
	Codec_ *c = nullptr;
	if (m_flag == 0)
	{
		c = new Response(m_encStr);
	}
	else
	{
		c = new Response(m_info);
	}
//	std::cout <<"RespondFactory: "<< c << std::endl;
	return c;
}
