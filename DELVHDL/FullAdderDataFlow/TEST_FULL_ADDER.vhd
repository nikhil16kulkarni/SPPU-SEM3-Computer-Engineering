--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   02:48:42 10/22/2019
-- Design Name:   
-- Module Name:   /home/near/VHDL/FullAdderDataFlow/TEST_FULL_ADDER.vhd
-- Project Name:  FullAdderDataFlow
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: FULL_ADDER
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY TEST_FULL_ADDER IS
END TEST_FULL_ADDER;
 
ARCHITECTURE behavior OF TEST_FULL_ADDER IS
COMPONENT FULL_ADDER
    PORT(
         a : IN  std_logic;
         b : IN  std_logic;
         c : IN  std_logic;
         sum : OUT  std_logic;
         carry : OUT  std_logic
        );
END COMPONENT;
    

   --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';
   signal c : std_logic := '0';

 	--Outputs
   signal sum : std_logic;
   signal carry : std_logic;
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: FULL_ADDER PORT MAP (
          a => a,
          b => b,
          c => c,
          sum => sum,
          carry => carry
        );
process
   begin		
	
		a<='0';
		b<='0';
		c<='0';
		wait for 10 ns;
		
		a<='0';
		b<='0';
		c<='1';
		wait for 10 ns;
		
		a<='0';
		b<='1';
		c<='0';
		wait for 10 ns;
		
		a<='0';
		b<='1';
		c<='1';
		wait for 10 ns;
		
		a<='1';
		b<='0';
		c<='0';
		wait for 10 ns;
		
		a<='1';
		b<='0';
		c<='1';
		wait for 10 ns;
		
		a<='1';
		b<='1';
		c<='0';
		wait for 10 ns;
		
		a<='1';
		b<='1';
		c<='1';
		wait for 10 ns;
		
   end process;

END;
