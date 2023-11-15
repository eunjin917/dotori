// ConnectDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dotori.h"
#include "ConnectDialog.h"
#include "afxdialogex.h"
#include "FightDialog.h"
#include "CMySocket.h"
#include "DotoriDll.h"


// ConnectDialog 대화 상자

IMPLEMENT_DYNAMIC(ConnectDialog, CDialog)

ConnectDialog::ConnectDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CONNECT, pParent)
	, m_strName(_T(""))
	, m_iType(0)
	, m_timer(_T(""))
	, m_ID(_T(""))
	, m_otherID(_T(""))
	, m_otherSum(_T(""))
	, m_sum(_T(""))
{

}

ConnectDialog::~ConnectDialog()
{
}

void ConnectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ESERVNAME, m_strName);
	DDX_Radio(pDX, IDC_RSERVER, m_iType);
	DDX_Control(pDX, IDC_BUTTON_GAMESTART, m_connect_fight);
	DDX_Text(pDX, IDC_EDIT_TIMER, m_timer);
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDX_Text(pDX, IDC_EDIT_O_ID, m_otherID);
	//  DDX_Text(pDX, IDC_EDIT_O_SUM, m_sum);
	DDX_Text(pDX, IDC_EDIT_O_SUM, m_otherSum);
	DDX_Text(pDX, IDC_EDIT_SUM, m_sum);
}


BEGIN_MESSAGE_MAP(ConnectDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_GAMESTART, &ConnectDialog::OnBnClickedButtonGamestart)
	ON_BN_CLICKED(IDC_RSERVER, &ConnectDialog::OnRType)
	ON_BN_CLICKED(IDC_RCLIENT, &ConnectDialog::OnRType)
	ON_BN_CLICKED(IDC_BLISTEN, &ConnectDialog::OnBnClickedBlisten)
	ON_BN_CLICKED(IDC_BCONNECT, &ConnectDialog::OnBnClickedBconnect)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// ConnectDialog 메시지 처리기

BOOL ConnectDialog::OnInitDialog()
{
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_strName = "localhost"; // 자기자신 PC로 접속(Editor Control)
	m_iType = 0; // radio button
	m_timer = "연결 대기 중";
	m_ID = ID;
	UpdateData(FALSE);

	count = 0;

	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);

	m_connect_fight.LoadBitmaps(IDB_BMP4, NULL, NULL, NULL);
	m_connect_fight.SizeToContent();

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
	m_png_image_check.Load(L"dotori_check.png");


	return TRUE; // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void ConnectDialog::OnPaint()
{
	CDialogEx::OnPaint();

	CClientDC dc(this);
	CImage Image;
	Image.Load(_T("connect.png"));
	Image.BitBlt(dc.m_hDC, 0, 0);


	switch (selCharacter) {
	case 0:
		m_character_image.Load(L"Porori.png");
		m_character_image.Draw(dc, -10, 220);
		break;
	case 1:
		m_character_image.Load(L"Darami1.png");
		m_character_image.Draw(dc, 20, 240);
		break;
	case 2:
		m_character_image.Load(L"Daram2.png");
		m_character_image.Draw(dc, 50, 200);
		break;
	case 3:
		m_character_image.Load(L"RealDaramg.png");
		m_character_image.Draw(dc, 20, 220);
		break;
	}

	if (otherCharacter > -1)
	{
		switch (otherCharacter) {
		case 0:
			m_other_image.Load(L"Porori.png");
			m_other_image.Draw(dc, 820, 220);
			break;
		case 1:
			m_other_image.Load(L"Darami1.png");
			m_other_image.Draw(dc, 840, 240);
			break;
		case 2:
			m_other_image.Load(L"Daram2.png");
			m_other_image.Draw(dc, 870, 200);
			break;
		case 3:
			m_other_image.Load(L"RealDaramg.png");
			m_other_image.Draw(dc, 840, 220);
			break;
		}
	}

	if (count == 2) {
		second = 3;
		SetTimer(0, 1000, NULL);	// 게임 시작 전 3 2 1
	}
}

