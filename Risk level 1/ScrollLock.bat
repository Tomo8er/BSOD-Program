rem 実行した後に右の CTRL キーを押しながら ScrollLockを押す
rem レジストリを削除したいときはScrollLockDelete.batを開いてください。

@echo off  

reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\i8042prt\Parameters" /v CrashOnCtrlScroll /t REG_DWORD /d 1 /f
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\kbdhid\Parameters" /v CrashOnCtrlScroll  /t REG_DWORD /d 1 /f