library ieee;
use ieee.std_logic_1164.all;                               
use work.pack_2.all;                                       
                                                         
entity uut is                                            
  port (EE_X : in  X01_vector(7 downto 0);
        EE_Y : out X01_vector(23 downto 16));       
end uut;     

architecture structure of uut is
    component sn7400 -- 2er-nand 
        port (x : in X01_vector (1 to 2); 
            y : out X01); 
    end component; 

    component sn7404 is -- not 
        port (x : in X01; y : out X01); 
    end component; 

    component sn7472 is -- JK-MS-Flipflop 
        port (s_b,r_b,c : in X01; 
            j,k : in X01_vector(1 to 3); 
            q,q_b : out X01); 
    end component;

    alias c     : x01 is EE_X(0);
    alias sl    : x01 is EE_X(1);
    alias cb    : x01 is EE_X(2);

    alias reset : x01 is EE_X(4);
    alias load  : x01 is EE_X(5);
    alias d1    : x01 is EE_X(6);
    alias d0    : x01 is EE_X(7);

    alias q1    : x01 is EE_Y(17);
    alias q0    : x01 is EE_Y(16);

    signal n1,n2,n3,n4,n5,n6 : X01; 

    signal nand1,nand2,nand3,nand4,nand5,nand6,nand7,nand8,nand9,nand10,nand11,nand12,nand13,nand14,nand15 : X01;

    signal fq0,nq0 : X01;

begin
    -- not: sn7404
    no1: sn7404 port map(x=>reset,y=>n1);
    no2: sn7404 port map(x=>cb,y=>n2);
    no3: sn7404 port map(x=>sl,y=>n3);
    no4: sn7404 port map(x=>nand4,y=>n4);
    no5: sn7404 port map(x=>nand3,y=>n5);
    no6: sn7404 port map(x=>nand6,y=>n6);
    --nand:sn7400
    
    na1: sn7400 port map(x(1)=>load,x(2)=>d1,y=>nand1);
    na2: sn7400 port map(x(1)=>load,x(2)=>d0,y=>nand2);
    na3: sn7400 port map(x(1)=>n1,x(2)=>nand1,y=>nand3);
    na4: sn7400 port map(x(1)=>sl,x(2)=>n2,y=>nand4);
    na5: sn7400 port map(x(1)=>cb,x(2)=>n3,y=>nand5);
    na6: sn7400 port map(x(1)=>n1,x(2)=>nand2,y=>nand6);
    na7: sn7400 port map(x(1)=>nand13,x(2)=>nand10,y=>nand7);
    na8: sn7400 port map(x(1)=>nand5,x(2)=>nand5,y=>nand8);
    na9: sn7400 port map(x(1)=>nand4,x(2)=>nand5,y=>nand9);
    na10: sn7400 port map(x(1)=>n4,x(2)=>nq0,y=>nand10);
    na11: sn7400 port map(x(1)=>n5,x(2)=>load,y=>nand11);
    na12: sn7400 port map(x(1)=>n4,x(2)=>fq0,y=>nand12);
    na13: sn7400 port map(x(1)=>nq0,x(2)=>nand8,y=>nand13);
    na14: sn7400 port map(x(1)=>n6,x(2)=>load,y=>nand14);
    na15: sn7400 port map(x(1)=>nand12,x(2)=>nand13,y=>nand15);
    
    --ffq1:
    ff1: sn7472 port map(s_b=>n5,r_b=>nand11,c=>c,j(1)=>nand15,j(2)=>'1',j(3)=>'1',k(1)=>nand7,k(2)=>'1',k(3)=>'1',q=>q1);

    --ffq0:
    ff2: sn7472 port map(s_b=>n6,r_b=>nand14,c=>c,j(1)=>nand9,j(2)=>'1',j(3)=>'1',k(1)=>nand5,k(2)=>'1',k(3)=>'1',q=>fq0,q_b=>nq0);
    q0 <= fq0;
    end structure;