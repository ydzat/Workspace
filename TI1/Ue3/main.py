#无向图遍历问题，拓扑排序问题
#V={1,2,3,4,5,6,7}
#E={ {1,2}, {2,3}, {1,4}, {4,3}, {2,4}, {1,5}, {6,5}, {7,5}, {5,4} }
#a) 输出上述图的遍历，及遍历中的每一步G'
#b) 给出一个3色图，该图能得出"weiß nicht",同时也给出G'。
#c) 指出算法的正确性。换句话说，如果图形不是3f，则绝对不会给出G ist 3-färbbar
#   提示：induktionsbeweis归纳法证明

# 2着色问题：存在两个集合V1,V2,有：
#     1. V = V1 ∪ V2 且 V1 ∩ V2 = ∅
#     2. 对于所有的边{u,v}，要么u in V1是v in V2; 要么u in V2时 v in V1。
#         即，不存在一条边，其两端同时存在于V1（或V2）
#     表示：没有一条边的两端为同一颜色。

# 3着色问题：G=(V,E)，V为顶点集合，E为边集合。将V分为3个颜色组，每个组形成一个
# 独立集，即其中没有相邻的顶点。

from unrGraph import unrGraph

i = 0
G = []



while(1):
    G.append([])
    
    G[i] = unrGraph()

    print("wie viele Knoten?")
    k = int(input())
    G[i].setValue(k)
    G[i].setKante()
    G[i].printGraph()
    # print("expandieren :")
    # G[i].expa(k)
    print("3-Färbung Schritt 2, G' ist:")
    #G[i].expa_3f(k)
    
    print("ohne Unterbrechung gilt es:")
    G[i].expa(k)


    print("weite Graphen machen?(y für ja, sonst exit)")
    ans = input()
    if ans != 'y':
        break
    i = i + 1