void ConnectDialog::OnBnClickedButtonGamestart()
{
	// 상대방에 뜨게 하기
	int iSent;
	const char* strMsg;
	char str[20];

	if (count == 1) {
		count = 2;
		str[1] = '2';
		switch (selCharacter)
		{
		case 0:
			str[0] = '0';
			break;
		case 1:
			str[0] = '1';
			break;
		case 2:
			str[0] = '2';
			break;
		case 3:
			str[0] = '3';
			break;
		}
	}
	else if (count == 0) {
		count = 1;
		str[1] = '1';
		switch (selCharacter)
		{
		case 0:
			str[0] = '0';
			break;
		case 1:
			str[0] = '1';
			break;
		case 2:
			str[0] = '2';
			break;
		case 3:
			str[0] = '3';
			break;
		}
	}

	int i = 0;
	while (ID[i] != '\0') {// ID찾기
		str[i + 2] = ID[i];
		i++;
	}
	strMsg = str;

	int iLen = strlen(strMsg) + 1;
	iSent = m_Csocket.Send(LPCTSTR(strMsg), iLen);

	if (iSent == SOCKET_ERROR) {
		MessageBox(_T("error"));
	}

	m_timer = "준비되었습니다. 상대방을 기다리는 중입니다.";
	UpdateData(FALSE);
	GetDlgItem(IDC_BUTTON_GAMESTART)->ShowWindow(FALSE);	// 더 이상 버튼 못누르게

	if (count == 2) {
		Invalidate(TRUE);
	}
}

void ConnectDialog::OnRType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_iType == 0) {
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}

void ConnectDialog::OnAccept()
{
	m_Ssocket.Accept(m_Csocket);
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_GAMESTART)->EnableWindow(TRUE);
}
void ConnectDialog::OnConnect()
{
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_GAMESTART)->EnableWindow(TRUE);
}
void ConnectDialog::OnClose()
{
	m_Csocket.Close();
	if (m_iType == 0)
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}

void ConnectDialog::OnSend() {}


void ConnectDialog::OnBnClickedBlisten()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	m_Ssocket.Create(4000);
	m_Ssocket.Listen();
}

void ConnectDialog::OnBnClickedBconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	UpdateData(TRUE); 
	m_Csocket.Create();
	m_Csocket.Connect(m_strName, 4000);
}

