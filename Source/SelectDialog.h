#pragma once


// SelectDialog 대화 상자

class SelectDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDialog)

public:
	SelectDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SelectDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnPaint();
	afx_msg BOOL OnInitDialog();
	int selCharacter;	// 몇번 캐릭터 선택헀는가?
private:
	CImage m_png_image, m_png_image2, m_png_image3, m_png_image4;
public:
	afx_msg void OnCharacterType();
	int m_character;
	CBitmapButton m_select_ok;

	CString ID;
};
