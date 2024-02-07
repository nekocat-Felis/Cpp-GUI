for /r %%i in (*.c *.cpp) do (
    g++ -c %%i -o source/object/%%~ni.o -I source/header -municode
)

g++ source/object/*.o -o release/start.exe -municode -mwindows
call release\start.exe