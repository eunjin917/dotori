// Logindialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "Logindialog.h"
#include "afxdialogex.h"
#include "SignDialog.h"
#include "SelectDialog.h"
#include <string>
#include "SaveLoad.h"
#include "Player.h"



// Logindialog 대화 상자

IMPLEMENT_DYNAMIC(Logindialog, CDialog)

Logindialog::Logindialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_LOGIN, pParent)
	, m_input_id(_T(""))
	, m_input_pw(_T(""))
{

}

Logindialog::~Logindialog()
{
}

void Logindialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_input_id);
	DDX_Text(pDX, IDC_EDIT_PW, m_input_pw);
}


BEGIN_MESSAGE_MAP(Logindialog, CDialog)
	ON_BN_CLICKED(IDOK, &Logindialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTT_SIGNUP, &Logindialog::OnBnClickedButtSignup)
	ON_BN_CLICKED(IDCANCEL, &Logindialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// Logindialog 메시지 처리기


void Logindialog::OnBnClickedButtSignup()    //확인(회원가입)
{
	SignDialog Sign;
	FILE *IDPW;
	CString rString;
	if (Sign.DoModal() == IDOK){
		fopen_s(&IDPW, "IDPW.txt", "a");

		CT2CA pszConvertedAnsiString(Sign.m_input_id);
		std::string s1(pszConvertedAnsiString);
		CT2CA pszConvertedAnsiString2(Sign.m_input_pw);
		std::string s2(pszConvertedAnsiString2);
		const char *a = s1.c_str();
		const char *b = s2.c_str();

		fprintf_s(IDPW, "%s %s\n", a, b);

		fclose(IDPW);

		makeNewSave(Sign.m_input_id);

		rString.Format(_T("회원가입이 되었습니다."));
		AfxMessageBox(rString);

		UpdateData(FALSE);
	}
}

void Logindialog::OnBnClickedOk()
{
	SelectDialog Select;
	int idcheck = 0, pwcheck = 0, mas;
	char id[20];
	char pw[20];
	FILE *IDPW;
	CString rString;
	//Logindialog Login;
	fopen_s(&IDPW, "IDPW.txt", "r");  // 마스터 파일 Open 
	UpdateData(TRUE);
	while (1) {
		mas = fscanf_s(IDPW, "%s %s", id, sizeof(id), pw, sizeof(pw));
		if (m_input_id == id) {
			idcheck = 1;
			if (m_input_pw == pw)
				pwcheck = 1;
		}
		if (mas == EOF)
			break;
	}
	fclose(IDPW);

	if (idcheck == 1 && pwcheck == 1) {
		player.playerID = m_input_id;
		rString.Format(_T("로그인이 되었습니다."));
		AfxMessageBox(rString);
		Invalidate(TRUE);
		UpdateData(FALSE);
		
		Select.ID = m_input_id;
		if (Select.DoModal() == IDOK)
		{
		}
	}
	else {
		rString.Format(_T("아이디 또는 비밀번호가 잘못 되었습니다."));
		AfxMessageBox(rString);
	}
}

void Logindialog::makeNewSave(CString playerID) {
	SaveLoad *pData = new SaveLoad;

	pData->dataset(playerID, 0, 0, 0);

	pData->datasave();

	delete pData;
}

void Logindialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}
