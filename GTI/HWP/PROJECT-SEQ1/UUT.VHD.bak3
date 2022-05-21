library ieee;
use ieee.std_logic_1164.all;

entity test is
end test;

architecture test of test is
  signal c,d,s11,s12,s13,s21,s22,s23,s24,q0,q1,q2,n1,n2,h1,h2 : x01;
begin
  c <= '0','1' after 100 ns,'0' after 200 ns,'1' after 400 ns,'0' after 500 ns,
       '1' after 700 ns,'0' after 800 ns,'1' after 1000 ns,'0' after 1100 ns,
       '1' after 1300 ns, '0' after 1400 ns;
  d <= '0','1' after 600 ns,'0' after 1200 ns;
  --
  q0 <= (c and d) or (not c and q0) after 10 ns;
  --
  s11 <= not c after 10 ns;
  s12 <= not s11 after 10 ns;
  s13 <= not s12 after 10 ns;
  h1  <= not s13 and not c;    -- Hilfssignal zu Ueberwachung der Takteingaenge
  n1  <= (q1 and s13) nor (c and d) after 10 ns;
  q1  <= not n1 after 10 ns;
  --
  s21 <= not c after 10 ns;
  s22 <= not s21 after 10 ns;
  s23 <= not s22 after 10 ns;
  s24 <= not s23 after 10 ns;
  h2  <= not s21 and not s24;  -- Hilfssignal zu Ueberwachung der Takteingaenge
  n2  <= (q2 and s21) nor (s24 and d) after 10 ns;
  q2  <= not n2 after 10 ns;
  --
end test; 
