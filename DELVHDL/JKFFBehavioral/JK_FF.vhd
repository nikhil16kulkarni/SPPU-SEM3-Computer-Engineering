----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:09:51 10/22/2019 
-- Design Name: 
-- Module Name:    JK_FF - BEHAVIORAL 
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

entity JK_FF is
    Port ( j : in  STD_LOGIC;
           k : in  STD_LOGIC;
           clear : in  STD_LOGIC;
           clock : in  STD_LOGIC;
           q : out  STD_LOGIC;
           q_bar : out  STD_LOGIC);
end JK_FF;

architecture BEHAVIORAL of JK_FF is
	signal jk : STD_LOGIC_VECTOR(1 downto 0):="00";
	signal q_temp : STD_LOGIC:='0';
begin
	jk<=j&k;
	process(clear,clock)
	begin
		if(clear='1') then
			q_temp<='0';
		elsif(clock'event and clock='1') then
			case(jk) is
				when "00"=>		q_temp<=q_temp;
				when "01"=>		q_temp<='0';
				when "10"=>		q_temp<='1';
				when others=>  q_temp<=not q_temp;
			end case;
		end if;
	end process;
	q<=q_temp;
	q_bar<=not q_temp;
end BEHAVIORAL;

