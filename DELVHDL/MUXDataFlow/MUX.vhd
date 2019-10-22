----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    04:26:00 10/22/2019 
-- Design Name: 
-- Module Name:    MUX - DATAFLOW 
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

architecture DATAFLOW of MUX is

begin

	y <= d0 when s1='0' and s0='0'
	else d1 when s1='0' and s0='1'
	else d2 when s1='1' and s0='0'
	else d3 when s1='1' and s0='1';

end DATAFLOW;

