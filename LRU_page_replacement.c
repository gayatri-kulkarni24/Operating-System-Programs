#include <stdio.h>

int main()
{
    int n, pages[20], frames, temp[10], counter[10];
    int i, j, time = 0, faults = 0, flag1, flag2, pos;

    printf("Enter no. of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter no. of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++) {
        temp[i] = -1;      // initialize frames
        counter[i] = 0;    // initialize usage counters
    }

    printf("\n Page reference string | frames\n");
	 for(i = 0; i < n; i++) {
        	flag1 = flag2 = 0;

       	 	// Check if page is already in memory (hit)
       		 for(j = 0; j < frames; j++) {
          		  if(temp[j] == pages[i]) {
               			 time++;
                		 counter[j] = time; // update usage time
               			 flag1 = flag2 = 1;
                		 break;
            		}
        	}

        	// Page not found in memory
       		 if(flag1 == 0) {
           		 // Check for empty frame
            		for(j = 0; j < frames; j++) {
            		    if(temp[j] == -1) {
                 		   time++;
                   		   temp[j] = pages[i];
                    		   counter[j] = time;
                 		   faults++;
                   		   flag2 = 1;
             		       	   break;
               		   }
            		}
        	}

       			 // If no empty frame: find least recently used page
        		if(flag2 == 0) {
           			 pos = 0;
            			for(j = 1; j < frames; j++) {
                			if(counter[j] < counter[pos]) {
                   				 pos = j;
               			 	}
           		 	}
			   	  time++;
			  	  temp[pos] = pages[i];
			 	  counter[pos] = time;
				  faults++;
         		 }

			// Output current state
			printf("\n %2d\t\t\t", pages[i]);
			for(j = 0; j < frames; j++) {
				    if(temp[j] != -1)
					printf("%2d ", temp[j]);
				    else
					printf("- ");
			}
   		}

    printf("\n\nTotal page faults = %d\n", faults);
    return 0;
}
