///////////////
// MD5.h
///////////////
// Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991.
// All rights reserved.
// "RSA Data Security, Inc. MD5 Message-Digest Algorithm" 

#ifndef MD5_H
#define MD5_H

// MD5 context.
//typedef unsigned long UINT4;
//typedef unsigned int UI;
//typedef unsigned char UC;
//typedef void * POINTER;
typedef struct
{
  unsigned long state[4];           // state (ABCD)
  unsigned long count[2];           // number of bits, modulo 2^64 (lsb first)
  unsigned char buffer[64];            // input buffer
} MD5_CTX;

// Constants for MD5Transform
#define S11      7
#define S12     12
#define S13     17
#define S14     22
#define S21      5
#define S22      9
#define S23     14
#define S24     20
#define S31      4
#define S32     11
#define S33     16
#define S34     23
#define S41      6
#define S42     10
#define S43     15
#define S44     21
// -------------------------------------------------------------------------
static unsigned char PADDING_MD5[64] = {0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

// F, G, H and I - main functions of the MD5 algorithm
#define F(x, y, z) (((x) & (y)) | ((~x) & ( z)))
#define G(x, y, z) (((x) & (z)) | (( y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// ROTATE_LEFT - cyclic shift of x left on n bits.
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

// FF, GG, HH, and II transforms for rounding 1, 2, 3, and 4
// Cyclic shift separated with addition in order to avoid recalculation
#define FF(a, b, c, d, x, s, ac) {\
  (a) += F ((b), (c), (d)) + (x) + (unsigned long)(ac);\
  (a)  = ROTATE_LEFT ((a), (s));\
  (a) += (b);}

#define GG(a, b, c, d, x, s, ac) {\
  (a) += G ((b), (c), (d)) + (x) + (unsigned long)(ac);\
  (a)  = ROTATE_LEFT ((a), (s));\
  (a) += (b);}

#define HH(a, b, c, d, x, s, ac) {\
  (a) += H ((b), (c), (d)) + (x) + (unsigned long)(ac);\
  (a)  = ROTATE_LEFT ((a), (s));\
  (a) += (b);}

#define II(a, b, c, d, x, s, ac) {\
  (a) += I ((b), (c), (d)) + (x) + (unsigned long)(ac);\
  (a) = ROTATE_LEFT ((a), (s));\
  (a) += (b);}
// -------------------------------------------------------------------------
static void MDTransformF (unsigned long s[4], unsigned long x[16])
{
  FF(s[0], s[1], s[2], s[3], x[ 0], S11, 0xd76aa478);     //  1
  FF(s[3], s[0], s[1], s[2], x[ 1], S12, 0xe8c7b756);     //  2
  FF(s[2], s[3], s[0], s[1], x[ 2], S13, 0x242070db);     //  3
  FF(s[1], s[2], s[3], s[0], x[ 3], S14, 0xc1bdceee);     //  4
  FF(s[0], s[1], s[2], s[3], x[ 4], S11, 0xf57c0faf);     //  5
  FF(s[3], s[0], s[1], s[2], x[ 5], S12, 0x4787c62a);     //  6
  FF(s[2], s[3], s[0], s[1], x[ 6], S13, 0xa8304613);     //  7
  FF(s[1], s[2], s[3], s[0], x[ 7], S14, 0xfd469501);     //  8
  FF(s[0], s[1], s[2], s[3], x[ 8], S11, 0x698098d8);     //  9
  FF(s[3], s[0], s[1], s[2], x[ 9], S12, 0x8b44f7af);     // 10
  FF(s[2], s[3], s[0], s[1], x[10], S13, 0xffff5bb1);     // 11
  FF(s[1], s[2], s[3], s[0], x[11], S14, 0x895cd7be);     // 12
  FF(s[0], s[1], s[2], s[3], x[12], S11, 0x6b901122);     // 13
  FF(s[3], s[0], s[1], s[2], x[13], S12, 0xfd987193);     // 14
  FF(s[2], s[3], s[0], s[1], x[14], S13, 0xa679438e);     // 15
  FF(s[1], s[2], s[3], s[0], x[15], S14, 0x49b40821);     // 16
}

