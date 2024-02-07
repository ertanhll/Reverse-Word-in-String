



#include <stdio.h>

void reverseWord(char *str, char *word ){
    
    char *p, *q, *r, *memory_index=0;
    int count=0, word_length=0, str_length=0, exist=0,check=0;

    p=str;
    r=str;
    q=word;
   
    if(*p!='\0' && *q!='\0' && *p!=' ' && *q!=' '){
      
        while(*q!='\0'){
            word_length++;
            q++;
        }
        q=word;
        
        while(*p!='\0'){
            str_length++;
            p++;
        }
        p=str;
        
        while(*p!='\0'){
            
            while(*p==*q && *p!=' '&& *p!='\0'){
                count++;
                p++;
                q++;
                exist=1;
            }
            if (count==word_length){
                p--;
                q--;
            }
            if(count!=word_length && exist==1){
                p--;
                q=q-count;
                exist=0;
                count=0;
            }
            if(exist==1){
                memory_index=p+2;
                p=p-count+3;
                *p='-';
                p++;
                exist=0;
              
                while(word_length-2>0){
                    *p=*q;
                    p++;
                    q--;
                    word_length--;
                    count=0;
                    check=1;
                }
            }
            p++;
        }
        int i=0;
        while(memory_index+i<str+str_length && check==1){
            *(str+str_length-i)=*(r+str_length-i-1);
            i++;
        }
        if(check==1) *(memory_index)=' ';
        else printf("No Word Match!\n");
     
        while(*str!='\0'){
            printf("%c",*str);
            str++;
        }
        printf("\n");
    }
}

int main() {
 
    char str[50]= "This is the input sentence";
    char word[20]="Thiss";
    
    reverseWord(str,word);
  
    return 0;
}
