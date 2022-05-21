library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7450 is -- 1/2 SN7450
  port (x11,x12,x21,x22 : in X01; y : out X01);
end sn7450;

architecture dataflow of sn7450 is
begin
  y <= (x11 and x12) nor (x21 and x22);
end dataflow;
