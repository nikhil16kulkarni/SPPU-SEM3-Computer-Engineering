----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    03:54:18 10/22/2019 
-- Design Name: 
-- Module Name:    CARRY_ - DATAFLOW 
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

entity CARRY0 is
    Port ( p : in  STD_LOGIC;
           q : in  STD_LOGIC;
           r : in  STD_LOGIC;
           c : out  STD_LOGIC);
end CARRY0;

architecture DATAFLOW of CARRY0 is

begin

	c<=(p and q)or(q and r)or(r and p);

end DATAFLOW;

