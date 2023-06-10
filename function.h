struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};


void insertFB(struct nodeFB **head, int id, int age) {
	struct nodeFB *newonode;
	newonode = malloc(sizeof(struct nodeFB));
	
	newonode -> id = id;
	newonode -> age = age;
	newonode -> next = *head;
	
	*head = newonode;
}

void insertGS(struct nodeGS **head, int id) {
	struct nodeGS *newonode;
	newonode = malloc(sizeof(struct nodeGS));
	
	newonode -> id = id;
	newonode -> next = *head;
	
	*head = newonode;

}

void sortfb(struct nodeFB *head) {
	struct nodeFB *temp=head, *temp2;
    	int hold1,hold2;

    	while (temp != NULL) {
        	temp2 = temp -> next;

        	while (temp2 != NULL) {
            		if (temp->id > temp2->id) {
                		hold1 = temp -> id;
                		hold2 = temp -> age;
                		temp -> id = temp2 -> id;
                		temp -> age = temp2 -> age;
                		temp2 -> id = hold1;
                		temp2 -> age = hold2;
            		}
            		temp2 = temp2 -> next;
        	}
        	temp = temp -> next;
    	}	

}

void sortgs(struct nodeGS *head) {
	struct nodeGS *temp=head, *temp2;
    	int hold1;

    	while (temp != NULL) {
        	temp2 = temp -> next;

        	while (temp2 != NULL) {
            		if (temp2->id > temp->id) {
                	hold1 = temp -> id;
                	temp -> id = temp2 -> id;
                	temp2 -> id = hold1;
            		}
            		temp2 = temp2 -> next;
        	}
        	temp = temp -> next;
    	}

}

void printFB(struct nodeFB *head) {
	struct nodeFB *tempfb;
	tempfb = head;
	sortfb(head);
	while (tempfb != NULL) {
		printf("%d %d\n",tempfb->id,tempfb->age);
		tempfb = tempfb -> next;
	}
	printf("\n");
}

void printGS(struct nodeGS *head) {
	struct nodeGS *tempgs;
	tempgs = head;
	sortgs(head);
	while (tempgs != NULL) {
		printf("%d\n",tempgs->id);
		tempgs = tempgs -> next;
	
	}
	printf("\n");
}	
void createFinalList(struct newNodeFB **head, struct nodeFB *headfb, struct nodeGS *headgs) {
	sortfb(headfb);
	sortgs(headgs);
	
	struct nodeFB *tempfb;
	tempfb = headfb;
	
	struct nodeGS *tempgs;
	tempgs = headgs;
	
	int c=0,idfb,agefb,idgs;
	
	while (tempfb != NULL) {
		c++;
		tempfb = tempfb->next;
	}
	
	tempfb = headfb;
	
	idfb = tempfb -> id;
	agefb = tempfb -> age;
	idgs = tempgs -> id;
	
	struct newNodeFB *newnodefb,*startfb;
	newnodefb = malloc(sizeof(struct newNodeFB));
	struct newNodeGS *newnodegs,*holdgs;
	newnodegs = malloc(sizeof(struct newNodeGS));
	
	startfb = newnodefb;
	
	newnodefb -> id = idfb;
	newnodefb -> age = agefb;
	newnodegs -> id = idgs;
	
	newnodefb -> next = newnodegs;
	
	tempfb = tempfb-> next;
	tempgs = tempgs -> next;
	
	for (int i=1; i<c; i++) {
		struct newNodeFB *nnodefb;
		nnodefb = malloc(sizeof(struct newNodeFB));
		struct newNodeGS *nnodegs;
		nnodegs = malloc(sizeof(struct newNodeGS));
		
		if (i == 1) {
			newnodegs -> next = nnodefb;
		}
		else {
			holdgs -> next = nnodefb;
		}
		idfb = tempfb -> id;
		agefb = tempfb -> age;
		idgs = tempgs -> id;			
		
		nnodefb -> id = idfb;
		nnodefb -> age = agefb;
		nnodegs -> id = idgs;
			
		nnodefb -> next = nnodegs;
			
		tempfb = tempfb -> next;
		tempgs = tempgs -> next;
		
		holdgs = nnodegs;
	}
	struct newNodeFB *lastfb;
	newnodefb = malloc(sizeof(struct newNodeFB));
	lastfb -> next = NULL;
	holdgs -> next = lastfb;
	
	*head = startfb;
	
}

void printAll(struct newNodeFB *head) {
	struct newNodeFB *tempfb;
	tempfb = head;
	struct newNodeGS *tempgs;
	tempgs = tempfb->next;
	
	while (tempfb -> next != NULL) {
		printf("%d %d\n",tempfb->id,tempfb->age);
		printf("%d\n",tempgs->id);
		
		tempfb = tempgs -> next;
		tempgs = tempfb->next;
	
	}
}




































// Bu lab kapsaminda kullanilacak butun fonksiyon tanimlarini bu dosyanin icine yazmaniz gerekmektedir.
// Tanimlanmasi zorunlu fonksiyonlar icerisinden kendi tanimayacaginiz baska fonksiyonlari cagirabilirsiniz.
// main.c dosyasinda bir degisiklik yapmayiniz.
// Sisteme function.h dosyasinin ismini OgrenciNumarasi.h olarak yukleyiniz.


