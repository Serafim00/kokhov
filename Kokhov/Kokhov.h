// Kokhov.h : main header file for the KOKHOV application
//

#if !defined(AFX_KOKHOV_H__3F46AD64_4230_42BE_AED5_D37D8FCEC3AA__INCLUDED_)
#define AFX_KOKHOV_H__3F46AD64_4230_42BE_AED5_D37D8FCEC3AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKokhovApp:
// See Kokhov.cpp for the implementation of this class
//

class CKokhovApp : public CWinApp
{
public:
	CKokhovApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKokhovApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKokhovApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOKHOV_H__3F46AD64_4230_42BE_AED5_D37D8FCEC3AA__INCLUDED_)
