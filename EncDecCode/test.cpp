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
	Request req(3, "�ڸ��ɷ�", "�ɵ�", "ϵͳ����", "���Ȼ");
	string enstr = encode(&req);
	cout << "request ���л�: " << enstr << endl;
	Request ans(enstr);
	RequestMsg* reMsg = static_cast<RequestMsg*>(decode(&ans));
	cout << "cmdType: " << reMsg->cmdtype() << " "
		<< "clientID " << reMsg->clientid() << " "
		<< "serverID " << reMsg->serverid() << " "
		<< "sign " << reMsg->sign() << " "
		<< "data " << reMsg->data() << endl;

	Response res(1, 78, "�ɵ��ڸ�", "ŶIE�Ƿ���", "��ĩ��V�췿��ո�");
	string restr = encode(&res);
	cout << "Respond���л���" << restr << endl;
	Response anp(restr);
	RespondMsg* resMsg = static_cast<RespondMsg*>(decode(&anp));
	cout << "rv: " << resMsg->rv() << " "
		<< "seckeyID: " << resMsg->seckeyid() << " "
		<< "clientID: " << resMsg->clientid() << " "
		<< "serverID: " << resMsg->serverid() << " "
		<< "data: " << resMsg->data() << endl;
	return 0;
}