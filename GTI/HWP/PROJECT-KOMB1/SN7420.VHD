library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7420 is -- 1/2 SN7420
  port (x : in X01_vector (1 to 4); y : out X01);
end sn7420;

architecture dataflow of sn7420 is
begin
  y <= not(x(1) and x(2) and x(3) and x(4));
end dataflow;