// -------------------------------------------------------------------------
static void MDTransformG (unsigned long s[4], unsigned long x[16])
{
  GG(s[0], s[1], s[2], s[3], x[ 1], S21, 0xf61e2562);     // 17
  GG(s[3], s[0], s[1], s[2], x[ 6], S22, 0xc040b340);     // 18
  GG(s[2], s[3], s[0], s[1], x[11], S23, 0x265e5a51);     // 19
  GG(s[1], s[2], s[3], s[0], x[ 0], S24, 0xe9b6c7aa);     // 20
  GG(s[0], s[1], s[2], s[3], x[ 5], S21, 0xd62f105d);     // 21
  GG(s[3], s[0], s[1], s[2], x[10], S22, 0x02441453);     // 22
  GG(s[2], s[3], s[0], s[1], x[15], S23, 0xd8a1e681);     // 23
  GG(s[1], s[2], s[3], s[0], x[ 4], S24, 0xe7d3fbc8);     // 24
  GG(s[0], s[1], s[2], s[3], x[ 9], S21, 0x21e1cde6);     // 25
  GG(s[3], s[0], s[1], s[2], x[14], S22, 0xc33707d6);     // 26
  GG(s[2], s[3], s[0], s[1], x[ 3], S23, 0xf4d50d87);     // 27
  GG(s[1], s[2], s[3], s[0], x[ 8], S24, 0x455a14ed);     // 28
  GG(s[0], s[1], s[2], s[3], x[13], S21, 0xa9e3e905);     // 29
  GG(s[3], s[0], s[1], s[2], x[ 2], S22, 0xfcefa3f8);     // 30
  GG(s[2], s[3], s[0], s[1], x[ 7], S23, 0x676f02d9);     // 31
  GG(s[1], s[2], s[3], s[0], x[12], S24, 0x8d2a4c8a);     // 32
}

// -------------------------------------------------------------------------
static void MDTransformH (unsigned long s[4], unsigned long x[16])
{
  HH(s[0], s[1], s[2], s[3], x[ 5], S31, 0xfffa3942);     // 33
  HH(s[3], s[0], s[1], s[2], x[ 8], S32, 0x8771f681);     // 34
  HH(s[2], s[3], s[0], s[1], x[11], S33, 0x6d9d6122);     // 35
  HH(s[1], s[2], s[3], s[0], x[14], S34, 0xfde5380c);     // 36
  HH(s[0], s[1], s[2], s[3], x[ 1], S31, 0xa4beea44);     // 37
  HH(s[3], s[0], s[1], s[2], x[ 4], S32, 0x4bdecfa9);     // 38
  HH(s[2], s[3], s[0], s[1], x[ 7], S33, 0xf6bb4b60);     // 39
  HH(s[1], s[2], s[3], s[0], x[10], S34, 0xbebfbc70);     // 40
  HH(s[0], s[1], s[2], s[3], x[13], S31, 0x289b7ec6);     // 41
  HH(s[3], s[0], s[1], s[2], x[ 0], S32, 0xeaa127fa);     // 42
  HH(s[2], s[3], s[0], s[1], x[ 3], S33, 0xd4ef3085);     // 43
  HH(s[1], s[2], s[3], s[0], x[ 6], S34, 0x04881d05);     // 44
  HH(s[0], s[1], s[2], s[3], x[ 9], S31, 0xd9d4d039);     // 45
  HH(s[3], s[0], s[1], s[2], x[12], S32, 0xe6db99e5);     // 46
  HH(s[2], s[3], s[0], s[1], x[15], S33, 0x1fa27cf8);     // 47
  HH(s[1], s[2], s[3], s[0], x[ 2], S34, 0xc4ac5665);     // 48
}

// -------------------------------------------------------------------------
static void MDTransformI (unsigned long s[4], unsigned long x[16])
{
  II(s[0], s[1], s[2], s[3], x[ 0], S41, 0xf4292244);     // 49
  II(s[3], s[0], s[1], s[2], x[ 7], S42, 0x432aff97);     // 50
  II(s[2], s[3], s[0], s[1], x[14], S43, 0xab9423a7);     // 51
  II(s[1], s[2], s[3], s[0], x[ 5], S44, 0xfc93a039);     // 52
  II(s[0], s[1], s[2], s[3], x[12], S41, 0x655b59c3);     // 53
  II(s[3], s[0], s[1], s[2], x[ 3], S42, 0x8f0ccc92);     // 54
  II(s[2], s[3], s[0], s[1], x[10], S43, 0xffeff47d);     // 55
  II(s[1], s[2], s[3], s[0], x[ 1], S44, 0x85845dd1);     // 56
  II(s[0], s[1], s[2], s[3], x[ 8], S41, 0x6fa87e4f);     // 57
  II(s[3], s[0], s[1], s[2], x[15], S42, 0xfe2ce6e0);     // 58
  II(s[2], s[3], s[0], s[1], x[ 6], S43, 0xa3014314);     // 59
  II(s[1], s[2], s[3], s[0], x[13], S44, 0x4e0811a1);     // 60
  II(s[0], s[1], s[2], s[3], x[ 4], S41, 0xf7537e82);     // 61
  II(s[3], s[0], s[1], s[2], x[11], S42, 0xbd3af235);     // 62
  II(s[2], s[3], s[0], s[1], x[ 2], S43, 0x2ad7d2bb);     // 63
  II(s[1], s[2], s[3], s[0], x[ 9], S44, 0xeb86d391);     // 64
}//----------------------
// Prototypes
static void MDTransform (unsigned long [4], unsigned char [64]);
static void Encode      (unsigned char *, unsigned long *, unsigned int);
static void Decode      (unsigned long *, unsigned char *, unsigned int);

