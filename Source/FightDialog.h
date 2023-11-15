#pragma once


// FightDialog 대화 상자

class FightDialog : public CDialog
{
	DECLARE_DYNAMIC(FightDialog)

public:
	FightDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~FightDialog();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	BOOL OnInitDialog();
private:
	CImage m_png_image, m_png_image2, m_png_image3, m_png_image4, m_png_image5, m_png_image6, m_png_image7, m_png_image8, m_png_image9, m_png_image10, m_png_image11, m_png_image12,
		m_png_image13, m_png_image14, m_png_image15, m_png_image16, m_png_image17, m_png_image18;

	CString ID;
	CString otherID;

public:
	afx_msg void OnPaint();
};
