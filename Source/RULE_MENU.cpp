// RULE_MENU.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "RULE_MENU.h"
#include "afxdialogex.h"


// RULE_MENU 대화 상자

IMPLEMENT_DYNAMIC(RULE_MENU, CDialog)

RULE_MENU::RULE_MENU(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MENU_RULE, pParent)
{

}

RULE_MENU::~RULE_MENU()
{
}

void RULE_MENU::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RULE_MENU, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// RULE_MENU 메시지 처리기


void RULE_MENU::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CImage Image;
	Image.Load(L"Menu_rule.png");
	Image.Draw(dc, 0, 0);
}
