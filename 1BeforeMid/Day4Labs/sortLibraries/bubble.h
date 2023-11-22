void bubbleSort(float array[], int len){

    float temp;

    for(int i=0; i<len-1; i++){



        for(int j=0; j<len-i; j++){

            if(array[j] < array[j+1]){

                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }

    }

}