----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    05:21:43 10/22/2019 
-- Design Name: 
-- Module Name:    OR0 - Behavioral 
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

entity OR0 is
    Port ( b0 : in  STD_LOGIC;
           b1 : in  STD_LOGIC;
           b2 : in  STD_LOGIC;
           b3 : in  STD_LOGIC;
           bout : out  STD_LOGIC);
end OR0;

architecture DATAFLOW of OR0 is

begin

	bout<=b0 or b1 or b2 or b3;

end DATAFLOW;


