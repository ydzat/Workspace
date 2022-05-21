package logiCacu;


import java.util.*;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.stream.Collectors;
 
public class SimplifyLogicalExpression {
 
    public static void main(String[] args) {
//        String expression = "((A+B)CD+ACD+AB(C+D'))'";
//        String expression = "A'C'+A'B'+BC+A'C'D";
//        String expression = "(ABCD+A'B'C'D')'";
//        String expression = "(A'B)'+(A+C)'";
        //String expression = "A'B'C'+A'B'C+AB'C+ABC+ABC'+A'BC'";
    	//String expression = "((AB')'(A'B)')'C'";
    	String expression = "A'B'+A'B+AB'";
    	
        System.out.println("expression : " + expression);
        List<String> results = simplifyExpression(expression);
        System.out.println();
        for (String simplify : results) {
            System.out.println("simplify : " + simplify);
        }
    }
 
    private static List<String> simplifyExpression(String expression) {
        int length = getLength(expression);
        if (length > 26) {
            throw new IllegalArgumentException("最多支持26个逻辑变量");
        }
 
        // 打开逻辑表达式, 如: (A+B)'=A'B', (AB)'=A'+B'
        String open = open(expression);
        System.out.println("open : " + open);
 
        // 逻辑表达式相乘, 如: (A+B)(B+C)=AB+AC+B+BC
        String multiply = multiply(open);
        System.out.println("multiply : " + multiply);
 
        // 化简逻辑表达式, 如: A+A'B=A+B, AB+A'C+BC=AB+A'C
        return simplify(multiply, length);
    }
 
 
    /**
     * 展开
     */
    private static String open(String expression) {
        StringBuilder sb = new StringBuilder();
        if (isNot(expression)) {
            String not = notNot(expression);
 
            List<String> res = new ArrayList<>();
            if (isOr(not)) {
                List<String> src = listOr(not);
                for (String e : src) {
                    res.add(reverse(e));
                }
 
                for (String s : res) {
                    sb.append(isSimple(s) ? s : open(s));
                }
                return sb.toString();
            } else {
                List<String> src = listAnd(not);
                for (String e : src) {
                    res.add(reverse(e));
                }
 
                for (String s : res) {
                    sb.append(isSimple(s) ? s : open(s)).append("+");
                }
                return "(" + strip(sb.toString().substring(0, sb.length() - 1)) + ")";
            }
        } else if (isOr(expression)) {
            List<String> list = listOr(expression);
            for (String s : list) {
                sb.append(isSimple(s) ? s : open(s)).append("+");
            }
            return "(" + strip(sb.toString().substring(0, sb.length() - 1)) + ")";
        } else {
            List<String> list = listAnd(expression);
            for (String s : list) {
                sb.append(isSimple(s) ? s : open(s));
            }
            return sb.toString();
        }
    }
 
 
    private static boolean isSimple(String str) {
        str = strip(str);
        return str.length() == 1 || str.length() == 2 && str.endsWith("'");
    }
 
