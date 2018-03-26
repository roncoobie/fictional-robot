#include <windows.h>

LRESULT CALLBACK 
MainWindowCallback(HWND   Window,
                   UINT   Message,
                   WPARAM WParam,
                   LPARAM LParam)
{
  switch(Message)
  {
    case WM_SIZE:
    {
      OutputDebugStringA("WM_SIZE\n");
    }break;

    case WM_DESTROY:
    {
      OutputDebugStringA("WM_DESTROY\n");
    }break;
   
    case WM_CLOSE:
    {
      OutputDebugStringA("WM_CLOSE\n");
    }break;

    case WM_ACTIVATEAPP:
    {
      OutputDebugStringA("WM_ACTIVATEAPP\n");
    }break;

    default:
    {
//      OutputDebugStringA("default\n");
    }break;
  } 
}

/*WinMain is what we need to call to get the OS talking to the application. 
Very first thing that needs to be done*/
int CALLBACK 
WinMain(HINSTANCE Instance,
        HINSTANCE PrevInstance,
        LPSTR     CommandLine,
        int       ShowCode)
{
  //Info on WNDCLASS at https://msdn.microsoft.com/en-us/library/windows/desktop/ms633576(v=vs.85).aspx
  WNDCLASS WindowClass = {0};

  //TODO: Check that HREDRAW and VREDRAW still matter to us.
  WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW; //Allocates a unique device context for each window in the class.
  // This will handle all of the messages coming from Windows.
  WindowClass.lpfnWndProc = ;
  WindowClass.hInstance = hInstance;
  //HICON     hIcon; Will use this for game icon eventually.
  WindowClass.lpszClassName = "FictionalRobotWindowClass";

  return(0);

};