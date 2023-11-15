// SignDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "SignDialog.h"
#include "afxdialogex.h"


// SignDialog 대화 상자

IMPLEMENT_DYNAMIC(SignDialog, CDialog)

SignDialog::SignDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SIGN, pParent)
	, m_input_id(_T(""))
	, m_input_pw(_T(""))
{

}

SignDialog::~SignDialog()
{
}

void SignDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_input_id);
	DDX_Text(pDX, IDC_EDIT_PW, m_input_pw);
}


BEGIN_MESSAGE_MAP(SignDialog, CDialog)
	ON_BN_CLICKED(IDOK, &SignDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTT_CHECK, &SignDialog::OnBnClickedButtCheck)
	ON_BN_CLICKED(IDCANCEL, &SignDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// SignDialog 메시지 처리기



void SignDialog::OnBnClickedButtCheck()
{
	int check = 0, mas;
	char id[20];
	char pw[20];

	fopen_s(&IDPW, "IDPW.txt", "r");  			// 마스터 파일 Open 
	UpdateData(TRUE);

	while (1) {
		mas = fscanf_s(IDPW, "%s %s", id, sizeof(id), pw, sizeof(pw));
		if (m_input_id == id)
			check++;
		if (mas == EOF)
			break;
	}

	fclose(IDPW);

	if (check == 0) {
		MessageBox(_T("사용 가능한 아이디입니다."));
		GetDlgItem(IDOK)->EnableWindow(TRUE);
	}
	else {
		CString rString;
		rString.Format(_T("아이디가 중복됩니다."));
		AfxMessageBox(rString);
	}
	UpdateData(FALSE);
}

void SignDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();
}

void SignDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}
