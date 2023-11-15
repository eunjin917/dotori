#pragma once


// SignDialog 대화 상자

class SignDialog : public CDialog
{
	DECLARE_DYNAMIC(SignDialog)

public:
	SignDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SignDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SIGN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	FILE *IDPW;
	CString m_input_id;
	CString m_input_pw;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtCheck();
	afx_msg void OnBnClickedCancel();
};
