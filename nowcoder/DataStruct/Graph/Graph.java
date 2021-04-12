package class10;

import java.util.HashSet;
import java.util.HashMap;
public class Graph {
    public HashMap<Integer, Node> nodes; //通过点集找到实例
    public HashSet<Edge> edges;


    public Graph(){
        nodes = new HashMap<>();
        edges = new HashSet<>();
    }
}
