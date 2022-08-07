#include <iostream>
#include "Codec_.h"
#include "Request.h"
#include "Response.h"
#include "RequestFactory.h"
#include "RespondFactory.h"
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
	//request ����
	//Request req(3, "�ڸ��ɷ�", "�ɵ�", "ϵͳ����", "���Ȼ");
	RequestInfo reqinfo = { 3, "�ڸ��ɷ�", "�ɵ�", "ϵͳ����", "���Ȼ" };
	//Request req(&reqinfo);
	CodecFactory *reqF = new RequestFactory(&reqinfo);//���� request��������
	Codec_ *req = reqF->createCodec();//��̬  ����request����
	string enstr = encode(req);
	cout << "request ���л�: " << enstr << endl;
	delete reqF;
	delete req;

	
	//Request ����
	reqF = new RequestFactory(enstr);
	req = reqF->createCodec();
	RequestMsg* reMsg = static_cast<RequestMsg*>(decode(req));
	cout << "cmdType: " << reMsg->cmdtype() << " "
		<< "clientID " << reMsg->clientid() << " "
		<< "serverID " << reMsg->serverid() << " "
		<< "sign " << reMsg->sign() << " "
		<< "data " << reMsg->data() << endl;
	delete reqF;
	delete req;

	cout << "=======================" << endl;

	//respond����
	//Response res(1, 78, "�ɵ��ڸ�", "ŶIE�Ƿ���", "��ĩ��V�췿��ո�");
	RespondInfo resinfo = { 1, 78, "�ɵ��ڸ�", "ŶIE�Ƿ���", "��ĩ��V�췿��ո�" };
	//Response res(&resinfo);
	CodecFactory *resF = new RespondFactory(&resinfo);//����respond���� ����
	Codec_ *res = resF->createCodec();//���� respond����
	string restr = encode(res);
	cout << "Respond���л���" << restr << endl;
	delete resF;
	delete res;
	
	//respond ����
	resF = new RespondFactory(restr);
	res = resF->createCodec();
	RespondMsg* resMsg = static_cast<RespondMsg*>(decode(res));
	cout << "rv: " << resMsg->rv() << " "
		<< "seckeyID: " << resMsg->seckeyid() << " "
		<< "clientID: " << resMsg->clientid() << " "
		<< "serverID: " << resMsg->serverid() << " "
		<< "data: " << resMsg->data() << endl;
	delete resF;
	delete res;

	return 0;
}