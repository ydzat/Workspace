library ieee;
use ieee.std_logic_1164.all;                               
use work.pack_2.all;                                       
                                                         
entity uut is
  port (EE_X : in  x01_vector(7 downto 0);
        EE_Y : out x01_vector(23 downto 16));
end uut;                                              
                                                       
architecture structure of uut is
  alias clear : x01 is EE_X(0);
  alias count : x01 is EE_X(1);
  alias clock : x01 is EE_X(2); 
  alias q     : x01_vector(1 downto 0) is EE_Y(17 downto 16);
  
            
  component sn7400                                        
    port (x : in  X01_vector (1 to 2);
          y : out X01);       
  end component;
  component sn7410                                        
    port (x : in  X01_vector (1 to 3);
          y : out X01);       
  end component;
  component sn7474                                        
    port (s_b,r_b,c,d : in X01; q,q_b : out X01);         
  end component;                                          
  signal r_b,s_b : X01;
  signal d,z,z_b : x01_vector(1 downto 0);
  signal const0  : x01 := '0';
  signal s       : x01_vector(1 to 5);
begin        
  -- Darstellung ist in f_out angenehmer        
  q(0) <= z(1);                                     
  q(1) <= z(0);                                     
  u01: sn7400 port map (x(1)=>const0,x(2)=>const0,y=>s_b);
  u02: sn7400 port map (x(1)=>clear,x(2)=>clear,y=>r_b);
  u03: sn7400 port map (x(1)=>count,x(2)=>count,y=>s(1));
  u04: sn7400 port map (x(1)=>s(1),x(2)=>z(1),y=>s(2));
  u05: sn7400 port map (x(1)=>count,x(2)=>z(0),y=>s(3));
  u06: sn7400 port map (x(1)=>s(1),x(2)=>z(0),y=>s(4));
  u07: sn7410 port map (x(1)=>count,x(2)=>z_b(1),x(3)=>z_b(0),y=>s(5));
  u08: sn7400 port map (x(1)=>s(2),x(2)=>s(3),y=>d(1));
  u09: sn7400 port map (x(1)=>s(4),x(2)=>s(5),y=>d(0));                
  u10: sn7474 port map (s_b,r_b,clock,d(1),z(1),z_b(1));
  u11: sn7474 port map (s_b,r_b,clock,d(0),z(0),z_b(0));
end structure;