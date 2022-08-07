#include <iostream>
#include "Codec_.h"
#include "Request.h"
#include "Response.h"
using namespace std;

string encode(Codec_ *codec)
{
	return codec->encodeMsg();
}

void* decode(Codec_ *codec)
{
	return codec->decodeMsg();
}

int main()
{
	Request req(3, "冠福股份", "飞碟", "系统韩国", "张斐然");
	string enstr = encode(&req);
	cout << "request 序列化: " << enstr << endl;
	Request ans(enstr);
	RequestMsg* reMsg = static_cast<RequestMsg*>(decode(&ans));
	cout << "cmdType: " << reMsg->cmdtype() << " "
		<< "clientID " << reMsg->clientid() << " "
		<< "serverID " << reMsg->serverid() << " "
		<< "sign " << reMsg->sign() << " "
		<< "data " << reMsg->data() << endl;

	Response res(1, 78, "飞碟内阁", "哦IE惹烦恼", "期末考V领房间空格");
	string restr = encode(&res);
	cout << "Respond序列化：" << restr << endl;
	Response anp(restr);
	RespondMsg* resMsg = static_cast<RespondMsg*>(decode(&anp));
	cout << "rv: " << resMsg->rv() << " "
		<< "seckeyID: " << resMsg->seckeyid() << " "
		<< "clientID: " << resMsg->clientid() << " "
		<< "serverID: " << resMsg->serverid() << " "
		<< "data: " << resMsg->data() << endl;
	return 0;
}