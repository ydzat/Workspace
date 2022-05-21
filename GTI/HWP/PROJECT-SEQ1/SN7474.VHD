library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity sn7474 is -- 1/2 SN7474
  port (s_b,r_b,c,d : in X01; q,q_b : out X01);
end sn7474;

architecture dataflow of sn7474 is
  signal l : X01_vector (1 to 6);
begin
  l(1) <= not(s_b  and l(4) and l(2));
  l(2) <= not(l(1) and r_b  and c   );
  l(3) <= not(l(2) and c    and r_b );
  l(4) <= not(l(3) and r_b  and d   );
  l(5) <= not(s_b  and l(2) and l(6));
  l(6) <= not(l(5) and r_b  and l(3));
  q    <= l(5);
  q_b  <= l(6);
end dataflow;
