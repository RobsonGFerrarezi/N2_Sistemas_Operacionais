#include <windows.h>
#include <stdio.h>

HANDLE conta1;
HANDLE conta2;

DWORD WINAPI transferencia_1(LPVOID arg)
{
    WaitForSingleObject(conta1, INFINITE);
    Sleep(1000);
    WaitForSingleObject(conta2, INFINITE);

    printf("Transferencia 1 concluida\n");

    ReleaseMutex(conta2);
    ReleaseMutex(conta1);
    return 0;
}

DWORD WINAPI transferencia_2(LPVOID arg)
{
    WaitForSingleObject(conta2, INFINITE);
    Sleep(1000);
    WaitForSingleObject(conta1, INFINITE);

    printf("Transferencia 2 concluida\n");

    ReleaseMutex(conta1);
    ReleaseMutex(conta2);
    return 0;
}

int main()
{
    conta1 = CreateMutex(NULL, FALSE, NULL);
    conta2 = CreateMutex(NULL, FALSE, NULL);

    HANDLE t1 = CreateThread(NULL, 0, transferencia_1, NULL, 0, NULL);
    HANDLE t2 = CreateThread(NULL, 0, transferencia_2, NULL, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);
    CloseHandle(conta1);
    CloseHandle(conta2);

    return 0;
}