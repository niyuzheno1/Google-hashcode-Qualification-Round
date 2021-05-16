@echo off
set /a "x = 2"

:more_to_process
    if %x% leq 9 (
        mkdir p%x%
	copy problem.zip p%x%\problem.zip
	cd p%x%
	powershell -command "Expand-Archive -Force 'problem.zip' '.'"
	del problem.zip
	cd ..
        set /a "x = x + 1"
        goto :more_to_process
    )
