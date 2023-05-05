// TODO: Заголовок для работы с интро

// TODO: Защита заголовочного файла, от переопределения(чтобы не определялся ещё раз)
#ifndef _LIB_CONSOLE__SETTINGS_CONSOLE  // ? Условие на существует ли макрос _LIB_CONSOLE__SETTINGS_CONSOLE
#define _LIB_CONSOLE__SETTINGS_CONSOLE  // ? Определение макроса


#include <string.h>
#include <Tlhelp32.h>
 
bool operator==(const char(& string)[260], const wstring& wstring)
{
	size_t bytesCopied = 0;
	char strBaseName[MAX_PATH] = { 0 };

	wcstombs_s(&bytesCopied, strBaseName, wstring.c_str(), MAX_PATH);
  	if(_strcmpi(string, strBaseName))
    	{
      		return true;
    	}
  	return false;
}
int GetProcesByName(wstring name)

{
	HANDLE snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pInfo = { 0 }; pInfo.dwSize = sizeof(PROCESSENTRY32);
	
	while (Process32Next(snapShot, &pInfo))
	{
		if ( pInfo.szExeFile == name)
		{
			CloseHandle(snapShot);
            cout << pInfo.th32ProcessID << endl;
			return pInfo.th32ProcessID;
		}
	}
	CloseHandle(snapShot);
	return 0;
}


unsigned long PIDByName(string AProcessName)
{
  HANDLE pHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  PROCESSENTRY32 ProcessEntry;
  unsigned long pid;
  ProcessEntry.dwSize = sizeof(ProcessEntry);
  bool Loop = Process32First(pHandle, &ProcessEntry);
 
  while (Loop)
    {
      if (ProcessEntry.szExeFile == AProcessName)
      {
        return ProcessEntry.th32ProcessID;
        pid = ProcessEntry.th32ProcessID;
        CloseHandle(pHandle);
        return pid;
      }
      Loop = Process32Next(pHandle, &ProcessEntry);
    }
    return 0;
}

// DWORD PIDByName(WCHAR * AProcessName)
// {
//   HANDLE pHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//   PROCESSENTRY32 ProcessEntry;
//   DWORD pid;
//   ProcessEntry.dwSize = sizeof(ProcessEntry);
//   bool Loop = Process32First(pHandle, &ProcessEntry);
 
//   while (Loop)
//     {
//       if (wcsstr(ProcessEntry.szExeFile, AProcessName))
//       {
//             return ProcessEntry.th32ProcessID;
//           pid = ProcessEntry.th32ProcessID;
//           CloseHandle(pHandle);
//           return pid;
//       }
//       Loop = Process32Next(pHandle, &ProcessEntry);
//     }
//     return 0;
// }


void Console_setting(){
    // CONSOLE_SCREEN_BUFFER_INFO info;
    // GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    // SMALL_RECT rc;
    // rc.X = rc.Y = 0;
    // rc.Left = rc.Top = rc.Bottom = rc.Right =  0;
    
    int iWidth = GetSystemMetrics(SM_CXSCREEN);  // разрешение экрана по горизонтали
    int iHeight = GetSystemMetrics(SM_CYSCREEN); // разрешение экрана по вертикали

    // rc.Bottom = iHeight;
    // rc.Right = iHeight;
    
    // SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rc);
   
    char Title[1024];
    GetConsoleTitle(Title, 1024); // Узнаем имя окна
    // GetModuleFileName(NULL,Title, sizeof(Title));
    HWND hwnd=FindWindow(NULL, Title); // Узнаем hwnd окна
    // ShowWindow(hwnd, SHOW_OPENNOACTIVATE);
    SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP| WS_VISIBLE);
    // SetWindowPos(hwnd,hwnd,0,0,0,0,SWP_NOZORDER|SWP_NOSIZE);
    // SetWindowPos(hwnd,hwnd,0,0,iWidth,iHeight+200,SWP_NOZORDER|SWP_NOMOVE);
    // MoveWindow(hwnd,0,0,iWidth,iHeight,true);
    // _getch();


    // TODO: Настройка объекта шрифта cfi
    CONSOLE_FONT_INFOEX cfi;                    // ? структура данных шрифта
    cfi.cbSize = sizeof cfi;                    // ? на чс, размер объекта типа данных CONSOLE_FONT_INFOEX
    cfi.nFont = 0;                              // ? Номер шрифта
    cfi.dwFontSize.X = 0;                       // ? Размер шрифта
    cfi.dwFontSize.Y = (int)(iHeight/200);      // ? Размер шрифта
    cfi.FontFamily = FF_DONTCARE;               // ? Название шрифта
    cfi.FontWeight = FW_NORMAL;                 // ? Ширина символа

    // Функция для редактирования "Строчек-объекттов-ЧТО_ТО_ПОДОБНОЕ"
    wcscpy(cfi.FaceName, L"Lucida Console");
    // Установка другого шрифта и размера в текучей(GetStdHandle(STD_OUTPUT_HANDLE)) консоли
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    // Установка(Изменение) кодировки на UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // нажимаем alt+enter
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    // ниже код также работает
    // keybd_event(VK_MENU,0x38,0,0); //press ALT
    // keybd_event(VK_RETURN,0x1c,0,0); //press ENTER
    // keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); //release ENTER
    // keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); //release ALT

    SetWindowPos(hwnd,HWND_TOP,0,0,0,0, SWP_SHOWWINDOW);
    SetWindowPos(hwnd,HWND_TOP,0,0,iWidth,iHeight, SWP_SHOWWINDOW);//SWP_NOZORDER|SWP_NOMOVE);
    SetScrollRange(hwnd,SB_VERT,0,0,FALSE);
    SetScrollPos(hwnd,SB_VERT,0,FALSE);

    COORD cd;
    cd.X = 0;
    cd.Y = 0;
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE, &cd);

    // SetForegroundWindow(hwnd);
    // AllowSetForegroundWindow(GetProcesByName(L"C:\\Users\\koshelev_da\\Desktop\\game\\b.exe"));

    // изменение разрешения дисплея
    // DEVMODE deviceMode;
    // {
    //     deviceMode.dmSize = sizeof(deviceMode);
    //     deviceMode.dmPelsWidth = iWidth;
    //     deviceMode.dmPelsHeight = iHeight;
    //     deviceMode.dmFields = DM_PELSHEIGHT | DM_PELSWIDTH;
    // }
    // ChangeDisplaySettings(&deviceMode, CDS_FULLSCREEN);
}

#endif  // ? Конец тела условия
