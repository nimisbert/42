library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity eth_10baset_tb is 
end entity;

architecture behave of eth_10baset_tb is

component ETH_10BASE_T is
    port(
        --input
        rst: in std_logic;
        clk: in std_logic;
        snd: in std_logic;
        --ethernet RD differential pair
        rdp: out std_logic;
        rdm: out std_logic;
        --ethernet TD differential pair
        tdp: out std_logic;
        tdm: out std_logic
    );
end component;

signal reset: std_logic;
signal clock: std_logic;
signal send : std_logic;
signal TD_POSITIVE : std_logic;
signal TD_NEGATIVE : std_logic;
signal RD_POSITIVE : std_logic;
signal RD_NEGATIVE : std_logic;

begin 
    UUT: ETH_10BASE_T
    port map(reset,clock,send,RD_POSITIVE,RD_NEGATIVE,TD_POSITIVE,TD_NEGATIVE);

    CLK: process
    begin
        clock <= '0';
        wait for 10 ns;
        clock <= '1';
        wait for 10 ns;
    end process;

    CLC: process
    begin
        reset <= '1';
        send <= '0';
        wait for 10 ns;
        reset <= '0';
        send <= '1';
        wait for 10 ns;
        send <= '0';
        wait for 3100 ns;
    end process;

end architecture;