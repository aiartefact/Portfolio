#define P32_RC5 0xB7E15163
#define Q32_RC5 0x9E3779B9

unsigned long S_RC5[26]; // масив підключів

unsigned long ROL_RC5(unsigned long x, unsigned long n)
{	n = n & 31; //n = n%32;
	return (x<<n) | (x >> (32-n));
}


unsigned long ROR_RC5(unsigned long x, unsigned long n)
{	n = n & 31; //n = n%32;
	return (x>>n) | (x << (32-n));
}

// -------------------------

void RC5_Key_Shedule(unsigned long* K)
{	unsigned long i,j,A,B;
	
	unsigned long L[4];
	for (j=0;j<4;j++)
		L[j]=K[j];
	
	S_RC5[0] = P32_RC5;
	for (i=1;i<26;i++)
		S_RC5[i] = S_RC5[i-1]+Q32_RC5;
	
	i=j=A=B=0;
	for (int s=1;s<=78;s++)
	{	A = S_RC5[i] = ROL_RC5(S_RC5[i]+A+B, 3);
		i = (i+1)%26;
		B = L[j] = ROL_RC5(L[j]+A+B, A+B);
		j=(j+1)%4;
	}
}

// ----------------------------

void RC5_Encrypt(unsigned long* M, unsigned long* K, unsigned long* C)
{	
	unsigned long A=M[0], B=M[1];

	RC5_Key_Shedule(K);

	A+=S_RC5[0];	B+=S_RC5[1];
	
	for (int i=1; i<=12;i++)
	{	A = ROL_RC5(A^B, B) + S_RC5[2*i];
		B = ROL_RC5(B^A, A) + S_RC5[2*i+1];
	}
	
	C[0] = A; C[1] = B;
}

// -----------------------------

void RC5_Decrypt(unsigned long* C, unsigned long* K, unsigned long* M)
{	
	unsigned long A=C[0], B=C[1];
	
	RC5_Key_Shedule(K);
	
	for (int i=12; i>=1;i--)
	{	B = ROR_RC5(B-S_RC5[2*i+1], A) ^ A;
		A = ROR_RC5(A-S_RC5[2*i],B) ^ B;
	}

	A-=S_RC5[0];	B-=S_RC5[1];
	
	M[0] = A; M[1] = B;
}
