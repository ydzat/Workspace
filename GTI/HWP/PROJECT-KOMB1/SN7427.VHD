library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7427 is -- 1/4 SN7427
  port (x : in X01_vector (1 to 3); y : out X01);
end sn7427;

architecture dataflow of sn7427 is
begin
  y <= not(x(1) or x(2) or x(3));
end dataflow;
