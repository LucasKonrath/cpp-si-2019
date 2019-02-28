# 1) Encontre o(s) erro(s) nos seguintes códigos:

a)
```
#include <stdio.h>
int globalval = 1; //variável global nunca utilizada
int main(argc, const char * argv[])
{
int var1; //variável nunca atribuida
printf("Hello, World!\n");
return; //falta o número no return, pois assinatura do método é int
}
```
b)
```
#include <stdio.h //falta / para fechar include do stdio
void main()
{
 printf("Hello, World!\n); //falta aspas para fechar string o hello world
}
```
c)
```
#include <stdio.h>
int main()
{
 prntf("Hello, World!\n"); // correto é printf
 return 0 // falta ;
}
```

d)
```
#include <stdio.h>
globalval = 1; //variável global nunca utilizada
int main(int argc, const char * argv[])
{
int var1; // variável local nunca atribuída
printf("Hello, World!\n");
return 0;
}
```
e)
```
#include <stdio.h>
int globalval = 1; //variável global nunca utilizada
void main(int argc, const char * argv[])
{
int var1; //variável global nunca atribuída
printf("Hello, World!\n");
return 0; // retorno incompatível com assinatura do método
}
```

f)
```
include <stdio.h> //faltou o # no include
void main()
{
 printf("Hello, World!\n");
}
```
g)
```
#include <stdio.h>
int main(int argc, const char * argv[])
{
 printf("Hello, World!\n");
// falta o retorno de int
}
```
h)
```
#include <stdio.h>
int man() //nome do método deve ser main
{
 printf("Hello, World!\n");
 return 0;
}
```
i)
```
#include <stdio.h>
void main()
{
 printf(Hello, World!\n");
// faltou } para fechar método
```
j)
```
#include “stdio.h” // delimitador de header errado. correto seria <stdio.h>
int main(int argc, const char * argv[])
{
 printf("Hello, World!\n");
 return 0;
}
```
k)
```
#include <stdio.h>
int main(int argc, const char * argv[])
{
 printf("Hello, World!\n");
 return 0 // faltou ;
}
```
l)
```
#include <stdio.h>
int main() // faltou { aqui
 printf("Hello, World!\n");
 return 0;
 ```