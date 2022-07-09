library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BITSTREAM_RX is
port(
    clk: in std_logic;
    rst: in std_logic;
    data_in: in std_logic;
    data_out: out unsigned(12 downto 0)
);
end entity;

architecture behave of BITSTREAM_RX is

signal sr : unsigned(12 downto 0);
signal cnt: integer range 0 to 12;

begin
    process(clk,rst)
    begin
        if(rst='1')then
            cnt <= 12;
            sr  <= "0000000000000";
        elsif(falling_edge(clk))then
            if(cnt=0)then
                cnt <= 12;
                data_out <= sr;
                data_out(0) <= data_in; --peut etre pas propre
                sr  <= "0000000000000";
            else
                cnt <= cnt - 1;
                sr(cnt) <= data_in;
            end if;
        end if;
    end process;
end architecture;
