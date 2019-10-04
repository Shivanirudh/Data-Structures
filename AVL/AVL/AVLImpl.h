#include"AVLProto.h"

static int ht(dictionaryADT* d){
	if(d==NULL)
		return -1;
	else
		return d->height;
}

dictionaryADT* singlerotatewithleft(dictionaryADT *D){
	dictionaryADT *tmp=D->left;
	D->left=tmp->right;
	tmp->right=D;
	
	D->height=(ht(D->left)>ht(D->right))?ht(D->left):ht(D->right);
	D->height++;
	
	tmp->height=(ht(tmp->left)>ht(D->right))?ht(tmp->left):ht(D->right);
	tmp->height++;
	
	return tmp;
}

dictionaryADT* singlerotatewithright(dictionaryADT *D){
	dictionaryADT *tmp=D->right;
	D->right=tmp->left;
	tmp->left=D;
	
	D->height=(ht(D->left)>ht(D->right))?ht(D->left):ht(D->right);
	D->height++;
	
	tmp->height=(ht(tmp->right)>ht(D->left))?ht(tmp->right):ht(D->left);
	tmp->height++;
	
	return tmp;
}

dictionaryADT* doublerotatewithleft(dictionaryADT *D){
	D->left=singlerotatewithright(D->left);
	return singlerotatewithleft(D);
}
		
dictionaryADT* doublerotatewithright(dictionaryADT *D){
	D->right=singlerotatewithleft(D->right);
	return singlerotatewithright(D);
}


dictionaryADT* insert(dictionaryADT *D, wordMeaning x){
	if(D==NULL){
		D=(dictionaryADT*)malloc(sizeof(dictionaryADT));
		D->wm=x;
		D->height=0;
		D->left=D->right=NULL;
	}
	else if(strcmp(x.word,D->wm.word)<0){
		D->left=insert(D->left,x);
		int diff=(ht(D->left)>ht(D->right))?ht(D->left):ht(D->right);
		
		if(diff==2){
			if(strcmp(x.word,D->left->wm.word)<0)
				D=singlerotatewithleft(D);
			else
				D=doublerotatewithleft(D);
		}
	}
	else if(strcmp(x.word,D->wm.word)>0){
		D->right=insert(D->right,x);
    	int diff=(ht(D->left)>ht(D->right))?ht(D->left):ht(D->right);
		if(diff== 2){
			if(strcmp(x.word,D->left->wm.word)>0)
				D=singlerotatewithright(D);
			else
				D=doublerotatewithright(D);
		}
	}
	D->height=(ht(D->left)>ht(D->right))?ht(D->left):ht(D->right);
	D->height++;
	return D;
}			

void displayWord(wordMeaning w){
	printf("%s\t-\t%s\n",w.word,w.meaning);
}

void disp(dictionaryADT *D,int depth){
	if(D){
		for(int i=0;i<depth;i++)
			printf("\t");
		
		displayWord(D->wm);
		disp(D->left,depth+1);
		disp(D->right,depth+1);
	}
}

void search(dictionaryADT *D, char word[]){
	if(D==NULL)
		printf("\nNo such record \n");
	if(!strcmp(word,D->wm.word))
		displayWord(D->wm);
	if(strcmp(word,D->wm.word)<0)
		search(D->left,word);
	if(strcmp(word,D->wm.word)>0)
		search(D->right,word);
}


