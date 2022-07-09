library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BITSTREAM_TX is
port(
    clk: in std_logic;       --clock 32MHz 
    rst: in std_logic;       --reset
    data_out: out std_logic; --bitstream out
    clk_out : out std_logic  --clock out
);
end entity;

architecture behave of BITSTREAM_TX is 

signal lfsr : unsigned(12 downto 0);
signal i : integer range 0 to 12;

begin
    process(clk,rst)
    begin
        if(rst='1')then 
            lfsr <= "1010001010110";
            data_out <= '0';
            i <= 12;
        elsif(rising_edge(clk))then
            if(i=0)then 
                i <= 12;
                lfsr <= shift_right(lfsr,1);
                lfsr(12) <= lfsr(1) XOR lfsr (0);
                data_out <= lfsr(i);
            else
                i <= i-1;
                data_out <= lfsr(i);
            end if;
        end if;
    end process;

    clk_out <= clk;
end architecture;