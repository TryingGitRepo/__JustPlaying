
// TestGetHub2View.cpp : implementation of the CTestGetHub2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestGetHub2.h"
#endif

#include "TestGetHub2Doc.h"
#include "TestGetHub2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestGetHub2View

IMPLEMENT_DYNCREATE(CTestGetHub2View, CView)

BEGIN_MESSAGE_MAP(CTestGetHub2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestGetHub2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestGetHub2View construction/destruction

CTestGetHub2View::CTestGetHub2View()
{
	// TODO: add construction code here

}

CTestGetHub2View::~CTestGetHub2View()
{
}

BOOL CTestGetHub2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestGetHub2View drawing

void CTestGetHub2View::OnDraw(CDC* /*pDC*/)
{
	CTestGetHub2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestGetHub2View printing


void CTestGetHub2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestGetHub2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestGetHub2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestGetHub2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestGetHub2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestGetHub2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestGetHub2View diagnostics

#ifdef _DEBUG
void CTestGetHub2View::AssertValid() const
{
	CView::AssertValid();
}

void CTestGetHub2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestGetHub2Doc* CTestGetHub2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestGetHub2Doc)));
	return (CTestGetHub2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTestGetHub2View message handlers
