GHDL = ghdl
GTKW = gtkwave

VPATH = ip tb vcd

.PHONY: clean

AND: AND_GATE.vhd AND_GATE_tb.vhd
	$(GHDL) -a ./ip/AND_GATE.vhd
	$(GHDL) -a ./tb/AND_GATE_tb.vhd
	$(GHDL) -e tb
	$(GHDL) -r tb --stop-time=100ns --vcd=AND_GATE.vcd
	mv AND_GATE.vcd ./vcd/AND_GATE.vcd
	\rm -f work*.cf
	\rm -f *.o ./tb.exe
	$(GTKW) -f ./vcd/AND_GATE.vcd -a tb.sav

BITSTREAM_TX: BITSTREAM_TX.vhd BITSTREAM_TX_tb.vhd
	$(GHDL) -a ./ip/BITSTREAM_TX.vhd
	$(GHDL) -a ./tb/BITSTREAM_TX_tb.vhd
	$(GHDL) -e bitstream_tx_tb
	$(GHDL) -r bitstream_tx_tb --stop-time=3101ns --vcd=BITSTREAM_TX.vcd
	mv BITSTREAM_TX.vcd ./vcd/BITSTREAM_TX.vcd
	\rm -f work*.cf
	\rm -f *.o ./bitstream_tx_tb.exe
	$(GTKW) -f ./vcd/BITSTREAM_TX.vcd -a bitstream_tx_tb.sav

BITSTREAM_RX: BITSTREAM_RX.vhd BITSTREAM_TX.vhd BITSTREAM_RX_tb.vhd
	$(GHDL) -a ./ip/BITSTREAM_TX.vhd
	$(GHDL) -a ./ip/BITSTREAM_RX.vhd
	$(GHDL) -a ./tb/BITSTREAM_RX_tb.vhd
	$(GHDL) -e bitstream_rx_tb
	$(GHDL) -r bitstream_rx_tb --stop-time=3101ns --vcd=BITSTREAM_RX.vcd
	mv BITSTREAM_RX.vcd ./vcd/BITSTREAM_RX.vcd
	\rm -f work*.cf
	\rm -f *.o ./bitstream_rx_tb.exe
	$(GTKW) -f ./vcd/BITSTREAM_RX.vcd -a bitstream_rx_tb.sav

ETH10BASET: ETH_10BASE-T.vhd
	$(GHDL) -a ./ip/ETH_10BASE-T.vhd
	$(GHDL) -a ./tb/ETH_10BASE-T_tb.vhd
	$(GHDL) -e eth_10baset_tb
	$(GHDL) -r eth_10baset_tb --stop-time=3101ns --vcd=eth_10baset_tb.vcd
	mv eth_10baset_tb.vcd ./vcd/eth_10baset_tb.vcd
	\rm -f work*.cf
	\rm -f *.o ./eth_10baset_tb.exe
	$(GTKW) -f ./vcd/eth_10baset_tb.vcd -a eth_10baset_tb.sav