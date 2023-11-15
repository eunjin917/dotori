#pragma once

// CMySocket 명령 대상

class CMySocket : public CAsyncSocket
{
public:
	CMySocket();
	~CMySocket();
	void SetParent(CDialog* pWnd);
private:
	CDialog* m_pWnd;
protected:
	virtual void OnAccept(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};


