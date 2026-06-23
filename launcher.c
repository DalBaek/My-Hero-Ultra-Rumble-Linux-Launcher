#include <windows.h>
#include <stdio.h>
#include <string.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nShow) {
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    char* lastSlash = strrchr(exePath, '\\');
    if (lastSlash) *lastSlash = '\0';

    char mhurPath[MAX_PATH];
    snprintf(mhurPath, MAX_PATH, "%s\\HerovsGame\\Binaries\\Win64\\MHUR.exe", exePath);

    char workDir[MAX_PATH];
    snprintf(workDir, MAX_PATH, "%s\\HerovsGame\\Binaries\\Win64", exePath);
    SetCurrentDirectoryA(workDir);

    SetEnvironmentVariableA("EOS_USE_ANTICHEATCLIENTNULL", "1");

    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi = {0};

    if (CreateProcessA(mhurPath, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 0;
}
