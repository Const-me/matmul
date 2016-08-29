set MM64=..\x64\Release\MatMul.exe
set MM32=..\Win32\Release\MatMul.exe
set MM=%MM32%

del result.txt
for %%n in (2000,4000) do for %%a in (1,2,7,3,4,8) do %MM% -a%%a -n%%n 2>> result.txt
rem for %%a in (0,1,2,7,3,4,8) do for %%n in (2000) do %MM% -a%%a -n%%n 2>> result.txt
pause