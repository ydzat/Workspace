package pvl4;

public interface HuffmanCode {
    String getCodes();
    String encode(String plainText);
    String decode(String huffmanText);
}
