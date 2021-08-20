// Author: Dhruv Shetty

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int n, seg1, seg2, seg3, seg4, result;
    scanf("%d",&n);

	// Breaks the number into 4 separate segments, each of which are 8 bits
	// Next, makes adjustments so the segments are placed on opposite positions as they were originally
	// Final adjustment in seg3 and seg4 is to account for arithmetic right shifting with negative numbers
	seg1 = (n & 0x000000FF) << 24;
	seg2 = (n & 0x0000FF00) << 8;
	seg3 = ((n & 0x00FF0000) >> 8) & 0x0000FF00;
	seg4 = ((n & 0xFF000000) >> 24) & 0x000000FF;

	// Recombines the adjusted segments into one int
	result = seg1 | seg2 | seg3 | seg4;

	printf("%d converts to %d\n", n, result);

	return 0;
}
