----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    04:58:58 10/22/2019 
-- Design Name: 
-- Module Name:    MUX - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity MUX is
    Port ( d0 : in  STD_LOGIC;
           d1 : in  STD_LOGIC;
           d2 : in  STD_LOGIC;
           d3 : in  STD_LOGIC;
           s0 : in  STD_LOGIC;
           s1 : in  STD_LOGIC;
           y : out  STD_LOGIC);
end MUX;

architecture Behavioral of MUX is

component INV0
    Port ( pin : in  STD_LOGIC;
           pout : out  STD_LOGIC);
end component;

component AND0
    Port ( a0 : in  STD_LOGIC;
			  a1 : in  STD_LOGIC;
			  a2 : in  STD_LOGIC;
           aout : out  STD_LOGIC);
end component;

component OR0
    Port ( b0 : in  STD_LOGIC;
			  b1 : in  STD_LOGIC;
			  b2 : in  STD_LOGIC;
			  b3 : in  STD_LOGIC;
           bout : out  STD_LOGIC);
end component;

signal s0bar,s1bar,t0,t1,t2,t3 : STD_LOGIC;

begin
	
	INV_1: INV0 port map(s0,s0bar);
	INV_2: INV0 port map(s1,s1bar);
	
	AND_1: AND0 port map(s1bar,s0bar,d0,t0);
	AND_2: AND0 port map(s1bar,s0,d1,t1);
	AND_3: AND0 port map(s1,s0bar,d2,t2);
	AND_4: AND0 port map(s1,s0,d3,t3);
	
	OR_1: OR0 port map(t0,t1,t2,t3,y);

end Behavioral;

