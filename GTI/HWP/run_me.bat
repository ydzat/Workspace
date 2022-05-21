set WORKING_DIR=%~dp0
set GHDL_PREFIX=%WORKING_DIR%GHDL\lib
set PATH=%WORKING_DIR%GHDL\bin;%WORKING_DIR%GTKW\bin;%PATH%

@echo off

IF NOT EXIST firstrun. GOTO :DEFAULT

cd %WORKING_DIR%GHDL\
set BASEGHDL= %WORKING_DIR%GHDL\
echo %BASEGHDL%
set GHDL=%BASEGHDL%\bin\ghdl
set LIB=%BASEGHDL%\lib
set STD_SRCS=       textio textio_body
set IEEE_SRCS=      std_logic_1164 std_logic_1164_body numeric_std numeric_std-body numeric_bit numeric_bit-body
set VITAL95_SRCS=   vital_timing vital_timing_body vital_primitives vital_primitives_body
set VITAL2000_SRCS= timing_p timing_b prmtvs_p prmtvs_b memory_p memory_b
set SYNOPSYS_SRCS=  std_logic_arith std_logic_textio std_logic_unsigned std_logic_signed std_logic_misc std_logic_misc-body
set MATH_REAL_SRCS= math_real math_real-body math_complex math_complex-body 
cd %LIB%\v87\std
for %%F in (%STD_SRCS%)       do  %GHDL% -a --std=87 --bootstrap --work=std %%F.v87
cd %LIB%\v87\ieee
for %%F in (%IEEE_SRCS%)      do %GHDL% -a --std=87 -P..\std --work=ieee %%F.v87
for %%F in (%VITAL95_SRCS%)   do %GHDL% -a --std=87 -P..\std --work=ieee %%F.vhd
cd %LIB%\v87\synopsys
for %%F in (%IEEE_SRCS%)      do %GHDL% -a --std=87 -P..\std --work=ieee ..\ieee\%%F.v87
for %%F in (%VITAL95_SRCS%)   do %GHDL% -a --std=87 -P..\std --work=ieee ..\ieee\%%F.vhd
for %%F in (%SYNOPSYS_SRCS%)  do %GHDL% -a --std=87 -P..\std --work=ieee %%F.vhd
cd %LIB%\v93\std
for %%F in (%STD_SRCS%)       do %GHDL% -a --std=93 --bootstrap --work=std %%F.v93
cd  %LIB%\v93\ieee
for %%F in (%IEEE_SRCS%)      do %GHDL% -a --std=93 -P..\std --work=ieee %%F.v93
for %%F in (%VITAL2000_SRCS%) do %GHDL% -a --std=93 -P..\std --work=ieee %%F.vhd
for %%F in (%MATH_REAL_SRCS%)  do %GHDL% -a --std=93 -P..\std --work=ieee ..\ieee\%%F.vhdl
cd  %LIB%\v93\synopsys
for %%F in (%IEEE_SRCS%)      do %GHDL% -a --std=93 -P..\std --work=ieee ..\ieee\%%F.v93
for %%F in (%VITAL2000_SRCS%) do %GHDL% -a --std=93 -P..\std --work=ieee ..\ieee\%%F.vhd
for %%F in (%SYNOPSYS_SRCS%)  do %GHDL% -a --std=93 -P..\std --work=ieee ..\..\v87\synopsys\%%F.vhd
for %%F in (%MATH_REAL_SRCS%) do %GHDL% -a --std=93 -P..\std --work=ieee ..\ieee\%%F.vhdl
cd %WORKING_DIR%
move firstrun. firstrun.ok

:DEFAULT
@echo off
echo.
echo *************************************************************************
echo **  Kurzhilfe  **********************************************************
echo *************************************************************************
echo *    Entfernen von temporaeren Dateien...
echo * ghdl --clean
echo * ghdl --remove
echo *
echo *    Analyse aller VHDL-Files im Verzeichnis
echo * ghdl -a *.vhd
echo *    ...es entsteht eine Datei "work-obj93.cf
echo *
echo *    Erstellen der Executable
echo *    "uut" ist dabei der Name der Top-Entity
echo * ghdl -e uut
echo *
echo *    Ausfuehren der Executable
echo * ghdl -r uut
echo *    
echo *
echo *    Die Testbench 'test' wird erstellt (Name nicht aenderbar).
echo * ghdl -r test --vcd=uut.vcd
echo *    Hier wird die Datei f_in als Stimuli genutzt und eine f_out
echo *    mit den Ergebnissen und die .vcd fuer GTK-Wave erzeugt.
echo *
echo *    Anzeigen der Ergebnisse mit GTK-Wave
echo * gtkwave uut.vcd
echo *
echo *************************************************************************
echo *    "build" fuehrte die gesammte Kette aus mit GTK-WAVE
echo * build
echo *    "build-only" fuehrte die gesammte Kette aus ohne GTK-WAVE
echo * build-only
echo *************************************************************************
echo *
echo *    Wechseln in das jeweilige Projektverzeichnis
echo * cd PROJECT-(BSP, KOMB1, KOMB2, SEQ1, SEQ2)
echo *
echo *************************************************************************
echo.
@echo on

cmd
pause
