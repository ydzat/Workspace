library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn74151 is -- SN74151
  port (e   : in  X01;
        s   : in  X01_vector (2 downto 0);
        d   : in  X01_vector (0 to 7); 
        y,w : out X01);
end sn74151;

architecture dataflow of sn74151 is
  signal l : X01_vector(0 to 8);
begin
  l(0) <= not e and not s(2) and not s(1) and not s(0) and d(0);
  l(1) <= not e and not s(2) and not s(1) and     s(0) and d(1);
  l(2) <= not e and not s(2) and     s(1) and not s(0) and d(2);
  l(3) <= not e and not s(2) and     s(1) and     s(0) and d(3);
  l(4) <= not e and     s(2) and not s(1) and not s(0) and d(4);
  l(5) <= not e and     s(2) and not s(1) and     s(0) and d(5);
  l(6) <= not e and     s(2) and     s(1) and not s(0) and d(6);
  l(7) <= not e and     s(2) and     s(1) and     s(0) and d(7);
  l(8) <= l(0) or l(1) or l(2) or l(3) or l(4) or l(5) or l(6) or l(7);
  y <= l(8);
  w <= not l(8);
end dataflow;
