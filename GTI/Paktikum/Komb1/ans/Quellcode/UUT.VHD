library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity uut is
  port (EE_X : in  x01_vector(7 downto 0);
        EE_Y : out x01_vector(23 downto 16));
end uut;

architecture structure of uut is
  
  alias a  : x01 is EE_X(0);
  alias b  : x01 is EE_X(1);
  alias c  : x01 is EE_X(2);
  alias d  : x01 is EE_X(3);
  alias y1 : x01 is EE_Y(16);
  alias y2 : x01 is EE_Y(17);
  
begin



end structure; 