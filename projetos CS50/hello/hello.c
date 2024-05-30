#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("hello world\n");
    string nome = get_string("Qual seu nome? ");
    printf("hello, %s\n", nome);
}