#include <windows.h>

/*WinMain is what we need to call to get the OS talking to the application. 
Very first thing that needs to be done*/
int CALLBACK 
WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR     lpCmdLine,
        int       nCmdShow
)
{
  //Info on WNDCLASS at https://msdn.microsoft.com/en-us/library/windows/desktop/ms633576(v=vs.85).aspx
  WNDCLASS WindowClass = {0};

  //TODO: Check that HREDRAW and VREDRAW still matter to us.
  WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW; //Allocates a unique device context for each window in the class.
  WindowClass.lpfnWndProc = ;
  WindowClass.hInstance = hInstance;
//  HICON     hIcon; Will use this for game icon eventually.
  WindowClass.lpszClassName = "FictionalRobotWindowClass";

  return(0);

};