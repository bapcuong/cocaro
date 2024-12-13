#include "pch.h"
#include "Banco.h"

Banco::Banco()
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			ds[i][j] = Oco(XDAU +  DAI * j, YDAU + DAI * i);
		}
	}
	nguoichoi = 1;
	dieukhien = 1;  // dc choi
}

void Banco::vehinh(CClientDC* pdc)
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			ds[i][j].vehinh(pdc);
		}
	}
}

void Banco::tickbanco(CClientDC* pdc,CPoint p)
{
	int i = 0, j = 0;
	if(dieukhien == 1)
	{
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
				if (ds[i][j].giatri == 0)
				{
					if (ds[i][j].tickoco(pdc, p, nguoichoi) == 1)
						if (checkwin(i, j) == 1) // neu win
						{
							dieukhien = 0;
							/// thong bao winner
							thongbaowinner(pdc);
						}
						else
						{
							nguoichoi = nguoichoi * -1;  // doi nguoi choi
						}
						
				}
		}
	}
	
}

int Banco::checkwin_ngang(int mi, int mj)
{
	int i = mi;
	int j = mj;
	int dem = 0;
	// dem qua phia ben trai
	for (j = mj - 1; j >= 0; j--)
		if (ds[i][j].giatri == nguoichoi)
			dem++; 
		else
			break;
	// dem qua phia ben phai
	for (j = mj + 1; j < 20; j++)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
	}
	if (dem == 4)
		return 1;
	else
		return 0;
}

int Banco::checkwin_doc(int mi, int mj)
{
	int i = mi, j = mj;
	int dem = 0;
	//kiem tra len tren;
	for (i = mi - 1; i >= 0; i--)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
	}
	//kiem tra xuong duoi
	for (i = mi + 1; i < 20; i++)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
	}
	if (dem == 4)
		return 1;
	else
		return 0;
	
}

int Banco::checkwin_cheophai(int mi, int mj)
{
	int i = mi;
	int j = mj;
	int dem = 0;
	// ktra cheo len tren, ca i va j  cung giam
	i = mi - 1;
	j = mj - 1;
	while (i >= 0 && j >= 0)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i--;
		j--;
	}
	// ktra cheo xuong duoi, ca i va j cung tang
	i = mi + 1;
	j = mj + 1;
	while (i < 20 && j < 20)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i++;
		j++;
	}
	if (dem == 4)
		return 1;
	else
		return 0;
}

int Banco::checkwin_cheotrai(int mi, int mj)
{
	int i = mi;
	int j = mj;
	int dem = 0;
	// ktra cheo trai tren, i giam va j tang
	i = mi - 1;
	j = mj + 1;
	while (i >= 0 && j < 20)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i--;
		j++;
	}
	// ktra cheo trai duoi, i tang va j giam
	i = mi + 1;
	j = mj - 1;
	while (i < 20 && j >= 0)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i++;
		j--;
	}
	if (dem == 4)
		return 1;
	else
		return 0;
}

int Banco::checkwin(int mi, int mj)
{
	int kq = 0;
	if (checkwin_ngang(mi, mj) == 1)
		kq = 1;
	else
		if (checkwin_doc(mi, mj) == 1)
			kq = 1;
		else
			if (checkwin_cheophai(mi, mj) == 1)
				kq = 1;
			else
				if (checkwin_cheotrai(mi, mj) == 1)
					kq = 1;
				//else
				//	if(checkwin(mi, mj) == 1) // neu win
				//	{
				//		dieukhien = 0;

				//		// Reset trò chơi sau khi thắng
				//		resetgame();
				//		return; // Kết thúc xử lý
				//	}
	return kq;
}

void Banco::thongbaowinner(CClientDC* pdc)
{
	CString strx, stro;
	strx.Format(_T("X is winner"));
	stro.Format(_T("O is winner"));
	int xmoi = 20;
	int ymoi = 20;
	if (nguoichoi == 1)
		pdc->TextOutW(xmoi, ymoi, stro);
	if (nguoichoi == -1)
		pdc->TextOutW(xmoi, ymoi, strx);
}



//void Banco::resetgame()
//{
//	int i, j;
//	for (i = 0; i < 20; i++) {
//		for (j = 0; j < 20; j++) {
//			ds[i][j].giatri = 0;  // Đặt lại giá trị tất cả các ô về 0 (trống)
//		}
//	}
//	nguoichoi = 1;  // Đặt lại người chơi bắt đầu là X
//	dieukhien = 1;  // Cho phép tiếp tục chơi
//}
//
//void Banco::OnBnClickedReset()
//{
//	
//		resetgame();  // Gọi hàm reset để làm mới bàn cờ
//		Invalidate(); // Vẽ lại giao diện
//	
//}

