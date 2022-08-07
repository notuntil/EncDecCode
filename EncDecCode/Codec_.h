#pragma once

#include <string>
using std::string;

class Codec_
{
public:
	Codec_();
	virtual ~Codec_();

	virtual string encodeMsg();
	virtual void* decodeMsg();
};

