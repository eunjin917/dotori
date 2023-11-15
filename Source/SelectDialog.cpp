// SelectDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "SelectDialog.h"
#include "afxdialogex.h"
#include "FightDialog.h"
#include "ConnectDialog.h"


// SelectDialog 대화 상자

IMPLEMENT_DYNAMIC(SelectDialog, CDialog)

SelectDialog::SelectDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SELECT, pParent)
	, m_character(0)
{

}

SelectDialog::~SelectDialog()
{
}

void SelectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_R_C1, m_character);
	DDX_Control(pDX, IDC_BUTTON2, m_select_ok);
}


BEGIN_MESSAGE_MAP(SelectDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &SelectDialog::OnBnClickedButton2)
	ON_WM_PAINT()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_R_C1, &SelectDialog::OnCharacterType)
	ON_BN_CLICKED(IDC_R_C2, &SelectDialog::OnCharacterType)
	ON_BN_CLICKED(IDC_R_C3, &SelectDialog::OnCharacterType)
	ON_BN_CLICKED(IDC_R_C4, &SelectDialog::OnCharacterType)
END_MESSAGE_MAP()


// SelectDialog 메시지 처리기
BOOL SelectDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 캐릭터 선택 기본값 설정
	m_character = 0;
	selCharacter = 0;
	UpdateData(FALSE);

	m_select_ok.LoadBitmaps(IDB_BMP3, NULL, NULL, NULL);
	m_select_ok.SizeToContent();

	m_png_image.Load(L"Porori.png");
	m_png_image2.Load(L"Darami1.png");
	m_png_image3.Load(L"Daram2.png");
	m_png_image4.Load(L"RealDaramg.png");
	return true;
}

void SelectDialog::OnBnClickedButton2()
{ 
	ConnectDialog connect;
	connect.selCharacter = selCharacter;
	connect.ID = ID;
	if (connect.DoModal() == IDOK)	// 캐릭터 선택했는지 보내주기
	{
		UpdateData(FALSE);
	}
}
void SelectDialog::OnCharacterType()	// 캐릭터 선택 라디오버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	selCharacter = m_character;
}

void SelectDialog::OnPaint()
{
	CDialogEx::OnPaint();
	CClientDC dc(this);
	CImage Image;
	Image.Load(_T("select.png"));
	Image.BitBlt(dc.m_hDC, 0, 0);// 배경화면


	m_png_image.Draw(dc, 30, 180);
	m_png_image2.Draw(dc, 290, 220);
	m_png_image3.Draw(dc, 570, 180);
	m_png_image4.Draw(dc, 770, 190);// 캐릭터
}

