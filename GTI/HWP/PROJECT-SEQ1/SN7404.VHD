library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7404 is -- 1/6 SN7404
  port (x : in X01; y : out X01);
end sn7404;

architecture dataflow of sn7404 is
begin
  y <= not x;
end dataflow;
