package class10;

//点结构描述
public class Node {
    public int value;//id或权重
    public int in;
    public int out;

    public ArrayList<Node> nexts;
    public ArrayList<Edge> edges;

    public Node(int value){
        this.value = value;
        in = 0;
        out = 0;
        nexts = new ArrayList();
        edges = new ArrayList();
    }
}
