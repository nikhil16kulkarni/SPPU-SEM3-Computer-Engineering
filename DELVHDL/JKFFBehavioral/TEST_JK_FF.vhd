--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:27:04 10/22/2019
-- Design Name:   
-- Module Name:   /home/near/VHDL/JKFFBehavioral/TEST_JK_FF.vhd
-- Project Name:  JKFFBehavioral
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: JK_FF
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
 
ENTITY TEST_JK_FF IS
END TEST_JK_FF;
 
ARCHITECTURE behavior OF TEST_JK_FF IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT JK_FF
    PORT(
         j : IN  std_logic;
         k : IN  std_logic;
         clear : IN  std_logic;
         clock : IN  std_logic;
         q : OUT  std_logic;
         q_bar : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal j : std_logic := '0';
   signal k : std_logic := '0';
   signal clear : std_logic := '0';
   signal clock : std_logic := '0';

 	--Outputs
   signal q : std_logic;
   signal q_bar : std_logic;

BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: JK_FF PORT MAP (
          j => j,
          k => k,
          clear => clear,
          clock => clock,
          q => q,
          q_bar => q_bar
        );
	
	-- Clock Process
	process
	begin
	
		wait for 5ns;
		clock <= not clock;
		
	end process;

	-- Stimulation Inputs
	process
	begin		
		
		clear<='1';
		wait for 10 ns;
			
		clear<='0';
		j<='0';
		k<='1';
		wait for 10 ns;
			
		clear<='0';
		j<='1';
		k<='0';
		wait for 10 ns;
			
		clear<='0';
		j<='1';
		k<='1';
		wait for 10 ns;
		
		clear<='0';
		j<='0';
		k<='0';
		wait for 10 ns;
			
	end process;

END;
