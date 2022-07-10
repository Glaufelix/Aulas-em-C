
typedef struct cubo Cubo;
Cubo* cubo_cria(float a);
void cubo_libera(Cubo* c);
void cubo_acessa(Cubo* c, float* a);
void cubo_atribui(Cubo *c, float a);
float cubo_area(Cubo* c);
float cubo_volume(Cubo* c);
