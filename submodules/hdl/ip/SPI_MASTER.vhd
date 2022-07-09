library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity SPI_MASTER is
port(
    --input
    add: in unsigned(7 downto 0);
    dat: in unsigned(7 downto 0);
    trg: in std_logic_vector;
    clki: in std_logic;
    --output
    nss: out std_logic_vector;
    clk: out std_logic_vector;
    mosi: out std_logic_vector;
    miso: out std_logic_vector;
);
end entity;
