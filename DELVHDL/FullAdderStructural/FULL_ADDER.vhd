----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    03:39:02 10/22/2019 
-- Design Name: 
-- Module Name:    FULL_ADDER - STRUCTURAL 
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

entity FULL_ADDER is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           carry : out  STD_LOGIC);
end FULL_ADDER;

architecture STRUCTURAL of FULL_ADDER is

	component SUM0
		 Port ( x : in  STD_LOGIC;
				  y : in  STD_LOGIC;
				  z : in  STD_LOGIC;
				  s : out  STD_LOGIC);
	end component;

	component CARRY0
		 Port ( p : in  STD_LOGIC;
				  q : in  STD_LOGIC;
				  r : in  STD_LOGIC;
				  c : out  STD_LOGIC);
	end component;

begin

	P1: SUM0 port map(a,b,c,sum);
	P2: CARRY0 port map(a,b,c,carry);
	
end STRUCTURAL;