void ConnectDialog::OnReceive()
{
	if (round == 0) {
		char *pBuf = new char[1024]{ '\0' };
		int iBufSize = 1025;
		int iRcvd;

		iRcvd = m_Csocket.Receive(pBuf, iBufSize);

		if (iRcvd == SOCKET_ERROR)
		{
		}
		else
		{
			pBuf[iRcvd - 1] = NULL;

			if (pBuf[0] == '0') {
				otherCharacter = 0;
			}
			else if (pBuf[0] == '1') {
				otherCharacter = 1;
			}
			else if (pBuf[0] == '2') {
				otherCharacter = 2;
			}
			else if (pBuf[0] == '3') {
				otherCharacter = 3;
			}

			if (pBuf[1] == '1')
				count = 1;
			else if (pBuf[1] == '2')
				count = 2;

			int i = 2;
			char str[20];
			while (pBuf[i] != '\0') {
				str[i - 2] = pBuf[i];
				i++;
			}

			m_otherID = str;
			otherID = m_otherID;
			UpdateData(FALSE);
			Invalidate(TRUE);
		}
	}

	else {
		char *pBuf = new char[1024];
		int iBufSize = 1025;
		int iRcvd;

		iRcvd = m_Csocket.Receive(pBuf, iBufSize);

		if (iRcvd == SOCKET_ERROR)
		{
		}
		else
		{
			pBuf[iRcvd - 1] = NULL;

			for (int i = 0; i < 3; i++) {
				if (pBuf[i] == '1')
					otherNum[i] = 1;
				else if (pBuf[i] == '2')
					otherNum[i] = 2;
				else if (pBuf[i] == '3')
					otherNum[i] = 3;
				else if (pBuf[i] == '4')
					otherNum[i] = 4;
				else if (pBuf[i] == '5')
					otherNum[i] = 5;
				else if (pBuf[i] == '6')
					otherNum[i] = 6;
				else if (pBuf[i] == '7')
					otherNum[i] = 7;
				else if (pBuf[i] == '8')
					otherNum[i] = 8;
				else if (pBuf[i] == '9')
					otherNum[i] = 9;
			}

			CClientDC dc(this);
			for (int i = 0; i < 3; i++) {
				if (otherNum[i] == 1) {
					m_png_image_check.Draw(dc, 678, 235);
				}
				else if (otherNum[i] == 2) {
					m_png_image_check.Draw(dc, 728, 235);
				}
				else if (otherNum[i] == 3) {
					m_png_image_check.Draw(dc, 778, 235);
				}
				else if (otherNum[i] == 4) {
					m_png_image_check.Draw(dc, 678, 285);
				}
				else if (otherNum[i] == 5) {
					m_png_image_check.Draw(dc, 728, 285);
				}
				else if (otherNum[i] == 6) {
					m_png_image_check.Draw(dc, 778, 285);
				}
				else if (otherNum[i] == 7) {
					m_png_image_check.Draw(dc, 678, 335);
				}
				else if (otherNum[i] == 8) {
					m_png_image_check.Draw(dc, 728, 335);
				}
				else if (otherNum[i] == 9) {
					m_png_image_check.Draw(dc, 778, 335);
				}
			}

			// 상대 합계 출력
			CString s2;
			s2 = Dtotal(otherNum[0], otherNum[1], otherNum[2]);
			m_otherSum = s2;
			UpdateData(FALSE);

			// 모두 동일한지 확인
			// 먼저 정렬
			int temp;
			for (int i = 0; i < 3; i++)    // 요소의 개수만큼 반복
				for (int j = 0; j < 2; j++)   // 요소의 개수 - 1만큼 반복
					if (clickNum[j] > clickNum[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
					{                                 // 큰 값을
						temp = clickNum[j];
						clickNum[j] = clickNum[j + 1];
						clickNum[j + 1] = temp;            // 다음 요소로 보냄
					}
			for (int i = 0; i < 3; i++)    // 요소의 개수만큼 반복
				for (int j = 0; j < 2; j++)   // 요소의 개수 - 1만큼 반복
					if (otherNum[j] > otherNum[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
					{                                 // 큰 값을
						temp = otherNum[j];
						otherNum[j] = otherNum[j + 1];
						otherNum[j + 1] = temp;            // 다음 요소로 보냄
					}

			if (clickNum[0] == otherNum[0] && clickNum[1] == otherNum[1] && clickNum[2] == otherNum[2]) {
				CString a;
				a.Format(_T("선택한 도토리가 동일합니다. 다시 선택해주십시오."));
				m_timer = a;
				UpdateData(FALSE);
				second = 10;
				dcount = 0;
				SetTimer(1, 1000, NULL);
				printIMG();
			}
			else {
				// 누가 이겼는지 출력
				CString result;
				//result = iswhoWin(clickNum, otherNum, ID, otherID);
				m_timer = result;
				UpdateData(FALSE);
			}
		}
	}
}

void ConnectDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString str;

	switch (nIDEvent) {
	case 0:
		str.Format(_T("%d초 후 시작"), second);
		m_timer = str;
		UpdateData(FALSE);
		second--;

		if (second == 0) {	// 3초 후 1라운드
			KillTimer(0);

			second = 10;
			SetTimer(1, 1000, NULL);	// 1라운드 시작
			round = 1;
		}
		break;
	case 1:
		if (second == 10) {
			printIMG();	// 도토리 사진 전체 출력
		}

		str.Format(_T("<%d라운드> %d"), round, second);
		m_timer = str;
		UpdateData(FALSE);
		second--;
		if (second == 0) {	// 10초 후 2라운드
			KillTimer(1);

			if (dcount != 3) {
				srand(time(NULL));
				for (int i = 0; i < 3; i++) {
					clickNum[i] = rand() % 9 + 1;
					while (i > 0 && clickNum[i - 1] == clickNum[i])
						clickNum[i] = rand() % 9 + 1;
				}
			}
			round1();
		}
		break;
	case 2:
		second++;
		if (second == 3) {
			KillTimer(2);
		}
		break;

		CDialog::OnTimer(nIDEvent);
	}
}

void ConnectDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (dcount != 3 && round!=0) {
		CClientDC dc(this);
		CImage Image;
		if (220 < point.x && 250 < point.y && 265 > point.x && 290 > point.y) {
			m_png_image_check.Draw(dc, 208, 235);
			clickNum[dcount++] = 1;
		}
		else if (266 < point.x && 250 < point.y && 319 > point.x && 290 > point.y) {
			m_png_image_check.Draw(dc, 258, 235);
			clickNum[dcount++] = 2;
		}
		else if (320 < point.x && 250 < point.y && 370 > point.x && 290 > point.y) {
			m_png_image_check.Draw(dc, 308, 235);
			clickNum[dcount++] = 3;
		}
		else if (220 < point.x && 300 < point.y && 265 > point.x && 340 > point.y) {
			m_png_image_check.Draw(dc, 208, 285);
			clickNum[dcount++] = 4;
		}
		else if (266 < point.x && 300 < point.y && 310 > point.x && 340 > point.y) {
			m_png_image_check.Draw(dc, 258, 285);
			clickNum[dcount++] = 5;
		}
		else if (320 < point.x && 300 < point.y && 370 > point.x && 340 > point.y) {
			m_png_image_check.Draw(dc, 308, 285);
			clickNum[dcount++] = 6;
		}
		else if (220 < point.x && 350 < point.y && 265 > point.x && 390 > point.y) {
			m_png_image_check.Draw(dc, 208, 335);
			clickNum[dcount++] = 7;
		}
		else if (266 < point.x && 350 < point.y && 310 > point.x && 390 > point.y) {
			m_png_image_check.Draw(dc, 258, 335);
			clickNum[dcount++] = 8;
		}
		else if (320 < point.x && 350 < point.y && 370 > point.x && 390 > point.y) {
			m_png_image_check.Draw(dc, 308, 335);
			clickNum[dcount++] = 9;
		}
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void ConnectDialog::printIMG()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
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


void ConnectDialog::round1()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	UpdateData(TRUE);

	// 네트워크 연결
	const char* strMsg;
	char str[3];
	int iSent;

	for (int i = 0; i < 3; i++) {
		switch (clickNum[i])
		{
		case 1:
			str[i] = '1';
			break;
		case 2:
			str[i] = '2';
			break;
		case 3:
			str[i] = '3';
			break;
		case 4:
			str[i] = '4';
			break;
		case 5:
			str[i] = '5';
			break;
		case 6:
			str[i] = '6';
			break;
		case 7:
			str[i] = '7';
			break;
		case 8:
			str[i] = '8';
			break;
		case 9:
			str[i] = '9';
			break;
		}
	}
	strMsg = str;

	int iLen = strlen(strMsg) + 1;
	iSent = m_Csocket.Send(LPCTSTR(strMsg), iLen);

	if (iSent == SOCKET_ERROR) {
		MessageBox(_T("error"));
	}

	// 내 합계 출력
	CString s;
	s = Dtotal(clickNum[0], clickNum[1], clickNum[2]);
	m_sum = s;
	UpdateData(FALSE);

	// 모두 동일한지 확인
	// 먼저 정렬
	int temp;
	for (int i = 0; i < 3; i++)    // 요소의 개수만큼 반복
		for (int j = 0; j < 2; j++)   // 요소의 개수 - 1만큼 반복
			if (clickNum[j] > clickNum[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
			{                                 // 큰 값을
				temp = clickNum[j];
				clickNum[j] = clickNum[j + 1];
				clickNum[j + 1] = temp;            // 다음 요소로 보냄
			}
	for (int i = 0; i < 3; i++)    // 요소의 개수만큼 반복
		for (int j = 0; j < 2; j++)   // 요소의 개수 - 1만큼 반복
			if (otherNum[j] > otherNum[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
			{                                 // 큰 값을
				temp = otherNum[j];
				otherNum[j] = otherNum[j + 1];
				otherNum[j + 1] = temp;            // 다음 요소로 보냄
			}
	if (clickNum[0] == otherNum[0] && clickNum[1] == otherNum[1] && clickNum[2] == otherNum[2]) {
		CString a;
		a.Format(_T("선택한 도토리가 동일합니다. 다시 선택해주십시오."));
		m_timer = a;
		UpdateData(FALSE);
		second = 10;
		dcount = 0;
		SetTimer(1, 1000, NULL);
		printIMG();
	}
	else {
		// 누가 이겼는지 출력
		CString result;
		//result = iswhoWin(clickNum, otherNum, ID, otherID);
		m_timer = result;
		UpdateData(FALSE);
	}
}