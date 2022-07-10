typedef struct cilindro Cilindro;

// cria um novo ponto
Cilindro* cld_cria(float x, float y);

// libera um ponto
void cld_libera(Cilindro* c);

// acesso os valores "X" e "y" de um ponto
void cld_acessa(Cilindro* c, float* x, float* y);

// atribuir os valores de "x" e "y" de um ponto
void cld_atribui(Cilindro *c, float x, float y);

// calcular a distância entre os dois ponto
float cld_volume(Cilindro* r, Cilindro* h);
