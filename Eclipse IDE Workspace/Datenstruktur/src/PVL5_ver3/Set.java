/*
 * @Author: your name
 * @Date: 2020-06-04 19:47:26
 * @LastEditTime: 2020-06-05 19:32:28
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Workspace\Datenstrukturen\PVL5_ver3\proj\Set.java
 */ 
package PVL5_ver3;

import java.util.List;

public interface Set extends Iterable<Set>{
    Set union(Set toInsert);
    Set cut(Set toCutWith);
    Set relativeComplementWith(Set sampleSet);
    boolean isSubsetOf(Set sampleSet);
    boolean equals(Set sampleSet);
    List<Integer> asIntList();
}
