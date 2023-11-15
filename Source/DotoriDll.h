// DotoriDll.h : DotoriDll DLL의 주 헤더 파일
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.


// CDotoriDllApp
// 이 클래스 구현에 대해서는 DotoriDll.cpp를 참조하세요.
//

class CDotoriDllApp : public CWinApp
{
public:
	CDotoriDllApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern "C" __declspec(dllimport) CString Dtotal(int i, int j, int z);
extern "C" __declspec(dllimport) CString iswhoWin(int p[], int r[], CString p_id, CString r_id);
