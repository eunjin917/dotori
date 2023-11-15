// FightDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "FightDialog.h"
#include "afxdialogex.h"


// FightDialog 대화 상자

IMPLEMENT_DYNAMIC(FightDialog, CDialog)

FightDialog::FightDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_FIGHT, pParent)
{

}

FightDialog::~FightDialog()
{
}

void FightDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FightDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &FightDialog::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// FightDialog 메시지 처리기
BOOL  FightDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_png_image.Load(L"dotori_1.png");
	m_png_image2.Load(L"dotori_2.png");
	m_png_image3.Load(L"dotori_3.png");
	m_png_image4.Load(L"dotori_4.png");
	m_png_image5.Load(L"dotori_5.png");
	m_png_image6.Load(L"dotori_6.png");
	m_png_image7.Load(L"dotori_7.png");
	m_png_image8.Load(L"dotori_8.png");
	m_png_image9.Load(L"dotori_9.png");
	m_png_image10.Load(L"dotori_10.png");
	m_png_image11.Load(L"dotori_11.png");
	m_png_image12.Load(L"dotori_12.png");
	m_png_image13.Load(L"dotori_13.png");
	m_png_image14.Load(L"dotori_14.png");
	m_png_image15.Load(L"dotori_15.png");
	m_png_image16.Load(L"dotori_16.png");
	m_png_image17.Load(L"dotori_17.png");
	m_png_image18.Load(L"dotori_18.png");

	return TRUE;
}

void FightDialog::OnBnClickedButton1()
{
	MessageBox(_T("스폰지밥멍청이님이 승리하였습니다. 게임화면으로 돌아갑니다."));
}


void FightDialog::OnPaint()
{
	if (IsIconic()) {}
	else {
		CPaintDC dc(this);
		m_png_image.Draw(dc, 220, 250);
		m_png_image2.Draw(dc, 270, 250);
		m_png_image3.Draw(dc, 320, 250);
		m_png_image4.Draw(dc, 220, 300);
		m_png_image5.Draw(dc, 270, 300);
		m_png_image6.Draw(dc, 320, 300);
		m_png_image7.Draw(dc, 220, 350);
		m_png_image8.Draw(dc, 270, 350);
		m_png_image9.Draw(dc, 320, 350);
		m_png_image10.Draw(dc, 690, 250);
		m_png_image11.Draw(dc, 740, 250);
		m_png_image12.Draw(dc, 790, 250);
		m_png_image13.Draw(dc, 690, 300);
		m_png_image14.Draw(dc, 740, 300);
		m_png_image15.Draw(dc, 790, 300);
		m_png_image16.Draw(dc, 690, 350);
		m_png_image17.Draw(dc, 740, 350);
		m_png_image18.Draw(dc, 790, 350);
	}
}
\