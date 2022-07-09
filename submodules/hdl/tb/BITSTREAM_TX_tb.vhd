library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bitstream_tx_tb is
end entity;

architecture behave of bitstream_tx_tb is

component BITSTREAM_TX is
port(
    clk: in std_logic;       --clock 32MHz 
    rst: in std_logic;       --reset
    data_out: out std_logic; --bitstream out
    clk_out : out std_logic  --clock out
);
end component;

signal reset: std_logic;
signal clock: std_logic;
signal datao: std_logic;
signal clock_out:std_logic;

begin
    UUT: BITSTREAM_TX
    port map(clock,reset,datao,clock_out);

    CLK: process
    begin
        clock <= '0';
        wait for 31.25 ns;
        clock <= '1';
        wait for 31.25 ns;
    end process;

    CLC: process
    begin
        reset <= '1';
        wait for 5 ns;
        reset <= '0';
        wait for 5 ns;
        wait for 3100.25 ns;
    end process;
end architecture;