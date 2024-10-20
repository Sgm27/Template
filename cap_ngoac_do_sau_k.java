import java.math.BigInteger;
import java.util.*;

public class Main {
	static BigInteger dp[][][] = new BigInteger[205][105][2];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < dp.length; i++) 
			for (int j = 0; j < dp[i].length; j++) 
				for (int k = 0; k < dp[i][j].length; k++) dp[i][j][k] = BigInteger.ZERO;
		
		int k = Integer.parseInt(sc.nextLine());
		String s = sc.nextLine();
		int n = s.length();
		s = " " + s;

		dp[0][0][0] = BigInteger.ONE;

		for (int i = 0; i < n; i++)
			for (int bac = 0; bac <= k; bac++)
			{
				if (dp[i][bac][1] != BigInteger.ZERO)
				{
					if (s.charAt(i+1) == '(') 
						dp[i + 1][bac + 1][1] = dp[i + 1][bac + 1][1].add(dp[i][bac][1]);
					if (s.charAt(i+1) == ')' && bac >= 1)
						dp[i + 1][bac - 1][1] = dp[i + 1][bac - 1][1].add(dp[i][bac][1]);
					if (s.charAt(i+1) == '?')
					{
						if (bac < k)
							dp[i + 1][bac + 1][1] = dp[i + 1][bac + 1][1].add(dp[i][bac][1]);
						if (bac >= 1)
							dp[i + 1][bac - 1][1] = dp[i + 1][bac - 1][1].add(dp[i][bac][1]);
					}
				}

				if (dp[i][bac][0] != BigInteger.ZERO)
				{
					int new_state = 0;
					if (bac + 1 == k) new_state = 1;
					if (s.charAt(i+1) == '(')
						dp[i + 1][bac + 1][new_state] = dp[i + 1][bac + 1][new_state].add(dp[i][bac][0]);
					if (s.charAt(i+1) == ')' && bac >= 1)
						dp[i + 1][bac - 1][0] = dp[i + 1][bac - 1][0].add(dp[i][bac][0]);
					if (s.charAt(i+1) == '?')
					{
						if (bac < k)
							dp[i + 1][bac + 1][new_state] = dp[i + 1][bac + 1][new_state].add(dp[i][bac][0]);
						if (bac >= 1)
							dp[i + 1][bac - 1][0] = dp[i + 1][bac - 1][0].add(dp[i][bac][0]);
					}
				}
			}
		System.out.println(dp[n][0][1]);
		sc.close();
	}	
}