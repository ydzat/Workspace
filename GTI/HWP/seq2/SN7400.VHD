library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7400 is -- 1/4 SN7400
  port (x : in X01_vector (1 to 2); y : out X01);
end sn7400;

architecture dataflow of sn7400 is
begin
  y <= x(1) nand x(2);
end dataflow;