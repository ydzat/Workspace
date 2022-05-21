library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn74260 is -- 1/2 SN74260
  port (x : in X01_vector (1 to 5); y : out X01);
end sn74260;

architecture dataflow of sn74260 is
begin
  y <= not(x(1) or x(2) or x(3) or x(4) or x(5));
end dataflow;