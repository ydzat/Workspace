library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn74153 is -- SN74153
  port (e1,e2  : in  X01;
        s      : in  X01_vector (1 downto 0);
        d1,d2  : in  X01_vector (0 to 3);
        y1,y2  : out X01);
end sn74153;

architecture dataflow of sn74153 is
  signal l : X01_vector(0 to 8);
begin
  l(0) <= not e1 and not s(1) and not s(0) and d1(0);
  l(1) <= not e1 and not s(1) and     s(0) and d1(1);
  l(2) <= not e1 and     s(1) and not s(0) and d1(2);
  l(3) <= not e1 and     s(1) and     s(0) and d1(3);
  l(4) <= not e2 and not s(1) and not s(0) and d2(0);
  l(5) <= not e2 and not s(1) and     s(0) and d2(1);
  l(6) <= not e2 and     s(1) and not s(0) and d2(2);
  l(7) <= not e2 and     s(1) and     s(0) and d2(3);
  y1   <= l(0) or l(1) or l(2) or l(3);
  y2   <= l(4) or l(5) or l(6) or l(7);
end dataflow;
