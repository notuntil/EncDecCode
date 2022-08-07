#include "RequestFactory.h"


RequestFactory::RequestFactory(string enc):m_encStr(enc)//�������Ϊ�ַ���ʱ�� m_flag��Ϊ0
{
	m_flag = 0;
	m_info = nullptr;
}

RequestFactory::RequestFactory(RequestInfo * info):m_info(info)//�������Ϊ�ṹ��ָ��ʱ��m_flag��Ϊ1
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
		c = new Request(m_encStr);//���� ���л��ַ�����������
	else
		c = new Request(m_info);//���� �ṹ��ָ�봴������
	return c;
}
