#include <windows.h>

LRESULT CALLBACK 
MainWindowCallback(HWND   Window,
                   UINT   Message,
                   WPARAM WParam,
                   LPARAM LParam)
{
  LRESULT Result = 0;

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
    
    case WM_PAINT:
    {
      OutputDebugStringA("WM_PAINT\n");
    }break
    default:
    {
//      OutputDebugStringA("default\n"); //may use this later if we need to print anything out about defaults
      Result = DefWindowProc(Window, Message, WParam, LParam);
    }break;
  }
  return(Result); 
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
  WindowClass.lpfnWndProc = MainWindowCallback;
  WindowClass.hInstance = Instance;
  //HICON     hIcon; Will use this for game icon eventually.
  WindowClass.lpszClassName = "FictionalRobotWindowClass";

  //Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.
  if(RegisterClass(&WindowClass))
    {
      HWND WindowHandle = 
        CreateWindowEx( //Creates an overlapped, pop-up, or child window.
          0,
          WindowClass.lpszClassName,
          "Fictional Robot",
          WS_OVERLAPPEDWINDOW|WS_VISIBLE,
          CW_USEDEFAULT,
          CW_USEDEFAULT,
          CW_USEDEFAULT,
          CW_USEDEFAULT,
          0,
          0,
          Instance,
          0);
      if(WindowHandle)
      {
        MSG Message;
        for(;;)
        {
          //need to start a message queue to loop through and extract any messages that may come in.
          BOOL MessageResult = GetMessage(&Message,0,0,0);
          if(MessageResult > 0)
          {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
          }
          else
          {
            break;
          }
        }
      }
      else
      {
      //TODO: Put some logging in here.
      }
    }
    else
    {
    //TODO: Put some logging in here.
    };

  return(0);

};