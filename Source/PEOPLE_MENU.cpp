// PEOPLE_MENU.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "PEOPLE_MENU.h"
#include "afxdialogex.h"


// PEOPLE_MENU 대화 상자

IMPLEMENT_DYNAMIC(PEOPLE_MENU, CDialog)

PEOPLE_MENU::PEOPLE_MENU(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MENU_PEOPLE, pParent)
{

}

PEOPLE_MENU::~PEOPLE_MENU()
{
}

void PEOPLE_MENU::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PEOPLE_MENU, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// PEOPLE_MENU 메시지 처리기


void PEOPLE_MENU::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CImage Image;
	Image.Load(L"PEOPLE.png");
	Image.Draw(dc, 0, 0);
}
