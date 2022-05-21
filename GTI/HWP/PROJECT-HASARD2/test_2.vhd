library ieee;
use ieee.std_logic_1164.all;                               
                                                          
package pack_1 is                                          
  type X01_vector is array (natural range <>) of X01;     
end pack_1;  
                                              
library ieee;                                                          
use ieee.std_logic_1164.all;                               
use work.pack_1.all;                                       
                                                          
entity sn7432 is                                          
  port (x : in X01_vector (1 to 2); y : out X01);         
end sn7432;                                               
                                                          
architecture dataflow of sn7432 is                        
begin                                                     
  y <= x(1) or x(2);                                      
end dataflow;                                             

library ieee;                                                          
use ieee.std_logic_1164.all;                               
use work.pack_1.all;                                       
                                                          
entity sn7474 is                                          
  port (s_b,r_b,c,d : in X01; q,q_b : out X01);           
end sn7474;                                               
                                                          
architecture dataflow of sn7474 is                        
  signal l : X01_vector (1 to 6);                         
begin                                                     
  l(1) <= not(s_b  and l(4) and l(2));                    
  l(2) <= not(l(1) and r_b  and c   );                    
  l(3) <= not(l(2) and c    and r_b );                    
  l(4) <= not(l(3) and r_b  and d   );                    
  l(5) <= not(s_b  and l(2) and l(6));                    
  l(6) <= not(l(5) and r_b  and l(3));                    
  q    <= l(5);                                           
  q_b  <= l(6);                                           
end dataflow;
                                             
library ieee;
use ieee.std_logic_1164.all;                               
use work.pack_1.all;                                       
                                                          
entity uut2 is                                            
  port (r_b,c : in X01; x : in X01_vector (1 to 2);       
        y : out X01_vector (1 to 2));                     
end uut2;                                                 
                                                          
architecture structure of uut2 is                         
  component sn7432                                        
    port (x : in X01_vector (1 to 2); y : out X01);       
  end component;                                          
  component sn7474                                        
    port (s_b,r_b,c,d : in X01; q,q_b : out X01);         
  end component;                                          
  signal s_b : X01 := '1'; signal d : X01;                
begin                                                     
  u1: sn7432 port map (x,d);                              
  u2: sn7474 port map (s_b,r_b,c,d,y(1),y(2));            
end structure;
                                            
library ieee;
use ieee.std_logic_1164.all;                               
use work.pack_1.all;                                       
                                                          
entity test is                                            
end test;                                                 
                                                          
architecture test5 of test is                              
  component uut2                                          
    port (r_b,c : in X01; x : in X01_vector (1 to 2);
          y : out X01_vector (1 to 2)); 
  end component;                                          
  signal r_b,c : X01; signal x : X01_vector (1 to 2);
  signal y : X01_vector (1 to 2);  
signal dummy: X01;  
begin                                                     
   r_b <= '0','1' after 10 ns;                            
   c   <= '0','1' after 20 ns,'0' after 30 ns,            
              '1' after 50 ns,'0' after 60 ns;            
   x   <= "01","10" after 40 ns;   
dummy <= '0','0' after 100 ns;   
  u1: uut2 port map (r_b,c,x,y);                          
end test5;                                                 

architecture test6 of test is                              
  component uut2                                          
    port (r_b,c : in X01; x : in X01_vector (1 to 2);
          y : out X01_vector (1 to 2)); 
  end component;                                          
  signal r_b,c : X01; signal x : X01_vector (1 to 2);
  signal y : X01_vector (1 to 2); 
signal dummy: X01;  
begin                                                     
   r_b <= '0','X' after 10 ns,'1' after 20 ns ;           
   c   <= '0','1' after 30 ns,'0' after 40 ns,            
              '1' after 70 ns,'0' after 80 ns;            
   x   <= "01","XX" after 50 ns,"10" after 60 ns;   
  dummy <= '0','0' after 100 ns;   
  u1: uut2 port map (r_b,c,x,y);                          
end test6;
