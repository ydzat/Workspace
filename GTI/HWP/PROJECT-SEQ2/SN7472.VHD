library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7472 is -- SN7472
  port (s_b,r_b,c : in X01; j,k : in X01_vector(1 to 3); q,q_b : out X01);
end sn7472;

architecture dataflow of sn7472 is
  signal l : X01_vector (1 to 9);
begin
  l(1) <= not(l(8) and j(1) and j(2) and j(3) and c);
  l(2) <= not(l(7) and k(1) and k(2) and k(3) and c);
  l(3) <= not(s_b  and l(1) and l(4));
  l(4) <= not(r_b  and l(2) and l(3));
  l(5) <= not(l(3) and l(9));
  l(6) <= not(l(4) and l(9));
  l(7) <= not(s_b  and l(5) and l(8));
  l(8) <= not(r_b  and l(6) and l(7));
  l(9) <= not c;
  q    <= l(7);
  q_b  <= l(8);
end dataflow;
