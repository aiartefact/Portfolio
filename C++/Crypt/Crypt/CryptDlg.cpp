
// CryptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Crypt.h"
#include "CryptDlg.h"
#include "afxdialogex.h"
//#include "stdint.h"
#include "afxdlgs.h"
#include "TEA.c"
#include "blowfish.c"
#include "CRC32.c"
#include "SHA-1.h"
#include "MD5.h"
#include "DES.h"
#include "AES.cpp"
#include "RC4.cpp"
#include "RC5.cpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int iA[26]={{'a'},{'b'},{'c'},{'d'},{'e'},{'f'},{'g'},{'h'},
				  {'i'},{'j'},{'k'},{'l'},{'m'},{'n'},{'o'},{'p'},
				  {'q'},{'r'},{'s'},{'t'},{'u'},{'v'},{'w'},{'x'},
				  {'y'},{'z'}};
const char cA[26]={{'a'},{'b'},{'c'},{'d'},{'e'},{'f'},{'g'},{'h'},
				  {'i'},{'j'},{'k'},{'l'},{'m'},{'n'},{'o'},{'p'},
				  {'q'},{'r'},{'s'},{'t'},{'u'},{'v'},{'w'},{'x'},
				  {'y'},{'z'}};
unsigned __int64 _64A[26]={{'a'},{'b'},{'c'},{'d'},{'e'},{'f'},{'g'},{'h'},
						  {'i'},{'j'},{'k'},{'l'},{'m'},{'n'},{'o'},{'p'},
						  {'q'},{'r'},{'s'},{'t'},{'u'},{'v'},{'w'},{'x'},
						  {'y'},{'z'}};
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCryptDlg dialog




CCryptDlg::CCryptDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCryptDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCryptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCryptDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCryptDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CCryptDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCryptDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CCryptDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CCryptDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCryptDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCryptDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCryptDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCryptDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCryptDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCryptDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCryptDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCryptDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCryptDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCryptDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCryptDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCryptDlg::OnBnClickedButton15)
END_MESSAGE_MAP()


// CCryptDlg message handlers

BOOL CCryptDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCryptDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCryptDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCryptDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCryptDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here	
	OnSysCommand(IDM_ABOUTBOX,0);
}

