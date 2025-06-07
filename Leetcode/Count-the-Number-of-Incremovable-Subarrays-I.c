int incremovableSubarrayCount(int* nums, int numsSize) {
    // Setup a counter for the number of incremovable subarray
    int counter = 0;
    int * prev = NULL; 
    // Check if the current nums array is already incremovable 
        // Yes: +1
    if(numsSize == 1){
        return 1;
    }

    printf("My counter is %d\n", counter);
    // Double For Loop / Double Pointer to check for incremovable subarrays
    for(int i = 0; i< numsSize; i++){
        for(int j = i; j< numsSize; j++){
            // Check for array not in between i to j
            // See if they are incremovable after taking i to jth indices out
            prev = NULL;
            int tracker = numsSize - (j-i) - 1;
            if(tracker == 0){
                counter += 1; // removing everything case;
                break;
            }
            for(int z = 0; z<numsSize; z++){
                if( z < i || z > j){ // 
                  //  printf("Tracker is %d\n", tracker);
                   // printf("Current value is %d\n\r", nums[z]);
                    if(prev == NULL){
                        prev = &nums[z];
                        tracker -= 1;
                        if(tracker == 0){
                            counter += 1;
                           // printf("Tracker is 0 %d\n", tracker);
                            break;
                        }
                    }
                    else if(*prev >= nums[z]){
                        break;
                    }
                    else{
                        tracker -= 1;
        
                        prev = &nums[z];
                        if(tracker == 0){
                            counter += 1;
                           // printf("Tracker is 0 %d\n", tracker);
                            break;
                        }
                    }
                    
                }
               
            }
            printf("i is %d and j is %d and the counter is %d\n\r", i, j, counter);
        }
    }
    return counter;
}