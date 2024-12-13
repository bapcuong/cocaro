#pragma once
#include "Oco.h"
#define XDAU  50
#define YDAU  50

class Banco
{
public:
	Oco ds[20][20];
	int nguoichoi;
	int dieukhien; // dieukhien = 1 thi dc choi, = 0 thi k dc choi
	Banco();
	void vehinh(CClientDC* pdc);
	void tickbanco(CClientDC* pdc, CPoint p);
	int checkwin_ngang(int mi, int mj);
	int checkwin_doc(int mi, int mj);
	int checkwin_cheophai(int mi, int mj);
	int checkwin_cheotrai(int mi, int mj);
	int checkwin(int mi, int mj);
	void thongbaowinner(CClientDC* pdc);

	//void resetGame(CClientDC* pdc);
	//virtual BOOL PreTranslateMessage(MSG* pMsg);

};

