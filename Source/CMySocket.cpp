// CMySocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "CMySocket.h"
#include "ConnectDialog.h"


// CMySocket

CMySocket::CMySocket()
{
}


CMySocket::~CMySocket()
{
}

void CMySocket::SetParent(CDialog*pWnd)
{
	m_pWnd = pWnd;
}

void CMySocket::OnAccept(int nErrorCode)
{
	if (nErrorCode == 0)
		((ConnectDialog*)m_pWnd)->OnAccept();
}
void CMySocket::OnConnect(int nErrorCode)
{
	if (nErrorCode == 0)
		((ConnectDialog*)m_pWnd)->OnConnect();
}
void CMySocket::OnReceive(int nErrorCode)
{
	if (nErrorCode == 0)
		((ConnectDialog*)m_pWnd)->OnReceive();
}
void CMySocket::OnClose(int nErrorCode)
{
	if (nErrorCode == 0)
		((ConnectDialog*)m_pWnd)->OnClose();
}
void CMySocket::OnSend(int nErrorCode)
{
	if (nErrorCode == 0)
		((ConnectDialog*)m_pWnd)->OnSend();
}