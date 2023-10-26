 item* curr = head;
        if(curr == NULL) return;
        for(int i=0; i<count; i++){
            while(curr!=NULL){
                if(curr->data > curr->next->data){
                    swapData(curr);
                }
                curr=curr->next;
            }
        }