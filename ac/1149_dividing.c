#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	int n, i, j, k, a[128], dp[60006], ans, sum, count; 

	count = 0; 
	while (1) { 
		for (i = 0, j = 1, sum = ans = 0; j <= 6; j++) { 
			scanf("%d", &n); 
			sum += n * j; 
			if (n) { 
				for (k = 1; n > k; k <<= 1)
					a[i++] = k * j, n -= k;
				a[i++] = n * j;
			} 
		} 
		n = i; 
		if (!sum) 
			break; 
		if ((sum & 1) == 0) {
			memset(dp, 0, sizeof(dp)), dp[0] = 1; 
			for (i = 0, sum >>= 1; i < n && !dp[sum]; i++) { 
				for (j = sum; j >= a[i] && !dp[sum]; j--) 
					dp[j] = dp[j - a[i]] || dp[j]; 
			} 
			ans = dp[sum]; 
		} 
		printf("Collection #%d:\n", ++count); 
		if (ans) 
			printf("Can be divided.\n\n"); 
		else
			printf("Can't be divided.\n\n"); 
	} 
	return 0; 
}