    /**
     * 如果满足(A+B)格式，剥离最外层括号
     */
    private static String strip(String str) {
        if (!str.startsWith("(") || !str.endsWith(")")) {
            return str;
        }
        int closeCount = 0;
        int close = 0;
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (c == '(') {
                close--;
            } else if (c == ')') {
                close++;
            }
            if (close == 0) {
                closeCount++;
                if (i == chars.length - 1 && closeCount == 1) {
                    String res = str.substring(1, str.length() - 1);
                    if (res.startsWith("(")) {
                        return strip(res);
                    } else {
                        return res;
                    }
                }
            }
        }
        return str;
    }
 
    private static List<String> listAnd(String str) {
        List<String> list = new ArrayList<>();
        int begin = 0;
        int close = 0;
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (c == '(') {
                close--;
            } else if (c == ')') {
                close++;
            }
            if (i < chars.length - 1 && chars[i + 1] == '\'') {
                continue;
            }
            if (close == 0) {
                list.add(strip(str.substring(begin, i + 1)));
                begin = i + 1;
            }
        }
        return list;
    }
 
    private static boolean isOr(String str) {
        int close = 0;
        char[] chars = str.toCharArray();
        for (char c : chars) {
            if (c == '(') {
                close--;
            } else if (c == ')') {
                close++;
            } else if (close == 0 && c == '+') {
                return true;
            }
        }
        return false;
    }
 
    private static boolean isAnd(String str) {
        return !isNot(str) && !isOr(str);
    }
 
    private static List<String> listOr(String str) {
        List<String> list = new CopyOnWriteArrayList<>();
        int begin = 0;
        int close = 0;
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (c == '(') {
                close--;
            } else if (c == ')') {
                close++;
            }
            if (close == 0) {
                if (c == '+') {
                    list.add(str.substring(begin, i));
                    begin = i + 1;
                } else if (i == chars.length - 1) {
                    list.add(str.substring(begin));
                }
            }
        }
        return list;
    }
 
    /**
     * 整体非判断，如：(A'B+CD')'
     */
    private static boolean isNot(String str) {
        int close = 0;
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (c == '(') {
                close--;
            } else if (c == ')') {
                close++;
            } else if (close == 0) {
                if (chars[0] == '(' && chars[i - 1] == ')' && c == '\'' && i == chars.length - 1) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
 
    /**
     * 取反
     */
    private static String reverse(String expression) {
        if (isNot(expression)) {
            return notNot(expression);
        }
        if (expression.length() == 1) {
            return expression + "'";
        } else if (expression.length() == 2 && expression.endsWith("'")) {
            return expression.substring(0, 1);
        } else {
            return "(" + strip(expression) + ")'";
        }
    }
 
    /**
     * 整体非的取非
     */
    private static String notNot(String expression) {
        return expression.substring(1, expression.length() - 2);
    }
 
    /**
     * (A+B)(B+C)=AB+AC+B+BC
     */
    private static String multiply(String expression) {
        if (!isAnd(strip(expression))) {
            return strip(expression);
        }
 
        List<List<String>> lists = new ArrayList<>();
 
        List<String> expressions = listAnd(expression);
        for (String and : expressions) {
            List<String> or = listOr(and);
            for (String s : or) {
                if (s.contains("(") && s.contains(")")) {
                    or.remove(s);
                    or.addAll(listOr(multiply(s)));
                }
            }
            lists.add(or);
        }
        Set<String> calc = new TreeSet<>(lists.get(0));
        for (int i = 1; i < lists.size(); i++) {
            List<String> multi = lists.get(i);
            Set<String> newCalc = new TreeSet<>();
            for (String c : calc) {
                for (String m : multi) {
                    newCalc.add(c + m);
                }
            }
            calc = modify(newCalc);
        }
 
        StringBuilder result = new StringBuilder();
        for (String s : calc) {
            result.append(lowerToUpperCase(s)).append("+");
        }
        return result.substring(0, result.length() - 1);
    }
 
 
    /**
     * a转为A'
     */
    private static String lowerToUpperCase(String s) {
        StringBuilder result = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                result.append(toOtherCase(c)).append("\'");
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }
 
    /**
     * a->A,A->a
     */
    private static char toOtherCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return (char) (c + 32);
        } else if (c >= 'a' && c <= 'z') {
            return (char) (c - 32);
        }
        throw new IllegalArgumentException();
    }
 
    /**
     * 把非转为小写字符
     */
    private static String notToLowerCase(String expression) {
        StringBuilder ss = new StringBuilder();
        char[] chars = expression.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (i < chars.length - 1 && chars[i + 1] == '\'' && chars[i] != ')') {
                ss.append((chars[i] + "").toLowerCase());
                i++;
            } else {
                ss.append(chars[i]);
            }
        }
        return ss.toString();
    }
 
    /**
     * 去重 AAB = AB
     * 去除包含反字符的 ABa = 0
     */
    private static Set<String> modify(Collection<String> expression) {
        Set<String> set = new TreeSet<>();
        z:
        for (String s : expression) {
            Set<Character> treeSet = new TreeSet<>();
            for (char c : notToLowerCase(s).toCharArray()) {
                if (treeSet.contains(toOtherCase(c))) {
                    continue z;
                }
                treeSet.add(c);
            }
            set.add(treeSet.stream().map(Object::toString).collect(Collectors.joining("")));
        }
        return set;
    }
 
    /**
     * 化简逻辑表达式
     */
    private static List<String> simplify(String expression, int length) {
        Map<String, MinimumTerm> map = toMinimumTermMap(expression);
        List<List<String>> lists = flatSimplifyResult(simplify(map));
 
        List<List<String>> result = new ArrayList<>();
        int minUse = Integer.MAX_VALUE;
        for (List<String> list : lists) {
            int use = 0;
            for (String s : list) {
                use += 1 << length - s.length();
            }
            if (minUse > use) {
                minUse = use;
                result.clear();
                result.add(list);
            } else if (minUse == use) {
                result.add(list);
            }
        }
        return result.stream().map(r -> lowerToUpperCase(String.join("+", r))).collect(Collectors.toList());
    }
 
    /**
     * 使用递归平铺SimplifyResult
     */
    private static List<List<String>> flatSimplifyResult(SimplifyResult result) {
        List<List<String>> lists = new ArrayList<>();
        if (result.others.isEmpty()) {
            List<String> list = new ArrayList<>();
            list.addAll(result.value);
            lists.add(list);
            return lists;
        }
        for (SimplifyResult res : result.others) {
            List<List<String>> r = flatSimplifyResult(res);
            for (List<String> list : r) {
                list.addAll(result.value);
            }
            lists.addAll(r);
        }
        return lists;
    }
 
    /**
     * 化简逻辑表达式
     */
    private static SimplifyResult simplify(Map<String, MinimumTerm> map) {
        // 复制一个新的map
        List<MinimumTerm> terms = new ArrayList<>(map.values());
        // 按照相邻项的多少排列
        Collections.sort(terms);
        SimplifyResult result = new SimplifyResult();
        for (MinimumTerm term : terms) {
            if (term.use > 0) {
                continue;
            }
            List<String> list = totalAdjacentTerms(term);
 
            if (allContains(map, list)) {
                for (String s : list) {
                    map.get(s).use++;
                }
                result.value.add(getSimple(term));
            } else {
                Map<MinimumTerm, List<String>> contains = maxContains(map, term);
                for (Map.Entry<MinimumTerm, List<String>> entry : contains.entrySet()) {
                    Map<String, MinimumTerm> copy = copy(map);
                    for (String s : entry.getValue()) {
                        copy.get(s).use++;
                    }
                    SimplifyResult res = new SimplifyResult();
                    res.value.add(getSimple(entry.getKey()));
                    res.others.add(simplify(copy));
                    result.others.add(res);
                }
                break;
            }
        }
        return result;
    }
 
    private static Map<String, MinimumTerm> copy(Map<String, MinimumTerm> map) {
        Map<String, MinimumTerm> newMap = new HashMap<>();
        map.forEach((k, v) -> newMap.put(k, v.copy()));
        return newMap;
    }
 
    private static Map<MinimumTerm, List<String>> maxContains(Map<String, MinimumTerm> map, MinimumTerm term) {
        Map<MinimumTerm, List<String>> result = new HashMap<>();
        for (int i = 1; i < term.trues; i++) {
            Map<MinimumTerm, List<String>> adjacentTerms = getAdjacentTerms(term, i);
            for (Map.Entry<MinimumTerm, List<String>> entry : adjacentTerms.entrySet()) {
                if (allContains(map, entry.getValue())) {
                    result.put(entry.getKey(), entry.getValue());
                }
            }
            if (!result.isEmpty()) {
                break;
            }
        }
        return result;
    }
 
    private static boolean allContains(Map<String, MinimumTerm> map, List<String> adjacentTerms) {
        boolean contains = true;
        for (String adjacentTerm : adjacentTerms) {
            if (!map.keySet().contains(adjacentTerm)) {
                contains = false;
            }
        }
        return contains;
    }
 
    private static Map<MinimumTerm, List<String>> getAdjacentTerms(MinimumTerm term, int count) {
        Map<MinimumTerm, List<String>> result = new HashMap<>();
        List<Set<Integer>> lists = combination(term.trues, count, 0);
        for (Set<Integer> list : lists) {
            MinimumTerm copy = term.copy();
            int k = 0;
            for (int i = 0; i < copy.around.size(); i++) {
                if (!copy.around.get(i)) {
                    continue;
                }
                if (list.contains(k)) {
                    copy.around.set(i, false);
                    copy.trues--;
                }
                k++;
            }
            List<String> terms = totalAdjacentTerms(copy);
            result.put(copy, terms);
        }
        return result;
    }
 
    /**
     * c n k 组合数
     */
    private static List<Set<Integer>> combination(int n, int k, int begin) {
        List<Set<Integer>> result = new ArrayList<>();
        for (int i = begin; i <= n - k; i++) {
            if (k > 1) {
                List<Set<Integer>> list = combination(n, k - 1, i + 1);
                for (Set<Integer> set : list) {
                    set.add(i);
                }
                result.addAll(list);
            } else {
                Set<Integer> set = new HashSet<>();
                set.add(i);
                result.add(set);
            }
        }
        return result;
    }
 
    /**
     * n个相邻项组成的2^n个所有项
     * 若ABCD有三个相邻最小项目A'BCD,AB'CD,ABC'D
     * 则返回8个最小项集合 ABCD,ABC'D,AB'CD,AB'C'D,A'BCD,A'BC'D,A'B'CD,A'B'C'D
     */
    private static List<String> totalAdjacentTerms(MinimumTerm term) {
        List<String> terms = new ArrayList<>();
 
        int n = 1 << term.trues;
        for (int i = 0; i < n; i++) {
            char[] chars = Integer.toBinaryString(i).toCharArray();
            int k = chars.length - 1;
            List<Integer> indices = new ArrayList<>();
            for (int j = 0; j < term.around.size(); j++) {
                if (!term.around.get(j)) {
                    continue;
                }
                if (chars.length >= k + 1 && k >= 0 && chars[k] == '1') {
                    indices.add(j);
                }
                k--;
            }
            terms.add(getOtherTermValue(term.value, indices));
        }
        return terms;
    }
 
    /**
     * 获取变量个数
     */
    private static int getLength(String expression) {
        Set<Character> set = new HashSet<>();
        for (char c : expression.toUpperCase().toCharArray()) {
            if (c >= 'A' && c <= 'Z') {
                set.add(c);
            }
        }
        return set.size();
    }
 
    private static Map<String, MinimumTerm> toMinimumTermMap(String expression) {
        Set<MinimumTerm> nodes = new HashSet<>();
        for (String s : expression.split("\\+")) {
            nodes.addAll(toMinimumTerms(s, getLength(expression)));
        }
        Map<String, MinimumTerm> map = new HashMap<>();
        for (MinimumTerm node : nodes) {
            map.put(node.value, node);
        }
        fillAround(map);
        return map;
    }
 
    /**
     * 填充是否存在相邻项
     */
    private static void fillAround(Map<String, MinimumTerm> map) {
        for (Map.Entry<String, MinimumTerm> entry : map.entrySet()) {
            for (int i = 0; i < entry.getValue().value.toCharArray().length; i++) {
                String otherTermValue = getOtherTermValue(entry.getValue().value, i);
                boolean contains = map.keySet().contains(otherTermValue);
                entry.getValue().around.add(contains);
                if (contains) {
                    entry.getValue().trues++;
                }
            }
 
        }
    }
 
    private static String getOtherTermValue(String value, int index) {
        List<Integer> indices = new ArrayList<>();
        indices.add(index);
        return getOtherTermValue(value, indices);
    }
 
    private static String getOtherTermValue(String value, List<Integer> indices) {
        for (Integer index : indices) {
            char c = value.charAt(index);
            String prefix = index <= 0 ? "" : value.substring(0, index);
            String suffix = index >= value.length() - 1 ? "" : value.substring(index + 1);
            value = prefix + toOtherCase(c) + suffix;
        }
        return value;
    }
 
    private static String getSimple(MinimumTerm term) {
        char[] chars = term.value.toCharArray();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < term.around.size(); i++) {
            if (!term.around.get(i)) {
                sb.append(chars[i]);
            }
        }
        return sb.toString();
    }
 
    private static Set<MinimumTerm> toMinimumTerms(String s, int length) {
        List<StringBuilder> terms = listMinimumTerms(notToLowerCase(s), length);
        Set<MinimumTerm> nodes = new HashSet<>();
        for (StringBuilder sb : terms) {
            MinimumTerm term = new MinimumTerm();
            term.value = sb.toString();
            nodes.add(term);
        }
        return nodes;
    }
 
    /**
     * 获取最小项列表
     *
     * @param len 最小项长度
     */
    private static List<StringBuilder> listMinimumTerms(String src, int len) {
        List<StringBuilder> sList = new CopyOnWriteArrayList<>();
        StringBuilder ns = new StringBuilder();
        sList.add(ns);
        for (int i = 'A'; i < 'A' + len; i++) {
            String c = (char) i + "";
            if (src.contains(c)) {
                for (StringBuilder s : sList) {
                    s.append(c);
                }
            } else if (src.toUpperCase().contains(c)) {
                // c是小写字符
                for (StringBuilder s : sList) {
                    s.append(c.toLowerCase());
                }
            } else {
                for (StringBuilder s : sList) {
                    StringBuilder nns = new StringBuilder(s);
                    nns.append(c.toLowerCase());
                    s.append(c);
                    sList.add(nns);
                }
            }
        }
        return sList;
    }
 
    /**
     * 最小项
     */
    private static class MinimumTerm implements Comparable<MinimumTerm> {
        String value;
        List<Boolean> around = new ArrayList<>();
        int trues = 0;
        int use = 0;
 
        @Override
        public int compareTo(MinimumTerm o) {
            return trues - o.trues;
        }
 
        @Override
        public String toString() {
            return value + around + trues + "/" + use;
        }
 
        MinimumTerm copy() {
            MinimumTerm term = new MinimumTerm();
            term.value = this.value;
            term.around.addAll(this.around);
            term.trues = this.trues;
            term.use = this.use;
            return term;
        }
    }
 
    /**
     * 最小项结果
     */
    private static class SimplifyResult {
        List<String> value = new ArrayList<>();
        List<SimplifyResult> others = new ArrayList<>();
 
        @Override
        public String toString() {
            return value.toString() + (others.isEmpty() ? "" : others.toString());
        }
    }
}
