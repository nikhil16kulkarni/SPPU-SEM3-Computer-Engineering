----------------------------------------------------------------------------------
-- Company: 
-- Engineer:       Near
-- 
-- Create Date:    03:10:35 10/22/2019 
-- Design Name: 
-- Module Name:    FULL_ADDER - BEHAVIORAL 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity FULL_ADDER is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           carry : out  STD_LOGIC);
end FULL_ADDER;

architecture BEHAVIORAL of FULL_ADDER is
begin
	process(a,b,c)
	begin
		if(a='0' and b='0' and c='0') then
			sum<='0';
			carry<='0';
		elsif(a='0' and b='0' and c='1') then
			sum<='1';
			carry<='0';
		elsif(a='0' and b='1' and c='0') then
			sum<='1';
			carry<='0';
		elsif(a='0' and b='1' and c='1') then
			sum<='0';
			carry<='1';
		elsif(a='1' and b='0' and c='0') then
			sum<='1';
			carry<='0';
		elsif(a='1' and b='0' and c='1') then
			sum<='0';
			carry<='1';
		elsif(a='1' and b='1' and c='0') then
			sum<='0';
			carry<='1';
		elsif(a='1' and b='1' and c='1') then
			sum<='1';
			carry<='1';
		end if;
	end process;
end BEHAVIORAL;

