library ieee; 
use ieee.std_logic_1164.all; 
use work.pack_2.all;
entity uut is 
        port ( EE_X : in x01_vector(7 downto 0); 
            EE_Y : out x01_vector(23 downto 16) ); 
end uut;

architecture structure of uut is
  alias a  : x01 is EE_X(0);
  alias b  : x01 is EE_X(1);
  alias c  : x01 is EE_X(2);
  alias d  : x01 is EE_X(3);


    component sn7400 is -- 2er NAND 
        port ( x : in X01_vector (1 to 2); 
            y : out X01 ); 
    end component;

    component sn7404 is -- Negatoren 
        port ( x : in X01; 
            y : out X01 ); 
    end component;

    component sn74151 is -- 8zu1 Multiplexer 
        port ( e : in X01; 
            s : in X01_vector (2 downto 0); 
            d : in X01_vector (0 to 7); 
            y,w : out X01 ); 
    end component;
    
    component sn74153 is -- 4zu1 Multiplexer 
        port ( e1,e2 : in X01; 
            s : in X01_vector (1 downto 0); 
            d1,d2 : in X01_vector (0 to 3); 
            y1,y2 : out X01 );
    end component;

    signal not_a,not_b,not_c,not_d : X01; 
    signal temp0, temp1, temp2, temp3 : X01; 
    signal buffy0 ,buffy1 : X01;

begin
    -- Block 1: Negation
    NOTA: sn7404 port map(x=>a, y=>not_a);
    NOTB: sn7404 port map(x=>b, y=>not_b); 
    NOTC: sn7404 port map(x=>c, y=>not_c); 
    NOTD: sn7404 port map(x=>d, y=>not_d);
    TEMP0: sn7400 port map(x(1)=>not_c, x(2)=>d, y=>temp0); 
    TEMP1_0: sn7400 port map(x(1)=>not_c, x(2)=>d, y=>buffy0); 
    TEMP1_1: sn7404 port map(x=>buffy0 ,y=>temp1);
    TEMP2_0: sn7400 port map(x(1)=>c,x(2)=>d,y=>buffy1);
    TEMP2_1: sn7404 port map(x=>buffy1 ,y=>temp2);
    TEMP3_1: sn7400 port map(x(1)=>c,x(2)=>not_d,y=>temp3);
    -- Block 2: 8-zu-1-Multiplexer
    MULTI8: sn74151 port map ( e => '0',
                            s(2)=>a, s(1)=>b, s(0)=>c,
                            d(0)=>d, d(1)=>'1', d(2)=>d, d(3)=>'0', 
                            d(4)=>'0', d(5)=>d, d(6)=>'1', d(7)=>d,
                            y=>EE_Y(1)
                            );
    -- Block 3: 4-zu-1-Multiplexer
    MULTI4: sn74153 port map ( e1 => '0', e2 =>'1',
                            s(1) => a, s(0) => b,
                            d1(0) => temp0, d1(1) => temp1, d1(2) => temp2, d1(3) => temp3,
                            d2(0) => '0', d2(1) => '0', d2(2) => '0', d2(3) => '0',
                            y1 => EE_Y(0)
                            );
end structure;