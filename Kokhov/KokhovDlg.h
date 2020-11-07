// KokhovDlg.h : header file
//
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_KOKHOVDLG_H__FA5B5070_0AD5_4F46_A0BE_5B88F63E39E7__INCLUDED_)
#define AFX_KOKHOVDLG_H__FA5B5070_0AD5_4F46_A0BE_5B88F63E39E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKokhovDlg dialog

class CKokhovDlg : public CDialog
{
// Construction
public:
	CKokhovDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKokhovDlg)
	enum { IDD = IDD_KOKHOV_DIALOG };
	CMSFlexGrid	m_FG1;
	CMSFlexGrid	m_FG2;
	float	m_edit1;
	float	m_edit2;
	int		m_edit3;
	float	m_edit4;
	float	m_edit5;
	float	m_edit6;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKokhovDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKokhovDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickMsFlexgrid1();
	afx_msg void OnKeyPressMsFlexgrid1(short FAR* KeyAscii);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOKHOVDLG_H__FA5B5070_0AD5_4F46_A0BE_5B88F63E39E7__INCLUDED_)
