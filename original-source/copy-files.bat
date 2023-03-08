
@rem    author          Oliver Blaser
@rem    date            08.03.2023
@rem    copyright       GNU LGPL-2.1 - Copyright (c) 2023 Oliver Blaser

setlocal

set ICONV_DIR=libiconv-1.17

del /f /q ..\include\iconv\*
del /f /q ..\src\*
del /f /q ..\src\include\*
del /f /q ..\resources\*


@rem This is the main file of the executable and is not needed to build the DLL.
@rem Note that it is licensed under GPL and not LGPL!
@rem copy %ICONV_DIR%\src\iconv.c ..\src\

copy %ICONV_DIR%\lib\iconv.c ..\src\

copy %ICONV_DIR%\srclib\relocatable.h ..\src\
copy %ICONV_DIR%\srclib\relocatable.c ..\src\
copy %ICONV_DIR%\libcharset\lib\localcharset.c ..\src\
copy %ICONV_DIR%\libcharset\include\localcharset.h.build.in ..\src\localcharset.h

copy %ICONV_DIR%\windows\libiconv.rc ..\resources\

copy %ICONV_DIR%\include\iconv.h.build.in ..\include\iconv\iconv.h
copy %ICONV_DIR%\config.h.in ..\src\include\config.h
copy %ICONV_DIR%\lib\*.h ..\src\include\
copy %ICONV_DIR%\lib\*.def ..\src\include\

endlocal
