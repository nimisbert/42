library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity myAND is
port( a: in  std_logic;
      b: in  std_logic;
      s: out std_logic
    );
end entity;

architecture behave of myAND is
begin
    s <= a AND b;
end architecture;