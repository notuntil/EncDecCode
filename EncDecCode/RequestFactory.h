#pragma once
#include "CodecFactory.h"
#include "Request.h"
class RequestFactory :
	public CodecFactory
{
public:
	RequestFactory(string enc);
	RequestFactory(RequestInfo *info);
	~RequestFactory();

	Codec_* createCodec();

private:
	bool m_flag;
	string m_encStr;
	RequestInfo *m_info;
};

