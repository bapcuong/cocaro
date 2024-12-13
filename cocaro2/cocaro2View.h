
// cocaro2View.h : interface of the Ccocaro2View class
//

#pragma once
#include "Hcn.h"
#include "Hcnmau.h"
#include "Oco.h"
#include "Banco.h"
class Ccocaro2View : public CView
{
protected: // create from serialization only
	Ccocaro2View() noexcept;
	DECLARE_DYNCREATE(Ccocaro2View)

// Attributes
public:
	Ccocaro2Doc* GetDocument() const;

// Operations
public:
	/*Hcn hcn1;
	Oco oco1;*/
	Banco banco;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~Ccocaro2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in cocaro2View.cpp
inline Ccocaro2Doc* Ccocaro2View::GetDocument() const
   { return reinterpret_cast<Ccocaro2Doc*>(m_pDocument); }
#endif

