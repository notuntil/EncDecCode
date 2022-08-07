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
	//request 编码
	//Request req(3, "冠福股份", "飞碟", "系统韩国", "张斐然");
	RequestInfo reqinfo = { 3, "冠福股份", "飞碟", "系统韩国", "张斐然" };
	//Request req(&reqinfo);
	CodecFactory *reqF = new RequestFactory(&reqinfo);//创建 request工厂对象
	Codec_ *req = reqF->createCodec();//多态  创建request对象
	string enstr = encode(req);
	cout << "request 序列化: " << enstr << endl;
	delete reqF;
	delete req;

	
	//Request 解码
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

	//respond编码
	//Response res(1, 78, "飞碟内阁", "哦IE惹烦恼", "期末考V领房间空格");
	RespondInfo resinfo = { 1, 78, "飞碟内阁", "哦IE惹烦恼", "期末考V领房间空格" };
	//Response res(&resinfo);
	CodecFactory *resF = new RespondFactory(&resinfo);//创建respond工厂 对象
	Codec_ *res = resF->createCodec();//创建 respond对象
	string restr = encode(res);
	cout << "Respond序列化：" << restr << endl;
	delete resF;
	delete res;
	
	//respond 解码
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