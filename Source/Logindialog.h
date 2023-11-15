#pragma once
#include "Player.h"
// Logindialog 대화 상자

class Logindialog : public CDialog
{
	DECLARE_DYNAMIC(Logindialog)

public:
	Logindialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Logindialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_input_id;
	CString m_input_pw;
	afx_msg void OnBnClickedButtSignup();
	void makeNewSave(CString playerID);
	afx_msg void OnBnClickedCancel();
	Player player;
};
