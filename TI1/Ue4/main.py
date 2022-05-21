'''DFS
0.创建一个栈stack，用于作为待遍历序列
1.将根结点放入stack中
2.从stack中取出第一个节点，并检验是否为目标。
    如果找到目标，则结束搜索，并传回结果
    否则将该结点的一个尚未检验过的直接子节点放入stack中。
3.重复步骤2
4.若不存在尚未检测过的直接子节点
    将上一级节点加入stack中
    重复步骤2
5.重复步骤4
6.若stack为空，表示遍历完成，无结果。
'''

void DFS(root){
  stack stk;
  stk.push(root);//let Knote_root in stack
  while(!stk.empty()){
    p = stk.top();//let the top element of the stack out, and visit it
    visit(p);
    stk.pop();
    if(p.child)  stk.push(stk.child)//let the child knoten in stack
  }
}

pop() := geben das letzte Elmenete von der List, das der letzte Eintrag in der List ist, und entferen SIe es aus der Liste.
visit() := Bestimmen Sie, ob der Knoten das ist, wonach Sie suchen. Wenn ja, Suchen erledigt ist. Wenn nein, weite.
push() := let Knote in stack
empty() := Stell fest, ob es leer ist
Datenstruktur: Stack
    FILO. Weil die Eigenschaft von DFS darin besteht, den zuletzt gefundenen Knoten zu beurteilen. Dies stimmt sehr gut mit den Eigenschaften des Stapels überein.

---------------------------------
Wenn DFS durchgeläuft, bilden alle Knoten auf einem der Pfade des gerichteten Graphen eine Verzweigung. Das heißt, die möglichen Beziehungen zwischen den Knoten auf diesem Pfad sind:
Eltern - (direkter o. indirekter) Kind, Bruder - Bruder(Kind - Kind).
Aufgrund d[u]<d[v], d.h. v ist ein direkter oder indirekter Nachfolger von u im zugehörigen Tiefensuchwald.
