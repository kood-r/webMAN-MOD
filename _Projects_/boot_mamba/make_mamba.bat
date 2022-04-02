@ECHO OFF
title make_package_custom
if not exist mamba md mamba

:: ----------------------------------------------
:: Simple script to build a PKG (by CaptainCPS-X)
:: ----------------------------------------------

:: Change these for your application / manual...
set CID=CUSTOM-INSTALLER_00-0000000000000000
set PKG_DIR=./mamba/
set PKG_NAME=boot_mamba.pkg

..\updater\pkg_custom.exe --contentid %CID% %PKG_DIR% %PKG_NAME%

pause
