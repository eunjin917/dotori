#pragma once
#include "CMySocket.h"

// ConnectDialog 대화 상자

class ConnectDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ConnectDialog)

public:
	ConnectDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ConnectDialog();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CONNECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int  count;
	afx_msg BOOL ConnectDialog::OnInitDialog();
	CMySocket m_Ssocket, m_Csocket;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	afx_msg void OnBnClickedButtonGamestart();
	CString m_strName;
	int m_iType;
	int selCharacter;	// 몇번 캐릭터 선택했는지
	int otherCharacter=-1;	 // 상태방이 선택한 캐릭터
	CImage m_character_image;	// 캐릭터 이미지
	CImage m_other_image; // 상대방 캐릭터 이미지
	int second = 0;	// 타이머 초
	afx_msg void OnRType();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBconnect();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CBitmapButton m_connect_fight;
	CString m_timer;
	int round = 0;

	CImage m_png_image, m_png_image2, m_png_image3, m_png_image4, m_png_image5, m_png_image6, m_png_image7, m_png_image8, m_png_image9, m_png_image10, m_png_image11, m_png_image12,
		m_png_image13, m_png_image14, m_png_image15, m_png_image16, m_png_image17, m_png_image18, m_png_image_check;
	int clickNum[3] = { 0 };
	int otherNum[3] = { 0 };
	int dcount = 0; // 도토리 몇개 선택됐는지
	int otherCount = 0;
	bool sended = FALSE;

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void printIMG();
	void round1();

	CString ID;
	CString otherID;
	CString m_ID;
	CString m_otherID;
	CString m_otherSum;
	CString m_sum;

	int myWin[4] = { 0 };	// 1, 2, 3만 쓰자
};