void CCryptDlg::OnBnClickedButton1() //TEA encrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to encrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}

		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d;
				int Bufr[1024],Bufw[1024],key[4];
				d = fs.GetLength();

				char str[10];
				itoa(d,str,10);
				fd.Write(&str,10);

				fk.Read(&key,4);
				for (int k=0 ; k < 4; k++)
					if (key[k]==0)
						key[k] = iA[k+k];
				while (fs.Read(&Bufr,1024))
				{
					int i=0,j=0;
					if ((d/1024 == 0) && (d%8 !=0))
					{
						while ((d+j)%8 !=0)
						{
							Bufr[d+j]=7;
							j++;
						}
					}
					while ((i<(d+j)) && (i<1024))
					{
						Bufw[i]=Bufr[i];
						Bufw[i+1]=Bufr[i+1];
						TEA_encrypt (Bufw+i,key);
						i+=2;
					}
					//if (((d+j)%2 != 0) && ((d+j)/1024 == 0))
					//fd.Write(&Bufw,i-1);
					//else fd.Write(&Bufw,i);
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton2() //TEA decrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to decrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		int y;
		y = fs.GetLength();
		if ((y-10) %8 != 0)
			{
				AfxMessageBox(_T("Source filesize must be multiply to 8"));
				return;
			}

		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d,d1;
				int d0;  //original length
				int Bufr[1024],Bufw[1024],key[4];
				d = fs.GetLength();

				char str[10];
				fs.Read(&str,10);
				d0=StrToIntA(str);
				d-=10;
				d0 %= 1024;
				d1=d;
				d1 %=1024;
				d0 = d1-d0;  //number of symbols empty to length be multiply to 8
				
				fk.Read(&key,4);
				for (int k=0 ; k < 4; k++)
					if (key[k]==0)
						key[k] = iA[k+k];
				while (fs.Read(&Bufr,1024))
				{
					int i=0;
					while ((i<d) && (i<1024))
					{
						Bufw[i]=Bufr[i];
						Bufw[i+1]=Bufr[i+1];
						TEA_decrypt (Bufw+i,key);
						i+=2;
					}
					if ((d-d0)/1024 == 0) 
						i-=d0;
					//if (((d-d0)%2 != 0) && ((d-d0)/1024 == 0))
					//fd.Write(&Bufw,i-1);
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CCryptDlg::OnBnClickedButton3() //Blowfish enrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to encrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}

		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d;
				unsigned long Bufr[1024],Bufw[1024];
				unsigned char key[56];
				d = fs.GetLength();

				char str[10];
				itoa(d,str,10);
				fd.Write(&str,10);

				fk.Read(&key,56);
				for (int k=0 ; k < 56; k++)
					if (key[k]==0)
						key[k] = cA[(k+k) % 26];
				BLOWFISH_CTX ctx;
				Blowfish_Init(&ctx,key,56);
				while (fs.Read(&Bufr,1024))
				{
					int i=0,j=0;
					if ((d/1024 == 0) && (d%8 !=0))
					{
						while ((d+j)%8 !=0)
						{
							Bufr[d+j]=7;
							j++;
						}
					}
					while ((i<(d+j)) && (i<1024))
					{
						Bufw[i]=Bufr[i];
						Bufw[i+1]=Bufr[i+1];
						Blowfish_Encrypt(&ctx,Bufw+i,Bufw+(i+1));
						i+=2;
					}
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton4() // Blowfish decrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to decrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		int y;
		y = fs.GetLength();
		if ((y-10) %8 != 0)
			{
				AfxMessageBox(_T("Source filesize must be multiply to 8"));
				return;
			}


		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d,d1;
				int d0;  //original length
				unsigned long Bufr[1024],Bufw[1024];
				unsigned char key[56];
				d = fs.GetLength();
				
				char str[10];
				fs.Read(&str,10);
				d0=StrToIntA(str);
				d-=10;
				d0 %= 1024;
				d1=d;
				d1 %=1024;
				d0 = d1-d0; //number of symbols empty to length be multiply to 8

				fk.Read(&key,56);
				for (int k=0 ; k < 56; k++)
					if (key[k]==0)
						key[k] = cA[(k+k) % 26];
				BLOWFISH_CTX ctx;
				Blowfish_Init(&ctx,key,56);
				while (fs.Read(&Bufr,1024))
				{
					int i=0;
					while ((i<d) && (i<1024))
					{
						Bufw[i]=Bufr[i];
						Bufw[i+1]=Bufr[i+1];
						Blowfish_Decrypt(&ctx,Bufw+i,Bufw+(i+1));
						i+=2;
					}
					if ((d-d0)/1024 == 0) 
						i-=d0;
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton5() //CRC32
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpen(TRUE,NULL,(LPCTSTR)_T("Choose source file"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fd; //destination
	CString fname;
	if(DlgOpen.DoModal()==IDOK)  
	{
		fname = DlgOpen.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		if(DlgSave.DoModal()==IDOK)
		{
			fname = DlgSave.GetPathName();
			fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
			unsigned int d,hash;
			d = fs.GetLength();
			unsigned char *Buf;
			Buf = new unsigned char[d];
			fs.Read(Buf,d);
			hash=Crc32(Buf,d);
			//unsigned int k=0xFFFFFFF;
			char str[9];
			itoa(hash,str,16);
			strupr(str);
			//HWND hWnd = GetSafeHwnd();
			//MessageBoxA(hWnd,strupr(str),"Title",NULL);
			if ((str[7] == 0))
				fd.Write(&str,7);
			else
				fd.Write(&str,8);
			HWND hWnd = GetSafeHwnd();
			MessageBoxA(hWnd,"Complete!","Report",NULL);
			fd.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton6() //SHA-1
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpen(TRUE,NULL,(LPCTSTR)_T("Choose source file"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fd; //destination
	CString fname;

	/////////////////////
/*	HWND hWnd = GetSafeHwnd();

	OPENFILENAME of;
	of.lStructSize = sizeof(of);
	of.hwndOwner = hWnd;
	of.hInstance = GetModuleHandle(0);
	of.lpstrFilter = NULL;
	of.lpstrTitle =NULL;//(LPCTSTR)"1111111111";
	GetOpenFileName(&of);

	fname = of.lpstrFileTitle;
	*/

	if(DlgOpen.DoModal()==IDOK)  
	{
		fname = DlgOpen.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		if(DlgSave.DoModal()==IDOK)
		{
			fname = DlgSave.GetPathName();

			fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
			unsigned int d,i;
			d = fs.GetLength();			
			unsigned int PaddingLen = 56 - (d % 64);
			if (d % 64 >= 56) 
				PaddingLen +=64;
			unsigned int FullLen = d + PaddingLen + 8; //8 - is equal to length of file
			
			unsigned char *Buf;
			Buf = new unsigned char [FullLen];
			fs.Read(Buf,d);
			memcpy(Buf+d, PADDING, PaddingLen);
			
			__int64 temp=d*8;
			Buf[FullLen-1]=temp%256; temp/=256;
			Buf[FullLen-2]=temp%256; temp/=256;
			Buf[FullLen-3]=temp%256; temp/=256;
			Buf[FullLen-4]=temp%256; temp/=256;
			Buf[FullLen-5]=temp%256; temp/=256;
			Buf[FullLen-6]=temp%256; temp/=256;
			Buf[FullLen-7]=temp%256; temp/=256;
			Buf[FullLen-8]=temp%256; temp/=256;

			unsigned int A,B,C,D,E;
			A=0x67452301;
			B=0xEFCDAB89;
			C=0x98BADCFE;
			D=0x10325476;
			E=0xC3D2E1F0;
			
			for (unsigned int block=0; block<FullLen/64; block++)
			{
				unsigned int a, b, c, d, e, W[80];
				for (i = 0; i < 16; ++i) 
				{
					W[i] = (Buf[block*64+4*i  ]<<24) + 
						   (Buf[block*64+4*i+1]<<16) + 
						   (Buf[block*64+4*i+2]<< 8) + 
						   (Buf[block*64+4*i+3]);
				}
				for (i = 16; i < 80; ++i) 
				{
					W[i] = W[i-3] ^ W[i-8] ^ W[i-14] ^ W[i-16];
					W[i] = ROL32(W[i], 1);
				}
				a=A;	b=B;	c=C;	d=D;	e=E;

				for (i = 0; i < 20; ++i)	FUNC(1,i);
				for (i = 20; i < 40; ++i) 	FUNC(2,i);
				for (i = 40; i < 60; ++i) 	FUNC(3,i);
				for (i = 60; i < 80; ++i) 	FUNC(4,i);
	
				A+=a;	B+=b;	C+=c;	D+=d;	E+=e;
			}

			char str[9];
			itoa(A,str,16);  //A
			strupr(str);
			if ((str[7] == 0))
				fd.Write(&str,7);
			else
				fd.Write(&str,8);
			fd.Write(" ",1);
			itoa(B,str,16);  //B
			strupr(str);
			if ((str[7] == 0))
				fd.Write(&str,7);
			else
				fd.Write(&str,8);
			fd.Write(" ",1);
			itoa(C,str,16);  //C
			strupr(str);
			if ((str[7] == 0))
				fd.Write(&str,7);
			else
				fd.Write(&str,8);
			fd.Write(" ",1);
			itoa(D,str,16);  //D
			strupr(str);
			if ((str[7] == 0))
				fd.Write(&str,7);
			else
				fd.Write(&str,8);
			fd.Write(" ",1);
			itoa(E,str,16);  //E
			strupr(str);
			if ((str[7] == 0))
				fd.Write(&str,7);
			else
				fd.Write(&str,8);
				
			HWND hWnd = GetSafeHwnd();
			MessageBoxA(hWnd,"Complete!","Report",NULL);
			fd.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton7() // MD5
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpen(TRUE,NULL,(LPCTSTR)_T("Choose source file"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fd; //destination
	CString fname;
	if(DlgOpen.DoModal()==IDOK)  
	{
		fname = DlgOpen.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		if(DlgSave.DoModal()==IDOK)
		{
			fname = DlgSave.GetPathName();
			fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
			int d;
			d = fs.GetLength();	
			unsigned char Buf[1024];
			_MD5 MD5;
			MD5.Init();

			while (fs.Read(&Buf,1024))
				{
					if (d >= 1024)
						MD5.Update(Buf, 1024);
					else 
						MD5.Update(Buf, d);
					d-=1024;
				}
			MD5.Final();
			
			unsigned int a[16];
			char str[4];
			for(int i=0; i<16; i++)
			{
				if ((int)MD5.digest[i] < 0)
					{
						a[i]=((unsigned int)MD5.digest[i])%256;
					}
				else 
					a[i]=(unsigned int)MD5.digest[i];
				itoa(a[i],str,16);
				fd.Write(str,2);
			}

			HWND hWnd = GetSafeHwnd();
			MessageBoxA(hWnd,"Complete!","Report",NULL);
			fd.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton8() // DES encrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to encrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}

		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d;
				unsigned __int64 Bufr[1024],Bufw[1024];
				unsigned __int64 key;
				d = fs.GetLength();

				char str[10];
				itoa(d,str,10);
				fd.Write(&str,10);

				fk.Read(&key,8);
				while (fs.Read(&Bufr,1024))
				{
					int i=0,j=0;
					if ((d/1024 == 0) && (d%8 !=0))
					{
						while ((d+j)%8 !=0)
						{
							Bufr[d+j]=7;
							j++;
						}
					}
					while ((i<(d+j)) && (i<1024))
					{
						Bufw[i]=DES_encrypt(Bufr[i],key);
						i+=1;
					}
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton9() //DES decrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to decrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		int y;
		y = fs.GetLength();
		if ((y-10) %8 != 0)
			{
				AfxMessageBox(_T("Source filesize must be multiply to 8"));
				return;
			}


		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d,d1;
				int d0;  //original length
				unsigned __int64 Bufr[1024],Bufw[1024];
				unsigned __int64 key;
				d = fs.GetLength();
				
				char str[10];
				fs.Read(&str,10);
				d0=StrToIntA(str);
				d-=10;
				d0 %= 1024;
				d1=d;
				d1 %=1024;
				d0 = d1-d0; //number of symbols empty to length be multiply to 8

				fk.Read(&key,8);
				while (fs.Read(&Bufr,1024))
				{
					int i=0;
					while ((i<d) && (i<1024))
					{
						Bufw[i]=DES_decrypt(Bufr[i],key);
						i+=1;
					}
					if ((d-d0)/1024 == 0) 
						i-=d0;
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton10() // AES encrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to encrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}

		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d, keylen;
				unsigned int keylenbit, Nrounds;
				unsigned long rkeys[64];
				char Bufr[1024],Bufw[1024],key[32];
				d = fs.GetLength();

				char str[10];
				itoa(d,str,10);
				fd.Write(&str,10);
				////////////////////////////
				char *rk;
				rk = new char[32];
				unsigned long *rk1;
				rk1 = new unsigned long[16];

				keylen = fk.GetLength();
				if (keylen <= 16)
				{
					//unsigned char key[16];
					keylenbit = 128;
					fk.Read(&key,16);
					for (int k=0 ; k < 16; k++)
						if (key[k]==0)
							key[k] = cA[(k+k) % 26];
				}
				if ((keylen > 16) && (keylen <= 24))
				{
					//unsigned char key[24];
					keylenbit = 192;
					fk.Read(&key,24);
					for (int k=15 ; k < 24; k++)
						if (key[k]==0)
							key[k] = cA[(k+k) % 26];
				}
				if (keylen > 24)
				{
					//unsigned char key[32];
					keylenbit = 256;
					fk.Read(&key,32);
					for (int k=23 ; k < 32; k++)
						if (key[k]==0)
							key[k] = cA[(k+k) % 26];
				}
				/*const char keyconst[32]={{key[0]}, {key[1]}, {key[2]}, {key[3]}, {key[4]}, {key[5]}, {key[6]}, {key[7]},
									 {key[8]}, {key[9]}, {key[10]},{key[11]},{key[12]},{key[13]},{key[14]},{key[15]},
									 {key[16]},{key[17]},{key[18]},{key[19]},{key[20]},{key[21]},{key[22]},{key[23]},
									 {key[24]},{key[25]},{key[26]},{key[27]},{key[28]},{key[29]},{key[30]},{key[31]}}; */
				Nrounds = rijndaelKeySetupEnc(rkeys,key,keylenbit);

				while (fs.Read(&Bufr,1024))
				{
					int i=0,j=0;
					if ((d/1024 == 0) && (d%8 !=0))
					{
						while ((d+j)%8 !=0)
						{
							Bufr[d+j]=7;
							j++;
						}
					}
					while ((i<(d+j)) && (i<1024))
					{
						//Bufw[i]=Bufr[i];
						//Bufw[i+1]=Bufr[i+1];
						rijndaelEncrypt(rkeys,Nrounds,Bufr+i,Bufw+i);
						i+=16;
					}
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton11() // AES decrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to decrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		int y;
		y = fs.GetLength();
		if ((y-10) %8 != 0)
			{
				AfxMessageBox(_T("Source filesize must be multiply to 8"));
				return;
			}


		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d,d1,keylen;
				int d0;  //original length
				unsigned int keylenbit, Nrounds;
				unsigned long rkeys[64];
				char Bufr[1024],Bufw[1024],key[32];
				d = fs.GetLength();
				
				char str[10];
				fs.Read(&str,10);
				d0=StrToIntA(str);
				d-=10;
				d0 %= 1024;
				d1=d;
				d1 %=1024;
				d0 = d1-d0; //number of symbols empty to length be multiply to 8

				keylen = fk.GetLength();
				if (keylen <= 16)
				{
					keylenbit = 128;
					fk.Read(&key,16);
					for (int k=0 ; k < 16; k++)
						if (key[k]==0)
							key[k] = cA[(k+k) % 26];
				}
				if ((keylen > 16) && (keylen <= 24))
				{
					keylenbit = 192;
					fk.Read(&key,24);
					for (int k=15 ; k < 24; k++)
						if (key[k]==0)
							key[k] = cA[(k+k) % 26];
				}
				if (keylen > 24)
				{
					keylenbit = 256;
					fk.Read(&key,32);
					for (int k=23 ; k < 32; k++)
						if (key[k]==0)
							key[k] = cA[(k+k) % 26];
				}
				Nrounds = rijndaelKeySetupDec(rkeys,key,keylenbit);

				while (fs.Read(&Bufr,1024))
				{
					int i=0;
					while ((i<d) && (i<1024))
					{
						//Bufw[i]=Bufr[i];
						//Bufw[i+1]=Bufr[i+1];
						rijndaelDecrypt(rkeys,Nrounds,Bufr+i,Bufw+i);
						i+=16;
					}
					if ((d-d0)/1024 == 0) 
						i-=d0;
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton12() // RC4 encrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to encrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}

		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}
			int keylen;
			keylen = fs.GetLength();
			if (fk.GetLength() < 8)
			{
				AfxMessageBox(_T("The key filesize must be 8 bytes or bigger"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d;
				char key[9],Bufr[1024],Bufw[1024];
				d = fs.GetLength();

				char str[10];
				itoa(d,str,10);
				fd.Write(&str,10);

				fk.Read(&key,8);
				for (int k=0 ; k < 8; k++)
					if (key[k]==0)
						key[k] = cA[(k+k) % 26];
 
				RC4_Init(key,8);

				while (fs.Read(&Bufr,1024))
				{
					int i=0,j=0;
					if ((d/1024 == 0) && (d%8 !=0))
					{
						while ((d+j)%8 !=0)
						{
							Bufr[d+j]=7;
							j++;
						}
					}
					if (d >= 1024)
					{
						RC4_Encrypt(Bufr, 1024, Bufw);
						fd.Write(&Bufw,1024);
					}
					else
					{
						RC4_Encrypt(Bufr, d+j, Bufw);
						fd.Write(&Bufw,d+j);
					}
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton13() // RC4 decrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to decrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		int y;
		y = fs.GetLength();
		if ((y-10) %8 != 0)
			{
				AfxMessageBox(_T("Source filesize must be multiply to 8"));
				return;
			}


		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}
			int keylen;
			keylen = fs.GetLength();
			if (fk.GetLength() < 8)
			{
				AfxMessageBox(_T("The key filesize must be 8 bytes or bigger"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d,d1;
				int d0;  //original length
				char key[9],Bufr[1024],Bufw[1024];
				d = fs.GetLength();
				
				char str[10];
				fs.Read(&str,10);
				d0=StrToIntA(str);
				d-=10;
				d0 %= 1024;
				d1=d;
				d1 %=1024;
				d0 = d1-d0; //number of symbols empty to length be multiply to 8

				fk.Read(&key,8);
				for (int k=0 ; k < 8; k++)
					if (key[k]==0)
						key[k] = cA[(k+k) % 26];

				RC4_Init(key,8);
	
				while (fs.Read(&Bufr,1024))
				{
					int i=0;
					if ((d-d0) >= 1024)
					{
						RC4_Encrypt(Bufr, 1024, Bufw);
						fd.Write(&Bufw,1024);
					}
					else
					{
						RC4_Encrypt(Bufr, d-d0, Bufw);
						fd.Write(&Bufw,d-d0);
					}
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton14() // RC5 encrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to encrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}

		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d;
				unsigned long Bufr[1024],Bufw[1024],key[4];
				d = fs.GetLength();

				char str[10];
				itoa(d,str,10);
				fd.Write(&str,10);

				fk.Read(&key,16);
				for (int k=0 ; k < 4; k++)
					if (key[k]==0)
						key[k] = iA[(k+k) % 26];
				

				while (fs.Read(&Bufr,1024))
				{
					int i=0,j=0;
					if ((d/1024 == 0) && (d%8 !=0))
					{
						while ((d+j)%8 !=0)
						{
							Bufr[d+j]=7;
							j++;
						}
					}
					while ((i<(d+j)) && (i<1024))
					{
						RC5_Encrypt(Bufr+i,key,Bufw+i);
						i+=2;
					}
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}


void CCryptDlg::OnBnClickedButton15() //RC5 decrypt
{
	// TODO: Add your control notification handler code here
	CFileDialog DlgOpenS(TRUE,NULL,(LPCTSTR)_T("Choose file to decrypt"));     
	CFileDialog DlgOpenK(TRUE,NULL,(LPCTSTR)_T("Choose file includes the key"));
	CFileDialog DlgSave(FALSE,NULL,(LPCTSTR)_T("Choose file to save operation\'s results"));
	CFile fs; //source
	CFile fk; //key
	CFile fd; //destination
	CString fname;
	if(DlgOpenS.DoModal()==IDOK)  
	{
		fname = DlgOpenS.GetPathName();
		if(!fs.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
		{
			AfxMessageBox(_T("Cannot open file"));
			return;
		}
		int y;
		y = fs.GetLength();
		if ((y-10) %8 != 0)
			{
				AfxMessageBox(_T("Source filesize must be multiply to 8"));
				return;
			}


		if(DlgOpenK.DoModal()==IDOK)  
		{
			fname = DlgOpenK.GetPathName();
			if(!fk.Open(fname, CFile::modeRead|CFile::typeBinary, NULL))
			{
				AfxMessageBox(_T("Cannot open file"));
				return;
			}

			if(DlgSave.DoModal()==IDOK)
			{
				fname = DlgSave.GetPathName();
				fd.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary, NULL);
				int d,d1;
				int d0;  //original length
				unsigned long Bufr[1024],Bufw[1024],key[4];
				d = fs.GetLength();
				
				char str[10];
				fs.Read(&str,10);
				d0=StrToIntA(str);
				d-=10;
				d0 %= 1024;
				d1=d;
				d1 %= 1024;
				d0 = d1-d0; //number of symbols empty to length be multiply to 8

				fk.Read(&key,16);
				for (int k=0 ; k < 4; k++)
					if (key[k]==0)
						key[k] = iA[(k+k) % 26];

				while (fs.Read(&Bufr,1024))
				{
					int i=0;
					while ((i<d) && (i<1024))
					{
						RC5_Decrypt(Bufr+i,key,Bufw+i);
						i+=2;
					}
					if ((d-d0)/1024 == 0) 
						i-=d0;
					fd.Write(&Bufw,i);
					d-=1024;
				}
				HWND hWnd = GetSafeHwnd();
				MessageBoxA(hWnd,"Complete!","Report",NULL);
				fd.Close();
			}
			fk.Close();
		}
		fs.Close();
	}
}
