--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   04:33:43 10/22/2019
-- Design Name:   
-- Module Name:   /home/near/VHDL/MUXDataFlow/TEST_MUX.vhd
-- Project Name:  MUXDataFlow
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: MUX
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

ENTITY TEST_MUX IS
END TEST_MUX;
 
ARCHITECTURE behavior OF TEST_MUX IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT MUX
    PORT(
         d0 : IN  std_logic;
         d1 : IN  std_logic;
         d2 : IN  std_logic;
         d3 : IN  std_logic;
         s0 : IN  std_logic;
         s1 : IN  std_logic;
         y : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal d0 : std_logic := '0';
   signal d1 : std_logic := '0';
   signal d2 : std_logic := '0';
   signal d3 : std_logic := '0';
   signal s0 : std_logic := '0';
   signal s1 : std_logic := '0';

 	--Outputs
   signal y : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: MUX PORT MAP (
          d0 => d0,
          d1 => d1,
          d2 => d2,
          d3 => d3,
          s0 => s0,
          s1 => s1,
          y => y
        );

process
   begin		
      
		d0<='1';
		d1<='0';
		d2<='0';
		d3<='0';
		
		s1<='0';
		s0<='0';
		wait for 10 ns;
		
		d0<='0';
		d1<='1';
		d2<='0';
		d3<='0';
		
		s1<='0';
		s0<='1';
		wait for 10 ns;
		
		d0<='0';
		d1<='0';
		d2<='1';
		d3<='0';
		
		s1<='1';
		s0<='0';
		wait for 10 ns;
		
		d0<='0';
		d1<='0';
		d2<='0';
		d3<='1';
		
		s1<='1';
		s0<='1';
		wait for 10 ns;
		
   end process;

END;
