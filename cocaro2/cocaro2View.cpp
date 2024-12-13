
// cocaro2View.cpp : implementation of the Ccocaro2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "cocaro2.h"
#endif

#include "cocaro2Doc.h"
#include "cocaro2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccocaro2View

IMPLEMENT_DYNCREATE(Ccocaro2View, CView)

BEGIN_MESSAGE_MAP(Ccocaro2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Ccocaro2View construction/destruction

Ccocaro2View::Ccocaro2View() noexcept
{
	// TODO: add construction code here
	/*hcn1 = Hcn(10, 10, 200, 100);
	oco1 = Oco(200, 200);*/
	banco = Banco();
	
}

Ccocaro2View::~Ccocaro2View()
{
}

BOOL Ccocaro2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Ccocaro2View drawing

void Ccocaro2View::OnDraw(CDC* /*pDC*/)
{
	Ccocaro2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	/*hcn1.vehinh(&pdc);*/
	
	/*Hcnmau hcn2 = Hcnmau(200, 200, 300, 250);
	hcn2.setMau(0, 0, 200);
	hcn2.vehinh(&pdc);*/

	/*oco1.giatri = 0;
	oco1.vehinh(&pdc);*/
	banco.vehinh(&pdc);
}

void Ccocaro2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ccocaro2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ccocaro2View diagnostics

#ifdef _DEBUG
void Ccocaro2View::AssertValid() const
{
	CView::AssertValid();
}

void Ccocaro2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ccocaro2Doc* Ccocaro2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ccocaro2Doc)));
	return (Ccocaro2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ccocaro2View message handlers


void Ccocaro2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default	
	CClientDC pdc(this);
	/*oco1.tickoco(&pdc, point, -1);*/
	banco.tickbanco(&pdc, point);
	CView::OnLButtonUp(nFlags, point);
}


void Ccocaro2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDblClk(nFlags, point);
}
