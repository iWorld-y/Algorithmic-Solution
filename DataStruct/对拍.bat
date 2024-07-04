@echo off  
:loop
    temp.exe < P5734_1.in > std.out
    python test.py < P5734_1.in > my.out
    fc my.out std.out 
if not errorlevel 1 goto loop  
pause
goto loop