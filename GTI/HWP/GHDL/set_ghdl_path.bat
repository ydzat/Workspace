::
:: set_ghdl_path.bat
::
::   Adds GHDL to PATH, takes effect in the current command shell only 
::
::   Also defines GHDL library prefix
::

::
:: Run this batch file once before using GHDL in a command shell
::

::
:: derive installation directory info from batch file location [ ~dp0 => dRIVE pATH 0 ]
::
set GHDL_INSTALL_DIR=%~dp0

::
:: set GHDL library prefix
::
set GHDL_PREFIX=%GHDL_INSTALL_DIR%lib

::
:: prefix GHDL binary location to current PATH
::
set PATH=%GHDL_INSTALL_DIR%bin;%PATH%



::
:: To make this setup persistent without needing this batch file, 
:: manually update your Windows user or system environment variables 
:: as follows, using your actual install path in place of the example 
:: path of c:\ghdl\ghdl-0.31-mcode-win32\ 
::
::  - prefix the existing PATH with 
::      c:\ghdl\ghdl-0.31-mcode-win32\bin;
::
::  - add a new environment variable:
::      GHDL_PREFIX=c:\ghdl\ghdl-0.31-mcode-win32\lib
::
::
:: Windows environment variables are typically found here:
::   Start=>Settings=>Control Panel=>System=>Advanced=>Environment Variables
::
