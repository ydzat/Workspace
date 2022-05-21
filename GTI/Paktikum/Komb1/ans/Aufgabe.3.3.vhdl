library ieee; 
use ieee.std_logic_1164.all; 
use work.pack_2.all;

entity uut is 
    port (x_fghij : in X01_vector(20 downto 13); 
        z_abcde : out X01_vector(20 downto 13)); 
end uut;

architecture structure of uut is

    alias a : x01 is x_fghij(20); 
    alias b : x01 is x_fghij(19); 
    alias c : x01 is x_fghij(18); 
    alias d : x01 is x_fghij(17);

    component sn7400 -- 2NAND 
        port (x : in X01_vector (1 to 2); y : out X01); 
    end component;
    component sn7427 -- 3NOR 
        port (x : in X01_vector (1 to 3); y : out X01);
    end component;
    component sn74260 -- 5NOR 
        port (x : in X01_vector (1 to 5); y : out X01); 
    end component;
    component sn7410 -- 3NAND 
        port (x : in X01_vector (1 to 3); y : out X01); 
    end component;
    component sn7420 -- 4NAND 
        port (x : in X01_vector (1 to 4); y : out X01); 
    end component;
signal not_a, not_b, not_c, not_d :X01; 
signal nand_out :X01_vector (1 to 4); 
signal nor_out :X01_vector (1 to 4);

begin 
    -- BLOCK 1 NEGATION
    NA:   sn7400   port map (x(1)=>a,x(2)=>a,y=>not_a); 
    NB:   sn7400   port map (x(1)=>b,x(2)=>b,y=>not_b); 
    NC:   sn7400   port map (x(1)=>c,x(2)=>c,y=>not_c); 
    ND:   sn7400   port map (x(1)=>d,x(2)=>d,y=>not_d);

    -- BLOCK 2 NOR/NOR
    NOR_1:   sn7427   port map 
        (x(1)=>not_a,x(2)=>not_c,x(3)=>d,y=>nor_out(1)); 
    NOR_2:   sn7427   port map 
        (x(1)=>not_a,x(2)=>b,x(3)=>c,y=>nor_out(2)); 
    NOR_3:   sn7427   port map 
        (x(1)=>a,x(2)=>c,x(3)=>d,y=>nor_out(3)); 
    NOR_4:   sn74260   port map 
        (x(1)=>a,x(2)=>not_b,x(3)=>not_c,x(4)=>a,x(5)=>not_c,y=>nor_out(4));
    NOR_RESULT:   sn74260   port map 
        (x(1 to 4)=>nor_out ,x(5)=>nor_out(4),y=>z_abcde(20));
-- BLOCK 3 NAND/NAND
    NAND_1:   sn7410   port map 
        (x(1)=>a,x(2)=>not_c,x(3)=>not_d,y=>nand_out(1));
    NAND_2:   sn7410   port map 
        (x(1)=>a,x(2)=>not_b,x(3)=>not_c,y=>nand_out(2)); 
    NAND_3:   sn7410   port map 
        (x(1)=>not_a,x(2)=>not_c,x(3)=>not_d,y=>nand_out(3)); 
    NAND_4:   sn7420   port map 
        (x(1)=>not_a,x(2)=>b,x(3)=>c,x(4)=>c,y=>nand_out(4));
    NAND_RESULT:   sn7420   port map 
        (x=>nand_out ,y=>z_abcde(19));
end structure;
