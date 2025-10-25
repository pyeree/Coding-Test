import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
//======================
// 백준 단계별로 풀어보기 : 2745 진법 변환
//======================
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String s = st.nextToken();
        int N = Integer.parseInt(st.nextToken());

        char [] c = s.toCharArray();
        int len = s.length();
        int [] nums = new int[len];


        for(int i =0; i<c.length; i++){
            char key = c[i];
            if('0'<=key && key<='9'){
                nums[i] = key-'0';
            }
            else if('A'<=key && key<='Z'){
                nums[i] = key-'A'+10;
            }
        }
        int result = 0;
        int j=len-1;
        for(int i=0; i<len; i++){
            int x = (int)(Math.pow(N,j));
            int sub = nums[i] * x;
            result += sub;
            if(j>=0){
                j--;
            }

        }
        System.out.println(result);












    }
}
