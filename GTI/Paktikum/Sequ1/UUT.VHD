library ieee; 
use ieee.std_logic_1164.all; 
use work.pack_2.all;

entity uut is 
    port (EE_X : in X01_vector (7 downto 0); 
EE_Y : out X01_vector (23 downto 16));
end uut; 

architecture structure of uut is

component sn7404 is -- 1/6 SN7404 
    port (x : in X01; 
        y : out X01); 
end component;

component sn7450 is -- 1/2 SN7450 
    port (x11 ,x12 ,x21 ,x22 : in X01; y : out X01); 
end component;

alias c1 : X01 is EE_X(0); 
alias d1 : X01 is EE_X(1); 
alias q11 : X01 is EE_Y(16); 
alias q12 : X01 is EE_Y(17); 

signal c,d : X01; 
signal s11 ,s12 ,s13 ,s14 ,s15 ,s21 ,s22 ,s23 ,s24 : X01; 

signal n1,n2 : x01; 
signal h1,h2 : x01; -- Hilfsausgänge der D-Flipflops

begin 

-- D-Flipflop1 
d11: sn7404 port map (x=>c1, y=>s11); 
d12: sn7404 port map (x=>s11, y=>s12); 
d13: sn7404 port map (x=>s12, y=>s13); 
d14: sn7404 port map (x=>s13, y=>s14);
d15: sn7404 port map (x=>s14, y=>s15);  
d16: sn7450 port map (x11=>h1, x12=>s15, x21=>c1, x22=>d1, y=>n1);
d17: sn7404 port map (x=>n1, y=>h1);
q11 <= h1;  

-- D-Flipflop2 
d21: sn7404 port map (x=>c1, y=>s21); 
d22: sn7404 port map (x=>s21, y=>s22); 
d23: sn7404 port map (x=>s22, y=>s23); 
d24: sn7404 port map (x=>s23, y=>s24); 
d25: sn7450 port map (x11=>h2, x12=>s21, x21=>s24, x22=>d1, y=>n2);
d26: sn7404 port map (x=>n2, y=>h2); 
q12 <= h2;



end structure;