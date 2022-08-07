#pragma once
#include "Codec_.h"

class CodecFactory
{
public:
	CodecFactory();
	virtual ~CodecFactory();
	virtual Codec_* createCodec();
};

