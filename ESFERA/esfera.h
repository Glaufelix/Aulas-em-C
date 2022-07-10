
typedef struct esfera Esfera;
Esfera* sfr_cria(float a);
void sfr_libera(Esfera* e);
void sfr_acessa(Esfera* e, float* a);
void sfr_atribui(Esfera* e, float a);
float sfr_volume(Esfera* e);
