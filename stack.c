#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define size 100
struct stack{
	char s[size];
	int top;
}st;
int iasFull(){
	return st.top >= size -1;
}
int isEmpty(){
	return st.top == -1;
}
void push(char data){
	if(iasFull()) return;
	st.s[++st.top] = data;
}
void pop(){
	if(isEmpty()) return;
	st.top--;
}
int isOP(char c){
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
		return 1;
	}
	return 0;
}
int prec(char c){
	if(c == '+' || c == '-') return 1;
	if(c == '*' || c == '/') return 2;
	if(c == '^') return 3;
	return 0;
}

int main(){
    st.top = -1;
	char c[100];
	printf("Enter Infix Expression :- ");
	scanf("%s",c);
	char ans[100];
	int idx = 0;
	for(int i=0; i<strlen(c); i++){
		if(isOP(c[i])){
			ans[idx++] = c[i];
		}
		else if(c[i] == '('){
			push(c[i]);
		}
		else if(c[i] == ')'){
			while(!isEmpty() && st.s[st.top] != '('){
				ans[idx++] = st.s[st.top];
				pop();
			}
			pop();
		}
		else{
			while(!isEmpty() && prec(st.s[st.top]) >= prec(c[i])){
				ans[idx++] = st.s[st.top];
				pop();
			}
			push(c[i]);
		}
	}
	while(!isEmpty()){
		ans[idx++] = st.s[st.top];
		pop();
	}
	printf("PostFix expression : %s", ans);
}