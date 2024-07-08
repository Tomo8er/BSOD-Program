using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

class Program
{
    // P/Invoke to call the NtSetInformationProcess function from ntdll.dll
    [DllImport("ntdll.dll", SetLastError = true)]
    private static extern int NtSetInformationProcess(IntPtr processHandle, int processInformationClass, ref int processInformation, int processInformationLength);

    static void Main()
    {
        // Define the process information to indicate a critical process
        int isCritical = 1;
        // Define the constant for BreakOnTermination
        int BreakOnTermination = 0x1D;
        
        // Enter debug mode to allow the modification
        Process.EnterDebugMode();
        
        // Get the handle for the current process
        IntPtr processHandle = Process.GetCurrentProcess().Handle;
        
        // Set the process as a critical process
        NtSetInformationProcess(processHandle, BreakOnTermination, ref isCritical, sizeof(int));
    }
}
