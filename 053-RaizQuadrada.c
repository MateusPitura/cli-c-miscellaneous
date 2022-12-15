/*
Implemente uma funcao que calcule as raizes de uma equacao do segundo grau do tipo
Ax^2 + Bx + C = 0. Lembrando que: X=(−B±√∆)/2A. Onde: ∆=B^2−4AC
A variavel A tem que ser diferente de zero.
- Se ∆ < 0 nao existe real.
- Se ∆ = 0 existe uma raiz real.
- Se ∆ ≥ 0 existem duas ra´ızes reais.
Essa funcao deve obedecer ao seguinte prototipo: int raizes(float A,float B,float C,float *X1,float *X2);
Essa funcao deve ter como valor de retorno o numero de raizes reais e distintas da
equacao. Se existirem raizes reais, seus valores devem ser armazenados nas variaveis apontadas por X1 e X2
*/