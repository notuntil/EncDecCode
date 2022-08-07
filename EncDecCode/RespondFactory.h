#pragma once
#include "CodecFactory.h"
#include "Response.h"

class RespondFactory :
	public CodecFactory
{
public:
	RespondFactory(string enc);
	RespondFactory(RespondInfo *info);

	~RespondFactory();

	Codec_* createCodec();

private:
	bool m_flag;
	string m_encStr;
	RespondInfo *m_info;
};

