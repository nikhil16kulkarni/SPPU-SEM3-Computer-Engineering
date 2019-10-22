----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:13:04 10/22/2019 
-- Design Name: 
-- Module Name:    ASYNC_UP - STRUCTURAL 
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

entity ASYNC_UP is
    Port ( clock : in  STD_LOGIC;
           clear : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR(2 downto 0));
end ASYNC_UP;

architecture STRUCTURAL of ASYNC_UP is
	component JK_FF is
	    Port ( j : in  STD_LOGIC;
				  k : in  STD_LOGIC;
				  count : out  STD_LOGIC_VECTOR(2 downto 0));
	end component;
begin


end STRUCTURAL;

