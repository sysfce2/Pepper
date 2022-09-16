/****************************************************************************************************
* Copyright © 2018-2021 Jovibor https://github.com/jovibor/   										*
* This software is available under the "MIT License".                                               *
* https://github.com/jovibor/Pepper/blob/master/LICENSE												*
* Pepper - PE (x86) and PE+ (x64) files viewer, based on libpe: https://github.com/jovibor/Pepper	*
* libpe - Windows library for reading PE (x86) and PE+ (x64) files inner structure information.		*
* https://github.com/jovibor/libpe																	*
****************************************************************************************************/
#pragma once
#include "CSplitterEx.h"

import Utility;
using namespace util;

class CChildFrame : public CMDIChildWndEx
{
public:
	auto GetWndStatData()->std::vector<SWINDOWSTATUS>&;
	void SetWindowStatus(HWND hWnd, bool fVisible);
	CSplitterEx m_stSplitterMain, m_stSplitterRight, m_stSplitterRightTop, m_stSplitterRightBottom;
	DECLARE_DYNCREATE(CChildFrame)
private:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnClose();
	BOOL PreCreateWindow(CREATESTRUCT& cs) override;
	BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) override;
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd);
	DECLARE_MESSAGE_MAP()
private:
	bool m_fSplitterCreated { false };
	UINT m_cx { }, m_cy { };
	std::vector<SWINDOWSTATUS> m_vecWndStatus { };
};