#ifndef SAVEUTIL_H
#define SAVEUTIL_H

#include <string.h>

// Source: https://github.com/ps2dev/mymc/blob/master/ps2save.py#L36
static unsigned char cbsPerm[] = {0x5f, 0x1f, 0x85, 0x6f, 0x31, 0xaa, 0x3b, 0x18,
		    0x21, 0xb9, 0xce, 0x1c, 0x07, 0x4c, 0x9c, 0xb4,
		    0x81, 0xb8, 0xef, 0x98, 0x59, 0xae, 0xf9, 0x26,
		    0xe3, 0x80, 0xa3, 0x29, 0x2d, 0x73, 0x51, 0x62,
		    0x7c, 0x64, 0x46, 0xf4, 0x34, 0x1a, 0xf6, 0xe1,
		    0xba, 0x3a, 0x0d, 0x82, 0x79, 0x0a, 0x5c, 0x16,
		    0x71, 0x49, 0x8e, 0xac, 0x8c, 0x9f, 0x35, 0x19,
		    0x45, 0x94, 0x3f, 0x56, 0x0c, 0x91, 0x00, 0x0b,
		    0xd7, 0xb0, 0xdd, 0x39, 0x66, 0xa1, 0x76, 0x52,
		    0x13, 0x57, 0xf3, 0xbb, 0x4e, 0xe5, 0xdc, 0xf0,
		    0x65, 0x84, 0xb2, 0xd6, 0xdf, 0x15, 0x3c, 0x63,
		    0x1d, 0x89, 0x14, 0xbd, 0xd2, 0x36, 0xfe, 0xb1,
		    0xca, 0x8b, 0xa4, 0xc6, 0x9e, 0x67, 0x47, 0x37,
		    0x42, 0x6d, 0x6a, 0x03, 0x92, 0x70, 0x05, 0x7d,
		    0x96, 0x2f, 0x40, 0x90, 0xc4, 0xf1, 0x3e, 0x3d,
		    0x01, 0xf7, 0x68, 0x1e, 0xc3, 0xfc, 0x72, 0xb5,
		    0x54, 0xcf, 0xe7, 0x41, 0xe4, 0x4d, 0x83, 0x55,
		    0x12, 0x22, 0x09, 0x78, 0xfa, 0xde, 0xa7, 0x06,
		    0x08, 0x23, 0xbf, 0x0f, 0xcc, 0xc1, 0x97, 0x61,
		    0xc5, 0x4a, 0xe6, 0xa0, 0x11, 0xc2, 0xea, 0x74,
		    0x02, 0x87, 0xd5, 0xd1, 0x9d, 0xb7, 0x7e, 0x38,
		    0x60, 0x53, 0x95, 0x8d, 0x25, 0x77, 0x10, 0x5e,
		    0x9b, 0x7f, 0xd8, 0x6e, 0xda, 0xa2, 0x2e, 0x20,
		    0x4f, 0xcd, 0x8f, 0xcb, 0xbe, 0x5a, 0xe0, 0xed,
		    0x2c, 0x9a, 0xd4, 0xe2, 0xaf, 0xd0, 0xa9, 0xe8,
		    0xad, 0x7a, 0xbc, 0xa8, 0xf2, 0xee, 0xeb, 0xf5,
		    0xa6, 0x99, 0x28, 0x24, 0x6c, 0x2b, 0x75, 0x5d,
		    0xf8, 0xd3, 0x86, 0x17, 0xfb, 0xc0, 0x7b, 0xb3,
		    0x58, 0xdb, 0xc7, 0x4b, 0xff, 0x04, 0x50, 0xe9,
		    0x88, 0x69, 0xc9, 0x2a, 0xab, 0xfd, 0x5b, 0x1b,
		    0x8a, 0xd9, 0xec, 0x27, 0x44, 0x0e, 0x33, 0xc8,
		    0x6b, 0x93, 0x32, 0x48, 0xb6, 0x30, 0x43, 0xa5};

typedef struct cbsHeader {
	char magic[4];
	u32 unk1;
	u32 dataOffset;
	u32 decompressedSize;
	u32 compressedSize;
	char name[32];
	
	struct {
		u8 unknown1;
		u8 sec;      // Entry creation date/time (second)
		u8 min;      // Entry creation date/time (minute)
		u8 hour;     // Entry creation date/time (hour)
		u8 day;      // Entry creation date/time (day)
		u8 month;    // Entry creation date/time (month)
		u16 year;    // Entry creation date/time (year)
	} create;
	
	struct {
		u8 unknown1;
		u8 sec;      // Entry creation date/time (second)
		u8 min;      // Entry creation date/time (minute)
		u8 hour;     // Entry creation date/time (hour)
		u8 day;      // Entry creation date/time (day)
		u8 month;    // Entry creation date/time (month)
		u16 year;    // Entry creation date/time (year)
	} modify;
	
	char unk2[8];
	u32 mode;
	char unk3[12];
	char title[72];
	char description[132];
} cbsHeader_t;

typedef struct cbsEntry {
	struct {
		u8 unknown1;
		u8 sec;      // Entry creation date/time (second)
		u8 min;      // Entry creation date/time (minute)
		u8 hour;     // Entry creation date/time (hour)
		u8 day;      // Entry creation date/time (day)
		u8 month;    // Entry creation date/time (month)
		u16 year;    // Entry creation date/time (year)
	} create;
	
	struct {
		u8 unknown1;
		u8 sec;      // Entry creation date/time (second)
		u8 min;      // Entry creation date/time (minute)
		u8 hour;     // Entry creation date/time (hour)
		u8 day;      // Entry creation date/time (day)
		u8 month;    // Entry creation date/time (month)
		u16 year;    // Entry creation date/time (year)
	} modify;
	
	u32 length;
	u32 mode;
	char unk1[8];
	char name[32];
} cbsEntry_t;

void rc4Crypt(unsigned char *buf, size_t bufLen, const unsigned char *perm)
{
	size_t i;
	unsigned char j = 0;
	unsigned char k = 0;
	unsigned char temp;
	unsigned char *s = malloc(256);
	
	memcpy(s, perm, 256);
	
	for(i = 0; i < bufLen; i++)
	{
		j += 1;
		k += s[j];
		
		temp = s[j];
		s[j] = s[k];
		s[k] = temp;
		
		buf[i] ^= s[(s[j] + s[k]) & 0xFF];
	}
	
	free(s);
}

void cbsCrypt(unsigned char *buf, size_t bufLen)
{
	rc4Crypt(buf, bufLen, cbsPerm);
}

#endif
