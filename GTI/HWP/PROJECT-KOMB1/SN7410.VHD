library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7410 is -- 1/3 SN7410
  port (x : in X01_vector (1 to 3); y : out X01);
end sn7410;

architecture dataflow of sn7410 is
begin
  y <= not(x(1) and x(2) and x(3));
end dataflow;
