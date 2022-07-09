library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb is
end entity;

architecture behave of tb is

component myAND is 
port(
    a: in  std_logic;
    b: in  std_logic;
    s: out std_logic
);
end component;

signal a: std_logic;
signal b: std_logic;
signal s: std_logic;

begin
    UUT: myAND
    port map(a,b,s);

    CALCUL: process
    begin
        a <= '0';
        b <= '0';
        wait for 10 ns;
        a <= '1';
        b <= '0';
        wait for 10 ns;
        a <= '0';
        b <= '1';
        wait for 10 ns;
        a <= '1';
        b <= '1';
        wait for 10 ns;
    end process;
end architecture;