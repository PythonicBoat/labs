void mergeSort() {
    struct node *t1 = NULL;
    struct node *t2 = NULL;
    while(t1!=NULL && t2!=NULL) {
        if (t1 -> data < t2 -> data) {
            c_start3(t1->data);
            t1 = t1->next;
        } else if (t1->data > t2->data){
            c_start3(t2->data);
        } else {
            c_start3(t1->data);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
}