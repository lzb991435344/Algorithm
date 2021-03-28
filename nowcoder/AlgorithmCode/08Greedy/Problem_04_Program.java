package Greedy;

import java.util.Arrays;
import java.util.Comparator;

public class Problem_04_Program {
    public static class Program{
        public int start;
        public int end;
        public Program(int start,int end){
            this.start = start;
            this.end = end;
        }

        public static class ProgramComprator implements Comparator<Program>{
            @Override
            //结束时间早的先安排
            public int compare(Program o1, Program o2) {
                return o2.end - o1.end;
            }
        }

        //使用堆做也可以,cur为当前时刻
        public static int bestArrange(Program[] program, int cur){
            Arrays.sort(program, new ProgramComprator());
            int res = 0;

            for(int i = 0; i < program.length; ++i){
                //项目可以安排
                if(cur <= program[i].start){//淘汰项目
                    res++;
                    cur = program[i].end;//调整时间，end的时间最早的
                }
            }
            return res;
        }
    }
    public static void main(String[] args){

    }
}
