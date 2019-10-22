----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    04:42:03 10/22/2019 
-- Design Name: 
-- Module Name:    MUX - BEHAVIORAL 
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

architecture BEHAVIORAL of MUX is

begin

	process(d0,d1,d2,d3,s0,s1)
	begin
	
		if(s1='0' and s0='0') then
			y<=d0;
		elsif(s1='0' and s0='1') then
			y<=d1;
		elsif(s1='1' and s0='0') then
			y<=d2;
		else
			y<=d3;
		end if;
	end process;
	
end BEHAVIORAL;

