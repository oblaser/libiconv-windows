
@rem    author          Oliver Blaser
@rem    date            07.03.2023
@rem    copyright       GNU LGPL-2.1 - Copyright (c) 2023 Oliver Blaser


setlocal

set /p VERSIONSTR=<dep_vstr.txt
set EXENAME=iconf
set WORKDIR=packed\libiconv-windows
set OUTDIRNAME=libiconv-%VERSIONSTR%
set OUTDIR=%WORKDIR%\%OUTDIRNAME%
set ARCHIVE=%OUTDIRNAME%.zip

rmdir /s /q %WORKDIR%

xcopy /i /s /e ..\include %OUTDIR%\include\
xcopy /i ..\bin %OUTDIR%\bin\
xcopy /i ..\lib %OUTDIR%\lib\

copy ..\license.txt "%OUTDIR%\"

set READMEFILE=%OUTDIR%\readme.txt
@echo.>%READMEFILE%
@echo.libiconv v%VERSIONSTR%>>%READMEFILE%
@echo.>>%READMEFILE%
@echo.For more information see https://github.com/oblaser/libiconv-windows>>%READMEFILE%
@echo.and https://www.gnu.org/software/libiconv/>>%READMEFILE%
@echo.>>%READMEFILE%
@echo.License: GNU LGPL-2.1 ^<http://gnu.org/licenses/^>.>>%READMEFILE%
@echo.This is free software. There is NO WARRANTY.>>%READMEFILE%


cd %WORKDIR%
"C:\Program Files\7-Zip\7z.exe" a %ARCHIVE% %OUTDIRNAME%\
cd ..\..

del packed\%ARCHIVE%
move %WORKDIR%\%ARCHIVE% packed\%ARCHIVE%

endlocal
