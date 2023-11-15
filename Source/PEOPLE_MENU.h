#pragma once


// PEOPLE_MENU 대화 상자

class PEOPLE_MENU : public CDialog
{
	DECLARE_DYNAMIC(PEOPLE_MENU)

public:
	PEOPLE_MENU(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~PEOPLE_MENU();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU_PEOPLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
