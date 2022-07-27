//typedef unsigned char UC;
unsigned char S_RC4[256];

void xchg(unsigned char &x, unsigned char &y) {unsigned char t=x; x=y; y=t;}

void RC4_Init(char* K, int K_len)
{
	int i,j;
	for (i=0;i<256;i++)
		S_RC4[i] = i;

	j=0;
	for (i=0; i<256;i++)
	{
		j = (j+S_RC4[i]+K[i%K_len]) % 256;
		xchg(S_RC4[i],S_RC4[j]);
	}
}

void RC4_Encrypt(char* M, int M_len, char* C)
{
	int i=0, j=0;
	for (int s = 0; s < M_len;s++)
	{
		i = (i+1) % 256;
		j = (j+S_RC4[i]) % 256;
		xchg(S_RC4[i],S_RC4[j]);
		int t = (S_RC4[i] + S_RC4[j]) % 256;
		C[s] = M[s] ^ S_RC4[t];
	}
}