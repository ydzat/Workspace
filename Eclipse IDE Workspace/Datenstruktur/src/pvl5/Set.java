package pvl5;

import java.util.List;

public interface Set extends Iterable<Set>{
    Set union(Set toInsert);
    Set cut(Set toCutWith);
    Set relativeComplementWith(Set sampleSet);
    boolean isSubsetOf(Set sampleSet);
    boolean equals(Set sampleSet);
    List<Integer> asIntList();
}
