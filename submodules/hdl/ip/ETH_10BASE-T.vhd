library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ETH_10BASE_T is
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
end entity;

architecture behave of ETH_10BASE_T is
-- finite state machine 
type t_state is (IDLE,SENDING);
signal state : t_state;
-- ethernet layer 
signal ethPreamb : unsigned(63 downto 0);
signal ethDstAdd : unsigned(47 downto 0);
signal ethSrcAdd : unsigned(47 downto 0);
signal ethType   : unsigned(15 downto 0);
-- ip layer 
signal ipHeader  : unsigned(71 downto 0);
signal ipProtocol: unsigned( 7 downto 0);
signal ipChkSum  : unsigned(15 downto 0);
signal ipSrc     : unsigned(31 downto 0);
signal ipDst     : unsigned(31 downto 0);
-- udp layer
signal udpSrcPort: unsigned(15 downto 0);
signal udpDstPort: unsigned(15 downto 0);
signal udpPldLen : unsigned(15 downto 0);
signal udpChkSum : unsigned(15 downto 0);
signal udpPayload: unsigned(143 downto 0);
-- ethernet layer
signal ethChkSum : unsigned(31 downto 0);
--
signal ethFrame  : unsigned(575 downto 0);
signal i : integer range 0 to 575;
signal tds : std_logic;

begin
    process(clk,rst)
    begin
        if(rst='1')then
            state     <= IDLE;
            i         <= 0;
            ethPreamb <= X"55_55_55_55_55_55_55_D5";
            ethDstAdd <= X"00_10_A4_7B_EA_80";
            ethSrcAdd <= X"00_12_34_56_78_90";
            ethType   <= X"08_00";
            ipHeader  <= X"45_00_00_2E_B3_FE_00_00_80";
            ipProtocol<= X"11";
            ipChkSum  <= X"05_40";
            ipSrc     <= X"C0_A8_00_2C";
            ipDst     <= X"C0_A8_00_04";
            udpSrcPort<= X"04_00";
            udpDstPort<= X"04_00";
            udpPldLen <= X"00_1A";
            udpChkSum <= X"2D_E8";
            udpPayload<= X"00_01_02_03_04_05_06_07_08_09_0A_0B_0C_0D_0E_0F_10_11";
            ethChkSUm <= X"B3_31_88_1B";
        elsif(clk'event AND clk='1')then
            case state is
                when IDLE =>
                    if(snd='1')then
                        state <= SENDING;
                    else
                        tdp <= 'X';
                        tdm <= 'X';
                        tds <= 'X';
                        i <= 0; 
                        state <= IDLE;
                    end if;
                when SENDING =>
                    if(i/=63)then
                        if(ethPreamb(i)='0')then
                            tdp <= '1';
                            tdm <= '0';
                            tds <= '0';
                        elsif(ethPreamb(i)='1')then
                            tdp <= '0';
                            tdm <= '1';
                            tds <= '1';
                        else
                            i <= 0;  
                            state <= IDLE;
                        end if;
                        i <= i+1;
                    else
                        i <= 0;
                        state <= IDLE;
                    end if;
            end case;
        elsif(clk'event AND clk='0')then
            case state is
                when IDLE => -- do nothing
                when SENDING =>
                    if(tds='0')then
                        tdp <= '0';
                        tdm <= '1';
                    elsif(tds='1')then
                        tdp <= '1';
                        tdm <= '0';
                    end if;
            end case;
        end if;
    end process;
end architecture;