#include "client_session.h"
#include "log.h"
#include <thread>
#include <chrono>

using namespace std;

void WAPI CClientSession::SetConnection(IConnection* poConnection)
{
	m_pConnection = poConnection;
}

void WAPI CClientSession::OnEstablish()
{
}

void WAPI CClientSession::OnTerminate()
{

}

void WAPI CClientSession::OnRecv(const char* pBuf, uint32 dwLen)
{
	EXLOG_DEBUG << "client session recv successful!!! msg : " << pBuf;
	if (m_pConnection != nullptr)
	{
		m_pConnection->Send(pBuf, dwLen);
	}
}

void WAPI CClientSession::Send(const char * pBuf, uint32 dwLen)
{
	if (m_pConnection == nullptr)
	{
		EXLOG_ERROR << "Send failed. connection is nullptr";
		return;
	}
	m_pConnection->Send(pBuf, dwLen);
}
