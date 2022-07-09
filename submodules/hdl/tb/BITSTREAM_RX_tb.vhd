library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bitstream_rx_tb is
end entity;

architecture behave of bitstream_rx_tb is

component BITSTREAM_TX is
port(
    clk: in std_logic;       --clock 32MHz 
    rst: in std_logic;       --reset
    data_out: out std_logic; --bitstream out
    clk_out : out std_logic  --clock out
);
end component;
component BITSTREAM_RX is
port(
    clk: in std_logic;
    rst: in std_logic;
    data_in: in std_logic;
    data_out: out unsigned(12 downto 0)
);
end component;

signal sim_reset : std_logic;
signal sim_clock : std_logic;
signal io        : std_logic;
signal clk_io    : std_logic;
signal data_out  : unsigned(12 downto 0);


begin
    UUT0: BITSTREAM_TX
    port map(sim_clock,sim_reset,io,clk_io);
    UUT1: BITSTREAM_RX
    port map(clk_io,sim_reset,io,data_out);

    CLK: process
    begin
        sim_clock <= '0';
        wait for 31.25 ns;
        sim_clock <= '1';
        wait for 31.25 ns;
    end process;

    CLC: process
    begin
        sim_reset <= '1';
        wait for 5 ns;
        sim_reset <= '0';
        wait for 5 ns;
        wait for 3100.25 ns;
    end process;
end architecture;