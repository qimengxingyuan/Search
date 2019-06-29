
/*二分查找
*/

int BinarySearch(int *arr, int len, int key)
{
    int left, right, mid;
    left = 0;
    right = len - 1;
    
    while(left <= right){
        mid = (left + right)/2;

        if(arr[mid] < key){
            left = mid + 1;
        }
        else if(arr[mid] > key){
            right = mid - 1;
        }
        else{
            return mid
        }
    }
    return -1;
}


/*插值查找
*关键字分布比较均匀
*时间复杂度 logn
*/
int InsertSearch(int *arr, int len, int key)
{
    int left, right, mid;
    left = 0;
    right = len - 1;

    while(left <= right){
        mid = left + (key - arr[left]) * (right - left) / (arr[right] - arr[left]);

        if(arr[mid] < key){
            left = mid + 1;
        }
        else if(arr[mid] > key){
            right = mid - 1;
        }
        else{
            return mid
        }
    }
    return -1;
}