class _MD5 {
	MD5_CTX context;
public:
	char digest[0x10];
	void Init();
	void Update(unsigned char *, unsigned int);
	void Final();
};

void _MD5::Init()
{
  context.count[0] = context.count[1] = 0;
  context.state[0] = 0x67452301;
  context.state[1] = 0xefcdab89;
  context.state[2] = 0x98badcfe;
  context.state[3] = 0x10325476;
}

void _MD5::Update(unsigned char *input, unsigned int inputLen)
{
  unsigned int i, index, partLen;
  index = (unsigned int)((context.count[0] >> 3) & 0x3F);
  if ((context.count[0] += ((unsigned long)inputLen << 3)) < ((unsigned long)inputLen << 3))
     context.count[1]++;
  context.count[1] += ((unsigned long)inputLen >> 29);
  partLen = 64 - index;
  // Applying transform as many times as possible
  if (inputLen >= partLen)
   {
     memcpy(context.buffer+index, input, partLen);
     MDTransform (context.state, context.buffer);

     for (i = partLen; i + 63 < inputLen; i += 64)
        MDTransform(context.state, &input[i]);
     index = 0;
   }
  else
     i = 0;
  // Input of the buffer remainder
  memcpy(context.buffer+index, input+i,inputLen-i);
}

void _MD5::Final()
{
  unsigned char bits[8];
  unsigned int index, padLen;
  Encode(bits, context.count, 8);
  // Filling up to 56 with modulo 64
  index = (unsigned int)((context.count[0] >> 3) & 0x3f);
  padLen = (index < 56) ? (56 - index) : (120 - index);
  Update(PADDING_MD5, padLen);
  Update(bits, 8);
  Encode((unsigned char*)digest, context.state, 16);
  memset(&context, 0, sizeof (context));
}

// -------------------------------------------------------------------------
// MD5 main transform. Structure transform on the block basis
static void MDTransform(unsigned long state[4], unsigned char block[64])
{
  unsigned long a = state[0], b = state[1], c = state[2], d = state[3], x[16];
  
  Decode(x, block, 64);

  MDTransformF (state, x);
  MDTransformG (state, x);
  MDTransformH (state, x);
  MDTransformI (state, x);
  
  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;

  // Resetting to zero the sensitive information
  memset((void *)x, 0, sizeof (x));
}

// -------------------------------------------------------------------------
// Encoding the input (UINT4) to output (UC). Adding length multiplied by 4
static void Encode(unsigned char *output, unsigned long *input, unsigned int len)
{
  unsigned int i, j;

  for (i = 0, j = 0; j < len; i++, j += 4)
   {
    output[ j ] = (unsigned char)(input[i]         & 0xff);
    output[j+1] = (unsigned char)((input[i] >>  8) & 0xff);
    output[j+2] = (unsigned char)((input[i] >> 16) & 0xff);
    output[j+3] = (unsigned char)((input[i] >> 24) & 0xff);
   }
}

// -------------------------------------------------------------------------
// Decoding the input (UC) to output (UINT4). Adding length multiplied by 4
static void Decode(unsigned long *output, unsigned char *input, unsigned int len)
{
  unsigned int i, j;

  for (i = 0, j = 0; j < len; i++, j += 4)
    output[i] = ((unsigned long)input[ j ])        | 
               (((unsigned long)input[j+1]) <<  8) |
               (((unsigned long)input[j+2]) << 16) | 
               (((unsigned long)input[j+3]) << 24);
}

#endif MD5_H

