library ieee ; 
use ieee.std_logic_1164.all; 
use work.pack_2.all; 
entity uut is 
    port ( EE_X : in X01_vector (7 downto 0);
            EE_Y : out X01_vector (23 downto 16));
end uut ; 
architecture structure of uut is 
    component sn7400 is 
        port ( x : in X01_vector (1 to 2); y : out X01 ); 
    end component; 

    component sn7472 is
        port ( s_b , r_b , c : in X01; 
              j , k : in X01_vector (1 to 3); 
              q , q_b : out X01 ); 
    end component;

    component sn7474 is
        port ( s_b , r_b , c , d : in X01;
              q , q_b : out X01 ); 
    end component; 
    alias j : X01 is EE_X(4); 
    alias k : X01 is EE_X(5);
    alias c : X01 is EE_X(6); 
    alias r : X01 is EE_X(7); 
    alias q1_out : X01 is EE_Y (20); 
    alias q2_out : X01 is EE_Y (21); 
    signal nk , q1 , nq1 , l6_13 , l8_12 , l11_d : X01; 
    signal nc , q2 , nq2 : X01; 
begin 

    NOTK: sn7400 port map ( x(1)=>k , x(2)=>k , y=>nk ); 
    NAND1: sn7400 port map ( x(1)=>nq1 , x(2)=>j , y=>l6_13 ); 
    NAND2: sn7400 port map ( x(1)=>nk , x(2)=>q1 , y=>l8_12 ); 
    NAND3: sn7400 port map ( x(1)=>l6_13 , x(2)=>l8_12 , y=>l11_d ); 
    D_FF: sn7474 port map ( s_b=>'1', r_b=>r , c=>c , d=>l11_d , q=>q1 , q_b=>nq1 ); 

    NOTC: sn7400 port map ( x(1)=>c , x(2)=>c , y=>nc );
    JK_FF: sn7472 port map ( s_b=>'1', r_b=>r , c=>nc , j(1)=>'1', j(2)=>j , j(3)=>'1', 
                              k(1)=>'1', k(2)=>k , k(3)=>'1', q=>q2 , q_b=>nq2 );

    q1_out<=q1; 
    q2_out<=q2; 
end structure;
