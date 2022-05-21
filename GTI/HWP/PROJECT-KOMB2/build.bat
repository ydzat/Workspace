@echo on
@echo ... Raeume auf ...
del uut.vcd > nul
del f_out > nul
ghdl --clean
ghdl --remove
@echo ... Analyse und Erstellen ...
ghdl -a DBB2_08.VHD
ghdl -a SN7400.VHD
ghdl -a SN7404.VHD
ghdl -a SN74151.VHD
ghdl -a SN74153.VHD
ghdl -a UUT.VHD
ghdl -e uut
ghdl -r uut
@echo ... Erstellen Testumgebung ...
ghdl -r test --vcd=uut.vcd
@echo.
@echo ... warten auf Beenden von GTK-Wave ...
@echo.
gtkwave uut.vcd uut.screen
