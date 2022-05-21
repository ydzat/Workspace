package pvl4_ver2;

public interface HuffmanCode {
    String getCodes();
    String encode(String plainText);
    String decode(String huffmanText);
}
