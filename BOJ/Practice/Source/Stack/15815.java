import java.io.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        Stack<Integer> st = new Stack<Integer>();
        String expr;
        expr = br.readLine();

        for (int i = 0; i < expr.length(); ++i) {
            char ch = expr.charAt(i);
            if ('0' <= ch && ch <= '9')
                st.push(ch - '0');
            else {
                int n2 = st.pop();
                int n1 = st.pop();
                switch(ch) {
                    case '+': st.push(n1 + n2); break;
                    case '-': st.push(n1 - n2); break;
                    case '*': st.push(n1 * n2); break;
                    case '/': st.push(n1 / n2); break;
                }
            }
        }

        bw.write(st.pop() + "\n");
        bw.flush();
        bw.close();
    }
}