library ieee;
use ieee.std_logic_1164.all;

package pack_2 is
  type x01_vector is array (natural range <>) of x01;
  function to_x01 (x : in string) return x01_vector;
  function to_char (x : in x01_vector) return string; 
end pack_2;

package body pack_2 is
  function to_x01 (x : in string) return x01_vector is
    alias    temp1 : string(1 to x'length) is x;
    variable temp2 : x01_vector(1 to x'length);
  begin
    for i in temp1'range loop
      case temp1(i) is
        when '0'    => temp2(x'length - i + 1) := '0';
        when '1'    => temp2(x'length - i + 1) := '1';
        when others => temp2(x'length - i + 1) := 'X';
      end case;
    end loop;
    return temp2;
  end to_x01;

  function to_char(x : in x01_vector) return string is
    alias    temp1 : x01_vector(1 to x'length) is x;
    variable temp2 : string(1 to x'length);
  begin
    for i in temp1'range loop
      case temp1(i) is
        when '0' => temp2(temp1'length - i + 1) := '0';
        when '1' => temp2(temp1'length - i + 1) := '1';
        when 'X' => temp2(temp1'length - i + 1) := 'X';
      end case;
    end loop;
    return temp2;
  end to_char;
end pack_2;

library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity uut is
  port (EE_X : in  x01_vector(7 downto 0);
        EE_Y : out x01_vector(23 downto 16));
end uut;

library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;
use std.textio.all;

entity dbb2_08 is
  port (x_fghij : out x01_vector(20 downto 13);
        z_abcde : in  x01_vector(20 downto 13));
end dbb2_08;

architecture behavior of dbb2_08 is
  file f_in        : text is in  "f_in";
  file f_out       : text is out "f_out";
  signal eof       : boolean := false;
  signal clock     : x01 := '0';
  signal number    : integer;
  signal stim_x01  : x01_vector(8 downto 1);
  signal stim_char : string(1 to 8);
  signal soll_char : string(1 to 8);
  signal comment   : string(1 to 40);
begin
  process (clock) begin
    if not eof or clock = '1' then
      clock <= not clock after 100 ns;
    end if;
  end process;
  process
    variable zeile : line;
    variable feld  : string(1 to 74);
    alias    stim  : string(1 to  8) is feld(17 to 24);
    alias    soll  : string(1 to  8) is feld(26 to 33);
    alias    comm  : string(1 to 40) is feld(35 to 74);
  begin
    number <= 0;
    while not endfile(f_in) loop
      readline(f_in,zeile);
      feld := (others => ' ');
      read(zeile,feld(1 to zeile'length));
      stim_x01 <= to_x01(stim);
      wait until clock = '1';
      number    <= number + 1;
      stim_char <= stim;
      soll_char <= soll;
      comment   <= comm;
      x_fghij   <= stim_x01;
    end loop;
    eof <= true;
    wait;
  end process;
  process
    variable zeile    : line;
    variable ist_char : string(1 to 8);
    variable mark     : string(1 to 8);
  begin
    wait until clock = '0';
    ist_char := to_char(z_abcde);
    write(zeile,number,right,3);
    write(zeile," "&stim_char&" -> "&ist_char&" "&comment);
    writeline(f_out,zeile);
    write(zeile,soll_char,right,24);
    writeline(f_out,zeile);
    mark := (others => ' ');
    for i in mark'range loop
      if soll_char(i) /= '-' then
        if ist_char(i) /= soll_char(i) then
          mark(i) := '^';
        end if;
      end if;
    end loop;
    write(zeile,mark,right,24);
    writeline(f_out,zeile);
  end process;
end behavior;

library ieee;
use ieee.std_logic_1164.all;
use work.pack_2.all;

entity test is
end test;

architecture test of test is
  component dbb2_08
    port (x_fghij : out x01_vector(20 downto 13);
          z_abcde : in  x01_vector(20 downto 13));
  end component;
  component uut
    port (EE_X : in  x01_vector(7 downto 0);
          EE_Y : out x01_vector(23 downto 16));
  end component;
  signal EE_X : x01_vector(7 downto 0) := (others => '0');
  signal EE_Y : x01_vector(23 downto 16) := (others => '0');
begin
  u1: dbb2_08 port map(EE_X,EE_Y);
  u2: uut     port map(EE_X,EE_Y);
end test;
